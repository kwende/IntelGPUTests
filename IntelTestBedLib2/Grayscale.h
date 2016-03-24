#pragma once
#include "RGB.h"
#include<gfx/gfx_rt.h>
#include "cilk/cilk.h"

class Grayscale
{
public:
    static void DoIt(rgb* input, rgb* output, int width, int height, bool gpu);
};

