#include <iostream>
using namespace std;

int getDelete(void)
{
	int choice;
	cout << "Do you want to delete A SPECIFIC CUSTOMER(1) or the ENTIRE DATABASE(2)? ";
	cin >> choice;

	return (choice);
}
