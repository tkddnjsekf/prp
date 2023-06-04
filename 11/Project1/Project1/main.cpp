#include <iostream>
#include <vector>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD Pos = { (SHORT)(x - 1), (SHORT)(y - 1) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

namespace MuSoeun
{
    class Object;
    class Component;

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

        void InitScreenBuf()
        {
            screenBuf = new char[(width + 1) * height + 1];

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width + 1; j++)
                {
                    if (j == width) {
                        screenBuf[(i * (width + 1)) + j] = '\n';
                        continue;
                    }
                    if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                        screenBuf[(i * (width + 1)) + j] = '*';
                    }
                    else {
                        screenBuf[(i * (width + 1)) + j] = ' ';
                    }
                }
            }
            screenBuf[(width + 1) * height + 1] = '\0';
        }
        void ReleaseScreenBuf()
        {
            if (screenBuf != nullptr)
            {
                delete (screenBuf);
            }
        }

        void DrawScreenBuf()
        {
            gotoxy(0, 0);
            system("cls");
            std::cout << screenBuf;
        }
    };

    class Object
    {
    public:
        std::vector<Component*> components;
        void AddComponent(Component* c);
        virtual void Render(char* screenbuffer) {};
    };

    class Component // Unity MonoBehavior
    {
    public:
        virtual void Start() {};
        virtual void Update() {};
    };

    void Scene::Loop() {
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

    void Scene::AddObject(Object* obj)
    {
        objList.push_back(obj);
        for (Component* com : obj->components)
        {
            com->Start();
        }
    }

    void Object::AddComponent(Component* c)
    {
        components.push_back(c);
    }
}

class SampleO : public MuSoeun::Object
{
public:
    int x;
    int y;

    SampleO() : x(2), y(2) {} // Initialize the player's initial position

    void Render(char* screenbuffer)
    {
        screenbuffer[(y * (30 + 1)) + x] = 'O'; // Update the player's position in the screen buffer
    }
};

class SampleScript : public MuSoeun::Component
{
public:
    void Start()
    {
        //start
    }

    void Update()
    {
        //update
    }
};

int main()
{
    //init
    MuSoeun::Scene mainScene;
    mainScene.width = 30;
    mainScene.height = 10;
    mainScene.InitScreenBuf();
    SampleO* o = new SampleO;
    o->AddComponent((MuSoeun::Component*)new SampleScript());
    mainScene.AddObject((MuSoeun::Object*)o);

    //game loop
    while (1)
    {
        mainScene.Loop();
        mainScene.DrawScreenBuf();
    }

    mainScene.ReleaseScreenBuf();

    return 0;
}sss