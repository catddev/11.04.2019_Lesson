#include "Var.h"

int main() {

	Var el = 5.7;
	Var el1("15");
	Var el3 = "15";
	el3.show();

	double a = 100 + el;
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
	(el -= el4).show();

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

	system("pause");
	return 0;
}