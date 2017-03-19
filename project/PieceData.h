#ifndef PIECE_DEF
#define PIECE_DEF

enum DIRECTION;

class PieceData {
public :
	enum PIECE_PROPERTY_FLAG {
		FLAG_BLOCK = (1),
		FLAG_CAN_ENTER_UP = (1 << 1),
		FLAG_CAN_ENTER_RIGHT = (1 << 2),
		FLAG_CAN_ENTER_DOWN = (1 << 3),
		FLAG_CAN_ENTER_LEFT = (1 << 4),
		FLAG_CHANGE_UP = (1 << 5),
		FLAG_CHANGE_RIGHT = (1 << 6),
		FLAG_CHANGE_DOWN = (1 << 7),
		FLAG_CHANGE_LEFT = (1 << 8),
		FLAG_NONE = (1 << 30)
	};

	enum PIECE_TYPE {
		PIECE_BLANK = 0,
		PIECE_PLANE,
		PIECE_BLOCK,
		PIECE_LEFT_RIGHT,
		PIECE_UP_DOWN,
		PIECE_CROSS,
		PIECE_LEFT_UP,
		PIECE_RIGHT_UP,
		PIECE_RIGHT_DOWN,
		PIECE_LEFT_DOWN,
		PIECE_UP_BLOCK,
		PIECE_RIGHT_BLOCK,
		PIECE_DOWN_BLOCK,
		PIECE_LEFT_BLOCK,
		PIECE_LEFT_RIGHT_BLOCK,
		PIECE_UP_DOWN_BLOCK,
		PIECE_CROSS_BLOCK,
		PIECE_LEFT_UP_BLOCK,
		PIECE_RIGHT_UP_BLOCK,
		PIECE_RIGHT_DOWN_BLOCK,
		PIECE_LEFT_DOWN_BLOCK,
	};

	static bool IsBlock(int piece_id);
	static bool CanEnter(int piece_id, DIRECTION direction);
	static DIRECTION GetChangeDirection(int piece_id, DIRECTION direction);

private:
	static const unsigned int piece_property[];
	static PIECE_PROPERTY_FLAG DirectionToCanEnterFlag(DIRECTION direction);
	static PIECE_PROPERTY_FLAG DirectionToBackwordChangeFlag(DIRECTION direction);
};

#endif