#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    if (x >= im.w) {
        x = im.w - 1;
    } else if (x < 0) {
        x = 0;
    }
    if (y >= im.h) {
        y = im.h - 1;
    } else if (y < 0) {
        y = 0;
    }
    if (c >= im.c) {
        c = im.c - 1;
    } else if (c < 0) {
        c = 0;
    }
    
    int i = c * im.w * im.h + y * im.w + x;
    
    return im.data[i];
}

int get_index(image im, int x, int y, int c) {
    return c * im.w * im.h + y * im.w + x;
}

void set_pixel(image im, int x, int y, int c, float v)
{
    if (x >= im.w || x < 0 || y >= im.h || y < 0 || c >= im.c || c < 0) {
        return;
    }
    int i = get_index(im, x, y, c);
    im.data[i] = v;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    memcpy(copy.data, im.data, im.w * im.h * im.c * sizeof(float));
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    //Y' = 0.299 R' + 0.587 G' + .114 B'
    for (int x = 0; x < im.w; ++x) {
        for (int y = 0; y < im.h; ++y) {
            int r_index = get_index(im, x, y, 0);
            int g_index = get_index(im, x, y, 1);
            int b_index = get_index(im, x, y, 2);
            int dest_index = r_index;
            gray.data[dest_index] = 0.299 * im.data[r_index] + 0.587 * im.data[g_index] + 0.114 * im.data[b_index];
        }
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
