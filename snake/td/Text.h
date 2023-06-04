#pragma once
#include <vector>
#include <string>
#include "Object.h"
#include "Vector2Int.h"
namespace MuSoeun
{
    enum TextAlign {
        Left, Center
    };
    class Text: public Object
    {
    public:
        std::string text;
        Vector2Int position;
        TextAlign textAlign;
        Text(std::string text, Vector2Int position, TextAlign textAlign = TextAlign::Left) {
            this->text = text;
            this->position = position;
            this->textAlign = textAlign;
        }

        std::vector<std::string> split(const std::string& str, const std::string& delim)
        {
            std::vector<std::string> tokens;
            size_t prev = 0, pos = 0;
            do
            {
                pos = str.find(delim, prev);
                if (pos == std::string::npos) pos = str.length();
                std::string token = str.substr(prev, pos - prev);
                if (!token.empty()) tokens.push_back(token);
                prev = pos + delim.length();
            } while (pos < str.length() && prev < str.length());
            return tokens;
        }

        void Render(ScreenBuffer *screenbuffer) override {
            Object::Render(screenbuffer);
            int i = 0;
            int j = 0;
            
            for (std::string line : split(text, "\n")) {
                int centerDelta = 0;
                if (textAlign == Center) {
                    centerDelta = line.length() / 2;
                }
                i = 0;
                for (char c : line) {
                    screenbuffer->SetCharactor(c, Vector2Int(position.x + i - centerDelta, position.y + j));
                    i++;
                }
                j++;
            }
        };
    };
}