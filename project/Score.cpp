#include <DxLib.h>
#include "Score.h"

Score::Score() {
	this->score = 0;
	this->stageClearBonus = 0;
	this->timeBonus = 0;
}

int Score::GetScore() {
	return this->score;
}

void Score::AddScore(int score) {
	this->score += score;
}

void Score::AddStageClearBonus(int score) {
	this->stageClearBonus = score;
	this->score += score;
}

void Score::AddTimeBonus(int score) {
	this->timeBonus = score;
	this->score += score;
}

int Score::GetTimeBonus() {
	return this->timeBonus;
}

int Score::GetStageClearBonus() {
	return this->stageClearBonus;
}

void Score::Draw() {
	DrawFormatString(5, 20, GetColor(255,255,255), "score : %d", this->score);
}
