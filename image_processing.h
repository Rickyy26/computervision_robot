//
// Created by Ricky on 2025-03-11.
//

#define RGB_IMAGE 1
#define GREY_IMAGE 2
#define LABEL_IMAGE 3

typedef unsigned char ibyte;
typedef unsigned short int i2byte;
typedef unsigned long int i4byte;

typedef struct{
    int type;
    i2byte height;
    i2byte width;
    ibyte *pdata;
    i2byte nlabels;
}image;

// 170 MB (10,000 x 5,650 pixel -- RGB image)
const DWORD SMAX = 170000000;

//

int activate_vision();

int activate_camera(int cam_number, int height, int width);

int acquire_image(image &a, int cam_number);

int deactivate_vision();

int stop_camera(int cam_number);

int start_camera(int cam_number);

//

int view_rgb_image(image &a);

int save_rgb_image(char *file_name, image &a);

int load_rgb_image(char *file_name, image &a);

int set_rgb_image(char *file_name, image &a);

int allocate_image(image &a);

int free_image(image &a);

//

int open_video_input(char *file_name, double &t_duration, int &width, int &height);

int close_video_input();

int open_video_output(char *file_name);

int close_video_output();

int read_video_input(image &a, double &t_sample);

int position_video_input(double t_position);

int write_video_output(image &a, double t_sample);