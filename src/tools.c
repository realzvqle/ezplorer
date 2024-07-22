#include "tools.h"
#include <winuser.h>





void msg_box(WCHAR* content, UINT icon){
    MessageBoxW(NULL, content, L"Ezplorer Shell", MB_OK | icon);
}



int yesno_box(WCHAR* content, UINT icon){
    return MessageBoxW(NULL, content, L"Ezplorer Shell", MB_YESNO | icon);
}