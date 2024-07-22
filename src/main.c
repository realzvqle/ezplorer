
#include "taskbar.h"



HDC dc;



void _entry(){

    dc = GetDC(NULL);
    taskbar_data tdata;
    tdata.color = RGB(255, 255, 255);
    tdata.size = 1755;
    taskbar_init(&tdata);
    taskbar_draw(&tdata);
    DeleteObject(tdata.brush);
    ReleaseDC(NULL, dc);
}