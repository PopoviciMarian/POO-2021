#include "Number.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

Number::Number(const char* value, int base) {
	this->value = _strdup(value);
	this->base = base;
}

Number::~Number() {
}

char Number::operator [](int index) {
   return value[index];
}

void Number::Print() {
	std::cout << value << std::endl;
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int toDeci(const char* str, int base) {
    int len = strlen(str);
    int power = 1;
    int num = 0;
    int i;
    for (i = len - 1; i >= 0; i--) {

        if (val(str[i]) >= base) {
            printf("Invalid Number");
            return -1;
        }

        num += val(str[i]) * power;
        power = power * base;
    }

    return num;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void strev(char* str){
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;
    while (inputNum > 0){
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
    strev(res);
    return res;
}

void Number::SwitchBase(int newBase) {
    char res[100];
    value = _strdup(fromDeci(res, newBase, toDeci(value, base)));
    base = newBase;
}

int Number::GetDigitsCount() {
    return strlen(value);
}

int Number::GetBase() {
    return base;
}


Number& Number::operator = (int val) {
    char buf[100];
    value = _strdup(fromDeci(buf, 2, val));
    base = 2;
    return (*this);
}

Number& Number::operator = (const char *s) {
    value = _strdup(s);
    base = 10;
    return (*this);
}

Number& Number::operator = (Number num) {
    value = num.value;
    base = num.base;
    return (*this);
}

Number operator+(Number n1, Number n2) {
    int maxBase = std::max(n1.base, n2.base);
    n2.SwitchBase(10);
    n1.SwitchBase(10);
    int result_int = atoi(n1.value) + atoi(n2.value);
    char buf[100];
    itoa(result_int, buf, 10);

    Number res(buf, 10);
    res.SwitchBase(maxBase);
    return res;
}

Number operator-(Number n1, Number n2) {
    int maxBase = std::max(n1.base, n2.base);
    n2.SwitchBase(10);
    n1.SwitchBase(10);
    int result_int = atoi(n1.value) - atoi(n2.value);
    char buf[100];
    itoa(result_int, buf, 10);

    Number res(buf, 10);
    res.SwitchBase(maxBase);
    return res;
}

Number operator*(Number n1, Number n2) {
    int maxBase = std::max(n1.base, n2.base);
    n2.SwitchBase(10);
    n1.SwitchBase(10);
    int result_int = atoi(n1.value) * atoi(n2.value);
    char buf[100];
    itoa(result_int, buf, 10);

    Number res(buf, 10);
    res.SwitchBase(maxBase);
    return res;
}

Number operator/(Number n1, Number n2) {
    int maxBase = std::max(n1.base, n2.base);
    n2.SwitchBase(10);
    n1.SwitchBase(10);
    int result_int = atoi(n1.value) / atoi(n2.value);
    char buf[100];
    itoa(result_int, buf, 10);

    Number res(buf, 10);
    res.SwitchBase(maxBase);
    return res;
}

Number operator%(Number n1, Number n2) {
    int maxBase = std::max(n1.base, n2.base);
    n2.SwitchBase(10);
    n1.SwitchBase(10);
    int result_int = atoi(n1.value) % atoi(n2.value);
    char buf[100];
    itoa(result_int, buf, 10);

    Number res(buf, 10);
    res.SwitchBase(maxBase);
    return res;
}



void operator += (Number& n1, Number n2) {
    n1 = (n1 + n2);
}

void operator -= (Number& n1, Number n2) {
    n1 = (n1 - n2);
}


bool Number::operator > (const Number& i) {
    int n1  = toDeci(value, base);
    int n2 = toDeci(i.value, i.base);
    return (n1 > n2);
}

bool Number::operator < (const Number& i) {
    int n1 = toDeci(value, base);
    int n2 = toDeci(i.value, i.base);
    return (n1 < n2);
}

bool Number::operator >= (const Number& i) {
    int n1 = toDeci(value, base);
    int n2 = toDeci(i.value, i.base);
    return (n1 >= n2);
}

bool Number::operator <= (const Number& i) {
    int n1 = toDeci(value, base);
    int n2 = toDeci(i.value, i.base);
    return (n1 <= n2);
}

bool Number::operator == (const Number& i) {
    int n1 = toDeci(value, base);
    int n2 = toDeci(i.value, i.base);
    return (n1 == n2);
}

Number& Number::operator-- () {
    value = _strdup(value + 1);
    return (*this);
}

void Number::operator--(int) {
    char *s = new char[strlen(value)-1];
    memcpy(s, value, strlen(value) - 1);
    memcpy(s + strlen(value) - 1, "\0", 1);
    value = _strdup(s);
}