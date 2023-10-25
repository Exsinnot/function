#include <windows.h>
//ดูสถานะของ KEY
GetAsyncKeyState(ตำแหน่ง KEY);
GetAsyncKeyState(0x02);
GetCursorPos(&xypos);
printf("%d %d\n",xypos.x,xypos.y);
SetCursorPos(x, y);
mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
keybd_event(0x53, 0, KEYEVENTF_EXTENDEDKEY, 0);
Sleep(10);
keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);