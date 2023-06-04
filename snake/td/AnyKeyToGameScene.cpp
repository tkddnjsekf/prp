#include "AnyKeyToGameScene.h"

void AnyKeyToGameScene::Update()
{
    if (_kbhit())
    {
        int key = _getch();
        MuSoeun::Scene::sceneIndex = 1;
    }
}
