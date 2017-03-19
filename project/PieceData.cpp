#include "PieceData.h"
#include "MovingObject.h"

const unsigned int PieceData::piece_property[] = {
	0, // PIECE_BLANK
	0, // PIECE_PLANE
	FLAG_BLOCK, // PIECE_BLOCK
	FLAG_CAN_ENTER_LEFT | FLAG_CAN_ENTER_RIGHT, // PIECE_LEFT_RIGHT
	FLAG_CAN_ENTER_UP | FLAG_CAN_ENTER_DOWN, // PIECE_UP_DOWN
	FLAG_CAN_ENTER_LEFT | FLAG_CAN_ENTER_RIGHT | FLAG_CAN_ENTER_UP | FLAG_CAN_ENTER_DOWN, // PIECE_CROSS
	FLAG_CAN_ENTER_LEFT | FLAG_CAN_ENTER_UP | FLAG_CHANGE_LEFT | FLAG_CHANGE_UP, // PIECE_LEFT_UP
	FLAG_CAN_ENTER_RIGHT | FLAG_CAN_ENTER_UP | FLAG_CHANGE_RIGHT | FLAG_CHANGE_UP, // PIECE_RIGHT_UP
	FLAG_CAN_ENTER_RIGHT | FLAG_CAN_ENTER_DOWN | FLAG_CHANGE_RIGHT | FLAG_CHANGE_DOWN, // PIECE_RIGHT_DOWN
	FLAG_CAN_ENTER_LEFT | FLAG_CAN_ENTER_DOWN | FLAG_CHANGE_LEFT | FLAG_CHANGE_DOWN, // PIECE_LEFT_DOWN
	FLAG_CHANGE_UP | FLAG_BLOCK, // PIECE_UP_BLOCK
	FLAG_CHANGE_RIGHT | FLAG_BLOCK, // PIECE_RIGHT_BLOCK
	FLAG_CHANGE_DOWN | FLAG_BLOCK, // PIECE_DOWN_BLOCK
	FLAG_CHANGE_LEFT | FLAG_BLOCK, // PIECE_LEFT_BLOCK
	FLAG_CAN_ENTER_LEFT | FLAG_CAN_ENTER_RIGHT | FLAG_BLOCK, // PIECE_LEFT_RIGHT_BLOCK
	FLAG_CAN_ENTER_UP | FLAG_CAN_ENTER_DOWN | FLAG_BLOCK, // PIECE_UP_DOWN_BLOCK
	FLAG_CAN_ENTER_LEFT | FLAG_CAN_ENTER_RIGHT | FLAG_CAN_ENTER_UP | FLAG_CAN_ENTER_DOWN | FLAG_BLOCK,// PIECE_CROSS_BLOCK
	FLAG_CAN_ENTER_LEFT | FLAG_CAN_ENTER_UP | FLAG_CHANGE_LEFT | FLAG_CHANGE_UP | FLAG_BLOCK, // PIECE_LEFT_UP_BLOCK
	FLAG_CAN_ENTER_RIGHT | FLAG_CAN_ENTER_UP | FLAG_CHANGE_RIGHT | FLAG_CHANGE_UP | FLAG_BLOCK, // PIECE_RIGHT_UP_BLOCK
	FLAG_CAN_ENTER_RIGHT | FLAG_CAN_ENTER_DOWN | FLAG_CHANGE_RIGHT | FLAG_CHANGE_DOWN | FLAG_BLOCK, // PIECE_RIGHT_DOWN_BLOCK
	FLAG_CAN_ENTER_LEFT | FLAG_CAN_ENTER_DOWN | FLAG_CHANGE_LEFT | FLAG_CHANGE_DOWN | FLAG_BLOCK // PIECE_LEFT_DOWN_BLOCK
};

bool PieceData::IsBlock(int piece_id) {
	return (PieceData::piece_property[piece_id] & PieceData::FLAG_BLOCK) != 0;
}

bool PieceData::CanEnter(int piece_id, DIRECTION direction) {
	PieceData::PIECE_PROPERTY_FLAG flag = PieceData::DirectionToCanEnterFlag(direction);
	if (flag == PieceData::FLAG_NONE) {
		return false;
	}

	return (PieceData::piece_property[piece_id] & flag) != 0;
}

DIRECTION PieceData::GetChangeDirection(int piece_id, DIRECTION direction) {
	PieceData::PIECE_PROPERTY_FLAG backword_flag = PieceData::DirectionToBackwordChangeFlag(direction);
	unsigned int change_flag = PieceData::piece_property[piece_id];
	if (backword_flag != PieceData::FLAG_NONE) {
		// 逆方向に方向転換してはいけないので、逆方向への転換フラグをオフにする
		change_flag &= ~backword_flag;
	}

	// 立っているフラグに対応した方向を返す
	if ((change_flag & PieceData::FLAG_CHANGE_UP) != 0) {
		return DIRECTION_UP;
	}
	if ((change_flag & PieceData::FLAG_CHANGE_RIGHT) != 0) {
		return DIRECTION_RIGHT;
	}
	if ((change_flag & PieceData::FLAG_CHANGE_DOWN) != 0) {
		return DIRECTION_DOWN;
	}
	if ((change_flag & PieceData::FLAG_CHANGE_LEFT) != 0) {
		return DIRECTION_LEFT;
	}
	return DIRECTION_NONE;
}

PieceData::PIECE_PROPERTY_FLAG PieceData::DirectionToCanEnterFlag(DIRECTION direction) {
	switch(direction) {
	case DIRECTION_UP:
		return PieceData::FLAG_CAN_ENTER_UP;
	case DIRECTION_RIGHT:
		return PieceData::FLAG_CAN_ENTER_RIGHT;
	case DIRECTION_DOWN:
		return PieceData::FLAG_CAN_ENTER_DOWN;
	case DIRECTION_LEFT:
		return PieceData::FLAG_CAN_ENTER_LEFT;
	}
	return PieceData::FLAG_NONE;
}

// 進入方向とは逆方向のChangeFlagを返す
PieceData::PIECE_PROPERTY_FLAG PieceData::DirectionToBackwordChangeFlag(DIRECTION direction) {
	switch(direction) {
	case DIRECTION_UP:
		return PieceData::FLAG_CHANGE_DOWN;
	case DIRECTION_RIGHT:
		return PieceData::FLAG_CHANGE_LEFT;
	case DIRECTION_DOWN:
		return PieceData::FLAG_CHANGE_UP;
	case DIRECTION_LEFT:
		return PieceData::FLAG_CHANGE_RIGHT;
	}
	return PieceData::FLAG_NONE;
}
