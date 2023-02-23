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
		// ȭ�� ���� ���
		system("cls");

		// �⺻ ��� ȭ��
		cout << cUtil.GetDayString();
		cout << cCompany.GetCompanyName();
		cout << cCompany.GetMoney();

		// ���� ���� �� �پ���
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

	// �⺻ ���� �Է�
	cout << "ȸ�� �̸�	: " << flush;
	cin >> sCompanyName;
	system("cls");
	cout << "�⺻ �ڱ�	: 100" << endl;
	cout << "������		: 1�� 5%" << endl;
	cout << "���� �ڱ�	: ";
	cin >> iBorrowMoney;
	system("cls");

	// ȸ�� ����
	Company cCompany(sCompanyName, iBaseMoney + iBorrowMoney);

	thread tCompany(Company_Thread, cCompany);

	while (1)
	{
		cin >> iGetAction;
	}
	
}