#include "inc.h"

int main()
{
	Util cUtil;
	string sCompanyName = "";
	int iBaseMoney = 100;
	int iBorrowMoney = 0;
	int iDayCount = 0;

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

	while (cCompany.iMoney > 0)
	{
		if (iDayCount == 3)
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
		cCompany.iMoney--;

		iDayCount++;
		this_thread::sleep_for(chrono::seconds(1));
	}
}