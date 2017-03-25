#ifndef MOVINGOBJECT_DEF
#define MOVINGOBJECT_DEF

class Board;
enum DIRECTION {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_NONE
};

class MovingObject {
private:
	static const int IMAGE_SIZE = 32;
	static const int POSITION_SCALE = 100;
	static const int MOVE_SPEED = 30;
	Board* board;
	int px;
	int py;
	DIRECTION direction;
	int movingCount;
	bool checkedChangeDirection;
	bool live;
	int imageHandle;
	int* imageHandleArray;
	int imageWidth;
	int imageHeight;

public :
	MovingObject(int px, int py, Board* board);
	void Update();
	void Draw();
	int GetBoardX();
	int GetBoardY();
	bool JudgePassedCenter();
	int GetCenterPieceX();
	int GetCenterPieceY();
	void Kill();
};

#endif