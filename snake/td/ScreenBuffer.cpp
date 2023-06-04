#include "ScreenBuffer.h"
using namespace MuSoeun;
ScreenBuffer::ScreenBuffer(int width, int height){
	rawBuffer = new char[width * height];
	rawColorBuffer = new char[width * height];
	this->width = width;
	this->height = height;
}
ScreenBuffer::~ScreenBuffer()
{
	delete[] rawBuffer;
}
void ScreenBuffer::Clear(){
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			rawBuffer[i * width + j] = ' ';
			rawColorBuffer[i * width + j] = 0;
		}
	}
}
void ScreenBuffer::Print() {
	std::string output = "";
	int nowColor = -1;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (rawColorBuffer[i * width + j] != nowColor) {
				nowColor = rawColorBuffer[i * width + j];
				switch (nowColor) {
				case 0:	output += ANSI_COLOR_RESET; break;
					case 1:	output += ANSI_COLOR_GREEN; break;
					case 2:	output +=ANSI_COLOR_YELLOW; break;
					case 3:	output +=ANSI_COLOR_BLUE; break;
					case 4:	output +=ANSI_COLOR_MAGENTA; break;
					case 5:	output +=ANSI_COLOR_CYAN; break;
					case 6:	output += ANSI_COLOR_RED; break;

				}
			}
			output += rawBuffer[i * width + j];
		}
		output += "\n";
	}
	std::cout << output;
}

void ScreenBuffer::SetCharactor(char c, Vector2Int position) {
	int index = position.x + position.y * width;
	if (index < 0 || index > width * height - 1) {
		//outer screen
	}
	else {
		rawBuffer[index] = c;
	}
}

void ScreenBuffer::SetColor(int c, Vector2Int position) {
	int index = position.x + position.y * width;
	if (index < 0 || index > width * height - 1) {
		//outer screen
	}
	else {
		rawColorBuffer[index] = c;
	}
}