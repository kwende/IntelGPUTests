#include "Grayscale.h"

void Grayscale::DoIt(rgb* input, rgb* output, int width, int height, bool gpu)
{
#pragma offload target(gfx) pin(input,output:length(width*height))
    cilk_for(int c = 0; c < width * height; c++)
    {
        char red = input[c].red; 
        char green = input[c].green; 
        char blue = input[c].blue; 

        cilk_for(int d = 0; d < 100; d++)
        {
            float temp;
            temp = (0.393f * red) + (0.769f * green) + (0.189f * blue);
            output[c].red = (temp > 255.f) ? 255.f : temp;
            temp = (0.349f * red) + (0.686f * green) + (0.168f * blue);
            output[c].green = (temp > 255.f) ? 255.f : temp;
            temp = (0.272f * red) + (0.534f * green) + (0.131f * blue);
            output[c].blue = (temp > 255.f) ? 255.f : temp;
        }
    }
}
