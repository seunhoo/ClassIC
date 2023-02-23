#include "inc.h"

int main()
{
	Util cUtil;
	string sCompanyName = "";
	int iBaseMoney = 100;
	int iBorrowMoney = 0;
	int iDayCount = 0;

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

	while (cCompany.iMoney > 0)
	{
		if (iDayCount == 10)
		{
			cUtil.UpdateDay();
			iDayCount = 0;
		}
		// 화면 비우는 방법
		system("cls");
		// 오늘 날짜 
		cout << cUtil.GetDayString();

		// 매초 마다 돈 줄어들기
		cCompany.iMoney--;
		cout << cCompany.sCompanyName << " 회사\n";
		cout << "돈: " << cCompany.iMoney;

		iDayCount++;
		this_thread::sleep_for(chrono::seconds(1));
	}
}