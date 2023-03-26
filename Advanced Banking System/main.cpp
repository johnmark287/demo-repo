#include "main.hpp"

int main(void)
{
	Cur_acct acc_c;
	Sav_acct acc_s;
	Account acc;

	int choice, ch, type = 0, flag = 0;

	while (flag == 0)
	{
		choice = getOption();
		switch (choice)
		{
		case 1:
			system("clear");
			type = getType();
			if (type == 1)
				acc_s.new_s();
			else
				acc_c.new_c();
			break;
		case 2:
			system("clear");
			type = getType();
			if (type == 1)
				acc_s.setDeposit_s();
			else
				acc_c.setDeposit_c();
			break;
		case 3:
			system("clear");
			type = getType();
			if (type == 1)
				acc_s.setWithdraw_s();
			else
				acc_c.setWithdraw_c();
			break;
		case 4:
			system("clear");
			type = getType();
			if (type == 1)
				acc_s.getBalance_s();
			else
				acc_c.getBalance_c();
			break;
		case 5:
			system("clear");
			acc.listCustomers();
			cin.get();
			break;
		case 6:
			system("clear");
			ch = getDelete();
			if (ch == 1)
			{
				type = getType();
				if (type == 1)
					acc_s.delete_s();
				else if (type == 2)
					acc_c.delete_c();
			}
			else
				acc.delete_a();
			break;
		case 7:
			system("clear");
			type = getType();
			if (type == 1)
				acc_s.update_s();
			else
				acc_c.update_c();
			break;
		case 8:
			cout << endl << endl << "Thank you for banking with us!" << endl;
			flag = 1;
		}
	}
	return (0);
}
