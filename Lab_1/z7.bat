@echo off
:START
set /A text_color=%random% %% 16
set /A background_color=%random% %% 16
call setcolor.bat !text_color!!background_color!
timeout 0.1 > nul
goto START