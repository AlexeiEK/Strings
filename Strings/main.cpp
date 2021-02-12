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

int to_int(char str[]);
bool is_bin(char str[]);
bool is_hex(char str[]);
int bin_to_dec(char str[]);

//#define ClassWork
//#define HomeWork06_02

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
#ifdef HomeWork06_02
void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		if (i % 16 == 0)cout << endl;
		cout << i << "  " << (char)i << " ";
	}
}
void main()
{
	setlocale(LC_ALL, "");
	ASCII();
	cout << endl << endl;
	const int n = 1500;
	char str[n];
	cout << "Введите строку: ";
	InputLine(str, n);
	cout << "Нажмите 'U', если хотите перевести строку в верхний регистр, либо 'L', чтобы перевести строку в нижний регистр." << endl;
	/*cout << (char)-125 << "  " << (char)-93 << "  " << endl;
	cout << (int)'Д' << "  " << (int)'д' << "  " << endl;*/
	char ch;                     // Клавиша
	ch = _getch();              //  Нажать клавишу
	//cout << ch << (int)ch << endl;
	switch (ch)
	{
	case 'U':
	case -125:
	case -93:
	case 'u': to_upper(str); break;
	case 'L':
	case -124:
	case -92:
	case 'l': to_lower(str); break;
		//default: to_lower(str);	break;case 'U': to_upper(str); break;
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
#endif // HomeWork06_02

void main()
{
	setlocale(LC_ALL, "");
	const int n = 1500;
	char str[n];
	cout << "Введите число: ";
	InputLine(str, n);
	int number = to_int(str);
	cout << "Число = " << number << endl;
	system("PAUSE");
	system("CLS");
	cout << "Введите двоичное число: ";
	InputLine(str, n);
	cout << "Ваше число в десятичной СС: " << bin_to_dec(str) << endl;
	cout << "Введите шестнадцатиричное число: ";
	InputLine(str, n);
	(is_hex(str)) ? cout << "Вы ввели верно!" : cout << "Неправильный формат числа!" << endl;
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
			//str[i] = (int)str[i] - 32;
			str[i] -= 32;
		}
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'А' && str[i] <= 'Я' || str[i] >= 'A' && str[i] <= 'Z')
		{
			//str[i] = (int)str[i] + 32;
			str[i] += 32;
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
int to_int(char str[])
{
	int buffer = 0, flag = 1;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '-' && buffer == 0) flag--;
		if (str[i] >= '0' && str[i] <= '9')	buffer = buffer * 10 + str[i] - 48;
	}
	if (flag > 0) return buffer;
	return 0 - buffer;
}
bool is_bin(char str[])
{
	for (int i = 0; str[i]; i++) if (str[i] != ' ' && str[i] < '0' || str[i] > '1') return 0;
	return 1;
}
bool is_hex(char str[])
{
	int i = 0, flag = 1;
	while (flag && str[i] == ' ' || str[i] == '0')
	{
		i++;
		if (str[i] == 'x' || str[i] == 'X')
		{
			i++;
			flag = 0;
		}
	}
	for (; str[i];)
	{
		if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'F' || str[i] >= 'a' && str[i] <= 'f' || str[i] == ' ')
		{
			i++;
		}
		else
		{
			return 0;
		}
	}
	return i;
}
int bin_to_dec(char str[])
{
	int buffer = 0;
	if (is_bin(str))
	{
		int iter = StrLen(str) - 1;
		for (; str[iter] == ' '; iter--);   //Убираем пробелы вконце строки
		for (int i = 0; str[i]; i++)
		{
			if (str[i] != ' ')
			{
				int buffer1;
				buffer1 = str[i] - 48;
				for (int j = i; j < iter; j++)
				{
					str[j] == ' ' ? buffer1 *= 1 : buffer1 *= 2;
				}
				buffer += buffer1;
			}
		}
	}
	return buffer;
}