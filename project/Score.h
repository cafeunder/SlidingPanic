#ifndef SCORE_DEF
#define SCORE_DEF

class Score {
private:
	int score;
	int stageClearBonus;
	int timeBonus;

public :
	Score();
	int GetScore();
	void AddScore(int score);
	void AddStageClearBonus(int bonus);
	void AddTimeBonus(int bonus);
	int GetTimeBonus();
	int GetStageClearBonus();

	void Draw();
};

#endif SCORE_DEF