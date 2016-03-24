// IntelTestBed2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <fstream>

#include "RGB.h"
#include "Grayscale.h"

int main()
{
    int width = 512;
    int height = 424; 

    rgb* originalImage = (rgb*)_aligned_malloc(sizeof(rgb) * width * height, 1024);
    rgb* modifiedImage = (rgb*)_aligned_malloc(sizeof(rgb) * width * height, 1024);

    DWORD dwStart = ::GetTickCount();

    Grayscale::DoIt(originalImage, modifiedImage, width, height, true);

    std::cout << (::GetTickCount() - dwStart) << std::endl;

    return 0;
}

