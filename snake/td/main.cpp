#include <iostream>
#include <vector>
#include <conio.h>
#include "MuSoeun.h"

#include "AnyKeyToGameScene.h"
#include "SnakeGameManagerScript.h"

using namespace MuSoeun;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    //init 
    Scene* nowScene = NULL;
    Scene::sceneIndex = 0;


    //game loop
    while (MuSoeun::Scene::sceneIndex != -1)
    {
        int befIndex = MuSoeun::Scene::sceneIndex;
        if (nowScene != NULL) {
            Sleep(10);
            nowScene->Loop();
        }
        else {
            befIndex = -1;
        }
        if (befIndex != MuSoeun::Scene::sceneIndex) {
            delete nowScene;
            nowScene = NULL;
            //new load
            switch (MuSoeun::Scene::sceneIndex) {
            case 0:
                {//mainscene
                    Scene* mainScene = new Scene();
                    mainScene->AddObject(new MuSoeun::Text("snake", Vector2Int(56, 4), Center));
                    auto gamestartText = new MuSoeun::Text("아무키나 눌러 게임시작", Vector2Int(56, 14), Center);
                    gamestartText->AddComponent(new AnyKeyToGameScene());
                    mainScene->AddObject(gamestartText);
                    auto gameinfoText = new MuSoeun::Text("게임방법", Vector2Int(56, 16), Center);
                    mainScene->AddObject(gameinfoText);
                    auto gameinfoDetailText = new MuSoeun::Text("화살표 키를 이용하여 방향을 바꾼어 사과를 먹는다.\n점점늘어나는 몸과 벽을 주의하며 성장한다.", Vector2Int(56, 17), Center);
                    mainScene->AddObject(gameinfoDetailText);
                    nowScene = mainScene;
                }
                break;
            case 1:
                {//ingame scene
                    Scene* gameScene = new Scene();
                    //gamescene 1
                    auto gameScore = new MuSoeun::Text("", Vector2Int(56, 0), Center);
                    auto gameoverText = new MuSoeun::Text("게임오버.. 잠시 후 메인으로 돌아갑니다.", Vector2Int(56, 17), Center);
                    auto gameManager = new SnakeGameManagerScript(gameScore, gameoverText);
                    gameScore->AddComponent(gameManager);
                    gameScene->AddObject(gameScore);
                    gameScene->AddObject(gameoverText);
                    nowScene = gameScene;
                }
                break;
            }
        }
    }
    return 0;
}