#ifndef STAGE_DEF
#define STAGE_DEF

#define BOARD_XNUM 12
#define BOARD_YNUM 8

class Board;
class MovingObject;

class Stage {
private:
	Board* board;
	MovingObject* movingObject;
	int time;

public :
	Stage();
	void Update();
	void Draw();
	void ReadFile(const char* stage_name);
};

#endif STAGE_DEF