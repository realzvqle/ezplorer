#include "taskbar.h"



extern HDC dc;

void taskbar_init(taskbar_data* tdata){
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    
    int dpiX = GetDeviceCaps(dc, LOGPIXELSX);  
    int dpiY = GetDeviceCaps(dc, LOGPIXELSY);
   
    tdata->rect = (RECT){screenWidth * dpiX, (screenHeight * dpiX), 0, tdata->size};
    tdata->brush = CreateSolidBrush(tdata->color);

}




void taskbar_draw(taskbar_data* tdata){
    while(1){
        FillRect(dc, &tdata->rect, tdata->brush);
        if(GetAsyncKeyState('W') & 0x8000){
            ExitProcess(0);
        }
    }
}