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

string Company::GetMoney()
{
	return to_string(iMoney) + " ¿ø \n";
}

string Company::GetCompanyName()
{
	return sCompanyName + " È¸»ç \n";
}
