#define WIN32_LEAN_AND_MEAN

#include "window.h"
#include "nk_gui.h"
#include "filehandling.h"


int main(void)
{
	WINDOW_DATA windowData;
	FILE_DATA fileData;
    unsigned int initialWindowWidth=420; // blaze it
    unsigned int initialWindowHeight=640;
    SetupWindow(windowData,initialWindowWidth,initialWindowHeight,L"YGO LOTD LE Character Data Editor v0.2");

    SetupGui(windowData,initialWindowWidth,initialWindowHeight);

    while (windowData.running)
    {
        HandleInput(windowData);

        HandleGui(fileData);

        RenderGui();
    }

    CleanupGui();
    CleanupWindow(windowData);
    return 0;
}

