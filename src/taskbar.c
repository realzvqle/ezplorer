#include "taskbar.h"


extern HDC dc;



static inline void ribbon_init(rect_data* rdata) {
    rdata->color = RGB(255, 255, 255);
    rdata->size = 90;
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int dpiX = GetDeviceCaps(dc, LOGPIXELSX);  
    rdata->rect = (RECT){90 * dpiX / 96, 0, screenWidth * dpiX, rdata->size};
    rdata->brush = CreateSolidBrush(rdata->color);
}

static inline void start_button_data(rect_data* sbdata) {
    sbdata->color = RGB(0, 90, 0);
    sbdata->size = 90;
    sbdata->rect = (RECT){0, 0, sbdata->size, sbdata->size};
    sbdata->brush = CreateSolidBrush(sbdata->color);
}

static inline void draw_start_button(rect_data* sbdata){
    FillRect(dc, &sbdata->rect, sbdata->brush);
    POINT cursor_pos;
    if(GetCursorPos(&cursor_pos)){
        if(cursor_pos.x >= sbdata->rect.left &&
            cursor_pos.x <= sbdata->rect.right &&
            cursor_pos.y >= sbdata->rect.top &&
            cursor_pos.y <= sbdata->rect.bottom){
                ShellAboutW(NULL, L"Ezplorer Shell", L"Ezplorer Shell, Copyright realzvqle, All Rights Reserved", NULL);
            }
    }
}

static inline void draw_ribbon(rect_data* rdata){
    FillRect(dc, &rdata->rect, rdata->brush);
    POINT cursor_pos;
    if(GetCursorPos(&cursor_pos)){
        if(cursor_pos.x >= rdata->rect.left &&
            cursor_pos.x <= rdata->rect.right &&
            cursor_pos.y >= rdata->rect.top &&
            cursor_pos.y <= rdata->rect.bottom){
                ShellAboutW(NULL, L"Ezplorer Shell", L"Ezplorer Shell, Copyright realzvqle, All Rights Reserved", NULL);
            }
    }
}

void taskbar_init(taskbar_data* tdata){
    ribbon_init(&tdata->rdata);
    start_button_data(&tdata->sbdata);
}


void taskbar_draw(taskbar_data* tdata){
    while(1){
        draw_start_button(&tdata->sbdata);
        draw_ribbon(&tdata->rdata);

        if(GetAsyncKeyState('W') & 0x8000){
            ExitProcess(0);
        }
    }
}