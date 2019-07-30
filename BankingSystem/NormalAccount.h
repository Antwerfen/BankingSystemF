#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "String.h"



class NormalAccount : public Account
{
private:
	char normal_level_name[LEVEL_LEN];
	double normal_level_ratio;
	int normal_cnt_input;
	int normal_state_normal;
public:
	
	//������?
	NormalAccount(int acc_id,const String cusName);
	
	//acc_num ,acc_ID, r_balance, cus_name, normal_name, normal_ratio, cnt
	NormalAccount(int level_sepa, int acc_num, int acc_ID, int r_balance, const char* cus_name,
		const char* normal_name, double normal_ratio, int cnt);

	//~NormalAccount();
	//�������� ����
	String level_return();

	//�������� ����
	double level_ratio_return();

	//����������� �˷��ִ� �Լ�
	int normal_acc_return();

	//�����Ա����� �ƴ��� üũ�ϴ� �Լ�
	int check_normal_cnt();

	//�����Ա� ������ �Ǵ��ϴ� cnt_input�� �ø��� �Լ�
	void plus_normal_cnt();

};



#endif // !__BANK_H__
