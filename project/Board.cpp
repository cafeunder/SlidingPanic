#include <DxLib.h>
#include "Board.h"
#include "ImageManager.h"
#include "Keyboard.h"

enum PIECE_TYPE {
	PIECE_BLANK,
	PIECE_PLANE,
	PIECE_BLOCK,
	PIECE_LEFT_RIGHT,
	PIECE_UP_DOWN,
	PIECE_LEFT_UP,
	PIECE_RIGHT_UP,
	PIECE_RIGHT_DOWN,
	PIECE_LEFT_DOWN,
	PIECE_UP_BLOCK,
	PIECE_RIGHT_BLOCK,
	PIECE_DOWN_BLOCK,
	PIECE_LEFT_BLOCK,
	PIECE_LEFT_RIGHT_BLOCK,
	PIECE_UP_DOWN_BLOCK
};

#define KEYINPUT(input) (Keyboard::GetInstance()->GetKeyInput(input))

Board::Board(int xSize, int ySize) {
	// ボードサイズとブランクの位置を初期化
	this->xSize = xSize;
	this->ySize = ySize;
	this->blankX = this->xSize - 1;
	this->blankY = this->ySize - 1;
	this->pieceArray = 0;

	// 元画像を読み込む
	this->imageHandle = GETIMAGE("tile");
	int image_width, image_height;
	GetGraphSize(this->imageHandle, &image_width, &image_height);

	// 元画像をピースごとの画像に分割する
	int image_xnum = image_width / PIECE_SIZE;
	int image_ynum = image_height / PIECE_SIZE;
	this->imageHandleArray = new int[image_xnum * image_ynum];
	for (int y = 0; y < image_ynum; y++) {
		for (int x = 0; x < image_xnum; x++) {
			int handle = DerivationGraph(x * PIECE_SIZE, y * PIECE_SIZE, PIECE_SIZE, PIECE_SIZE, this->imageHandle); 
			this->imageHandleArray[x + y * image_xnum] = handle;
		}
	}
}

Board::~Board() {
	delete[] this->pieceArray;
	delete this->imageHandleArray;
}

void Board::SetPieceArray(int** pieceArray, int blankX, int blankY) {
	if (this->pieceArray) {
		delete[] this->pieceArray;
	}

	this->pieceArray = pieceArray;
	this->blankX = blankX;
	this->blankY = blankY;
}

void Board::Update() {
	if (KEYINPUT(KEY_INPUT_UP) == 1) {
		if (this->CanReplace(this->blankX, this->blankY - 1)) {
			this->pieceArray[this->blankY][this->blankX] = this->pieceArray[this->blankY - 1][this->blankX];
			--this->blankY;
			this->pieceArray[this->blankY][this->blankX] = 0;
		}
	}
	if (KEYINPUT(KEY_INPUT_DOWN) == 1) {
		if (this->CanReplace(this->blankX, this->blankY + 1)) {
			this->pieceArray[this->blankY][this->blankX] = this->pieceArray[this->blankY + 1][this->blankX];
			++this->blankY;
			this->pieceArray[this->blankY][this->blankX] = 0;
		}
	}
	if (KEYINPUT(KEY_INPUT_LEFT) == 1) {
		if (this->CanReplace(this->blankX - 1, this->blankY)) {
			this->pieceArray[this->blankY][this->blankX] = this->pieceArray[this->blankY][this->blankX - 1];
			--this->blankX;
			this->pieceArray[this->blankY][this->blankX] = 0;
		}
	}
	if (KEYINPUT(KEY_INPUT_RIGHT) == 1) {
		if (this->CanReplace(this->blankX + 1, this->blankY)) {
			this->pieceArray[this->blankY][this->blankX] = this->pieceArray[this->blankY][this->blankX + 1];
			++this->blankX;
			this->pieceArray[this->blankY][this->blankX] = 0;
		}
	}
}

void Board::Draw() {
	for (int y = 0; y < this->ySize; y++) {
		for (int x = 0; x < this->xSize; x++) {
			int dx = x * PIECE_SIZE + BOARD_OFFSET_X;
			int dy = y * PIECE_SIZE + BOARD_OFFSET_Y;
			DrawGraph(dx, dy, this->imageHandleArray[this->pieceArray[y][x]], true);
		}
	}
}

bool Board::CanReplace(int x, int y) {
	if (x < 0 && x >= this->xSize && y < 0 && y >= this->ySize) {
		return false;
	}
	if (this->IsBlock(this->pieceArray[y][x])) {
		return false;
	}
	return true;
}

bool Board::IsBlock(int piece) {
	return (piece == PIECE_BLOCK ||
		piece == PIECE_UP_BLOCK ||
		piece == PIECE_RIGHT_BLOCK ||
		piece == PIECE_DOWN_BLOCK ||
		piece == PIECE_LEFT_BLOCK ||
		piece == PIECE_UP_BLOCK ||
		piece == PIECE_RIGHT_BLOCK ||
		piece == PIECE_DOWN_BLOCK ||
		piece == PIECE_LEFT_BLOCK ||
		piece == PIECE_LEFT_RIGHT_BLOCK ||
		piece == PIECE_UP_DOWN_BLOCK);
}
