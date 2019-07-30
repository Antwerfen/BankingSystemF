
#include "MiniBankingCommonDecl.h"
#include <iostream>
#include <cstdlib>

#include "Account_template.h"


using namespace std;


//������
template <typename T>

Account_template<T>::Account_template()
	:arrlen(0)
{
	arr = new T[MAX_ACC];
}

/*
template <typename T>
Account_template<T>::Account_template(int len)
	:arrlen(len)
{
	arr = new T[len];
}
*/

//[]������ �����ε�
template <typename T>
T& Account_template<T>::operator[](int idx)
{
	if (idx < 0 || idx >= 100)
	{
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}
	return arr[idx];
}

//const []������ �����ε�
template <typename T>
T Account_template<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}
	return arr[idx];
}

//GetArrLen()
template <typename T>
int Account_template<T>::getArrLen()const
{
	return arrlen;
}

//�Ҹ���
template <typename T>
Account_template<T>::~Account_template()
{
	delete[]arr;
}