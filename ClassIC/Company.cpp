#include "inc.h"
#include "Company.h"

Company::Company(string name,int money)
	:sCompanyName(name)
	,iBaseMoney(money)
{
	iMoney = iBaseMoney;
}

Company::~Company()
{
}

string Company::GetMoneyString()
{
	return to_string(iMoney) + " ¿ø \n";
}

string Company::GetCompanyName()
{
	return sCompanyName + " È¸»ç \n";
}

unsigned int Company::GetMoney()
{
	return iMoney;
}

unsigned int Company::SetMoney(int money)
{
	return iMoney + money;
}
