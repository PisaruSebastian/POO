#pragma once

ref class LoyalityScheme {
public: 
	LoyalityScheme();
	void EarnPointsOnAmount(double amountSpent);
	void RedeemPoints(int points);
	int GetPoints();

private:
	int totalPoints;
};