#include "../main.hpp"

int getType(void)
{
	int type;

	do
	{
		cout << "1. Savings account" << endl;
		cout << "2. Current account" << endl;
		cout << "Choose an account type: ";
		cin >> type;
	}while (type != 1 && type != 2);

	return (type);
}
