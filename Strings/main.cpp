#include<iostream>
#include<Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	'\0';  //ASCII-символ с кодом 0
	//Null terminated lines
	//char str[5] = { 'H','e','l','l','o' };
	//for (int i = 0; i < 5; i++)cout << str[i]; cout << endl;
	//cout << str << endl;
	/*char str[] = "Hello";
	cout << str << endl;*/

	//system("CHCP 1251");
	const int n = 20;
	char str[n];
	cout << "Введите строку: ";
	InputLine(str, n);
	cout << str << endl;
	cout << "Длина строки: " << StrLen(str) << endl;
}
void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, n);
	SetConsoleCP(866);
}
int StrLen(char str[])
{
	//Возвращает длину строки
	int i = 0;
	for (; str[i]; i++);
	return i;
}