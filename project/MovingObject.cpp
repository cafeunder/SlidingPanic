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

	this->imageHandle = GETIMAGE("mychar");
	GetGraphSize(this->imageHandle, &this->imageWidth, &this->imageHeight);
}

void MovingObject::Update() {
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

	if (bx != this->GetBoardX() || by != this->GetBoardY()) {
		this->checkedChangeDirection = false;
	}

	// ピースの中盤に初めて差し掛かったら、方向転換するかどうかをチェック
	if (!this->checkedChangeDirection
		&& (this->px >= this->GetBoardX() * PIECE_SIZE + PIECE_SIZE / 2
		&& this->py >= this->GetBoardY() * PIECE_SIZE + PIECE_SIZE / 2)) {
		DIRECTION change_direction = this->board->GetChangeDirection(this->GetBoardX(), this->GetBoardY(), this->direction); 
		if (change_direction != DIRECTION_NONE) {
			this->direction = change_direction;

			// 中盤からはみ出た部分を放置すると少しずつズレていくので、位置を修正する
			if (this->px >= this->GetBoardX() * PIECE_SIZE + PIECE_SIZE / 2) {
				this->px = this->GetBoardX() * PIECE_SIZE + PIECE_SIZE / 2;
			}
			if (this->py >= this->GetBoardY() * PIECE_SIZE + PIECE_SIZE / 2) {
				this->py = this->GetBoardY() * PIECE_SIZE + PIECE_SIZE / 2;
			}
		}
		this->checkedChangeDirection = true;
	}
}

void MovingObject::Draw() {
	float dx = this->px - this->imageWidth / 2 + BOARD_OFFSET_X;
	float dy = this->py - this->imageHeight / 2 + BOARD_OFFSET_Y;
	SetDrawMode( DX_DRAWMODE_BILINEAR );
	DrawGraphF(dx, dy, this->imageHandle, true);
	SetDrawMode( DX_DRAWMODE_NEAREST );

	DrawFormatString(0, 0, GetColor(255,255,255), "%d, %d", (int)this->px, (int)this->py);
}

int MovingObject::GetBoardX() {
	return this->px / PIECE_SIZE;
}

int MovingObject::GetBoardY() {
	return this->py / PIECE_SIZE;
}
