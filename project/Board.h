#ifndef BOARD_DEF
#define BOARD_DEF

#define BOARD_OFFSET_X 32
#define BOARD_OFFSET_Y 64
#define PIECE_SIZE 48

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

public :
	Board(int xSize, int ySize);
	~Board();
	void Update();
	void Draw();
	bool CanReplace(int x, int y);
	bool IsBlock(int piece);
	int GetXSize() { return this->xSize; }
	int GetYSize() { return this->ySize; }
	void SetPieceArray(int** pieceArray, int blankX, int blankY);
};

#endif