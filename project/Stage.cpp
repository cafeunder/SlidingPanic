#include <fstream>
#include <sstream>
#include "Stage.h"
#include "Board.h"
#include "MovingObject.h"

Stage::Stage() {
	this->board = new Board(BOARD_XNUM, BOARD_YNUM);
	this->movingObject = 0;
}

void Stage::Update() {
	board->Update();
	movingObject->Update();
}

void Stage::Draw() {
	board->Draw();
	movingObject->Draw();
}

void Stage::ReadFile(const char* stage_name) {
	char buf[256];
	sprintf(buf, "data\\stage\\%s.txt", stage_name);
	std::ifstream input_stream(buf, std::ios::in);

	std::string line;
	std::string record;
	std::getline(input_stream, line);
	const char delimiter =  ',';

	// MovingObject
	if (!this->movingObject) {
		delete this->movingObject;
	}

	std::istringstream separater(line);
	std::getline(separater, record, delimiter);
	int mx = std::stoi(record);
	std::getline(separater, record, delimiter);
	int my = std::stoi(record);

	// Board‚Ì“Ç‚Ýž‚Ý
	int xNum = this->board->GetXSize();
	int yNum = this->board->GetYSize();
	int blankX, blankY;
	int** piece_array = new int*[yNum];

	for (int y = 0; y < yNum; y++) {
		piece_array[y] = new int[xNum];
		std::getline(input_stream, line);

		std::istringstream separater(line);
		for (int x = 0; x < xNum; x++) {
			std::getline(separater, record, delimiter);
			piece_array[y][x] = std::stoi(record);
			if (piece_array[y][x] == 0) {
				blankX = x;
				blankY = y;
			}
		}
	}
	this->board->SetPieceArray(piece_array, blankX, blankY);
	this->movingObject = new MovingObject(mx * PIECE_SIZE + PIECE_SIZE / 2, my * PIECE_SIZE + PIECE_SIZE / 2, this->board);
}
