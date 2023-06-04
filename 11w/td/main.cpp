#include <iostream>
#include <vector>
#include "MuSoeun.h"

int main()
{
    //init scene
    MuSoeun::Scene mainScene;
    mainScene.width = 10;
    mainScene.height = 10;
    mainScene.InitScreenBuf();

    //game loop
    while (1)
    {
        mainScene.Loop();
        mainScene.DrawScreenBuf();
    }
    mainScene.ReleaseScreenBuf();
    return 0;
}