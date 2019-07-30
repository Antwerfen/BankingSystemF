#include "MiniBankingCommonDecl.h"
#include "AccountHandler.h"
#include "ACCOUNT.h"
#include "screenOutMenu.h"
#include "etc.h"
#include "String.h"



int main(void)
{
	
	AccountHandler Handler;
	Handler.Read_data_file();
		
		int choice;
		//int acc_select;

		while (1)
		{
			system("cls");
			ShowMenu();

			
			switch (choice = input_choice())
			{
			case MAKE:
				ShowAccMakeMenu();
				Handler.select_accCreate();
				
				//Handler.make_account();
				
				break;

				
			case DEPOSIT:
				Handler.deposit_money();
				break;

				
			case WITHDRAW:
				Handler.withdraw_money();
				break;

				
			case INQUIRE:
				Handler.inquire_account();
				break;
				
			case SHOWALLACC:
				Handler.show_all();
				break;
				
				
			case EXIT:
				//delete Handler;
				cout << "�̿����ּż� �����մϴ�." << endl;
				
				return 0;
				
			default:
				cout << "���� �޴��Դϴ�." << endl;

			}


			getchar();
			getchar();
		}

		return 0;
}










