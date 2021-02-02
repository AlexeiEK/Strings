#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

void InputLine(char str[], const int n);
int StrLen(char str[]);

void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_number(char str[]);

//#define ClassWork

#ifdef ClassWork
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
#endif // ClassWork
void main()
{
	setlocale(LC_ALL, "");
	const int n = 1500;
	char str[n];
	cout << "Введите строку: ";
	InputLine(str, n);
	cout << "Нажмите 'U', если хотите перевести строку в верхний регистр, либо любую другую клавишу, чтобы перевести строку в нижний регистр." << endl;
	char ch;                     // Клавиша
	ch = _getch();              //  Нажать клавишу
	switch (ch)
	{
	case 'U': to_upper(str); break;
	case 'u': to_upper(str); break;
	default: to_lower(str);	break;
	}
	cout << str << endl;
	cout << "Введите строку: ";
	InputLine(str, n);
	system("CLS");
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	cout << "Введите число: ";
	InputLine(str, n);
	system("CLS");
	cout << str << endl;
	is_number(str) ? cout << "Да - это число!" : cout << "Это не число!";
	cout << endl;
	cout << "Введите строку: ";
	InputLine(str, n);
	system("CLS");
	cout << str << endl;
	is_palindrome(str) ? cout << "Эта строка палиндром!" : cout << "Эта строка не является палиндромом!";
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
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'а' && str[i] <= 'я' || str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = (int)str[i] - 32;
		}
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'А' && str[i] <= 'Я' || str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (int)str[i] + 32;
		}
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//Убираем пробелы вначале строки
		while (str[0] == ' ')
		{
			for (int j = 0; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
		//Убираем лишние пробелы далее в строке
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
bool is_palindrome(char str[])
{
	to_lower(str);
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
	int j = StrLen(str);
	int i = 0;
	do
	{
		str[i] == str[j - 1] ? i++ : i = 0;
		j--;
	} while (i && j);
	return i;
}
bool is_number(char str[])
{
	int i = 0;
	do
	{
		str[i] >= '0' && str[i] <= '9' || str[i] == ' ' ? i++ : i = 0;  // Пробелы можно убрать, если они не нужны
	} while (i && str[i]);
	return i;
}