#include "Board.h"
#include <DxLib.h>

Board::Board(int xSize, int ySize) {
	this->xSize = xSize;
	this->ySize = ySize;
	this->blankX = this->xSize - 1;
	this->blankY = this->ySize - 1;

	this->pieceArray = new int*[ySize];
	for (int y = 0; y < this->ySize; y++) {
		this->pieceArray[y] = new int[xSize];
		for (int x = 0; x < this->xSize; x++) {
			this->pieceArray[y][x] = 1;
		}
	}
	this->pieceArray[this->blankY][this->blankX] = 0;
}

Board::~Board() {
	delete[] this->pieceArray;
}

void Board::Update() {
}

void Board::Draw() {
	for (int y = 0; y < this->ySize; y++) {
		for (int x = 0; x < this->xSize; x++) {
			int dx = x * PIECE_SIZE + OFFSET_X;
			int dy = y * PIECE_SIZE + OFFSET_Y;

			if (this->pieceArray[y][x] != 0) {
				DrawBox(dx, dy, dx + PIECE_SIZE, dy + PIECE_SIZE, GetColor(10, 80, 240), true);
				DrawBox(dx, dy, dx + PIECE_SIZE, dy + PIECE_SIZE, GetColor(255, 255, 255), false);
			}
		}
	}
}
