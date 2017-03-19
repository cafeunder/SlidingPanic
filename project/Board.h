#ifndef BOARD_DEF
#define BOARD_DEF

enum DIRECTION;

class Board {
private:
	int blankX;
	int blankY;
	int xSize;
	int ySize;
	int imageWidth;
	int imageHeight;
	int** pieceArray;
	int imageHandle;
	int* imageHandleArray;

	bool CanReplace(int x, int y);

public :
	static const int PIECE_SIZE = 48;
	static const int BOARD_OFFSET_X = 32;
	static const int BOARD_OFFSET_Y = 64;

	Board(int xSize, int ySize);
	~Board();
	void Update();
	void Draw();
	bool CanEnter(int x, int y, DIRECTION current);
	int GetXSize() { return this->xSize; }
	int GetYSize() { return this->ySize; }
	void SetPieceArray(int** pieceArray, int blankX, int blankY);
	DIRECTION GetChangeDirection(int x, int y, DIRECTION current);
};

#endif