__author__ = "Ardeleanu Lucian"
__copyright__ = "Autoliv, 2021"
__version__ = "1.5"
__maintainer__ = "Ardeleanu Lucian"
__email__ = "lucian.ardeleanu@autoliv.com"
__status__ = "Released"

# This script will resync a file/directory in PTC. 

# =================== IMPORTS =======================================
import argparse

# ======= API DEFINITION ============================================
def Resync_PTC(PTC_User_Name, PTC_Password, PTC_Sync_Path):

    #================= IMPORTS =========================
    import os

    # ================ VARIABLES =======================
    PTCLogIn_flag = 0
    path_to_si = '"C:/Program Files (x86)/Integrity/ILMClient11/bin/si.exe" '
    # =============== WORKFLOW =========================
    if (PTCLogIn_flag == 0):
        s = 1
        while (s == 1):
            s = os.system(path_to_si + "connect --hostname='ALVA-MKS01.alv.autoliv.int' --port='7001' --user=" + PTC_User_Name + " --password=" + PTC_Password)
        PTCLogIn_flag = 1

    sync = 1
    while (sync == 1):
        sync = os.system( path_to_si + "resync --overwriteChanged --sandbox " + PTC_Sync_Path + " --yes")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input-path', help="Path to folder to resync. Add at final path /project.pj", required=True)
    parser.add_argument('-u', '--input-username', help="Username for PTC Account", required=True)
    parser.add_argument('-p', '--input-passowrd', help="Passowrd for PTC Account", required=True)
    args = parser.parse_args()

    Resync_PTC(PTC_User_Name=args.input_username, PTC_Password=args.input_passowrd, PTC_Sync_Path=args.input_path)


if __name__ == '__main__':
    main()