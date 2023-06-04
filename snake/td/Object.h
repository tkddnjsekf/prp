#pragma once
#include <vector>
#include "Component.h"
#include "ScreenBuffer.h"
namespace MuSoeun
{
    class Object
    {
    public:
        bool enable = true; 
        std::vector<Component*> components;
        void AddComponent(Component* c);
        virtual void Render(ScreenBuffer* screenbuffer);
    };
}