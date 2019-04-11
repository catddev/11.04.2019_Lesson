#include "Var.h"

Var::Var()
{
	intV = 0;
	doubleV = 0;
	strV = ""; //как сделать пустую строку по умочанию?
}

Var::Var(int i)
{
	intf = true;
	doublef = false;//т.к если не прописать явно для остальных флажков, то они по умолчанию будут true
	stringf = false;
	this->intV = i;
	this->doubleV = i;
	this->strV = to_string(i); //функция to_string() переводит значение в строку
}

Var::Var(double d)
{
	doublef = true;
	intf = false;
	stringf = false;
	this->doubleV = d;
	this->intV = d;
	this->strV = to_string(d);
}

Var::Var(string s)
{
	stringf = true;
	doublef = false;
	intf = false;
	this->strV = s;
	this->intV = atoi(s.c_str()); // функция c_str() переводит string в char массив, т.к. atoi применим только к чар-массивам
	this->doubleV = atof(s.c_str()); //alfa_to_float
}

Var::Var(const char * s)
{
	stringf = true;
	doublef = false;
	intf = false;
	//stscpy_s(strv.c_str(), s);
	strV = string(s);
	this->intV = atoi(strV.c_str());
	this->doubleV = atof(strV.c_str());
}

//Var::operator int()
//{
//	return intV;
//}

Var::operator double()
{
	return doubleV;
}

Var Var::operator=(string s)
{
	stringf = true;
	doublef = false;
	intf = false;
	this->strV = s;
	this->intV = atoi(s.c_str());
	this->doubleV = atof(s.c_str());

	return (*this);
}

Var Var::operator+(Var obj) //чтобы выбирал тип по первому операнду: Var А+ Var В будет выбирать по типу A
{
	Var tmp(*this); //дается временный объект Var как точная копия Var
	if (tmp.intf)
		tmp.intV += obj.intV;
	else if (tmp.doublef)
		tmp.doubleV += obj.doubleV;
	else if (tmp.stringf)
		tmp.strV += obj.strV;

	return tmp; //возвращаем tmp, чтобы исходный объект не менять!
}

Var Var::operator+(int i)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV += i;
	else if (tmp.doublef)
		tmp.doubleV += i;
	else if (tmp.stringf)
		tmp.strV += to_string(i);

	return tmp;
}

Var Var::operator+(double d)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV += d;
	else if (tmp.doublef)
		tmp.doubleV += d;
	else if (tmp.stringf)
		tmp.strV += to_string(d);

	return tmp;
}

Var Var::operator+(string s)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV += atoi(s.c_str());
	else if (tmp.doublef)
		tmp.doubleV += atof(s.c_str());
	else if (tmp.stringf)
		tmp.strV += s;

	return tmp;
}
Var Var::operator+(const char* s)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV += atoi(s);
	else if (tmp.doublef)
		tmp.doubleV += atof(s);
	else if (tmp.stringf)
		tmp.strV += string(s);

	return tmp;
}
Var Var::operator+=(Var obj)
{
	if (intf)
		intV += obj.intV;
	else if (doublef)
		doubleV += obj.doubleV;
	else if (stringf)
		strV += obj.strV;

	return *this;
}

Var Var::operator+=(int i)
{
	return(*this + i);
}

Var Var::operator+=(double d)
{
	return(*this + d);
}

Var Var::operator+=(string s)
{
	return(*this + s);
}
Var Var::operator+=(const char* s)
{
	return(*this + s);
}
bool Var::operator==(Var obj)
{
	if (intf)
	{
		if (intV == obj.intV)
			return true;
	}
	else if (doublef)
	{
		if (doubleV == obj.doubleV)
			return true;
	}
	else if (stringf)
	{
		if (strV == obj.strV)
			return true;
	}
	else
		return false;
}
bool Var::operator==(int i)
{
	return (intV == i);
}
bool Var::operator==(double d)
{
	return (doubleV == d);
}
bool Var::operator==(string s)
{
	return  (strV == s);
}
bool Var::operator==(const char * s)
{
	return (strV == s);
}
bool Var::operator!=(Var obj)
{
	return(!*this==(obj)); //отрицаем оператор==
}
bool Var::operator!=(int i)
{
	return (intV != i);
}
bool Var::operator!=(double d)
{
	return (doubleV != d);
}
bool Var::operator!=(string s)
{
	return (strV != s);
}
bool Var::operator!=(const char * s)
{
	return (strV != s);
}
Var Var::operator-(Var obj)
{
	Var tmp(*this);
	if (tmp.intf)
		tmp.intV = abs(intV - obj.intV);
	else if (tmp.doublef)
		tmp.doubleV = abs(intV - obj.doubleV);
	/*else if (tmp.stringf)
		tmp.strV -= obj.strV;*/

	return tmp;
}
Var Var::operator-(int i)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV -= i;
	else if (tmp.doublef)
		tmp.doubleV -= i;
	/*else if (tmp.stringf)
		tmp.strV -= to_string(i);*/

	return tmp;
}
Var Var::operator-(double d)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV -= d;
	else if (tmp.doublef)
		tmp.doubleV -= d;
	/*else if (tmp.stringf)
		tmp.strV -= to_string(d);*/

	return tmp;
}
//Var Var::operator-(string s)
//{
//	
//}
//Var Var::operator-(const char * s)
//{
//	
//}
Var Var::operator-=(Var obj)
{
	if (intf)
		intV -= obj.intV;
	else if (doublef)
		doubleV -= obj.doubleV;
	/*else if (stringf)
		strV -= obj.strV;*/

	return *this;
}
Var Var::operator-=(int i)
{
	return(*this - i);
}
Var Var::operator-=(double d)
{
	return(*this - d);
}
Var Var::operator*(Var obj)
{
	Var tmp(*this);
	if (tmp.intf)
		tmp.intV *= obj.intV;
	else if (tmp.doublef)
		tmp.doubleV *= obj.doubleV;
	else if (tmp.stringf)
		//tmp.strV.operator*=(obj.strV); //см будет ли вызывать перегружэенный оператор

	return tmp;
}
Var Var::operator*(int i)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV *= i;
	else if (tmp.doublef)
		tmp.doubleV *= i;
	/*else if (tmp.stringf)
		tmp.strV *= to_string(i);*/

	return tmp;
}
Var Var::operator*(double d)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV *= d;
	else if (tmp.doublef)
		tmp.doubleV *= d;
	/*else if (tmp.stringf)
		tmp.strV *= to_string(d);*/

	return tmp;
}
Var Var::operator*(string s)
{
	Var tmp(*this);
	//?
	return tmp;
}
Var Var::operator*(const char * s)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV *= atoi(s);
	else if (tmp.doublef)
		tmp.doubleV *= atof(s);
	else if (tmp.stringf)
	{
		int k = 0;
		for (int i = 0; i < strlen(s); i++)
		{
			for (int j = 0; j < strlen(*this->s); j++)//?
			{
				if (s[i] != s[j])
				{
					swap(s[j], s[k]);
					k++;
					break;
				}
			}
		}
		for (int i = 0; i < k; i++)
			tmp[i] = s[i];

	}
	return tmp;
}
//Var Var::operator-=(string s)
//{
//	
//}
//Var Var::operator-=(const char * s)
//{
//	
//}
bool Var::operator>(Var obj)
{
	if (intf)
	{
		if (intV > obj.intV)
			return true;
	}
	else if (doublef)
	{
		if (doubleV > obj.doubleV)
			return true;
	}
	else if (stringf)
	{
		if (strV > obj.strV)
			return true;
	}
	else
		return false;
}
bool Var::operator>(int i)
{
	return (intV > i);
}
bool Var::operator>(double d)
{
	return (doubleV > d);
}
bool Var::operator>(string s)
{
	return  (strV > s);
}
bool Var::operator>(const char * s)
{
	return  (strV > s);
}
bool Var::operator<(Var obj)
{
	if (intf)
	{
		if (intV < obj.intV)
			return true;
	}
	else if (doublef)
	{
		if (doubleV < obj.doubleV)
			return true;
	}
	else if (stringf)
	{
		if (strV < obj.strV)
			return true;
	}
	else
		return false;
}
bool Var::operator<(int i)
{
	return (intV < i);
}
bool Var::operator<(double d)
{
	return (doubleV < d);
}
bool Var::operator<(string s)
{
	return  (strV < s);
}
bool Var::operator<(const char * s)
{
	return  (strV < s);
}
void Var::show()
{
	if (intf)
		cout << intV << endl;
	else if (doublef)
		cout << doubleV << endl;
	else if (stringf)
		cout << strV << endl;
}
