#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "MiniBankingCommonDecl.h"
#include "String.h"





class Account
{
private:
	int accID;
	int balance;
	String cusName;

public:

	Account();
	
	//������
	Account(int input_accID, const String input_cusName);
	
	//�ҷ������ ������
	Account(int input_accID, const String input_cusName, int input_balance);

	//����
	Account(Account& copy);

	
	//���¹�ȣ�˻�
	int Search_accID()const;

	//�����ܾ� ������
	int def_balance()const;
	
	//���¹�ȣ ����
	int accID_return()const;
	//�ܾ� ����
	int balance_return()const;
	//�̸� ����
	String name_return()const;

	//�� �ֱ�
	void input_money(int input_money);

	//�� ����
	int output_money(int output_money);

	
	
	virtual String level_return() ; //���뿹���� ��Ÿ���� ���� ����
	
	virtual double level_ratio_return();	//���뿹���� ���� ����
	
	virtual String High_level_name_return();	//���뿹���̶�� �̸��� ����

	virtual double High_level_ratio_return();	//�ſ���� �⺻ ���� ����

	virtual double High_plus_ratio_return();	//�ſ���� �߰� ���� ����

	virtual int high_acc_return();//�ſ�������� �˷��ִ� �Լ�

	virtual int normal_acc_return();//����������� �˷��ִ� �Լ�

	virtual int check_normal_cnt();//��������� �����Ա� ���θ� �˷��ִ� �Լ�

	virtual int check_high_cnt();//�ſ������ �����Ա� ���θ� �˷��ִ� �Լ�
	
	virtual void plus_normal_cnt();//��������� cnt�� �ø��� �Լ�

	virtual void plus_high_cnt();	//�ſ������ cnt�� �ø��� �Լ�

	


	
};

#endif // !__BANK_H__

