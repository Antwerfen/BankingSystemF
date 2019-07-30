#ifndef __ACCOUNT_TEMPLATE_H__
#define __ACCOUNT_TEMPLATE_H__

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Account_template
{
private:
	T* arr;
	int arrlen;

	//���������
	Account_template(const Account_template& arr) {}

	//���Կ�����
	Account_template& operator=(const Account_template& arr) {}


public:
	Account_template();
	//Account_template(int len);

	//������
	T& operator[](int idx);
	//��¿�
	T operator[](int idx) const;
	//����� ��� ���� �ľ��� ����
	int getArrLen()const;
	//�Ҹ���
	~Account_template();





};

//������
template <typename T>

Account_template<T>::Account_template();
//Account_template<T>::Account_template(int len);


//[]������ �����ε�
template <typename T>
T& Account_template<T>::operator[](int idx);


//const []������ �����ε�
template <typename T>
T Account_template<T>::operator[](int idx) const;


//GetArrLen()
template <typename T>
int Account_template<T>::getArrLen()const;


//�Ҹ���
template <typename T>
Account_template<T>::~Account_template();


#endif // !__ACCOUNT_TEMPLATE_H__