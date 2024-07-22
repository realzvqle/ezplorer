
#include "taskbar.h"



HDC dc;


void _entry(){
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    dc = GetDC(NULL);
    int dpiX = GetDeviceCaps(dc, LOGPIXELSX);  
    int dpiY = GetDeviceCaps(dc, LOGPIXELSY);

    taskbar_data tdata;
    tdata.color = RGB(255, 255, 255);
    tdata.size = 90;
    taskbar_init(&tdata);
    taskbar_draw(&tdata);
    DeleteObject(tdata.brush);
    ReleaseDC(NULL, dc);
}