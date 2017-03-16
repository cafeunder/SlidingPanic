#ifndef BOARD_DEF
#define BOARD_DEF

#define OFFSET_X 32
#define OFFSET_Y 64
#define PIECE_SIZE 48

class Board {
private:
	int blankX;
	int blankY;
	int xSize;
	int ySize;
	int** pieceArray;

public :
	Board(int xSize, int ySize);
	~Board();
	void Update();
	void Draw();
};

#endif