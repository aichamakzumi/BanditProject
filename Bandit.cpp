#include "Bandit.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Bandit::Bandit(int initialBalance, int initialBet)
	: drum1(10), drum2(10), drum3(10)
{
	this->balance = (initialBalance > 0 ? initialBalance : 100);
	this->bet = (initialBet > 0 ? initialBet : 10);

	this->InitDrums();
}

void Bandit::InitDrums()
{
	const char symbols[] = { '7', '$', '*', '#', '@', '&', '%' };
	const int totalSymbols = 7;

	this->drum1.Clear();
	this->drum2.Clear();
	this->drum3.Clear();

	for (int i = 0; i < totalSymbols; i++)
	{
		this->drum1.Push(symbols[i]);
		this->drum2.Push(symbols[(i + 2) % totalSymbols]);
		this->drum3.Push(symbols[(i + 4) % totalSymbols]);
	}
}

bool Bandit::CanPlay() const
{
	return this->balance >= this->bet;
}

int Bandit::GetBalance() const
{
	return this->balance;
}

int Bandit::GetBet() const
{
	return this->bet;
}

void Bandit::SetBet(int newBet)
{
	if (newBet > 0)
	{
		this->bet = newBet;
	}
}

void Bandit::AddBalance(int amount)
{
	if (amount > 0)
	{
		this->balance += amount;
	}
}

void Bandit::Spin()
{
	if (!this->CanPlay())
	{
		cout << "Недостатньо монет для ставки! Потрібно: " << this->bet << ", у вас: " << this->balance << endl;
		return;
	}

	this->balance -= this->bet;

	int steps1 = rand() % 21 + 10;
	int steps2 = rand() % 21 + 10;
	int steps3 = rand() % 21 + 10;

	cout << ">> Смикаємо за важіль... Ставка: " << this->bet << " монет." << endl;
	cout << ">> Барабани обертаються за допомогою кільцевої черги..." << endl;

	this->drum1.Rotate(steps1);
	this->drum2.Rotate(steps2);
	this->drum3.Rotate(steps3);

	cout << "   Барабан 1 зробив " << steps1 << " обертів." << endl;
	cout << "   Барабан 2 зробив " << steps2 << " обертів." << endl;
	cout << "   Барабан 3 зробив " << steps3 << " обертів." << endl;

	char s1 = this->drum1.Peek();
	char s2 = this->drum2.Peek();
	char s3 = this->drum3.Peek();

	cout << endl;
	cout << "  +---+---+---+" << endl;
	cout << "  | " << s1 << " | " << s2 << " | " << s3 << " |" << endl;
	cout << "  +---+---+---+" << endl;
	cout << endl;

	int win = 0;

	if (s1 == '7' && s2 == '7' && s3 == '7')
	{
		win = this->bet * 50;
		cout << "*** ДЖЕКПОТ! ТРИ СІМКИ (7 7 7)! ***" << endl;
		cout << "Ви виграли: " << win << " монет!" << endl;
	}
	else if (s1 == '$' && s2 == '$' && s3 == '$')
	{
		win = this->bet * 25;
		cout << "*** ВЕЛИКИЙ КУШ! ТРИ ДОЛАРИ ($ $ $)! ***" << endl;
		cout << "Ви виграли: " << win << " монет!" << endl;
	}
	else if (s1 == s2 && s2 == s3)
	{
		win = this->bet * 15;
		cout << "*** ЧУДОВО! ТРИ В РЯД (" << s1 << " " << s2 << " " << s3 << ")! ***" << endl;
		cout << "Ви виграли: " << win << " монет!" << endl;
	}
	else if (s1 == s2 || s2 == s3 || s1 == s3)
	{
		win = this->bet * 2;
		char match = (s1 == s2 ? s1 : (s2 == s3 ? s2 : s1));
		cout << "** ПЕРЕМОГА! Дві однакові (" << match << ")! **" << endl;
		cout << "Ви виграли: " << win << " монет!" << endl;
	}
	else
	{
		cout << "На жаль, жодної комбінації. Спробуйте ще раз!" << endl;
	}

	this->balance += win;
	cout << "Поточний баланс: " << this->balance << " монет." << endl;
}
