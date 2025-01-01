# -*- coding: iso-8859-1 -*-

# #####################################################################################################################
#  FILE DESCRIPTION
#  --------------------------------------------------------------------------------------------------------------------
#  \file
#  \brief        Python script for automating data processing on hex files using HexView
#  --------------------------------------------------------------------------------------------------------------------
#  COPYRIGHT
#  --------------------------------------------------------------------------------------------------------------------
#  \par Copyright
#  \verbatim
#  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
#
#                This software is copyright protected and proprietary to Vector Informatik GmbH.
#                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
#                All other rights remain with Vector Informatik GmbH.
#  \endverbatim
# *********************************************************************************************************************
# *  ------------------------------------------------------------------------------------------------------------------
# *  EXAMPLE CODE ONLY                                                                                                 
# *  ------------------------------------------------------------------------------------------------------------------
# *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW              
# *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The            
# *  Example Code is neither intended nor qualified for use in series production. The Example Code as well             
# *  as any of its modifications and/or implementations must be tested with diligent care and must comply              
# *  with all quality requirements which are necessary according to the state of the art before their use.             
# *********************************************************************************************************************
# #####################################################################################################################

# #####################################################################################################################
#  AUTHOR IDENTITY
#  --------------------------------------------------------------------------------------------------------------------
#  Name                          Initials      Company
#  --------------------------------------------------------------------------------------------------------------------
#  Christian Baeuerle            CB            Vector Informatik GmbH
#  --------------------------------------------------------------------------------------------------------------------
#  REVISION HISTORY
#  --------------------------------------------------------------------------------------------------------------------
#  Version   Date        Author  Change Id          Description
#  --------------------------------------------------------------------------------------------------------------------
#  01.00.00  2020-09-11  CB      -                  First implementation
#  01.01.00  2020-10-16  CB      -                  Generate LZMA compression
# #####################################################################################################################

# ---------------------------------------------------------------------------------------------------------------------
# Imported modules
# ---------------------------------------------------------------------------------------------------------------------

import sys
import os
import shutil
import fnmatch
import struct
import argparse
import re
import time

# ---------------------------------------------------------------------------------------------------------------------
# Configuration constants - to be adapted
# ---------------------------------------------------------------------------------------------------------------------

# Paths / directories

# Folder relative path to working directory
ROOT_PATH_REL = 'S:\Tools'

# Root-relative paths
HEXVIEW_PATH_REL = r'\HexView\Installation\HexView-1.13.01\hexview.exe'
LZMA_COMPRESSION_TOOL_PATH_REL = r'\Vector\Installation\fbl_aurix-vMB-BLuC-1.2.5.0\Misc\Cmpr_Lzma\COMPRESS_LZMA_Util.exe'

AES_KEY_REL = r'\..\..\..\..\Components\HSM\Supplier\Keys\aes_key.txt'
AES_IV_REL = r'\..\..\..\..\Components\HSM\Supplier\Keys\aes_iv.txt'
ECC_KEY = r'\..\..\..\..\Components\HSM\Supplier\Keys\cccv2_key_private.txt'

# LZMA parameters - please adapt if necessary
LZMA_OPT_LEVEL = r'9'
LZMA_DICT_SIZE = r'4096'


# ---------------------------------------------------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------------------------------------------------

# Number of characters in AES key- and IV file
AES_FILE_SIZE = 32
ALIGNMENT = 2

IDX_CMPR_VECTOR = 0
IDX_CMPR_LZMA = 1

IDX_CMPR_NAME = 0
IDX_CMPR_BIN_FCT = 1
IDX_CMPR_HEX_FCT = 2

# ---------------------------------------------------------------------------------------------------------------------
# Global variables
# ---------------------------------------------------------------------------------------------------------------------

compressionList = []

# ---------------------------------------------------------------------------------------------------------------------
# Implementation
# ---------------------------------------------------------------------------------------------------------------------

def set_path_vars():
    global local_path
    global root_path
    global hexview_path

    local_path = os.getcwd()
    root_path = ROOT_PATH_REL
    hexview_path = root_path + HEXVIEW_PATH_REL

    #print("Local path: " + local_path)
    #print("root path: " + root_path)
    #print("hexview path: " + hexview_path)
    print("Creating DAG SWDL Files")
    
    assert os.path.exists(root_path)
    assert os.path.exists(hexview_path)

def clean_up():
    if os.path.exists(r'tmp'):
        shutil.rmtree(r'tmp', ignore_errors=True)
    if os.path.exists(r'out'):
        shutil.rmtree(r'out', ignore_errors=True)

def prepare():
    if not os.path.exists(r'tmp'):
        os.mkdir(r'tmp')
    if not os.path.exists(r'out'):
        os.mkdir(r'out')
    assert os.path.exists(r'tmp')
    assert os.path.exists(r'out')

def get_file_name_without_extension_from_path(path):
    fileName = os.path.basename(path)
    fileName = os.path.splitext(fileName)
    fileName = fileName[0]
    return fileName

def concatenate_files(inputFiles, outputFile):
    # Avoid creating the file multiple times in case HMAC and RSA are used
    if not os.path.exists(outputFile):
        destination = open(outputFile, r'wb')
        totalSize = 0
        for file in inputFiles:
            totalSize += os.path.getsize(file)
            shutil.copyfileobj(open(file, r'rb'), destination)
        destination.close()
        assert totalSize == os.path.getsize(outputFile)
    assert os.path.exists(outputFile)

def create_file_path(path, folder, suffix, extension):
    fileName = get_file_name_without_extension_from_path(path)
    filePath = os.path.normpath(r'./' + folder + '/' + fileName + suffix + r'.' + extension)
    return filePath

def create_copy_of_input_file(inputFile):
    copiedInputFile = create_file_path(inputFile, r'out', r'', os.path.splitext(inputFile)[1][1:])
    shutil.copyfile(inputFile, copiedInputFile)
    assert os.path.exists(copiedInputFile)
    return copiedInputFile

def copy_sigfile_to_working_folder(inputFile):
    source = create_file_path(inputFile, r'./out', r'_cccv2', r'sig')
    target = create_file_path(inputFile, r'./', r'_cccv2', r'sig')
    shutil.copyfile(source, target)
    assert os.path.exists(target)

def single_region_create_binary_with_prepended_address_and_length_from_binary(binFile, address, length):
    binaryWithPrependedAddressAndLength = create_file_path(binFile, r'tmp', r'_addr_len', 'bin')
    # Avoid creating the file multiple times in case HMAC and RSA are used
    if not os.path.exists(binaryWithPrependedAddressAndLength):
        addressLengthString = r'%08x%08x' % (address, length)
        hexViewCommand = hexview_path + r'  /S /MO:' + binFile + r';8 /FR:0,8 /FP:' + addressLengthString + r' /XN /O:' + binaryWithPrependedAddressAndLength
        os.system(hexViewCommand)
    assert os.path.exists(binaryWithPrependedAddressAndLength)

def load_aes_file(inputFile):
    key_string = ""

    key_file = open(inputFile, "r")
    key_file.seek(0, os.SEEK_END)
    file_size = key_file.tell()
    key_file.seek(0, os.SEEK_SET)
    # File has to consist of 32 characters - 16 byte AES key or 16 bytes initialization vector
    if file_size != AES_FILE_SIZE:
        print("Invalid file - AES-keys and IVs need to have 16 bytes (32 ADCII characters). ")
    else:
        key_string = key_file.read(file_size)
    key_file.close()

    return key_string

def get_address_from_segment_binary_file_name(fileName):
    # Strip '.bin' from fileName, separate string into substrings, last substring contains hexadecimal address
    fileName = fileName[:-4]
    temp = fileName.split(r'_')
    segment = 0
    for namePart in temp:
        if namePart == r'segment':
            segmentfound = segment
        segment += 1
    assert temp[segmentfound] == r'segment'
    return int(temp[segmentfound + 1], 16)

def get_size_of_segmented_binary(fileName):
    segment_file = open(fileName, "r")
    segment_file.seek(0, os.SEEK_END)
    file_size = segment_file.tell()
    return file_size

def sort_array_of_segment_binaries(segmentedBinaries):
    sortedSegmentedBinaries = sorted(segmentedBinaries, key=get_address_from_segment_binary_file_name)
    return sortedSegmentedBinaries

def split_hex_file_into_multiple_binaries(inputFile):
    binaries = create_file_path(inputFile, r'tmp', r'_segment', r'bin')
    hexViewCommand = hexview_path + r' "' + inputFile + r'" /S /xsb /O:' + binaries
    os.system(hexViewCommand)
    segmentedBinaries = []
    file_sizes = []
    for file in os.listdir(os.path.normpath(r'./tmp/')):
        if fnmatch.fnmatch(file, get_file_name_without_extension_from_path(inputFile) + '_segment_*.bin'):
            segmentedBinaries.append(os.path.normpath(r'./tmp/' + file))
            file_sizes.append(get_size_of_segmented_binary(os.path.normpath(r'./tmp/' + file)))
    assert len(segmentedBinaries) > 0
    return segmentedBinaries, file_sizes

def concatenate_segment_binaries_into_hex_file(segmentedBinaries, uncompressed_mem_sizes, fileName, suffix):
    hexFilePath = create_file_path(fileName, r'out', suffix, r'hex')
    open(hexFilePath, 'a').close()
    lastAddress = 0
    fileIndex = 0
    for binFile in segmentedBinaries:
        address = get_address_from_segment_binary_file_name(binFile)
        fileSize = uncompressed_mem_sizes[fileIndex]
        # Check if addresses overlap
        if lastAddress > address:
            address = lastAddress + (ALIGNMENT - (lastAddress % ALIGNMENT))
        hexAddress = r'0x%08x' % address

        single_region_create_binary_with_prepended_address_and_length_from_binary(binFile, address, fileSize)

        binaryWithPrependedAddressAndLength = create_file_path(binFile, r'tmp', r'_addr_len', 'bin')
        hexViewCommand = hexview_path + r' /S /XI /MO:' + hexFilePath + r'+' + binaryWithPrependedAddressAndLength + r';' + hexAddress + r' /O:' + hexFilePath
        os.system(hexViewCommand)
        lastAddress = address + fileSize
        fileIndex += 1
    assert os.path.exists(hexFilePath)

# Concatenate segmented files into hex files
def concatenate_segment_binaries(segmentedBinaries, uncompressed_mem_sizes, fileName):
    # Unprocessed data
    concatenate_segment_binaries_into_hex_file(segmentedBinaries, uncompressed_mem_sizes, fileName, r'')
    # Encrypted data
    segmentedEncryptedBinaries = [segmentBinary.replace(r'.bin', r'_enc.bin') for segmentBinary in segmentedBinaries]
    concatenate_segment_binaries_into_hex_file(segmentedEncryptedBinaries, uncompressed_mem_sizes, fileName, r'_enc')

    for compression in compressionList:
        # Compressed data
        segmentedCompressedBinaries = [segmentBinary.replace(r'.bin', compression[IDX_CMPR_NAME] + r'.bin') for segmentBinary in segmentedBinaries]
        concatenate_segment_binaries_into_hex_file(segmentedCompressedBinaries, uncompressed_mem_sizes, fileName, compression[IDX_CMPR_NAME])
        # Compressed and encrypted data
        segmentedCompressedEncryptedBinaries = [segmentBinary.replace(r'.bin', compression[IDX_CMPR_NAME] + r'_enc' + r'.bin') for segmentBinary in segmentedBinaries]
        concatenate_segment_binaries_into_hex_file(segmentedCompressedEncryptedBinaries, uncompressed_mem_sizes, fileName, compression[IDX_CMPR_NAME] + r'_enc' )


# Data Processing -----------------------------------------------------------------------------------------

def multi_region_calculate_crc32_from_hex(inputFile):
    crc = create_file_path(inputFile, r'./', r'', r'crc')
    hexViewCommand = hexview_path + r' "' + inputFile + r'" /S -cs9:' + crc
    os.system(hexViewCommand)
    assert os.path.exists(crc)

def multi_region_calculate_signature(inputFile):
    err_file_arg = "-e:" + local_path + r'\error.txt'
    ecc_key_path = local_path + ECC_KEY
    sig_file = create_file_path(inputFile, local_path + r'./out', r'_cccv2', r'sig')
    hexViewCommand = hexview_path + r' "' + inputFile + r'"  /S  ' + err_file_arg + r' /dp48:' + ecc_key_path + ';' + sig_file
    os.system(hexViewCommand)
    assert os.path.exists(sig_file)

# Create LZ77 compressed file
def compress_file_vector(inputFile):
    err_file_arg = "-e:" + local_path + r'\error.txt'
    cmpr_file = create_file_path(inputFile, r'./', compressionList[IDX_CMPR_VECTOR][IDX_CMPR_NAME], r'hex')
    hexViewCommand = hexview_path + r' "' + inputFile + r'" ' + err_file_arg + r'  /S /dp19 -xi -o ' + cmpr_file
    os.system(hexViewCommand)
    assert os.path.exists(cmpr_file)

def compress_binary_vector(inputFile, compressedFile):
    err_file_arg = "-e:" + local_path + r'\error.txt'
    hexViewCommand = hexview_path + r' "' + inputFile + r'" ' + err_file_arg + r'  /S /dp19 -xn -o ' + compressedFile
    os.system(hexViewCommand)
    assert os.path.exists(compressedFile)

# Create LZMA compressed file
def compress_binary_lzma(binFile, compressedFile):
    compressionToolCommand = root_path + LZMA_COMPRESSION_TOOL_PATH_REL + r' -O' + LZMA_OPT_LEVEL + r' -ws=' + LZMA_DICT_SIZE + ' ' + binFile + ' ' + compressedFile + r' >nul 2>&1'
    os.system(compressionToolCommand)
    assert os.path.exists(compressedFile)

def compress_file_lzma(inputFile, segmentedBinaries):
    err_file_arg = "-e:" + local_path + r'\error.txt'
    cmpr_file = create_file_path(inputFile, r'./', compressionList[IDX_CMPR_LZMA][IDX_CMPR_NAME], r'hex')
    
    # Delete file if it already exists
    if os.path.exists(cmpr_file):
        os.remove(cmpr_file)

    for binFile in segmentedBinaries:
        # Compress each single binary
        cmpr_bin_file = create_file_path(binFile, r'./tmp', compressionList[IDX_CMPR_LZMA][IDX_CMPR_NAME], r'bin')
        compressionToolCommand = root_path + LZMA_COMPRESSION_TOOL_PATH_REL + r' -O' + LZMA_OPT_LEVEL + r' -ws=' + LZMA_DICT_SIZE + ' ' + binFile + ' ' + cmpr_bin_file + r' >nul 2>&1'
        os.system(compressionToolCommand)

        # merge compressed files
        address = get_address_from_segment_binary_file_name(binFile)
        hexAddress = r'0x%08x' % address
        hexViewCommand = hexview_path + r' /S /XI /MO:' + cmpr_file + r'+' + cmpr_bin_file + r';' + hexAddress + r' /O:' + cmpr_file
        os.system(hexViewCommand)

    assert os.path.exists(cmpr_file)

def encrypt_file_aes(inputFile):
    err_file_arg = "-e:" + local_path + r'\error.txt'
    aes_key_path = local_path + AES_KEY_REL
    aes_iv_path = local_path + AES_IV_REL

    key_string = load_aes_file(aes_key_path)
    if (key_string == ""):
        print("Encryption failed- invalid key.")
        return

    iv_string = load_aes_file(aes_iv_path)
    if (iv_string == ""):
        print("Encryption failed - invalid initialization vector")
        return

    enc_file = create_file_path(inputFile, r'./', r'_enc', r'hex')
    enc_hexview_cmd = r' /S /dp11:' + key_string + ';PKCS7#IV=' + iv_string
    hexViewCommand = hexview_path + r' "' + inputFile + r'" ' + err_file_arg + enc_hexview_cmd +r' -xi -o ' + enc_file
    os.system(hexViewCommand)
    assert os.path.exists(enc_file)

def encrypt_binary(inputFile):
    err_file_arg = "-e:" + local_path + r'\error.txt'
    aes_key_path = local_path + AES_KEY_REL
    aes_iv_path = local_path + AES_IV_REL

    key_string = load_aes_file(aes_key_path)
    if (key_string == ""):
        print("Encryption failed - invalid key.")
        return

    iv_string = load_aes_file(aes_iv_path)
    if (iv_string == ""):
        print("Encryption failed - invalid initialization vector")
        return

    enc_file = create_file_path(inputFile, r'./tmp', r'_enc', r'bin')
    enc_hexview_cmd = r' /S /dp11:' + key_string + ';PKCS7#IV=' + iv_string
    hexViewCommand = hexview_path + r' "' + inputFile + r'" ' + err_file_arg + enc_hexview_cmd +r' -xn -o ' + enc_file

    os.system(hexViewCommand)
    assert os.path.exists(enc_file)

def compress_files(inputFile):
    # encrypt plaintext file
    encrypt_file_aes(inputFile)

    # Create compressed file for each available compression
    for compression in compressionList:
        # Compress file
        compression[IDX_CMPR_HEX_FCT](inputFile)
        cmprInputFile = create_file_path(inputFile, r'./', compression[IDX_CMPR_NAME], r'hex')

        #encrypt compressed file
        encrypt_file_aes(cmprInputFile)

def compress_binaries(segmentedBinaries):
    for segmentedBinary in segmentedBinaries:
        for compression in compressionList:
            cmpr_file = create_file_path(segmentedBinary, r'./tmp',compression[IDX_CMPR_NAME], r'bin')
            compression[IDX_CMPR_BIN_FCT](segmentedBinary, cmpr_file)

def encrypt_binaries(segmentedBinaries):
    for segmentedBinary in segmentedBinaries:
        encrypt_binary(segmentedBinary)

def encrypt_compressed_binaries(segmentedBinaries):
    for segmentedBinary in segmentedBinaries:
        for compression in compressionList:
            cmpr_file = create_file_path(segmentedBinary, r'./tmp', compression[IDX_CMPR_NAME], r'bin')
            encrypt_binary(cmpr_file)

def calculate_signatures(inputFile):
    plain_file = create_file_path(inputFile, r'./out', r'', r'hex')
    multi_region_calculate_signature(plain_file)
    copy_sigfile_to_working_folder(plain_file)

    for compression in compressionList:
        cmpr_file = create_file_path(inputFile, r'./out', compression[IDX_CMPR_NAME], r'hex')
        multi_region_calculate_signature(cmpr_file)
        copy_sigfile_to_working_folder(cmpr_file)

    enc_file = create_file_path(inputFile, r'./out', r'_enc', r'hex')
    multi_region_calculate_signature(enc_file)
    copy_sigfile_to_working_folder(enc_file)

    for compression in compressionList:
        cmpr_enc_file = create_file_path(inputFile, r'./out', compression[IDX_CMPR_NAME] + r'_enc', r'hex')
        multi_region_calculate_signature(cmpr_enc_file)
        copy_sigfile_to_working_folder(cmpr_enc_file)

def main():

    inputFilePaths = []
    segment_addresses = []

    set_path_vars()
    clean_up()
    prepare()

    # Always generate compresed file with Vector compression
    compressionList.append(['_lz77', compress_binary_vector, compress_file_vector])

    # Generate LZMA-compressed file if compression tool is available
    if os.path.exists(root_path + LZMA_COMPRESSION_TOOL_PATH_REL):
        compressionList.append(['_lzma', compress_binary_lzma, compress_file_lzma])

    # Check for input arguments
    parser = argparse.ArgumentParser(prog=r'dag_swdl_files_create.py', description=r'Data processing on hex files using HexView. Provide multiple input files to merge them.')
    parser.add_argument(r'-i', r'--input', type=str, action=r'append', metavar=r'YourInputFilePath', help=r'The input file path, multiple paths can be specified')

    if len(sys.argv)==1:
        parser.print_help(sys.stderr)
        sys.exit(1)
    args = parser.parse_args()

    args.input = [] if None else args.input

    for path in args.input:
        assert os.path.exists(path)
        inputFilePaths.append(path)

    inputFile = inputFilePaths[0]
    # inputFile = create_copy_of_input_file(inputFilePaths[0])
    fileName = get_file_name_without_extension_from_path(inputFilePaths[0])

    # Calculate CRC32 on uncompressed- and unecrypted file for verification of programmed data
    # (output- or pipelined verificaton)
    multi_region_calculate_crc32_from_hex(inputFile)

    # Create a single bin file for each segment of the download hex file
    # Needed for LZMA compression and signature calculation
    segmentedBinaries, uncompressed_mem_size  = split_hex_file_into_multiple_binaries(inputFile)

    # Create compressed- and encrypted files

    # encrypt file
    encrypt_file_aes(inputFile)

    # compress_file Vector(inputFile)
    compress_file_vector(inputFile)

    # Encrypt compressed file
    cmprInputFile = create_file_path(inputFile, r'./', compressionList[IDX_CMPR_VECTOR][IDX_CMPR_NAME], r'hex')
    encrypt_file_aes(cmprInputFile)

    # Compress and encrypt (LZMA)
    if len(compressionList) > IDX_CMPR_LZMA:
        compress_file_lzma(inputFile, segmentedBinaries)

        cmprInputFile = create_file_path(inputFile, r'./', compressionList[IDX_CMPR_LZMA][IDX_CMPR_NAME], r'hex')
        encrypt_file_aes(cmprInputFile)

    # === Prepare files for signature calculation ===
    # Hash calculation has to be done on address, uncompresse lengh and data

    # Compress and encrypt the segment binary files
    compress_binaries(segmentedBinaries)
    encrypt_binaries(segmentedBinaries)
    encrypt_compressed_binaries(segmentedBinaries)

    # Concatenate the segmented files with prepended address and length information
    concatenate_segment_binaries(segmentedBinaries, uncompressed_mem_size, inputFile)

    # Create signatures on concatenation result
    calculate_signatures(inputFile)

    # Remove temprorary folders
    clean_up()

    print("Files successfully created ")


# ---------------------------------------------------------------------------------------------------------------------
# Script entry point
# ---------------------------------------------------------------------------------------------------------------------

if __name__ == "__main__":
    main()
