#ifndef __MINIBANKINGCOMMONDECL_H__
#define __MINIBANKINGCOMMONDECL_H__

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>


using namespace std;

#include "String.h"




#define NAME_LEN 20 //���̸��� ����
#define LEVEL_LEN 15 //���������� ����
#define Level_ratio 0.25 //������� �⺻ ������
#define PASS_WORD 9999
#define High_Level_ratio 0.25 // �ſ���� �⺻ ������
#define MAX_ACC 100


//�޴��� ������
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, SHOWALLACC, EXIT };



// ������ ����
enum { NORMAL = 1, CREDIT = 2, GOBACK = 3 };

//�ſ���� �߰����� �κ�
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };







#endif
