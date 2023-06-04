#include "SnakeGameManagerScript.h"

SnakeGameManagerScript::SnakeGameManagerScript(Text* scoreText, Text* gameOverText)
{
	this->scoreText = scoreText;
	this->gameOverText = gameOverText;
	snakeLength = 5;//ÃÊ±â ±æÀÌ 3
	//¹ìÀº O »ç°ú´Â a
	gameOverText->enable = false;
	snakePosition.x = Scene::width / 2;
	snakePosition.y = Scene::height / 2;
	rot = 0;
	srand(time(NULL));
	applePosition.x = 1+rand() % (Scene::width-2);
	applePosition.y = 1+rand() % (Scene::height-2);
	gameover = false;
}

void SnakeGameManagerScript::Render(ScreenBuffer* screenBuffer)
{
	//render snake
	screenBuffer->SetCharactor(snake, snakePosition);
	screenBuffer->SetCharactor(apple, applePosition);
	//¹ì ¸öÅë ·»´õ
	for (int i = 0; i < moveHistory.size(); i++) {
		//¹ì ¸ö Ãæµ¹
		int index = moveHistory.size() - 1 - i;
		if (index < 0) {
			break;
		}
		//º®
		for (int i = 0; i < Scene::width; i++) {
			screenBuffer->SetCharactor(wall, Vector2Int(i, 0));
			screenBuffer->SetCharactor(wall, Vector2Int(i, Scene::height-1));
		}
		for (int i = 0; i < Scene::height; i++) {
			screenBuffer->SetCharactor(wall, Vector2Int(0, i));
			screenBuffer->SetCharactor(wall, Vector2Int(Scene::width-1, i));
		}
		if (i < snakeLength) {
			screenBuffer->SetCharactor(snake, moveHistory[index]);
			screenBuffer->SetColor(snakeLength % 7, moveHistory[index]);
		}
		else {
			//ÀÜ»ó
			screenBuffer->SetCharactor('.', moveHistory[index]);
		}
	}
}

void SnakeGameManagerScript::Update()
{
	if (gameover) {
		if (_kbhit())
		{
			_getch();
		}
		gameOverText->enable = true;
		//¾Æ¹«Å°³ª ´©¸£¸é µ¹¾Æ°¨
		gameoverFrame += 1;
		if (gameoverFrame >= 30) {
			MuSoeun::Scene::sceneIndex = 0;
		}
	}
	else {
		if (_kbhit())
		{
			int key = _getch();
			//72 77 80 75 À§ ¿ì ÇÏ ÁÂ
			switch (key) {
			case 72:
				rot = 0;
				break;
			case 77:
				rot = 1;
				break;
			case 80:
				rot = 2;
				break;
			case 75:
				rot = 3;
				break;
			}
		}
		frame += 1;
		int d = 6;
		if (frame % d == 0) {
			moveHistory.push_back(snakePosition);
			switch (rot) {
			case 0:
				snakePosition.y -= 1;
				break;
			case 1:
				snakePosition.x += 1;
				break;
			case 2:
				snakePosition.y += 1;
				break;
			case 3:
				snakePosition.x -= 1;
				break;
			}
			while (moveHistory.size()> snakeLength+5) {
				moveHistory.pop_front();
			}

			//Ãæµ¹°¨Áö
			if (snakePosition.x < 1 || snakePosition.x >= Scene::width-1 || snakePosition.y <1 || snakePosition.y >= Scene::height-1) {
				gameover = true;
			}
			if (snakePosition.x == applePosition.x && snakePosition.y == applePosition.y) {
				//getapple
				snakeLength += 1;
				applePosition.x = 1 + rand() % (Scene::width - 2);
				applePosition.y = 1 + rand() % (Scene::height - 2);
			}
			for (int i = 0; i < snakeLength; i++) {
				//¹ì ¸ö Ãæµ¹
				int index = moveHistory.size() - 1 - i;
				if (index < 0) {
					break;
				}
				if (snakePosition.x == moveHistory[index].x && snakePosition.y == moveHistory[index].y) {
					gameover = true;
				}
			}
			scoreText->text = "Á¡¼ö: " + std::to_string(snakeLength);
		}
	}
}
