#include "Var.h"

Var::Var() 
{
	intV = 0;
	doubleV = 0;
	strV = ""; //пустую строку по умочанию
	intf = true;
	doubleV = false;
	stringf = false;
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

Var::operator int() const
{
	return intV;
}

Var::operator double() const
{
	return doubleV;
}

Var::operator string() const
{
	return strV;
}

Var Var::operator=(string s)
{
	stringf = true;
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
	return(*this = *this + (obj));
}

Var Var::operator+=(int i)
{
	*this = *this + (i);

	return *this;
}

Var Var::operator+=(double d)
{
	*this = *this + (d);

	return *this;
}

Var Var::operator+=(string s)
{
	*this = *this + (s);

	return *this;
}
Var Var::operator+=(const char* s)
{
	*this = *this + (s);

	return *this;
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
	return (strV == string(s));//
}
bool Var::operator!=(Var obj)
{
	return(!(*this==(obj))); //отрицаем оператор==
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
	return (strV != string(s));
}
Var Var::operator-(Var obj)
{
	Var tmp(*this);
	if (tmp.intf)
		tmp.intV = intV - obj.intV;
	else if (tmp.doublef)
		tmp.doubleV = intV - obj.doubleV;
	else if (tmp.stringf)
	{ }

	return tmp;
}
Var Var::operator-(int i)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV -= i;
	else if (tmp.doublef)
		tmp.doubleV -= i;
	else if (tmp.stringf)
	{ }

	return tmp;
}
Var Var::operator-(double d)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV -= d;
	else if (tmp.doublef)
		tmp.doubleV -= d;
	else if (tmp.stringf)
	{ }

	return tmp;
}
Var Var::operator-(string s)
{
	Var tmp(*this);
	if (tmp.intf)
		tmp.intV -= atoi(s.c_str());
	else if (tmp.doublef)
		tmp.doubleV -= atof(s.c_str());
	else if (tmp.stringf)
	{
	}

	return tmp;
}
Var Var::operator-(const char * s)
{
	Var tmp(*this);
	if (tmp.intf)
		tmp.intV -= atoi(s);
	else if (tmp.doublef)
		tmp.doubleV -= atof(s);
	else if (tmp.stringf)
	{
	}

	return tmp;
}
Var Var::operator-=(Var obj)
{
	*this = this->operator-(obj); //!!!!!!!!!! через указатель вызываем другой метод класса this->operator или(*this).operator, но стрелка быстрее
	return *this;
}
Var Var::operator-=(int i)
{
	*this = this->operator-(i);
	return *this;
}
Var Var::operator-=(double d)
{
	*this = this->operator-(d);
	return *this;
}

Var Var::operator*(Var obj)
{
	Var tmp(*this);
	if (tmp.intf)
		tmp.intV *= obj.intV;
	else if (tmp.doublef)
		tmp.doubleV *= obj.doubleV;
	else if (tmp.stringf)
	{
		if (obj.intf)
		{
			string s = tmp.strV;
			for (int i = 0; i < obj.intV - 1; i++) //-1 потому что один раз уже скопировали tmp.strV в string, или если string s пустое, то в цикле просто i<obj.intV
				tmp.strV += s;
		}
		else if (obj.doublef)
		{
			string s = tmp.strV;
			for (int i = 0; i < int(obj.doubleV) - 1; i++)// into intf
				tmp.strV += s;
		}
		else
			tmp.strV = strMult(tmp.strV, obj.strV);
	}
	return tmp;
}
Var Var::operator*(int i)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV *= i;
	else if (tmp.doublef)
		tmp.doubleV *= i;
	else if (tmp.stringf) //сами придумали правило
	{
		string s = tmp.strV;
		
		for (int j = 0; j < i - 1; j++)
			tmp.strV += s;
	}

	return tmp;
}
Var Var::operator*(double d)
{
	Var tmp(*this);

	if (tmp.intf)
		tmp.intV *= d;
	else if (tmp.doublef)
		tmp.doubleV *= d;
	else if (tmp.stringf)
	{
		string s = tmp.strV;
		for (int j = 0; j < d - 1; j++)
			tmp.strV += s;
	}

	return tmp;
}

Var Var::operator*(string s)
{
	Var tmp(*this);
	if (intf)
		tmp.intV *= atoi(s.c_str());
	else if (doublef)
		tmp.intV *= atof(s.c_str());
	else if(stringf)
		tmp.strV = strMult(tmp.strV, s);
	return tmp;
}
Var Var::operator*(const char * s)
{
	Var tmp(*this);
	if (intf)
		tmp.intV *= atoi(s);
	else if (intf)
		tmp.intV *= atof(s);
	else
		tmp.strV = strMult(tmp.strV, string(s));
	//if (tmp.intf)
	//	tmp.intV *= atoi(s);
	//else if (tmp.doublef)
	//	tmp.doubleV *= atof(s);
	//else if (tmp.stringf)
	//{
	//	int k = 0;
	//	for (int i = 0; i < strlen(s); i++)
	//	{
	//		for (int j = 0; j < strlen(strV.c_str()); j++)// сначала переведем в чар массив, чтобы определить длину
	//		{
	//			if (s[i] == s[j])
	//			{
	//				swap(s[j], s[k]);
	//				k++;
	//				if (j <= k) k--; //j-1?? and j--
	//				break;
	//			}
	//		}
	//	}
	//	for (int i = 0; i < k; i++)
	//	{
	//		tmp.strV.c_str[i] = s[i]; //???
	//	}
	//}
	return tmp;
}
Var Var::operator/(Var obj)
{
	Var tmp(*this);
	if (tmp.intf)
	{
		tmp.doubleV = double(tmp.intV) / obj.intV;// обязательно сохранять дробную часть, даже при флажке intf, потому переводим в double
		tmp.intf = false;
		tmp.doubleV = true;
		//tmp.intV /= obj.intV;
	}
	else if (tmp.doublef)
		tmp.doubleV /= obj.doubleV;
	else if (tmp.stringf)
	{
		if (obj.intf) {
			tmp.strV = tmp.strV.substr(0, tmp.strV.size() / obj.intV);//substr(pos, n) возвращает подстроку с позиции Pos длиной n символов
		}
		tmp.strV = strDiv(tmp.strV, obj.strV);
	}
	return tmp;
}
Var Var::operator/(int i)
{
	Var tmp(*this);

	if (tmp.intf)
	{
		tmp.doubleV = double(tmp.intV) / i;
		tmp.intf = false;
		tmp.doubleV = true;
	}
	else if (tmp.doublef)
		tmp.doubleV /= i;
	else if (tmp.stringf) //сами придумали правило
	{
		string s;

		for (int j = 0; j < strV.size() / i; j++) //or j < strlen(strV.c_str())/i
			s +=strV[j];

		tmp.strV = s;
	}
	return tmp;
}
Var Var::operator/(double d)
{
	Var tmp(*this);

	if (tmp.intf)
	{
		tmp.doubleV = double(tmp.intV) / d;
		tmp.intf = false;
		tmp.doubleV = true;
	}
	else if (tmp.doublef)
		tmp.doubleV /= d;
	else if (tmp.stringf) //сами придумали правило
	{
		string s;
		
		for (int j = 0; j < int(strV.size()/ d); j++)
			s += strV[j];

		tmp.strV = s;
	}

	return tmp;
}
Var Var::operator/(string s)
{
	Var tmp(*this);
	if (intf)
		tmp.intV /= double(atoi(s.c_str()));
	else if (doublef)
		tmp.intV /= atof(s.c_str());
	else
		tmp.strV = strDiv(tmp.strV, s);
	return tmp;
}
Var Var::operator/(const char * s)
{
	Var tmp(*this);
	if (intf)
		tmp.intV /= double(atoi(s));
	else if (doublef)
		tmp.intV /= atof(s);
	else
	tmp.strV = strDiv(tmp.strV, string(s));

	return tmp;
}
Var Var::operator*=(Var obj)
{
	*this = *this*obj;
	return *this;
}
Var Var::operator*=(int i)
{
	*this = *this*(i);
	return *this;
}
Var Var::operator*=(double d)
{
	*this = *this*(d);
	return *this;
}
Var Var::operator*=(string s)
{
	*this=*this*(s);
	return *this;
}
Var Var::operator*=(const char * s)
{
	*this=*this*(s);
	return *this;
}
Var Var::operator/=(Var obj)
{
	*this = *this/(obj);
	return *this;
}
Var Var::operator/=(int i)
{
	*this = *this/(i);
	return *this;
}
Var Var::operator/=(double d)
{
	*this = *this/(d);
	return *this;
}
Var Var::operator/=(string s)
{
	*this = *this /(s);
	return *this;
}
Var Var::operator/=(const char * s)
{
	*this=*this/(s);
	return *this;
}
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
	return  (strV > string(s));
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
	return  (strV < string(s));
}
bool Var::operator>=(Var obj)
{
	if (intf)
	{
		if (intV >= obj.intV)
			return true;
	}
	else if (doublef)
	{
		if (doubleV >= obj.doubleV)
			return true;
	}
	else if (stringf)
	{
		if (strV >= obj.strV)
			return true;
	}

	return false;
}
bool Var::operator>=(int i)
{
	return (intV >= i);
}
bool Var::operator>=(double d)
{
	return (doubleV >= d);
}
bool Var::operator>=(string s)
{
	return  (strV >= s);
}
bool Var::operator>=(const char * s)
{
	return  (strV >= string(s));
}
bool Var::operator<=(Var obj)
{
	if (intf)
	{
		if (intV <= obj.intV)
			return true;
	}
	else if (doublef)
	{
		if (doubleV <= obj.doubleV)
			return true;
	}
	else if (stringf)
	{
		if (strV <= obj.strV)
			return true;
	}

	return false;
}
bool Var::operator<=(int i)
{
	return (intV <= i);
}
bool Var::operator<=(double d)
{
	return (doubleV <= d);
}
bool Var::operator<=(string s)
{
	return  (strV <= s);
}
bool Var::operator<=(const char * s)
{
	return  (strV <= string(s));
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

string strMult(string s1, string s2)
{
	string s;
	bool f;
	for (int i = 0; i < s1.size(); i++)
	{
		f = false;
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				f = true;
				break;
			}
		}
		if (f == true)
			s += s1[i];
	}
	return s;
}

string strDiv(string s1, string s2)
{
	string s;
	bool f;
	for (int i = 0; i < s1.size(); i++)
	{
		f = false;
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				f = true;
				break;
			}
		}
		if (f == false)
			s += s1[i];
	}
	return s;
}
