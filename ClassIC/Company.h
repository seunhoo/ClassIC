#pragma once
class Company
{
public:
	Company(string name, int money);
	~Company();

	unsigned int iMoney;
	string sCompanyName;

	string GetMoneyString();
	string GetCompanyName();

	unsigned int GetMoney();
	unsigned int SetMoney(int money);

private:
	int iBaseMoney;




};

