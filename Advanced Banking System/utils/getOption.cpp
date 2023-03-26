#include "../main.hpp"

int getOption(void)
{
	int opt = 0;
	cout << endl << endl<< "****WELCOME TO THE CENTRAL BANK OF KENYA****" << endl << endl;
	do
	{
		cout << "1. New Customer          |5. List Customers" << endl;
		cout << "2. Deposit               |6. Delete Customer" << endl;
		cout << "3. Withdraw              |7. Update Customer Details" << endl;
		cout << "4. Check Balance         |8. Exit System" << endl << endl;
		// cout << "5. List Customers" << endl;
		// cout << "6. Delete Customer" << endl;
		// cout << "7. Update Customer Details" << endl;
		// cout << "8. Exit System" << endl << endl;
		cout << "Kindly choose an option from the ones above: ";
		cin >> opt;
	} while (opt <= 0 || opt > 8);
	
	return (opt);
}