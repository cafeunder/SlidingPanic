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
	static const int MOVE_SPEED = 10;
	Board* board;
	float px;
	float py;
	DIRECTION direction;
	int imageHandle;
	int imageWidth;
	int imageHeight;
	int movingCount;
	bool checkedChangeDirection;

public :
	MovingObject(int px, int py, Board* board);
	void Update();
	void Draw();
	int GetBoardX();
	int GetBoardY();
};

#endif