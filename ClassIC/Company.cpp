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
