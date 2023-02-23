#include "inc.h"
#include "Util.h"

char sCalendarDay[8] = {'일','월','화','수','목','금','토'};

Util::Util()
{
}

Util::~Util()
{
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
    sDay = to_string(iCalendarYear) + "년 " + to_string(iCalendarMonth) + "월 " + to_string(iCalendarDay) + "일 " + to_string(GetDay()) + "요일 \n";
	return sDay;
}

char Util::GetDay()
{
    return sCalendarDay[iCalendarDay % 7];
}
