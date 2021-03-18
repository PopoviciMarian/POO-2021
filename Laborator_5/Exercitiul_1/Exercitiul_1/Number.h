#include <iostream>
#include <string>

#pragma once
class Number{
	const char* value;
	int base;
	
public:
	Number(const char* value, int base); 
	Number(int val) : Number((std::to_string(val)).c_str(), 10) { };
	Number(const Number& n) { this->value = n.value, this->base = n.base; };
	~Number();
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); 
	int  GetBase(); 
	
	char operator [](int index);
	
	Number& operator = (int val);
	Number& operator = (const char* s);
	Number& operator = (Number num);

	friend Number operator + (Number n1, Number n2);
	friend Number operator - (Number n1, Number n2);
	friend Number operator * (Number n1, Number n2);
	friend Number operator / (Number n1, Number n2);
	friend Number operator % (Number n1, Number n2);

	friend void  operator += (Number& n1, Number n2);
	friend void  operator -= (Number& n1, Number n2);
	
	bool operator > (const Number& i);	
	bool operator < (const Number& i);
	bool operator >= (const Number& i);
	bool operator <= (const Number& i);
	bool operator == (const Number& i);
	
	Number& operator -- ();
	void operator -- (int value);
};