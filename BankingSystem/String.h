#ifndef __STRING_H__
#define __STRING_H__

#include "MiniBankingCommonDecl.h"

class String
{
private:
	int strLen;
	char* str;

public:

	//ó��
	String();

	//���� Ȯ��
	String(int len);

	//����?
	String(const char* text);

	//����,���� �� �� �Է�?
	String(int len, const char *text);

	//���� ������?
	String(const String& copy);

	//����?
	String(const char* text, int idx);

	//?
	String(char* text1, char* text2);

	//?
	virtual ~String()
	{
		delete[]str;
	}

	
	String& operator+=(const char* text);
	

	String& operator=(const char* text);
	

	String& operator=(const String& copy);
	

	char& operator[](int idx);
	

	String operator+(const String& copy);
	

	friend ostream& operator<<(ostream& out, const String& obj);

	friend istream& operator>>(istream& in, String& obj);


};
	
	

#endif