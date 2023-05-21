#pragma once
#include <vector>
#include "Component.h"
namespace MuSoeun
{
    class Object
    {
    public:
        std::vector<Component*> components;
        void AddComponent(Component* c);
        virtual void Render(char* screenbuffer) {};
    };
}