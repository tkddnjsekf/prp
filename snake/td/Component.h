#pragma once
#include "ScreenBuffer.h"
namespace MuSoeun
{
    class Component // Unity MonoBehavior
    {
    public:
        virtual void Render(ScreenBuffer* screenbuffer);
        virtual void Start();
        virtual void Update();
    };
}