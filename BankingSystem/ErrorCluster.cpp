#include "MiniBankingCommonDecl.h"
#include "ErrorCluster.h"


Input_error::Input_error(int in_money)
	:insult_money(in_money)
{
}

void Input_error::Show_reason(void)
{
	cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��Ͽ� �ֽñ� �ٶ��ϴ�." << endl << endl;
}



Output_error::Output_error(int out_money)
	:output_money(out_money)
{
}



void Output_error::Show_reason(void)
{
	cout << "���忡 �ܰ� ���ų� �߸��� �Է��Դϴ�." << endl;
	cout << "�ٽ� �õ��Ͽ� �ֽñ� �ٶ��ϴ�."<< endl;

}



Space_error::Space_error(int is_there_any_sapce)
	:acc_space(is_there_any_sapce)
{
}

void Space_error::Show_reason(void)
{
	cout << "�� �̻��� ������ �����ϴ�. �����ڿ��� �������ֽʽÿ�." << endl << endl;
}


