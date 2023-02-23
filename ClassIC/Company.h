#pragma once
class Company
{
public:
	Company(string name, int money);
	~Company();

	unsigned int iMoney;
	string sCompanyName;

	string GetMoney();
	string GetCompanyName();

private:
	int iBaseMoney;




};

