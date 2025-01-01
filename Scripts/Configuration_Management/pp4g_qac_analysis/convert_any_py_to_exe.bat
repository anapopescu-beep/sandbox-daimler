@echo off
for %%f in (*.py) do (
    if "%%~xf"==".py" pyinstaller --onefile %%f
)


