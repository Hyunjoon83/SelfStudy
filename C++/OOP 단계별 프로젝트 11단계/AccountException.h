#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class MinusException{
private:
	int exval;
public:
	MinusException(int val) : exval(val){}
	void ShowExceptionInfo(void) const {
		cout<<"Withdraw "<<exval<<" money is successfully completed!"<<endl;
	}
};

class InsuffException{
private:
	int balance; 
	int reqval; 
public:
	InsuffException(int val, int req): balance(val), reqval(req){}
	void ShowExceptionInfo() const{
		cout<<"No enough money: Deposit "<<reqval-balance<<" money please!"<<endl;
	}
};

#endif