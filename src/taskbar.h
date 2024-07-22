#ifndef TASKBAR_H_INCLUDED
#define TASKBAR_H_INCLUDED


#include "ezplorer.h"




typedef struct _taskbar_data{
    int size;
    COLORREF color;
    RECT rect;
    HBRUSH brush;
} taskbar_data;


void taskbar_init(taskbar_data* tdata);
void taskbar_draw(taskbar_data* tdata);




#endif