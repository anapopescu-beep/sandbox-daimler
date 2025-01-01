@echo off
si setprefs --command=ci --save branchIfVariant=yes
si setprefs --command=add --save onExistingArchive=sharearchive
REM Unmount S drive
subst S: /d
REM Mount S drive
subst S: "%~d0%~p0\..\..\.."