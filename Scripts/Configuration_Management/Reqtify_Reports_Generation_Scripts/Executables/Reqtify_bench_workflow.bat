@echo off

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables\PTC_Resyncronizer.exe -i='C:\_Projects\AUDI_TR6\Phase_01\View_Development\project.pj' -u='Jenkins01' -p='jnk01' > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\resincronizer_log_VIEW_DEV.txt" 2>&1 |rem

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables\PTC_Resyncronizer.exe -i='C:\_Projects\AUDI_TR6\Phase_01\View_Test\Tests\project.pj' -u='Jenkins01' -p='jnk01' > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\resincronizer_log_VIEW_TEST.txt" 2>&1 |rem

taskkill /F /IM IntegrityClient.exe /T > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\logfile_TASKKILL_PTC.txt" 2>&1 |rem

CALL C:\_Projects\AUDI_TR6\Phase_01\View_Development\Scripts\VirtualDrive\core\Mount_S_Drive.bat > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\Mount_s_drive.txt" 2>&1 |rem

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Scripts\VirtualDrive\core\RemoveReadOnly.bat  > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\Remove_read_only.txt" 2>&1 |rem

cd /d C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables\update_reqtify_folders.exe  -p="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\_Full" -d="C:\_Projects\AUDI_TR6\Phase_01\View_Development" -t="C:\_Projects\AUDI_TR6\Phase_01\View_Test" > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\logfile_update_reqtify_folders.txt" 2>&1 |rem

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables\Reqtify_report_generator.exe -o="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Reports" -p="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\_Full" -n="PP4G_E_Ph2.rqtf" > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\logfile_reqtify_autorun.txt" 2>&1 |rem

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables\export_grafics_from_reports.exe -i="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Reports\PSE_1P1P_SBE_Software_Arhictecture_Matrix_TR6.xlsm" -o="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Reports\exported_graphics\PSE_1P1P_SBE_Software_Arhictecture_Matrix_TR6" > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\logfile_export_graphics_sw_Arch_matrix.txt" 2>&1 |rem

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables\export_grafics_from_reports.exe -i="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Reports\PSE_1P1P_SBE_Software_Requirement_Matrix_TR6.xlsm" -o="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Reports\exported_graphics\PSE_1P1P_SBE_Software_Requirement_Matrix_TR6" > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\logfile_export_graphics_sw_req_matrix.txt" 2>&1 |rem

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables\export_grafics_from_reports.exe -i="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Reports\PSE_1P1P_SBE_SW_Design_Matrix_TR6.xlsm" -o="C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Reports\exported_graphics\PSE_1P1P_SBE_SW_Design_Matrix_TR6"  > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\logfile_export_graphics_sw_design_matrix.txt" 2>&1 |rem

C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Scripts\Executables\PTC_check_in_members.exe -i='C:\_Projects\AUDI_TR6\Phase_01\View_Development\Tools\Reqtify\Workspace\Reports\project.pj' -u='Jenkins01' -p='jnk01' -d='808861:4' > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\logfile_ptc_uploader.txt" 2>&1 |rem

taskkill /F /IM IntegrityClient.exe /T > "C:\Users\g-rbt.electronics\Desktop\Reqtify_Logs\logfile_TASKKILL_PTC.txt" 2>&1 |rem