#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountHandler.h"
#include "AccountHandler.cpp"
#include "String.h"
#include "String.cpp"
#include "AccountException.h"
#include "BoundCheckArray.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

int main(void)
{
	AccountHandler manager;
	int choice;
	
	while(1)
	{
		manager.ShowMenu();
		cout<<"Choice: "; 
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
		case MAKE:
			manager.MakeAccount(); 
			break;
		case DEPOSIT:
			manager.DepositMoney(); 
			break;
		case WITHDRAW: 
			manager.WithdrawMoney(); 
			break;
		case INQUIRE:
			manager.ShowAllAccInfo(); 
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}
	return 0;
}