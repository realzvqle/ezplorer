#ifndef TASKBAR_H_INCLUDED
#define TASKBAR_H_INCLUDED


#include "ezplorer.h"
#include <stdint.h>



typedef struct _rect_data {
    int size;
    COLORREF color;
    RECT rect;
    HBRUSH brush;
} rect_data;

typedef struct _taskbar_data {
    rect_data rdata;
    rect_data sbdata;

} taskbar_data;

void taskbar_init(taskbar_data* tdata);
void taskbar_draw(taskbar_data* tdata);




#endif