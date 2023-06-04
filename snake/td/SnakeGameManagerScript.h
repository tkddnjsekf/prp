#pragma once
#include "MuSoeun.h"
#include <vector>
#include <deque>
#include <conio.h>

using namespace MuSoeun;

class SnakeGameManagerScript : public Component {
public:
	int snakeLength = 0;
	int lastkey = 0;
	//snake
	char snake = 'O';
	std::deque<Vector2Int> moveHistory;
	Vector2Int snakePosition;
	int rot;
	//apple
	char apple = 'a';
	char wall = 'x';
	Vector2Int applePosition;
	Text *scoreText;
	Text *gameOverText;
	bool gameover = false;
	SnakeGameManagerScript(Text* scoreText, Text* gameOverText);
	void Render(ScreenBuffer* screenBuffer);
	int frame = 0;
	int gameoverFrame = 0;
	void Update();
};