#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
#include "Object.h"
#include "ScreenBuffer.h"
void gotoxy(short x, short y);
namespace MuSoeun
{
    class Scene
    {
    private:
        std::vector<Object*> objList;
    public:
        static int sceneIndex;
        Scene();
        ~Scene();
        static const int width = 120;
        static const int height = 29;
        ScreenBuffer *screenBuf;
        void AddObject(Object* obj);
        void Loop();
        void InitScreenBuf();
        void ReleaseScreenBuf();
        void ClearScreenBuf();
        void DrawScreenBuf();
    };
}