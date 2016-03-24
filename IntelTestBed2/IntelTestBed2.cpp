// IntelTestBed2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<gfx/gfx_rt.h>
#include "cilk/cilk.h"

struct rgb
{
    unsigned char red;
    unsigned char green; 
    unsigned char blue; 
};

int main()
{
    rgb* originalImage = new rgb[320 * 240]; 
    rgb* modifiedImage = new rgb[320 * 240]; 

#pragma offload target(gfx) pin(originalImage,modifiedImage:length(320*240*sizeof(rgb)))
    cilk_for(int c = 0; c < 320 * 240; c++)
    {
        float temp;
        temp = (0.393f * originalImage[c].red) + (0.769f * originalImage[c].green) + (0.189f * originalImage[c].blue);
        modifiedImage[c].red = (temp > 255.f) ? 255.f : temp;
        temp = (0.349f * originalImage[c].red) + (0.686f * originalImage[c].green) + (0.168f * originalImage[c].blue);
        modifiedImage[c].green = (temp > 255.f) ? 255.f : temp;
        temp = (0.272f * originalImage[c].red) + (0.534f * originalImage[c].green) + (0.131f * originalImage[c].blue);
        modifiedImage[c].blue = (temp > 255.f) ? 255.f : temp;
    }

    return 0;
}

