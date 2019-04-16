#include "Var.h"

int main() {

	Var el = 5.7;
	// если чтото передается в кавычках, то это в любом случае чар-массив
	Var el1("15");//const char
	Var el3 = "15";//const char
	el3.show();

	double a = el; //только прямое присваивание
	double b = el + el3;
	Var el4 = 1000;
	Var c = el4 + el3;
	Var d = el3 + el4;
	cout << a << " " << b << " " << endl; 
	c.show();
	d.show();
	cout << endl << endl;

	Var el2 = "Hello";
	el2.show();
	el2 = el2 + "2000text";
	el2.show();
	el2 = el2 + 500;
	el2.show();
	el2 = el2 + 700.897;
	el2.show();
	Var el7="";
	el7+=el2;
	cout << "+=Var test" << endl;
	el7.show();
	cout << "-=Var test" << endl;
	(el -= el4).show();
	(el2 -= 1000).show(); //nothing will happen here because flag is stringf

	Var el5(el1);
	if (el1 == el5) cout << "equal" << endl;
	Var el6 = 10000;
	if(el6==1000000) cout << "el 6 equal" << endl;
	else cout << "el6 different" << endl;
	if(el1=="15") cout << "el1 equal" << endl;

	if (el1 != el2) cout << "el1 and el2 are different" << endl;
	if(el1!="texttttt") cout << "el1 different" << endl;

	if (el7 > el1) cout << "el7 is larger" << endl;
	if (el4 < 2000) cout << "el4 is less" << endl;

	Var el22(el7);
	if (el7 >= el22) cout << "el7 is larger or equal" << endl;
	if (el2 >= el1) cout << "el2 is larger or equal" << endl;
	if (el4 <= 1000) cout << "el4 is less or equal" << endl;
	if (el4 <= 1500) cout << "el4 is less or equal" << endl;

	cout << "*=Var test" << endl;
	(el *= 1.5).show();
	Var el8 = 1000;
	(el8 *= 3).show();
	Var el9="Microsoft";
	Var el44 = "Microsoft";
	(el44 *= 5).show();
	string s1 = "Windows";
	(el9 *=s1).show();
	Var el88 = 2.5;
	(el9*=el88).show();
	cout << "/=Var test" << endl;
	(el /= 1.57).show();
	(el /= 4).show();
	(el8 /= el1).show();
	string s2 = "Windows";
	(el9 /2.5).show();
	Var el10="Microsoft";
	Var el11="Windows";
	(el10 /= el11).show();
	(el10 /= s2).show();

	Var vs[10];// можно благодаря конструктору по умолчанию

	Var aa = 10;
	Var bb = "Hello";
	Var cc = 7.8;

	//тесты на операторы int, double, string, чтобы было возможно прямое присваивание значений Var в переменную соответствующего типа
	int x = aa;
	cout << x << endl;
	double y = cc;
	cout << y << endl;
	string s;
	s = bb;
	cout << s << endl;
	s = aa;
	cout << s << endl;

	system("pause");
	return 0;
}