#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Bandit.h"

using namespace std;

int main()
{
	system("chcp 65001 > nul");
	srand(static_cast<unsigned int>(time(nullptr)));

	cout << "=================================================" << endl;
	cout << "        ГРА \"ОДНОРУКИЙ БАНДИТ\" (SLOT MACHINE)    " << endl;
	cout << "=================================================" << endl;
	cout << "Правила гри:" << endl;
	cout << " - Початковий баланс: 100 монет." << endl;
	cout << " - Ставка за один спін: 10 монет." << endl;
	cout << " - Для обертання барабанів використовується кільцева черга!" << endl;
	cout << " - Таблиця виплат:" << endl;
	cout << "     [ 7 | 7 | 7 ] -> Джекпот! (ставка x 50 = 500 монет)" << endl;
	cout << "     [ $ | $ | $ ] -> Великий куш! (ставка x 25 = 250 монет)" << endl;
	cout << "     [ X | X | X ] -> Три однакові (ставка x 15 = 150 монет)" << endl;
	cout << "     [ X | X | * ] -> Дві однакові (ставка x 2  = 20 монет)" << endl;
	cout << "=================================================" << endl << endl;

	Bandit game(100, 10);

	while (game.CanPlay())
	{
		cout << "Ваш баланс: " << game.GetBalance() << " монет. Ставка: " << game.GetBet() << " монет." << endl;
		cout << "Натисніть [Enter], щоб смикнути важіль (або введіть 'q' для виходу): ";

		string input;
		if (!getline(cin, input) || input == "q" || input == "Q")
		{
			cout << endl << "Ви вирішили завершити гру. Ваш виграш/баланс: " << game.GetBalance() << " монет." << endl;
			break;
		}

		cout << endl;
		game.Spin();
		cout << "-------------------------------------------------" << endl << endl;
	}

	if (!game.CanPlay())
	{
		cout << "У вас закінчилися монети на балансі! Гра завершена." << endl;
	}

	cout << "Дякуємо за гру!" << endl << endl;

	system("pause");
	return 0;
}
