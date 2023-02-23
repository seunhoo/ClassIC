#include "inc.h"
#include "Util.h"

//char sCalendarDay[8] = {'일','월','화','수','목','금','토','\0'};
vector<string> sCalendarDay{ "일","월","화","수","목","금","토" };
Util::Util()
{
}

Util::~Util()
{
}

string AddComma(int num)
{
    string sNum = std::to_string(num);
    int iLen = sNum.length();
    for (int i = iLen - 3; i > 0; i -= 3) {
        sNum.insert(i, ",");
    }
    return sNum;
}

void Util::UpdateDay()
{
    int iMaxDay = 0;
    switch (iCalendarMonth) {
    case 2:
        if ((iCalendarYear % 4 == 0) || (iCalendarYear % 100 == 0))
            iMaxDay = 29;
        else
            iMaxDay = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        iMaxDay = 30;
        break;
    default:
        iMaxDay = 31;
        break;
    }
    iCalendarDay++;
    if (iCalendarDay > iMaxDay)
    {
        iCalendarDay = 1;
        iCalendarMonth++;
    }
    if (iCalendarMonth > 12)
    {
        iCalendarMonth = 1;
        iCalendarYear;
    }
}

string Util::GetDayString()
{
    string sDay = "";
    sDay = to_string(iCalendarYear) + "년 " + to_string(iCalendarMonth) + "월 " + to_string(iCalendarDay) + "일 " + GetDay() + "요일 \n";
	return sDay;
}

string Util::GetDay()
{
    return sCalendarDay[iCalendarDay % 7];
}
