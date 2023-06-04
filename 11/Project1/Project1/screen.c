#include "screen.h"

int clearBuffer(char* screenBuf, int width, int height)
{
	int i = 0;	/* ���� index */
	int j = 0;  /* ���� index */
	while (j < height)
	{
		while (i < width + 1) /* ���๮�ڶ����� + 1*/
		{
			if (i == width)
				screenBuf[i + (j * (width + 1))] = '\n';
			else
			{
				if (i == 0 || i == 1 || i == (width - 1) || i == (width - 2) || j == 0 || j == (height - 1))
					screenBuf[i + (j * (width + 1))] = '*';
				else
					screenBuf[i + (j * (width + 1))] = ' ';
			}
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	screenBuf[height * (width + 1) - 1] = '\0';
}

/* �����ð��� ��� x,y�� ��Ʈ���� ���� �Լ��� ¥�� ��. */
int writeStringToBuffer(const char* string, int x, int y)
{
	int mapWidth = strlen(string);
}

/* Ÿ��Ʋ ȭ�� �׸��� ���۶� ���ӿ���, ���Ӽ��� ��� �̷������� ����� ���� ���ϰ���? */
int setTitleToScreenBuffer(char* screenBuf, int width, int height)
{

}

int setGameOverToScreenBuffer(char* screenBuf, int width, int height)
{

}