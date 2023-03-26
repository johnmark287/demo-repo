#include "../main.hpp"

void Cur_acct::new_c(void)
{
	ofstream file("data_c.dat",ios::app | ios::binary);

	cout << "Enter name: ";
	cin >> name;
	cout <<"Enter account number: ";
	cin >> number;
	type = 1;
	chequeBook = false;
	if (!file.is_open())
	{
		cout << "Error in opening the database!" << endl;
		return;
	}
	file.write(reinterpret_cast<char *>(this), sizeof(*this));
	cout << endl << "Successfully added " << (*this).name << " to the system!" << endl;
	file.close();
}

void Cur_acct::setDeposit_c(void)
{	
	double amount;
	int num, flag = 0;
	fstream file;
	file.open("data_c.dat", ios::in | ios::out | ios::binary);

	cout << "Enter the account number: ";
	cin >> num;

	if (file.is_open())
	{
		file.seekg(0);
		while (file.read(reinterpret_cast<char *>(this), sizeof(*this)))
		{
			if ((*this).number == num)
			{
				cout << endl << "Current amount in "<< (*this).name <<"'s account: " << (*this).balance << endl;
				flag = 1;
				cout << "Enter the amount to be deposited: ";
				cin >> amount;
				(*this).balance += amount;
				file.seekp(-sizeof(*this), ios::cur);
				file.write(reinterpret_cast<char *>(this), sizeof(*this));
				cout << "New amount in "<< (*this).name <<"'s account: " << (*this).balance << endl;
				file.close();
				break;
			}
		}
		if (flag == 0)
			cout << "User does not exist!"<< endl;
	}
	else
		cout << "Could not open file!\n" << endl;
}

void Cur_acct::setWithdraw_c(void)
{
	double with;
	int num, flag = 0;
	fstream file;
	file.open("data_c.dat", ios::in | ios::out | ios::binary);

	cout << "Enter the account number: ";
	cin >> num;
	if (file.is_open())
	{
		file.seekg(0);

		while (file.read(reinterpret_cast<char *>(this), sizeof(*this)))
		{
			if ((*this).number == num)
			{
				flag = 1;
				cout << endl << "Current amount in "<< (*this).name <<"'s account: " << (*this).balance << endl;
				cout << "Enter the amount to be withdrawn: ";
				cin >> with;
				if (with > (*this).balance)
					cout << "Invalid withdraw amount!" << endl;
				else
				{
					(*this).balance -= with;
					file.seekp(-sizeof(*this), ios::cur);
					file.write(reinterpret_cast<char *>(this), sizeof(*this));
					cout << "The new balance for " << (*this).name << " is : " << (*this).balance << endl;
					break;
				}
			}
		}
		file.close();
		if (flag == 0)
			cout << "User does not exist!"<< endl;
	}
	else
		cout << "Could not open file!\n" << endl;
}

void Cur_acct::getBalance_c(void)
{
	int num, flag;
	fstream file;
	file.open("data_c.dat", ios::in | ios::out | ios::binary);

	cout << "Enter the account number: ";
	cin >> num;

	if (file.is_open())
	{
		file.seekg(0);
		while (file.read(reinterpret_cast<char *>(this), sizeof(*this)))
		{
			if ((*this).number == num)
			{
				flag = 1;
				cout << "Your account balance for "<< (*this).name << " is: " << (*this).balance << endl;
				break;
			}
		}
		file.close();
		if (flag == 0)
			cout << "User does not exist!"<< endl;
	}
	else
		cout << "Could not open file!\n" << endl;
}

void Cur_acct::delete_c(void)
{
	int num, flag = 0;
	string nm;
	ifstream file;
	ofstream new_file;


	file.open("data_c.dat", ios::in | ios::out | ios::binary);

	cout << "Enter the account number: ";
	cin >> num;

	if (file.is_open())
	{
		file.seekg(0);
		new_file.open("temp_c.dat", ios::binary | ios::app);
		if (new_file.is_open())
		{
			while (file.read(reinterpret_cast<char *>(this), sizeof(*this)))
			{
				if ((*this).number == num)
				{
					nm = (*this).name;
					flag = 1;
				}	
				else
					new_file.write(reinterpret_cast<char *>(this), sizeof(*this));
			}
			
			file.close();
			new_file.close();
			cout << "Successfully deleted " << nm << " from the system!" << endl;
			if (flag == 0)
			{
				cout << "Customer not found!" << endl;
				remove("temp_c.dat");
			}
			else
			{
				remove("data_c.dat");
				rename("temp_c.dat", "data_c.dat");
			}
		}
	}
	else
		cout << "Could not open file!\n" << endl;
}

void Cur_acct::update_c(void)
{
	int num, flag = 0;
	fstream file;


	file.open("data_c.dat", ios::in | ios::out | ios::binary);

	cout << "Enter the account number: ";
	cin >> num;

	if (file.is_open())
	{
		file.seekg(0);
			while (file.read(reinterpret_cast<char *>(this), sizeof(*this)))
			{
				if ((*this).number == num)
				{
					flag = 1;
					cout << "Enter new accout name: ";
					cin >> (*this).name;
					file.seekp(-sizeof(*this), ios::cur);
					file.write(reinterpret_cast<char *>(this), sizeof(*this));
				}
			}
			
			file.close();
			if (flag == 0)
				cout << "Customer not found!" << endl;
		}
	else
		cout << "Could not open file!\n" << endl;
}
