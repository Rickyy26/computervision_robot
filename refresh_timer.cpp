//
// Created by Ricky on 2025-03-11.
//
#include <iostream>
#include <Windows.h>
#include "refresh_timer.h"

using namespace std;

#define KEY(c) ( GetAsyncKeyState((int)(c)) & (SHORT)0x8000 )


void pause()
{
    while( !KEY(VK_SPACE) ) {}
    Sleep(300); // give some time to release space bar
}
