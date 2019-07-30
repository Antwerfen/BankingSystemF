#include "MiniBankingCommonDecl.h"
#include "AccountHandler.h"
#include "etc.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

#include "ErrorCluster.h"





//������?
//AccountHandler::AccountHandler()
//	:accNum(0)
//{}

AccountHandler::AccountHandler()
	:accNum(0)
{
	//accList = new Account_ptr[MAX_ACC];
}

//�Ҹ���
AccountHandler::~AccountHandler()
{
	//for (int i = 0; i < accNum; i++)
	//{
	//delete[]accList;
	//}
}

Account_ptr& AccountHandler::operator[](int idx)
{
	if (idx < 0 || idx >= MAX_ACC)
	{
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}

	return accList[idx];
}

Account_ptr AccountHandler::operator[](int idx) const
{
	if (idx < 0 || idx >= MAX_ACC)
	{
		cout << "�迭�� ������ ������ϱ�?" << endl;
		exit(1);
	}

	return accList[idx];
}





//���� �����
void AccountHandler::make_account(int num)
{

	int def_id;
	String cus_name;
	int account_cheker = -1;

	try
	{
		if (accNum == MAX_ACC)
		{
			Space_error expn(accNum);
			throw expn;
		}
	}

	catch (Space_error & expn)
	{
		expn.Show_reason();
		return;

	}

	cout << "1.���°���" << endl;
	cout << "���� �Է� : ";
	cin >> def_id;

	//�ִ°ų� ���°ų� �˻�
	if (search_accID(def_id))
	{
		cout << "�̹� �����ϴ� �����Դϴ�." << endl;
		return;
	}


	cout << "���� �Է� : ";
	cin >> cus_name;


	//���������� ���¸� ����� �κ�
	switch (num)
	{
	case 1://�븻

		//cout << "1.���뿹�ݰ��»���" << endl;
		//NormalAccount* normal;
		//normal = new NormalAccount(def_id, cus_name);

		accList[accNum] = new NormalAccount(def_id, cus_name);
		//AddAccount(normal);


		cout << ' ' << endl << endl;
		account_cheker = 1;
		accNum++;

		//���� ������¹�ȣ->���¼���->���¹�ȣ->�ܾ�->���̸�->�����������->�������cnt->��������̸�

		break;



	case 2://�ſ�
		char level_rank[10];

		cout << ' ' << endl;
		cout << "2.�ſ�ŷڰ��»���" << endl;

		cout << "�ȳ����� ������ �ſ����� �Է����ּ���." << endl;
		cout << "��) A���, B���, C��� ���" << endl << endl;
		cout << "���� : ������ �����Ƿ� ���� �߸��� �ſ����� �Է��Ͽ�"
			<< "�߻��ϴ� �������� ��� å������ �ʽ��ϴ�." << endl;


		cin >> level_rank;


		accList[accNum] = new HighCreditAccount(def_id, cus_name, level_rank);

		cout << ' ' << endl << endl;
		account_cheker = 2;

		accNum++;
		//data_file << accNum << endl;

		//���� �ſ���¹�ȣ->���¼���->���¹�ȣ->�ܾ�->���̸�->�ſ���±⺻����->�ſ�����߰�����->�ſ����cnt->�ſ�����̸�

		break;

	default://��
		cout << "�� �� ���� ������ �߻��߽��ϴ�." << endl << endl;
		break;
	}
	//��������ϴºκ�
	screenout(account_cheker);
	//Show_create_result(accList[accNum], num,accNum);
	

	put_in_txt();



	//Show_create_acc_result(accNum);



	return;
}


/*===================�Ա� ===========================*/
//�Ա��ϱ�
void AccountHandler::deposit_money()
{
	switch (accNum)
	{
	case 0:
		cout << "���� �Էµ� ���� 0" << endl;
		break;

	default:

		int input_accID;
		int input_money;
		int idx;

		cout << "2.�Ա�" << endl;
		cout << "�Ա��Ϸ��� ���¹�ȣ�� �Է��ϼ��� ";
		cin >> input_accID;

		if (!search_accID(input_accID))
		{
			cout << "�ش� ���¹�ȣ�� �����ϴ�." << endl;
			return;
		}

		cout << "�󸶸� �Ա��Ͻðڽ��ϱ�? ";

		try
		{
			cin >> input_money;
			cout << ' ' << endl << endl;

			//������ �� �ִ� �Լ�
			idx = accID_idx(input_accID, input_money);
		}
		catch (Input_error & expn)
		{
			expn.Show_reason();
			return;
		}


		//Show_create_acc_result(accNum);


		//�������
		other_screenout(idx);
		put_in_txt();
		break;
	}

}


//accid ��ġ ã�� �� �ֱ�
int AccountHandler::accID_idx(int input_accid, int input_money)
{
	if (input_money <= 0)
	{
		Input_error expn(input_money);
		throw expn;
	}

	for (int i = 0; i < accNum; i++)
	{
		if (input_accid == accList[i]->Search_accID())
		{
			if (accList[i]->normal_acc_return() == 1) //�������
			{
				double plus_ratio;

				if (accList[i]->check_normal_cnt() > 0)
				{
					plus_ratio = (1.0 + Level_ratio) * input_money;
					accList[i]->input_money(plus_ratio * 1);
					accList[i]->plus_normal_cnt();
					return i;
				}

				else
				{
					accList[i]->input_money(input_money);
					accList[i]->plus_normal_cnt();
					return i;
				}
			}

			else if (accList[i]->high_acc_return() == 2)//�ſ����
			{
				double plus_plus_ratio;

				if (accList[i]->check_high_cnt() > 0)
				{
					plus_plus_ratio = (input_money * (1.0 + Level_ratio) * (1.0 + accList[i]->High_plus_ratio_return()));
					accList[i]->input_money(plus_plus_ratio * 1);
					accList[i]->plus_high_cnt();
					return i;
				}

				else
				{
					accList[i]->input_money(input_money);
					accList[i]->plus_high_cnt();
					return i;
				}

			}


		}

	}
	return -1;
}


/*===================��� ===========================*/
//����ϱ�
void AccountHandler::withdraw_money()
{
	switch (accNum)
	{
	case 0:
		cout << "���� �Էµ� ���� 0" << endl;
		break;

	default:

		int output_accID;
		int output_money;
		int idx;

		cout << "3.���" << endl;
		cout << "����Ϸ��� ���¹�ȣ�� �Է��ϼ��� ";
		cin >> output_accID;

		if (!search_accID(output_accID))
		{
			cout << "�ش� ���¹�ȣ�� �����ϴ�." << endl;
			return;
		}

		cout << "�󸶸� ����Ͻðڽ��ϱ�? ";


		try
		{
			cin >> output_money;
			cout << ' ' << endl << endl;

			//������ �� �ִ� �Լ�
			idx = real_withdraw_money(output_accID, output_money);
		}
		catch (Output_error & expn)
		{
			expn.Show_reason();
			return;
		}


		//�������
		other_screenout(idx);
		put_in_txt();

		//Show_create_acc_result(accNum);

		break;
	}

}

//accid ��ġ ã�� �� ���� ��ġ ��ȯ
int AccountHandler::real_withdraw_money(int output_accid, int output_money)
{
	if (output_money <= 0)
	{
		Output_error expn(output_money);
		throw expn;
	}


	for (int i = 0; i < accNum; i++)
	{
		if (output_accid == accList[i]->Search_accID())
		{
			if (accList[i]->output_money(output_money) >= 0)
				return i;

			else
				return -1;

		}
	}
	return -1;
}

/*=============================  yes or no ===========================*/

//���� ���� �����˻�
bool AccountHandler::search_accID(int input_accID)
{

	for (int i = 0; i < accNum; i++)
	{
		if (input_accID == accList[i]->Search_accID())
		{

			return true;
		}
	}
	return false;
}

//���� ���³� �ſ���³�
void AccountHandler::select_accCreate(void)
{
	int antwerpen;

	switch (antwerpen = input_choice())
	{
	case NORMAL:
		cout << "1.���뿹�ݰ��»���" << endl;
		make_account(antwerpen);
		break;

	case CREDIT:
		cout << "2.�ſ�ŷڰ��»���" << endl;
		make_account(antwerpen);
		break;

	case GOBACK:
		cout << "ó�� ȭ������ ���ư��ϴ�." << endl;
		break;

	default:
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}

}




/*===========================================���� ��ȸ ���� ===========================================*/

//�� ���� �����˻�
void AccountHandler::inquire_account()
{
	switch (accNum)
	{
	case 0:
		cout << "���� �Էµ� ���� 0" << endl;
		break;

	default:

		int input_accID;
		//int input_money;
		//int idx;

		cout << "4.������ȸ" << endl;
		cout << "��ȸ�Ϸ��� ���¹�ȣ�� �Է��ϼ��� ";
		cin >> input_accID;
		cout << ' ' << endl;

		if (!search_accID(input_accID))
		{
			cout << "�ش� ���¹�ȣ�� �����ϴ�." << endl;
			return;
		}

		//search_accID�� int������ ��ġ�� �� ���� �� ����.
		//idx = 
		inqire_screenout(input_accID);

		//�������

		break;
	}
}

//��ü ���� ��ȸ �޴�
void AccountHandler::show_all()
{
	int input_pass;

	cout << "��й�ȣ�� �Է��Ͻʽÿ�. ";
	cin >> input_pass;
	cout << ' ' << endl << endl;

	switch (input_pass)
	{
	case PASS_WORD:
	{
		switch (accNum)
		{
		case 0:
			cout << "��ȸ�� ������ �����ϴ�." << endl;
			break;

		default:
			show_all_screenout();

			break;
		}
		break;
	}
	default:
		cout << "������ ���� ����� ��ȸ�� �� �����ϴ�." << endl;
		break;
	}
}

//���Ͷ� ����(���»�����)
void AccountHandler::screenout(int cheker)
{
	int idx = accNum - 1;

	switch (cheker)
	{
	case 1:
		cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
		cout << "====================================" << endl;
		cout << "	���¹�ȣ : " << accList[idx]->accID_return() << endl;
		cout << "	�������� : " << accList[idx]->level_return(); cout << endl;
		cout << "	�������� : " << accList[idx]->level_ratio_return() << "%" << endl;
		cout << "	��    �� : " << accList[idx]->balance_return() << "��" << endl;
		cout << "	������ : " << accList[idx]->name_return(); cout << "��" << endl;
		cout << "====================================" << endl;
		break;

	case 2:
		cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
		cout << "====================================" << endl;
		cout << "	���¹�ȣ : " << accList[idx]->accID_return() << endl;
		cout << "	�������� : " << accList[idx]->High_level_name_return(); cout << ' ' << endl;
		cout << "	�������� : " << accList[idx]->High_level_ratio_return() << endl;
		cout << "	�߰����� : " << accList[idx]->High_plus_ratio_return() << endl;
		cout << "	��    �� : " << accList[idx]->balance_return() << "��" << endl;
		cout << "	������ : " << accList[idx]->name_return(); cout << "��" << endl;
		cout << "====================================" << endl;
		break;

	default:
		cout << "������ �Բ��ϴ� xx����" << endl;
		break;
	}
}

//���Ͷ� ����(�� ���� �����˻���)
int AccountHandler::inqire_screenout(int input_accid)
{

	for (int idx = 0; idx < accNum; idx++)
	{
		if (input_accid == accList[idx]->Search_accID())
		{
			if (accList[idx]->normal_acc_return() == 1)
			{
				cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
				cout << "====================================" << endl;
				cout << "	���¹�ȣ : " << accList[idx]->accID_return() << endl;
				cout << "	�������� : " << accList[idx]->level_return(); cout << endl;
				cout << "	�������� : " << accList[idx]->level_ratio_return() << "%" << endl;
				cout << "	��    �� : " << accList[idx]->balance_return() << "��" << endl;
				cout << "	������ : " << accList[idx]->name_return(); cout << "��" << endl;
				cout << "====================================" << endl;
				return 1;
			}


			else if (accList[idx]->high_acc_return() == 2)
			{
				cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
				cout << "====================================" << endl;
				cout << "	���¹�ȣ : " << accList[idx]->accID_return() << endl;
				cout << "	�������� : " << accList[idx]->High_level_name_return(); cout << ' ' << endl;
				cout << "	�������� : " << accList[idx]->High_level_ratio_return()<<"%" << endl;
				cout << "	�߰����� : " << accList[idx]->High_plus_ratio_return()<<"%" << endl;
				cout << "	��    �� : " << accList[idx]->balance_return() << "��" << endl;
				cout << "	������ : " << accList[idx]->name_return(); cout << "��" << endl;
				cout << "====================================" << endl;
				return 2;
			}

			else
			{
				cout << "������ �Բ��ϴ� xx����" << endl;
				return -1;
			}
		}
	}
	return -1;
}


//�ٸ� �κ� �������(�Ա�,���)
void AccountHandler::other_screenout(int idx)
{
	switch (idx)
	{
	case -1:
		cout << "������ �Բ��ϴ� xx����" << endl;
		break;

	default:

		if (accList[idx]->normal_acc_return() == 1)
		{
			cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
			cout << "====================================" << endl;
			cout << "	���¹�ȣ : " << accList[idx]->accID_return() << endl;
			cout << "	�������� : " << accList[idx]->level_return(); cout << endl;
			cout << "	�������� : " << accList[idx]->level_ratio_return() << "%" << endl;
			cout << "	��    �� : " << accList[idx]->balance_return() << "��" << endl;
			cout << "	������ : " << accList[idx]->name_return(); cout << "��" << endl;
			cout << "====================================" << endl;
			return;
		}


		else if (accList[idx]->high_acc_return() == 2)
		{
			cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
			cout << "====================================" << endl;
			cout << "	���¹�ȣ : " << accList[idx]->accID_return() << endl;
			cout << "	�������� : " << accList[idx]->High_level_name_return(); cout << ' ' << endl;
			cout << "	�������� : " << accList[idx]->High_level_ratio_return()<<"%" << endl;
			cout << "	�߰����� : " << accList[idx]->High_plus_ratio_return() <<"%"<< endl;
			cout << "	��    �� : " << accList[idx]->balance_return() << "��" << endl;
			cout << "	������ : " << accList[idx]->name_return(); cout << "��" << endl;
			cout << "====================================" << endl;
			return;
		}
		break;
	}

}

//��ü ������ȸ�� ���Ͷ� ����
void AccountHandler::show_all_screenout()const
{
	for (int idx = 0; idx < accNum; idx++)
	{
		if (accList[idx]->normal_acc_return() == 1)
		{
			cout << idx + 1 << "��° ����" << endl;
			cout << "====================================" << endl;
			cout << "	���¹�ȣ : " << accList[idx]->accID_return() << endl;
			cout << "	�������� : " << accList[idx]->level_return(); cout << endl;
			cout << "	�������� : " << accList[idx]->level_ratio_return() << "%" << endl;
			cout << "	��    �� : " << accList[idx]->balance_return() << "��" << endl;
			cout << "	������ : " << accList[idx]->name_return(); cout << "��" << endl;
			cout << "====================================" << endl << endl;
		}

		if (accList[idx]->high_acc_return() == 2)
		{
			cout << idx + 1 << "��° ����" << endl;
			cout << "====================================" << endl;
			cout << "	���¹�ȣ : " << accList[idx]->accID_return() << endl;
			cout << "	�������� : " << accList[idx]->High_level_name_return(); cout << ' ' << endl;
			cout << "	�������� : " << accList[idx]->High_level_ratio_return()<<"%" << endl;
			cout << "	�߰����� : " << accList[idx]->High_plus_ratio_return()<<"%" << endl;
			cout << "	��    �� : " << accList[idx]->balance_return() << "��" << endl;
			cout << "	������ : " << accList[idx]->name_return(); cout << "��" << endl;
			cout << "====================================" << endl << endl;

		}

	}
	return;
}



//����

/*
void AccountHandler::AddAccount(Account_ptr *emp)
{
	accList[accNum++] = emp;

}
*/


int AccountHandler::accNum_return()
{
	return accNum;
}

Account* AccountHandler::accList_return(int idx)
{
	return accList[idx];
}

void AccountHandler::Read_data_file(void)
{
	ifstream data_file("data.txt");


	int level_sepa; // ����������ȣ
	int acc_num;	// ���¼���
	int acc_ID;		// ���¹�ȣ
	int r_balance;	// �ܾ�
	char* cus_name = new char[NAME_LEN];	//���̸�
	double normal_ratio;	//�����������
	double high_ratio, high_plus_ratio;	//�ſ��������,�ſ�����߰�����
	int cnt;	//�����Ա��ΰ� �ƴѰ�
	char* normal_name = new char[LEVEL_LEN];	//��������̸�
	char* high_name = new char[LEVEL_LEN];		//�ſ�����̸�

	int acc_num2;

	if (data_file.is_open())
	{
		data_file >> acc_num2;

		for (int i = 0; i < acc_num2; i++) {

			data_file >> level_sepa;


			if (level_sepa == 1)
			{
				data_file >> acc_num;
				data_file >> acc_ID;
				data_file >> r_balance;
				data_file >> cus_name;
				data_file >> normal_ratio;
				data_file >> cnt;
				data_file >> normal_name;
				//acc_num ,acc_ID, r_balance, cus_name, normal_name, normal_ratio, cnt
				//accNum = acc_num;
				accList[accNum++] = new NormalAccount(level_sepa, acc_num, acc_ID, r_balance,
					cus_name, normal_name, normal_ratio, cnt);
				//������ ���ϰ� ���α׷��� ���¼��� ����ȭ�� ����

			}
			//���� �ſ���¹�ȣ->���¼���->���¹�ȣ->�ܾ�->���̸�->�ſ���±⺻����->�ſ�����߰�����->�ſ����cnt->�ſ�����̸�
			else if (level_sepa == 2)
			{
				data_file >> acc_num;
				data_file >> acc_ID;
				data_file >> r_balance;
				data_file >> cus_name;
				data_file >> high_ratio;
				data_file >> high_plus_ratio;
				data_file >> cnt;
				data_file >> high_name;
				//accNum = acc_num;
				//acc_num, acc_ID, r_balance, cus_name, high_name, high_ratio, high_plus_ratio, cnt
				accList[accNum++] = new HighCreditAccount(level_sepa, acc_num, acc_ID,
					r_balance, cus_name, high_name, high_ratio, high_plus_ratio, cnt);
				//������ ���ϰ� ���α׷��� ���¼��� ����ȭ�� ����

			}
		}
		/*
		while(1)
		{

			data_file >> level_sepa;
				if (data_file.fail())
				break;


			if (level_sepa == 1)
			{
				data_file >> acc_num;
				data_file >> acc_ID;
				data_file >> r_balance;
				data_file >> cus_name;
				data_file >> normal_ratio;
				data_file >> cnt;
				data_file >> normal_name;
				//acc_num ,acc_ID, r_balance, cus_name, normal_name, normal_ratio, cnt
				//accNum = acc_num;
				accList[accNum++] = new NormalAccount(level_sepa,acc_num, acc_ID, r_balance,
					cus_name, normal_name, normal_ratio, cnt);
				//������ ���ϰ� ���α׷��� ���¼��� ����ȭ�� ����
			}
			//���� �ſ���¹�ȣ->���¼���->���¹�ȣ->�ܾ�->���̸�->�ſ���±⺻����->�ſ�����߰�����->�ſ����cnt->�ſ�����̸�
			else if (level_sepa == 2)
			{
				data_file >> acc_num;
				data_file >> acc_ID;
				data_file >> r_balance;
				data_file >> cus_name;
				data_file >> high_ratio;
				data_file >> high_plus_ratio;
				data_file >> cnt;
				data_file >> high_name;
				//accNum = acc_num;
				//acc_num, acc_ID, r_balance, cus_name, high_name, high_ratio, high_plus_ratio, cnt
				accList[accNum++] = new HighCreditAccount(level_sepa, acc_num, acc_ID,
					r_balance,cus_name, high_name, high_ratio, high_plus_ratio, cnt);
				//������ ���ϰ� ���α׷��� ���¼��� ����ȭ�� ����

			}


			//break;

		}
		*/
	}
	else
	{
		cout << "������ ������ �ʾҽ��ϴ�." << endl;
		exit(1);
	}
	delete[]cus_name;
	delete[]normal_name;
	delete[]high_name;

	data_file.close();

	//if (accNum != 0)
	//	accNum++;//�����߰�.


}


void AccountHandler::put_in_txt(void)
{
	ofstream data_file("data.txt");//,ios::app);
	if (data_file.is_open())
	{
		data_file << accNum << endl;

		for (int i = 0; i < accNum; i++)
		{

			if (accList[i]->normal_acc_return() == 1)
			{
				data_file << accList[i]->normal_acc_return() << ' ' << accNum << ' ' << accList[i]->accID_return() << ' ' << accList[i]->balance_return()
					<< ' ' << accList[i]->name_return() << ' ' << accList[i]->level_ratio_return() << ' '
					<< accList[i]->check_normal_cnt() << ' ' << accList[i]->level_return() << endl;
			}

			else if (accList[i]->high_acc_return() == 2)
			{
				data_file << accList[i]->high_acc_return() << ' ' << accNum << ' ' << accList[i]->accID_return() << ' ' << accList[i]->balance_return() << ' '
					<< accList[i]->name_return() << ' ' << accList[i]->High_level_ratio_return() << ' '
					<< accList[i]->High_plus_ratio_return() << ' '
					<< accList[i]->check_high_cnt() << ' ' << accList[i]->High_level_name_return() << endl;

			}


			else
			{
				cout << "�� �� ���� ������ �߻��߽��ϴ�." << endl << endl;
				return;
			}
		}
	}

	else
	{
		cout << "������ �� �� �����ϴ�." << endl << endl;
	}
	data_file.close();


}

/*
int AccountHandler::Show_create_result(Account *address, int checker,int acc)
{
	return 0;
}
*/
