#ifndef STAGE_DEF
#define STAGE_DEF

#define BOARD_XNUM 12
#define BOARD_YNUM 8
#define STAGE_NUM 3

class Score;
class Board;
class MovingObject;

class Stage {
private:
	Board* board;
	MovingObject* movingObject;
	int stageNum;
	int timelimit;
	int elapsedTime;
	int goalX;
	int goalY;
	bool clear;

public :
	Stage();
	int Update(Score* score);
	void Draw();
	void ReadFile(int stage_index);
	double UseTimeRatio();
};

#endif STAGE_DEF