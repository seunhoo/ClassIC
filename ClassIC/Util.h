#pragma once

#ifndef __UTIL_H__
#define __UTIL_H__
class Util
{
public:

	Util();
	~Util();


	int iCalendarYear = 2000;
	int iCalendarMonth = 1;
	int iCalendarDay = 1;

	
	void UpdateDay();

	string GetDayString();
	string GetDay();

};


#endif // !__UTIL_H__

