#include "inc.h"

static int iCountTime = 2;

void Company_Thread(Company cCompany)
{
	Util cUtil;
	int iDayCount = 0;
	int iGetAction = 0;
	while (cCompany.iMoney > 0)
	{
		if (iDayCount >= iCountTime * 3)
		{
			cUtil.UpdateDay();
			iDayCount = 0;
		}
		// 화면 비우는 방법
		system("cls");

		// 기본 출력 화면
		cout << cUtil.GetDayString();
		cout << cCompany.GetCompanyName();
		cout << cCompany.GetMoney();

		// 매초 마다 돈 줄어들기
		cCompany.iMoney -= iCountTime;

		iDayCount += iCountTime;
		this_thread::sleep_for(chrono::seconds(iCountTime));
	}
}

int main()
{

	string sCompanyName = "";
	int iBaseMoney = 100;
	int iBorrowMoney = 0;
	int iGetAction = 0;

	// 기본 정보 입력
	cout << "회사 이름	: " << flush;
	cin >> sCompanyName;
	system("cls");
	cout << "기본 자금	: 100" << endl;
	cout << "이자율		: 1년 5%" << endl;
	cout << "대출 자금	: ";
	cin >> iBorrowMoney;
	system("cls");

	// 회사 생성
	Company cCompany(sCompanyName, iBaseMoney + iBorrowMoney);

	thread tCompany(Company_Thread, cCompany);

	while (1)
	{
		cin >> iGetAction;
	}
	
}