#ifndef _SAV_ACCT_HPP_
#define _SAV_ACCT_HPP_
#include "../main.hpp"
class Sav_acct:private Account
{
	public:
		void new_s(void);
		void setDeposit_s(void);
		void setWithdraw_s(void);
		void getBalance_s(void);
		void delete_s(void);
		void update_s(void);
};

#endif
