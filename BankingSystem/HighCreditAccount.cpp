#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "HighCreditAccount.h"
#include "String.h"


char A[8] = { "A���" };
char B[8] = { "B���" };
char C[8] = { "C���" };


char High_Level[LEVEL_LEN] = { "�ſ�ŷڰ���" };


//�⺻���� ������
HighCreditAccount::HighCreditAccount(int acc_id, const String cusName, const char* level_rank)
	:Account(acc_id, cusName), High_ratio(0.0), high_state_high(0)
{
	int len = strlen(High_Level) + 1;
	strcpy_s(high_level_name, len, High_Level);

	high_level_def_ratio = High_Level_ratio;

	high_cnt_input = 0;
	high_state_high = 2;

	if (strcmp(level_rank, A) == 0)
	{
		High_ratio = LEVEL_A * 0.01;
		return;
	}

	else if (strcmp(level_rank, B) == 0)
	{
		High_ratio = LEVEL_B * 0.01;
		return;
	}

	else if (strcmp(level_rank, C) == 0)
	{
		High_ratio = LEVEL_C * 0.01;
		return;
	}

}

//������ ���� ������
HighCreditAccount::HighCreditAccount(int level_sepa, int acc_num, int acc_ID, 
	int r_balance, const char* cus_name, const char* high_name, 
	double high_ratio, double high_plus_ratio, int cnt)
	:Account(acc_ID, cus_name,r_balance),high_level_def_ratio(high_ratio),High_ratio(high_plus_ratio),
	high_cnt_input(cnt),high_state_high(level_sepa)
{
	int len = strlen(high_name) + 1;
	strcpy_s(high_level_name, len, high_name);
}

String HighCreditAccount::High_level_name_return() //�������� ����
	{
		return high_level_name;
	}

	double HighCreditAccount::High_level_ratio_return() //�⺻ ����
	{
		return high_level_def_ratio;
	}

	double HighCreditAccount::High_plus_ratio_return() //�߰� ����
	{
		return High_ratio;
	}

	int HighCreditAccount::high_acc_return()
	{
		
		return high_state_high; // �ſ���� = 2 ��ȯ
	}

	int HighCreditAccount::check_high_cnt()
	{
		return high_cnt_input;
	}

	void HighCreditAccount::plus_high_cnt()
	{
		high_cnt_input++;
	}



	

	


	
