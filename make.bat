@echo off




cl /c src/*.c 
link *.obj kernel32.lib user32.lib shell32.lib gdi32.lib /entry:_entry /out:ezplorer.exe /subsystem:windows
del *.obj
start ezplorer.exe