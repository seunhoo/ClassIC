#pragma once
class Company
{
public:
	Company(string name, int money);
	~Company();

	int iMoney;
	string sCompanyName;
private:
	int iBaseMoney;


};

