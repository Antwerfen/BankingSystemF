#include "MiniBankingCommonDecl.h"
#include "NormalAccount.h"
#include "ACCOUNT.h"
#include "String.h"


char Normal_Level[LEVEL_LEN] = { "���뿹�ݰ���" };


//�⺻���� ������
NormalAccount::NormalAccount(int acc_id, const String in_cusName)
	:Account(acc_id,in_cusName), normal_level_ratio(Level_ratio),
	normal_cnt_input(0),normal_state_normal(1)
{
	int len = strlen(Normal_Level) + 1;
	strcpy_s(normal_level_name, len, Normal_Level);
	//normal_level_ratio = Level_ratio;
	//���� bank���� �� �̹� 0���� ���ִϱ� �ʿ䰡 ��������?
	//normal_cnt_input = 0;
	//normal_state_normal = 1;
}

//������ ���� ������
NormalAccount::NormalAccount(int level_sepa, int acc_num, int acc_ID, 
	int r_balance, const char* cus_name, const char* normal_name, double normal_ratio, int cnt)
	:Account(acc_ID, cus_name, r_balance), normal_level_ratio(normal_ratio),
	normal_cnt_input(cnt),normal_state_normal(level_sepa)
{
	int len = strlen(normal_name) + 1;
	strcpy_s(normal_level_name, len, normal_name);
}

//������¶�� ���� ����
String NormalAccount::level_return()
{
	return normal_level_name;
}

//������������� ����
double NormalAccount::level_ratio_return()
{
	return normal_level_ratio;
}

//����������� ��Ÿ���� ���� ����
int NormalAccount::normal_acc_return()
{
	return normal_state_normal;
}

//�����Աݿ��� Ȯ���� ���� cnt ����
int NormalAccount::check_normal_cnt()
{
	return normal_cnt_input;
}

//cnt�� ������Ű�� �Լ�
void NormalAccount::plus_normal_cnt()
{
	normal_cnt_input++;
}



