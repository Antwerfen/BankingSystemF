#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "NormalAccount.h"
#include "String.h"
#include "ErrorCluster.h"

//����������
//�� �ҷ����� �ɷ� �ʱ�ȭ ��Ű�°� �����߰ڴ�.
Account::Account(int input_accID, const String input_cusName)
	:accID(input_accID), balance(0)
{
	cusName = input_cusName;
}

Account::Account(int input_accID, const String input_cusName, int input_balance)
	:accID(input_accID),cusName(input_cusName), balance(input_balance)
{
	//^ ��^/
}



//����
Account::Account(Account& copy)
{
	accID = copy.accID;
	balance = copy.balance;
	cusName = copy.cusName;
}


//���¹�ȣ �˻�
int Account::Search_accID()const
{
	return accID;
}

//���¹�ȣ ����
int Account::accID_return() const
{
	
	return accID;
}

//�ܾ� ����
int Account::balance_return() const
{
	return balance;
}

//�����ܾ� ������
int Account::def_balance()const
{
	return 0;
}

//�̸� ����
String Account::name_return() const
{
	return cusName;
}

//�� �ֱ�
void Account::input_money(int input_money)
{

	balance = balance + input_money;
}

//�� ����
int Account::output_money(int output_money)
{
	int t;
	if (balance < output_money)
	{
		t = 1;
		Output_error expn(output_money);
		throw expn;

		//cout << "�ܾ׺��� ����Ϸ��� �׼��� �� Ů�ϴ�." << endl<<endl;
		//return -1;
	}
	else
	{
		balance = balance - output_money;
		cout << "���¿��� " << output_money << "���� ����Ͽ����ϴ�." << endl<<endl;
		return 1;
	}
}


//--------------------���뿹���̶�� �̸��� ����
String Account::level_return()
{
	return 0;
}


//-------------------���뿹���� ���� ����
double Account::level_ratio_return()
{
	return 0.0;
}


//-------------------�ſ뿹���̶�� �̸��� ����
String Account::High_level_name_return()
{
	return 0;
}

//------------------�ſ뿹���� ���� ���� ����
double Account::High_level_ratio_return()
{
	return 0.0;
}


//-------------------�ſ뿹���� �߰� ���� ����
double Account::High_plus_ratio_return()
{
	return 0.0;
}


//-----------------------------������¶�� ���� �˸��� �Լ�
int Account::normal_acc_return()
{
	return 0;
}


//---------------------------------�ſ���¶�� ���� �˸��� �Լ�
int  Account::high_acc_return()
{
	return 0;
}

//-----------------���� ���°� �����Ա����� �ƴ���
int Account::check_normal_cnt()
{
	return 0;
}


//-----------------------------------�ſ���°� �����Ա����� �ƴ���
int Account::check_high_cnt()
{
	return 0;
}


//----------------------------------���� ���¸� �����Աݿ��� ������ϴ� �Լ�
void Account::plus_normal_cnt()
{
	
}


//---------------------------------�ſ���¸� �����Աݿ��� ������ϴ� �Լ�
void Account::plus_high_cnt()
{
	
}






