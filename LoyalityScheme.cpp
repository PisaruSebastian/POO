#include "pch.h"
#include "stdafx.h"
#include "LoyalityScheme.h"

#using <mscorlib.dll>
using namespace System;

LoyalityScheme::LoyalityScheme() {
	Console::WriteLine("Congratulation, you now qulify for bonus points");
	totalPoints = 0;
}

void LoyalityScheme::EarnPointsOnAmount(double amountSpent) {
	int points = (int)(amountSpent / 10);
	totalPoints += points;
	Console::Write("New bonus points earned: ");
	Console::WriteLine(points);
}

void LoyalityScheme::RedeemPoints(int points) {
	if (points <= totalPoints) {
		totalPoints -= points;
	}
	else {
		totalPoints = 0;
	}
}

int LoyalityScheme::GetPoints() {
	return totalPoints;
}