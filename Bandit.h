#pragma once
#include "CircularQueue.h"

class Bandit
{
private:
	CircularQueue drum1;
	CircularQueue drum2;
	CircularQueue drum3;
	int balance;
	int bet;

	void InitDrums();

public:
	Bandit(int initialBalance = 100, int initialBet = 10);

	void Spin();
	bool CanPlay() const;

	int GetBalance() const;
	int GetBet() const;
	void SetBet(int newBet);
	void AddBalance(int amount);
};
