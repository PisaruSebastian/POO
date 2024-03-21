#include "pch.h"
#include "stdafx.h"
#include "CreditCardAccount.h"
#using <mscorlib.dll>
using namespace System;

void CreditCardAccount::SetCreditLimit(double amount) {
	creditLimit = amount;
}

bool CreditCardAccount::MakePurchase(double amount) {
	if (curentBalance + amount > creditLimit)
	{
		return false;
	}
	else {
		curentBalance += amount;

		if (curentBalance >= creditLimit / 2) {
			if (scheme == nullptr) {
				scheme = gcnew LoyalityScheme();
			}
			else {
				scheme->EarnPointsOnAmount(amount);
			}
		}
		return true;
	}
	
}

void CreditCardAccount::MakeRepayment(double amount) {
	curentBalance -= amount;
}

void CreditCardAccount::PrintStatment() {
	Console::Write("Curent balance: ");
	Console::WriteLine(curentBalance);
}

long CreditCardAccount::GetAccountNumber(){
	return accountNumber;
}

CreditCardAccount::CreditCardAccount(long number, double limit) {
	accountNumber = number;
	creditLimit = limit;
	curentBalance = 0.0;
	numbersOfAccounts++;
	Console::Write("This is account number: ");
	Console::WriteLine(numbersOfAccounts);
	scheme = nullptr;
}

int CreditCardAccount::GetNumberOfAccounts() {
	return numbersOfAccounts;
}

	


static CreditCardAccount::CreditCardAccount() {
	interestRate = 4.5;
	Console::WriteLine("Static constructor called");
}

void CreditCardAccount::RedeemLoyalityPoints() {
	if (scheme == nullptr) {
		Console::WriteLine("Sorry, you don't have a loyalty scheme yet!");
	}
	else {
		Console::Write("Points available: ");
		Console::Write(scheme->GetPoints());
		Console::Write("\nHow many points do you want to redeem?\n");
		String^ input = Console::ReadLine();
		int points = Convert::ToInt32(input);
		scheme->RedeemPoints(points);
		Console::Write("Points remaining: ");
		Console::WriteLine(scheme->GetPoints());
	}
}
