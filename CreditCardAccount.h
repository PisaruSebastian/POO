#pragma once
#include "LoyalityScheme.h"

ref class CreditCardAccount{
public:
	void RedeemLoyalityPoints();
	literal System::String ^name = "Super Platinum Card";
	static CreditCardAccount();
	static int GetNumberOfAccounts();
	CreditCardAccount(long number, double limit);
	void SetCreditLimit(double amount);
	bool MakePurchase(double amount);
	void MakeRepayment(double amount);
	void PrintStatment();
	long GetAccountNumber();


private:
	LoyalityScheme^ scheme;
	static double interestRate;
	static int numbersOfAccounts = 0;
	initonly long accountNumber;
	double curentBalance;
	double creditLimit;
};





