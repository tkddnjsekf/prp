#include "Scene.h"

void gotoxy(short x, short y) {
    COORD pos = { x,y }; //x, y 좌표 설정
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서 설정
}

void MuSoeun::Scene::Loop() {
    ClearScreenBuf();
    // draw & run component
    for (Object* obj : objList)
    {
        obj->Render(screenBuf);
        for (Component* com : obj->components)
        {
            com->Update();
        }
    }
}

void MuSoeun::Scene::InitScreenBuf()
{
    screenBuf = new char[width * height];
    ClearScreenBuf();
}

void MuSoeun::Scene::ReleaseScreenBuf()
{
    if (screenBuf != nullptr)
    {
        delete (screenBuf);
    }
}

void MuSoeun::Scene::ClearScreenBuf()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            screenBuf[i*width + j] = ' ';
        }
    }
}

void MuSoeun::Scene::DrawScreenBuf()
{
    gotoxy(0, 0);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << screenBuf[i * width + j];
        }
        std::cout << std::endl;
    }
}

void MuSoeun::Scene::AddObject(Object* obj)
{
    objList.push_back(obj);
    for (Component* com : obj->components)
    {
        com->Start();
    }
}