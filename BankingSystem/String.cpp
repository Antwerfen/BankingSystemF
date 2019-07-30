#include "MiniBankingCommonDecl.h"
#include "String.h"

String::String()
	:strLen(0), str(NULL)
{
	//^ ��^
}

//���� Ȯ��
String::String(int len)
{
	this->strLen = len;
	str = new char[this->strLen];
}

//����
String::String(const char* text)
{
	strLen = strlen(text) + 1;
	str = new char[strLen];
	strcpy_s(str, strLen, text);
}

//^ ��^?
String::String(int len, const char* text)
{
	strLen = len + 1;

	str = new char[strLen];

	for (int i = 0; i < strLen; i++)
	{
		str[i] = text[i];
	}

	str[strLen] = '\0';
}

String::String(const String& copy)
{
	strLen = strlen(copy.str) + 1;
	str = new char[strLen];
	strcpy_s(str, strLen, copy.str);
}

String::String(const char* text, int idx)
{
	strLen = idx + 1;

	str = new char[strLen];

	strcpy_s(str, strLen, text);

	str[idx] = '\0';
}


String::String(char* text1, char* text2)
{
	strLen = strlen(text2) - strlen(text1) + 1; //���� ���°���?
	str = new char[strLen];

	char* text_double;
	text_double = text1;

	for (int i = 0; i < strLen - 1; i++) //���� ���°Ŵ�? ���� ��?
	{
		str[i] = text_double[i];
	}
	str[strLen - 1] = '\0';
}

String& String::operator+=(const char* text)
{
	char* str2;
	int len2;
	len2 = strlen(text) + 1;
	str2 = new char[len2];
	strcpy_s(str2, len2, str);

	delete[]str;
	str = str2;//new char[strLen+len2];
	//strcpy_s(str,strLen + len2, str2);

	return *this;
}

String& String::operator=(const char* text)
{
	delete[]str;

	strLen = strlen(text) + 1;
	str = new char[strLen];
	strcpy_s(str, strLen, text);

	return *this;
}

String& String::operator=(const String& copy)
{
	delete[]str;

	strLen = strlen(copy.str) + 1;
	str = new char[strLen];
	strcpy_s(str, strLen, copy.str);

	return *this;
}

char& String::operator[](int idx)
{
	return this->str[idx];
}

String String::operator+(const String& copy)
{
	int len2;
	len2 = copy.strLen + (this->strLen) - 1;
	String copy2(len2);

	strcpy_s(copy2.str, len2, this->str);
	strcat_s(copy2.str, len2, copy.str);

	//strcat(this.str,copy.str);

	return copy2;
}



ostream& operator<<(ostream& out, const String& obj)
{
	out << obj.str;
	return out;
}

istream& operator>>(istream& in, String& obj)
{
	char* text = new char[100];
	cin >> text;

	obj.strLen = strlen(text) + 1;

	obj.str = new char[obj.strLen];

	strcpy_s(obj.str, obj.strLen, text);

	delete[]text;

	return in;
}



