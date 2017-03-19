#include <DxLib.h>
#include "Board.h"
#include "ImageManager.h"
#include "MovingObject.h"

MovingObject::MovingObject(int px, int py, Board* board) {
	this->board = board;
	this->px = px;
	this->py = py;
	this->movingCount = 0;
	this->direction = this->board->GetChangeDirection(this->GetBoardX(), this->GetBoardY(), DIRECTION_NONE);
	this->checkedChangeDirection = true;
	this->live = true;

	// 元画像を読み込む
	this->imageHandle = GETIMAGE("mychar");
	int image_width, image_height;
	GetGraphSize(this->imageHandle, &image_width, &image_height);

	// 元画像を分割する
	int image_xnum = image_width / IMAGE_SIZE;
	int image_ynum = image_height / IMAGE_SIZE;
	this->imageHandleArray = new int[image_xnum * image_ynum];
	for (int y = 0; y < image_ynum; y++) {
		for (int x = 0; x < image_xnum; x++) {
			int handle = DerivationGraph(x * IMAGE_SIZE, y * IMAGE_SIZE, IMAGE_SIZE, IMAGE_SIZE, this->imageHandle); 
			this->imageHandleArray[x + y * image_xnum] = handle;
		}
	}
}

void MovingObject::Update() {
	if (!this->live) { return; }

	int bx = this->GetBoardX();
	int by = this->GetBoardY();
	switch(this->direction) {
	case DIRECTION_UP:
		this->py -= MOVE_SPEED / 60.0;
		break;
	case DIRECTION_DOWN:
		this->py += MOVE_SPEED / 60.0;
		break;
	case DIRECTION_LEFT:
		this->px -= MOVE_SPEED / 60.0;
		break;
	case DIRECTION_RIGHT:
		this->px += MOVE_SPEED / 60.0;
		break;
	}

	// 違うピースの上に乗ったなら、侵入可能かどうかを調べる
	if (bx != this->GetBoardX() || by != this->GetBoardY()) {
		if (!this->board->CanEnter(this->GetBoardX(), this->GetBoardY(), this->direction)) {
			this->live = false;
		}
		this->checkedChangeDirection = false;
	}

	// ピースの中盤に初めて差し掛かったら、方向転換するかどうかをチェック
	if (!this->checkedChangeDirection
		&& (this->px >= this->GetBoardX() * Board::PIECE_SIZE + Board::PIECE_SIZE / 2
		&& this->py >= this->GetBoardY() * Board::PIECE_SIZE + Board::PIECE_SIZE / 2)) {
		DIRECTION change_direction = this->board->GetChangeDirection(this->GetBoardX(), this->GetBoardY(), this->direction); 
		if (change_direction != DIRECTION_NONE) {
			this->direction = change_direction;

			// 中盤からはみ出た部分を放置すると少しずつズレていくので、位置を修正する
			if (this->px >= this->GetBoardX() * Board::PIECE_SIZE + Board::PIECE_SIZE / 2) {
				this->px = this->GetBoardX() * Board::PIECE_SIZE + Board::PIECE_SIZE / 2;
			}
			if (this->py >= this->GetBoardY() * Board::PIECE_SIZE + Board::PIECE_SIZE / 2) {
				this->py = this->GetBoardY() * Board::PIECE_SIZE + Board::PIECE_SIZE / 2;
			}
		}
		this->checkedChangeDirection = true;
	}
}

void MovingObject::Draw() {
	float dx = this->px - IMAGE_SIZE / 2 + Board::BOARD_OFFSET_X;
	float dy = this->py - IMAGE_SIZE / 2 + Board::BOARD_OFFSET_Y;

	SetDrawMode( DX_DRAWMODE_BILINEAR );
	int draw_handle = (this->live) ? this->imageHandleArray[0] : this->imageHandleArray[1];
	DrawGraphF(dx, dy, draw_handle, true);
	SetDrawMode( DX_DRAWMODE_NEAREST );

	// DEBUG
	DrawFormatString(0, 0, GetColor(255,255,255), "%d, %d", (int)this->px, (int)this->py);
}

int MovingObject::GetBoardX() {
	return this->px / Board::PIECE_SIZE;
}

int MovingObject::GetBoardY() {
	return this->py / Board::PIECE_SIZE;
}
