#include <DxLib.h>
#include "MovingObject.h"
#include "Board.h"
#include "ImageManager.h"
#include "Keyboard.h"
#include "PieceData.h"

#define KEYINPUT(input) (Keyboard::GetInstance()->GetKeyInput(input))

Board::Board(int xSize, int ySize) {
	// ボードサイズとブランクの位置を初期化
	this->xSize = xSize;
	this->ySize = ySize;
	this->blankX = this->xSize - 1;
	this->blankY = this->ySize - 1;
	this->pieceArray = 0;
	this->replaced = false;

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

void Board::Replace(int x, int y, DIRECTION direction) {
	int piece_id = this->pieceArray[y][x];

	switch (direction) {
	case DIRECTION_UP:
		this->pieceArray[y - 1][x] = piece_id;
		break;
	case DIRECTION_DOWN:
		this->pieceArray[y + 1][x] = piece_id;
		break;
	case DIRECTION_LEFT:
		this->pieceArray[y][x - 1] = piece_id;
		break;
	case DIRECTION_RIGHT:
		this->pieceArray[y][x + 1] = piece_id;
		break;
	}

	this->blankX = x;
	this->blankY = y;
	this->pieceArray[y][x] = PieceData::PIECE_BLANK;

	this->replaced = true;
	this->replaceDirection = direction;
	this->replaceX = x;
	this->replaceY = y;
}

void Board::Update() {
	this->replaced = false;

	// 各スライドキーに従ってピースを置き換える
	// 1フレームに1方向の入力しか受け付けない
	if (KEYINPUT(KEY_INPUT_UP) == 1) {
		if (this->CanReplace(this->blankX, this->blankY - 1)) {
			this->Replace(this->blankX, this->blankY - 1, DIRECTION_DOWN);
		}
	} else if (KEYINPUT(KEY_INPUT_DOWN) == 1) {
		if (this->CanReplace(this->blankX, this->blankY + 1)) {
			this->Replace(this->blankX, this->blankY + 1, DIRECTION_UP);
		}
	} else if (KEYINPUT(KEY_INPUT_LEFT) == 1) {
		if (this->CanReplace(this->blankX - 1, this->blankY)) {
			this->Replace(this->blankX - 1, this->blankY, DIRECTION_RIGHT);
		}
	} else if (KEYINPUT(KEY_INPUT_RIGHT) == 1) {
		if (this->CanReplace(this->blankX + 1, this->blankY)) {
			this->Replace(this->blankX + 1, this->blankY, DIRECTION_LEFT);
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
	if (PieceData::IsBlock(this->pieceArray[y][x])) {
		return false;
	}
	return true;
}

bool Board::CanEnter(int x, int y, DIRECTION current) {
	return PieceData::CanEnter(this->pieceArray[y][x], current);
}

DIRECTION Board::GetChangeDirection(int x, int y, DIRECTION current) {
	return PieceData::GetChangeDirection(this->pieceArray[y][x], current);
}

bool Board::GetReplaceData(int* out_x, int* out_y, DIRECTION* direction) {
	*out_x = this->replaceX;
	*out_y = this->replaceY;
	*direction = this->replaceDirection;
	return this->replaced;
}
