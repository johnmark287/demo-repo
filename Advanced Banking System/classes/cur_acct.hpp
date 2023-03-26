#ifndef _CUR_ACCT_HPP_
#define _CUR_ACCT_HPP_
#include "../main.hpp"
class Cur_acct:private Account
{
	public:
		void new_c (void);
		void setDeposit_c(void);
		void setWithdraw_c(void);
		void getBalance_c(void);
		void delete_c(void);
		void update_c(void);

		
};

#endif
