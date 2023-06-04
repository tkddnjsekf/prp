#include "Scene.h"

int MuSoeun::Scene::sceneIndex = 0;

void gotoxy(short x, short y) {
    COORD pos = { x,y }; //x, y ��ǥ ����
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ŀ�� ����
}

void MuSoeun::Scene::Loop() {
    ClearScreenBuf();
    // draw & run component
    for (Object* obj : objList)
    {
        if (obj->enable) {
            obj->Render(screenBuf);
            for (Component* com : obj->components)
            {
                com->Update();
            }
        }
    }
    DrawScreenBuf();
}

void MuSoeun::Scene::InitScreenBuf()
{
    screenBuf = new ScreenBuffer(width, height);
    ClearScreenBuf();
}

void MuSoeun::Scene::ReleaseScreenBuf()
{
    delete screenBuf;
}

void MuSoeun::Scene::ClearScreenBuf()
{
    screenBuf->Clear();
}

void MuSoeun::Scene::DrawScreenBuf()
{
    gotoxy(0, 0);
    screenBuf->Print();
}

MuSoeun::Scene::Scene() {
    InitScreenBuf();
}

MuSoeun::Scene::~Scene()
{
    ReleaseScreenBuf();
}

void MuSoeun::Scene::AddObject(Object* obj)
{
    objList.push_back(obj);
    for (Component* com : obj->components)
    {
        com->Start();
    }
}