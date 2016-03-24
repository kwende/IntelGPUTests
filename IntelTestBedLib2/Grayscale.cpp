#include "Grayscale.h"

void Grayscale::DoIt(rgb* input, rgb* output, int width, int height, bool gpu)
{
#pragma offload target(gfx) pin(input,output:length(width*height))
    cilk_for(int c = 0; c < width * height; c++)
    {
        cilk_for(int d = 0; d < 100; d++)
        {
            float temp;
            temp = (0.393f * input[c].red) + (0.769f * input[c].green) + (0.189f * input[c].blue);
            output[c].red = (temp > 255.f) ? 255.f : temp;
            temp = (0.349f * input[c].red) + (0.686f * input[c].green) + (0.168f * input[c].blue);
            output[c].green = (temp > 255.f) ? 255.f : temp;
            temp = (0.272f * input[c].red) + (0.534f * input[c].green) + (0.131f * input[c].blue);
            output[c].blue = (temp > 255.f) ? 255.f : temp;
        }
    }
}
