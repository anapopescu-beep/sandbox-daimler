# Export Grafics From Reports
# Lucian Ardeleanu
# Autoliv, 09.03.2021

# Imports
import os, os.path
import win32com.client
from PIL import ImageGrab
import argparse
import ntpath
import win32com.client as win32

# Main function
def main():
    # Arguments parse
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input-path', help="Path to file to extract graphs", required=True)
    parser.add_argument('-o', '--output-path', help="Path to folder where to save extracted images", required=True)
    args = parser.parse_args()

    #extract file name from path
    extract_name_from_path = ntpath.basename(args.input_path)

    # Extract only a part from entire file name
    extract_type_from_name = extract_name_from_path[13:-9]

    # Shrink name a little bit
    extract_type_from_name = extract_type_from_name.replace('Software', 'SW')

    # Set a excel apllication as xl class
    xl=win32com.client.Dispatch("Excel.Application")

    # open fileP30
    wb = xl.Workbooks.Open(args.input_path, ReadOnly=0)

    # Write cell to activate
    writeData = wb.Worksheets('FrontPage')
    writeData.Cells(24, 15).Value = 'Auto Generated'

    # Set worksheet Statistics
    xl.Worksheets("Statistics").Activate()

    # Run VBA button Update Statistics
    xl.Application.Run("Feuil1.UpdateStatisticTable")


    # Define counter used for naming images
    counter_for_all_images = 0

    # Select again sheet Statistics
    sheet = xl.Sheets("Statistics")

    # Iterate through sheets
    for n, shape in enumerate(sheet.Shapes):
        try:
            # If a image has been found in sheet, then copy it
            shape.Copy()
            # And then grab it in object image
            image = ImageGrab.grabclipboard()
        except:
            # otherwise, continue. This try-except block is mandatory
            continue

        # Get image size. You need to save only graphs, not buttons
        width, height = image.size

        # if grabbed image has dimensions greater than a button, than save it
        if ( height > 150 ):
            image.save( args.output_path + '/' + extract_type_from_name + '_img_' + str(counter_for_all_images) + '.png')
            counter_for_all_images += 1
        pass
    pass

    # Detele unecessary objects
    del xl
    wb.Close(True)


if __name__ == "__main__":
    main()