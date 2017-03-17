#include <DxLib.h>
#include "Board.h"
#include "Keyboard.h"

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
	if (KEYINPUT(KEY_INPUT_UP) == 1) {
		if (this->blankY > 0) {
			this->pieceArray[this->blankY][this->blankX] = this->pieceArray[this->blankY - 1][this->blankX];
			--this->blankY;
			this->pieceArray[this->blankY][this->blankX] = 0;
		}
	}
	if (KEYINPUT(KEY_INPUT_DOWN) == 1) {
		if (this->blankY < this->ySize - 1) {
			this->pieceArray[this->blankY][this->blankX] = this->pieceArray[this->blankY + 1][this->blankX];
			++this->blankY;
			this->pieceArray[this->blankY][this->blankX] = 0;
		}
	}
	if (KEYINPUT(KEY_INPUT_LEFT) == 1) {
		if (this->blankX > 0) {
			this->pieceArray[this->blankY][this->blankX] = this->pieceArray[this->blankY][this->blankX - 1];
			--this->blankX;
			this->pieceArray[this->blankY][this->blankX] = 0;
		}
	}
	if (KEYINPUT(KEY_INPUT_RIGHT) == 1) {
		if (this->blankX < this->xSize - 1) {
			this->pieceArray[this->blankY][this->blankX] = this->pieceArray[this->blankY][this->blankX + 1];
			++this->blankX;
			this->pieceArray[this->blankY][this->blankX] = 0;
		}
	}
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
