#include <DxLib.h>
#include <fstream>
#include <sstream>
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
	PIECE_UP,
	PIECE_RIGHT,
	PIECE_DOWN,
};

Board::Board(int xSize, int ySize) {
	// ボードサイズとブランクの位置を初期化
	this->xSize = xSize;
	this->ySize = ySize;
	this->blankX = this->xSize - 1;
	this->blankY = this->ySize - 1;

	// ピース配列を初期化
	this->pieceArray = new int*[ySize];
	for (int y = 0; y < this->ySize; y++) {
		this->pieceArray[y] = new int[xSize];
		for (int x = 0; x < this->xSize; x++) {
			this->pieceArray[y][x] = -1;
		}
	}

	// ファイルを読み込んで配列を初期化
	this->ReadStageFile("test");

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

void Board::ReadStageFile(const char* stage_name) {
	char buf[256];
	sprintf(buf, "data\\stage\\%s.txt", stage_name);
	std::ifstream input_stream(buf, std::ios::in);

	std::string line;
	for (int y = 0; y < this->ySize; y++) {
		std::getline(input_stream, line);

		const char delimiter =  ',';
		std::istringstream separater(line);

		std::string record;
		for (int x = 0; x < this->xSize; x++) {
			std::getline(separater, record, delimiter);
			this->pieceArray[y][x] = std::stoi(record);
			if (this->pieceArray[y][x] == 0) {
				this->blankX = x;
				this->blankY = y;
			}
		}
	}
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
			DrawGraph(dx, dy, this->imageHandleArray[this->pieceArray[y][x]], true);
		}
	}
}
