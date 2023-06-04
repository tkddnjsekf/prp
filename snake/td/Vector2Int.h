#pragma once
namespace MuSoeun
{
	class Vector2Int {
	public:
		Vector2Int() {

		}
		Vector2Int(int x, int y) {
			this->x = x;
			this->y = y;
		}
		int x;
		int y;
	};
}