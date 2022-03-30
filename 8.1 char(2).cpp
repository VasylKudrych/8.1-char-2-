#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void Change(char* str);

void Change(char* str)
{
	char* t = new char[strlen(str)];
	int d;
	int pos1 = 0;
	int pos2 = 0;
	*t = 0;
	d = strlen(str); //довжина рядка str
	for (int i = 0; i < d - 3; i++)
	{
		if ((str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!'))
		{
			pos2 = i + 4; //визначається кінцева точка однакових символів 
			strncat(t, str + pos1, pos2 - pos1 - 4);
			strcat(t, "**"); // в допоміжний масив вносяться символи, які заміняються
			pos1 = pos2; // задається точка, до якої заміна вже проведена
		}
	}
	strcat(t, str + pos1); // додається все, що залишилось після останньої заміни
	strcpy(str, t); // копіюється строка t в str
}

int main()
{
	char str[101]; //оголошення масиву
	cout << "Enter string:" << endl;
	cin.getline(str, 100); // вводяться  написані символи в масив

	Change(str); // викликається функція заміни однакових символів
	cout << "Result: " << str << endl;

}
