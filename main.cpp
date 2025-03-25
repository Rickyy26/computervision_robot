#include <iostream>
#include <cstdio>
#include <fstream>
#include <Windows.h>

using namespace std;
#define KEY(c) ( GetAsyncKeyState((int)(c)) & (SHORT)0x8000 )

#include "refresh_timer.h"
#include "image_processing.h"
#include "vision_processing.h"

int main() {
    int i;
    int cam_number, height, width, image_size;
    ibyte *p; //pixel postion pointer
    ibyte R, G, B, grey;
    image rgb1;

    activate_vision();

    cam_number=0;
    height = 480;
    width = 640;

    set_rgb_image("blue_target.bmp",rgb1);

    view_rgb_image(rgb1);
    cout << "\ninput original image size (W x H) rgb1";
    pause();

    width = rgb1.width;
    height = rgb1.height;
    cout << "\nwidth =" << width;
    cout << "\nheight =" << height;

    image_size = width * height;

    p = rgb1.pdata;

    for(i = 0; i < image_size; i++){
        B = *p;
        G = *(p+1);
        R = *(p+2);

        //if in range then turn the pixel to "extra blue"
        if((B > 120) && (R < 50) && (G < 100)){
            R = 0;
            G = 0;
            B = 255;
        }

        *p = B;
        *(p+1) = G;
        *(p+2) = R;

        //skips to next pixel
        p += 3;
    }
    view_rgb_image(rgb1);

    cout << "\nresulting image -- press space to continue";
    pause();

    free_image(rgb1);

    deactivate_vision();

    cout << "\n\n\ndone\n\n\n";
    return 0;
}
