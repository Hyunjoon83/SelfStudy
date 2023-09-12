#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::ShowMenu(void) const{
	cout<<"-----Menu------"<<endl;
	cout<<"1. Make Account"<<endl;
	cout<<"2. Deposit"<<endl;
	cout<<"3. Withdraw"<<endl;
	cout<<"4. Print all account information"<<endl;
	cout<<"5. End program"<<endl;
}

void AccountHandler::MakeAccount(void){
	int sel;
	cout<<"[Choose Account Type]"<<endl;
	cout<<"1.Normal Account ";
	cout<<"2.High Credit Account "<<endl;
	cout<<"Choice: ";
	cin>>sel;
	
	if(sel==NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void){
	int id;
	String name;
	int balance;
	int interRate;

	cout<<"[Make Normal Account]"<<endl;
	cout<<"Account ID: ";	cin>>id;
	cout<<"Name: ";	cin>>name;
	cout<<"Deposit: ";	cin>>balance;
	cout<<"Interest Rate: ";	cin>>interRate;
	cout<<endl;

	accArr[accNum++]=new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void){
	int id;
	String name;
	int balance;
	int interRate;
	int creditLevel;

	cout<<"[Make High Credit Account]"<<endl;
	cout<<"Account ID: ";	cin>>id;
	cout<<"Name: ";	cin>>name;
	cout<<"Balance: ";	cin>>balance;
	cout<<"Interest Rate: ";	cin>>interRate;
	cout<<"Credit Rate(1toA, 2toB, 3toC): ";	cin>>creditLevel;
	cout<<endl;

	switch(creditLevel){
	case 1:
		accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
	}
}

void AccountHandler::DepositMoney(void){
	int money;
	int id;
	cout<<"[Deposit]"<<endl;
	cout<<"Account ID: ";	cin>>id;

	while(true){
		cout<<"Deposit: ";	cin>>money;
	
		try{
			for(int i=0; i<accNum; i++){
				if(accArr[i]->GetAccID()==id){
					accArr[i]->Deposit(money);
					cout<<"Deposit completed"<<endl<<endl;
					return;
				}
			}
			cout<<"Invalid Account ID."<<endl<<endl;
			return;
		}
		catch(MinusException& expt){
			expt.ShowExceptionInfo();
			cout<<"Rewrite Deposit money only."<<endl;
		}
	}
}

void AccountHandler::WithdrawMoney(void){
	int money;
	int id;
	cout<<"[Withdraw]"<<endl;
	cout<<"Account ID: ";	cin>>id;

	while(true){
		cout<<"Withdraw: ";	cin>>money;
		
		try{
			for(int i=0; i<accNum; i++){
				if(accArr[i]->GetAccID()==id){
					accArr[i]->Withdraw(money);
					cout<<"Withdraw completed"<<endl<<endl;
					return;
				}
			}
			cout<<"Invalid Account ID."<<endl<<endl;
			return;
		}
		catch(MinusException& expt){
			expt.ShowExceptionInfo();
			cout<<"Rewrite deposit money only."<<endl;
		}
		catch(InsuffException& expt){
			expt.ShowExceptionInfo();
			cout<<"Rewrite withdraw money only."<<endl;
		}
	}
}

AccountHandler::AccountHandler() : accNum(0){}

void AccountHandler::ShowAllAccInfo(void) const{
	for(int i=0; i<accNum; i++){
		accArr[i]->ShowAccInfo();
		cout<<endl;
	}
}

AccountHandler::~AccountHandler(){
	for(int i=0; i<accNum; i++)
		delete accArr[i];
}