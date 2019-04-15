//универсальная переменная
//task for exam!!!!!!!!
#pragma once
#include<iostream>
#include <iomanip>
#include<Windows.h>
#include<ctime>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;

//1.	Реализовать класс var - «Универсальная переменная».Объекты экземпляры этого класса способны хранить в себе значения следующих типов : int, double, String(строка – уже готовый класс).
//Например :
//	void main()
//{
//	var a = 15;
//	var b = “Hello”;
//	var c = 7.8;
//	var d = “50”;
//	b = a + d;
//	b.Show();		// Выведет 65
//	if (a == b) cout << “Equal\n”; else cout << “Not Equal\n”;
//}
//Для класса var необходимо перегрузить арифметические операторы : +, -, *, / , +=, -=, *=, /=
//И операторы сравнения : <, >, <= , >= , == , !=
//(Вся перегрузка осуществляется как функции - члены класса var)
//
//При перегрузке операторов учитывать следующее : если в операции типы значений двух операндов типа var разные, то необходимо приводить(конвертировать) значение из второго операнда к типу значения первого операнда и только после этого выполнять операцию. (При этом значение(и тип) второго операнда в самом объекте var не меняется)
//Например :
//	var a = 10, b = “120”, c;
//c = a + b;
//c.Show();		// Выведет 130
//c = b + a;
//c.Show();		// Выведет “12010”
//
//Для типа Строка операция * должна возвращать новую строку, состоящую только из символов первой строки, которые есть во  второй строке, например:
//var a = “Microsoft”, b = “Windows”, c;
//c = a * b;
//c.Show();		// Выведет “ioso”
//
//Для типа Строка операция / должна возвращать новую строку, состоящую из символов первой строки, которых нет во второй строке, например:
//var a = “Microsoft”, b = “Windows”, c;
//c = a / b;
//c.Show();		// Выведет “Mcrft”
//
//Аналогично для Строки *= и /=
//Добавить в класс var преобразования к типам : int, double, char*

string strMult(string s1, string s2);
string strDiv(string s1, string s2);
class Var {
	int intV;
	double doubleV;
	string strV;
	bool intf, doublef, stringf; //флажки
public:
	Var();
	//creating different constructors
	Var(int i);
	Var(double d);
	Var(string s);
	Var(const char*s);
	//operator int();
	operator double();

	Var operator=(string s);

	Var operator+(Var obj);
	Var operator+(int i);
	Var operator+(double d);
	Var operator+(string s);
	Var operator+(const char* s);

	Var operator+=(Var obj); //в отличие от просто оператора +, здесь все изменения будут в текущем объекте, будут его изменять
	Var operator+=(int i);
	Var operator+=(double d);
	Var operator+=(string s);
	Var operator+=(const char* s);

	Var operator-(Var obj);
	Var operator-(int i);
	Var operator-(double d);
	Var operator-(string s);
	Var operator-(const char* s);

	Var operator-=(Var obj);
	Var operator-=(int i);
	Var operator-=(double d);

	Var operator*(Var obj);
	Var operator*(int i);
	Var operator*(double d);
	Var operator*(string s);
	Var operator*(const char* s);

	Var operator/(Var obj);
	Var operator/(int i);
	Var operator/(double d);
	Var operator/(string s);
	Var operator/(const char* s);

	Var operator*=(Var obj);
	Var operator*=(int i);
	Var operator*=(double d);
	Var operator*=(string s);
	Var operator*=(const char* s);

	Var operator/=(Var obj);
	Var operator/=(int i);
	Var operator/=(double d);
	Var operator/=(string s);
	Var operator/=(const char* s);

	bool operator==(Var obj);
	bool operator==(int i);
	bool operator==(double d);
	bool operator==(string s);
	bool operator==(const char* s);

	bool operator!=(Var obj);
	bool operator!=(int i);
	bool operator!=(double d);
	bool operator!=(string s);
	bool operator!=(const char* s);

	bool operator>(Var obj);
	bool operator>(int i);
	bool operator>(double d);
	bool operator>(string s);
	bool operator>(const char* s);

	bool operator<(Var obj);
	bool operator<(int i);
	bool operator<(double d);
	bool operator<(string s);
	bool operator<(const char* s);

	bool operator>=(Var obj);
	bool operator>=(int i);
	bool operator>=(double d);
	bool operator>=(string s);
	bool operator>=(const char* s);

	bool operator<=(Var obj);
	bool operator<=(int i);
	bool operator<=(double d);
	bool operator<=(string s);
	bool operator<=(const char* s);

	void show();
};
