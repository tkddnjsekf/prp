#pragma once
#include <iostream>
#include "Vector2Int.h"

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

namespace MuSoeun {

	class ScreenBuffer {
	public:
		char* rawBuffer = NULL;
		char* rawColorBuffer = NULL;
		int width;
		int height;
		ScreenBuffer(int width, int height);
		~ScreenBuffer();
		void Print();
		void Clear();
		void SetCharactor(char c, Vector2Int position);
		void SetColor(int c, Vector2Int position);
	};
}
