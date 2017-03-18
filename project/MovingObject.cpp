#include <DxLib.h>
#include "Board.h"
#include "ImageManager.h"
#include "MovingObject.h"

MovingObject::MovingObject(int px, int py) {
	this->px = px;
	this->py = py;

	this->direction = DIRECTION_DOWN;
	this->imageHandle = GETIMAGE("mychar");
	GetGraphSize(this->imageHandle, &this->imageWidth, &this->imageHeight);
}

void MovingObject::Update() {
	switch(this->direction) {
	case DIRECTION_UP:
		this->py--;
		break;
	case DIRECTION_DOWN:
		this->py++;
		break;
	case DIRECTION_LEFT:
		this->px--;
		break;
	case DIRECTION_RIGHT:
		this->px++;
		break;
	}
}

void MovingObject::Draw() {
	int dx = this->px - this->imageWidth / 2 + BOARD_OFFSET_X;
	int dy = this->py - this->imageHeight / 2 + BOARD_OFFSET_Y;
	DrawGraph(dx, dy, this->imageHandle, true);
}
