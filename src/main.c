
#include "taskbar.h"



HDC dc;


void _entry(){
    dc = GetDC(NULL);
    taskbar_data tdata;
    taskbar_init(&tdata);
    taskbar_draw(&tdata);
    DeleteObject(tdata.rdata.brush);
    ReleaseDC(NULL, dc);
}