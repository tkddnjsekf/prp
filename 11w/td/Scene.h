#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
#include "Object.h"
void gotoxy(short x, short y);

namespace MuSoeun
{
    class Scene
    {
    private:
        std::vector<Object*> objList;
    public:
        int width;
        int height;
        char* screenBuf;
        void AddObject(Object* obj);
        void Loop();
        void InitScreenBuf();
        void ReleaseScreenBuf();
        void ClearScreenBuf();
        void DrawScreenBuf();
    };
}