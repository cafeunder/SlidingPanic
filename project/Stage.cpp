#include <fstream>
#include <sstream>
#include <vector>
#include <DxLib.h>
#include "Stage.h"
#include "Board.h"
#include "MovingObject.h"
#include "Util.h"

Stage::Stage() {
	this->board = new Board(BOARD_XNUM, BOARD_YNUM);
	this->movingObject = 0;
	this->clear = false;
}

void Stage::Update() {
	board->Update();
	movingObject->Update();
	if (this->goalX == this->movingObject->GetBoardX() && this->goalY == this->movingObject->GetBoardY()) {
		this->clear = true;
	}
}

void Stage::Draw() {
	board->Draw();
	movingObject->Draw();

	DrawFormatString(150, 0, GetColor(255,255,255), "%d", this->clear);
}

void Stage::ReadFile(const char* stage_name) {
	char buf[256];
	sprintf(buf, "data\\stage\\%s.txt", stage_name);
	std::ifstream input_stream(buf, std::ios::in);

	std::string line;
	// MovingObject
	if (!this->movingObject) {
		delete this->movingObject;
	}

	// スタート地点の読み込み
	std::getline(input_stream, line);
	std::vector<std::string> record = SeparateString(line, ',');
	int mx = std::stoi(record[0]);
	int my = std::stoi(record[1]);

	// ゴール地点の読み込み
	std::getline(input_stream, line);
	record = SeparateString(line, ',');
	this->goalX = std::stoi(record[0]);
	this->goalY = std::stoi(record[1]);

	// Boardの読み込み
	int xNum = this->board->GetXSize();
	int yNum = this->board->GetYSize();
	int blankX, blankY;
	int** piece_array = new int*[yNum];

	for (int y = 0; y < yNum; y++) {
		piece_array[y] = new int[xNum];
		std::getline(input_stream, line);
		record = SeparateString(line, ',');

		for (int x = 0; x < xNum; x++) {
			piece_array[y][x] = std::stoi(record[x]);
			if (piece_array[y][x] == 0) {
				blankX = x;
				blankY = y;
			}
		}
	}
	this->board->SetPieceArray(piece_array, blankX, blankY);

	this->movingObject = new MovingObject(
		mx * Board::PIECE_SIZE + Board::PIECE_SIZE / 2,
		my * Board::PIECE_SIZE + Board::PIECE_SIZE / 2, this->board
	);
}
