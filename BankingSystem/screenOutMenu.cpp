#include "MiniBankingCommonDecl.h"
#include "AccountHandler.h"
#include "screenOutMenu.h"



//�ʱ� �޴�
void ShowMenu(void)
{
	cout << "======Menu======" << endl;
	cout << "  1. ���°���" << endl;
	cout << "  2. ��    ��" << endl;
	cout << "  3. ��    ��" << endl;
	cout << "  4. ������ȸ" << endl;
	cout << "  5. ��ü��ȸ" << endl;
	cout << "  6. ��    ��" << endl;
	cout << "================" << endl;

}
//���°��� �޴�
void ShowAccMakeMenu(void)
{
	cout << "======Menu======" << endl;
	cout << "  1. ���뿹�ݰ��� ����" << endl;
	cout << "  2. �ſ�ŷڰ��� ����" << endl;
	cout << "  3. ó������ ���ư���" << endl;
	cout << "================" << endl;
}



/*
int Show_create_result(Account *address,int checker,int acc)
{
	//int idx = address->accNum_return() - 1;
	
	
}
*/


/*
int r_show::Show_create_result(Account* address, int checker, int acc)
{
	if (address->normal_acc_return() == 1)

	{
		cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
		cout << "====================================" << endl;
		cout << "	���¹�ȣ : " << address->accID_return() << endl;
		cout << "	�������� : " << address->level_return(); cout << endl;
		cout << "	�������� : " << address->level_ratio_return() << "%" << endl;
		cout << "	��    �� : " << address->balance_return() << "��" << endl;
		cout << "	������ : " << address->name_return(); cout << "��" << endl;
		cout << "====================================" << endl;
		return 0;
	}


	else if (address->high_acc_return() == 2)
	{
		cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
		cout << "====================================" << endl;
		cout << "	���¹�ȣ : " << address->accID_return() << endl;
		cout << "	�������� : " << address->High_level_name_return(); cout << ' ' << endl;
		cout << "	�������� : " << address->High_level_ratio_return() << "%" << endl;
		cout << "	�߰����� : " << address->High_plus_ratio_return() << "%" << endl;
		cout << "	��    �� : " << address->balance_return() << "��" << endl;
		cout << "	������ : " << address->name_return(); cout << "��" << endl;
		cout << "====================================" << endl;
		return 0;
	}

	return 0;
}
*/
