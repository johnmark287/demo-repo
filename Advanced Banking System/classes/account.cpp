#include "../main.hpp"

// Account::Account()
// {
// 	balance = 0.00;
// }

Account::Account(string name, string number, string type, double balance, bool chequeBook)
{
	name = name;
	number = number;
	type = type;
	balance = balance = 0.00;
	chequeBook = chequeBook;
}
void Account::listCustomers(void)
{
	int flag;
	fstream file, fl;
	fl.open("data_s.dat", ios::in | ios::out | ios::binary);

	if (fl.is_open())
	{
		fl.seekg(0);
		cout << "<----SAVINGS ACCOUNT MEMBERS----->" << endl << endl;
		if (fl.peek() == EOF)
		{
			cout << "None!" << endl;
		}
		else
		{
			while (fl.read(reinterpret_cast<char *>(this), sizeof(*this)))
			{
				cout << "NAME: " << (*this).name;
				cout << "	ACOUNT NUMBER: " << (*this).number << endl;
			}
		}
		fl.seekp(-sizeof(*this), ios::cur);
		fl.write(reinterpret_cast<char *>(this), sizeof(*this));
		fl.close();
	}
	else
		cout << "Could not open file!\n" << endl;

	cout << endl << "<----CURRENT ACCOUNT MEMBERS----->" << endl << endl;
	file.open("data_c.dat", ios::in | ios::out | ios::binary);

	if (file.is_open())
	{
		file.seekg(0);
		if (file.peek() == EOF)
		{
			cout << "None!" << endl;
		}
		else
		{
			while (file.read(reinterpret_cast<char *>(this), sizeof(*this)))
			{
				cout << "NAME: " << (*this).name;
				cout << "	ACOUNT NUMBER: " << (*this).number << endl;
			}
		}
		file.seekp(-sizeof(*this), ios::cur);
		file.write(reinterpret_cast<char *>(this), sizeof(*this));
		file.close();
	}
	else
		cout << "Could not open file!\n" << endl;

}
void Account::delete_a(void)
{
	int num, flag = 0;
	string nm;
	char ch;
	ifstream file, fl;


	file.open("data_s.dat", ios::in | ios::out | ios::binary);
	fl.open("data_c.dat", ios::in | ios::out | ios::binary);

	if (file.is_open() && fl.is_open())
	{
		flag = 1;
		system("rm data_s.dat");
		system("rm data_c.dat");
		cout << "Successfully deleted the entire database!" << endl;
		if (flag == 0)
			cout << "Operation unsuccessful!" << endl;
	}
	else
		cout << "Could not open file!\n" << endl;
}