#include "Object.h"

void MuSoeun::Object::AddComponent(Component * c)
{
    components.push_back(c);
}

void MuSoeun::Object::Render(ScreenBuffer* screenbuffer)
{
    for (auto* component : components) {
        component->Render(screenbuffer);
    }
};
