#ifndef MOVINGOBJECT_DEF
#define MOVINGOBJECT_DEF

enum DIRECTION {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
};

class MovingObject {
private:
	int px;
	int py;
	int direction;
	int imageHandle;
	int imageWidth;
	int imageHeight;

public :
	MovingObject(int px, int py);
	void Update();
	void Draw();
};

#endif