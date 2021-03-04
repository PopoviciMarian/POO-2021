#include "Math.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>

int Math::Add(int x, int y) {
	return x + y;
}
int Math::Add(int x, int y, int z) {
	return x + y + z;
}
int Math::Add(double x, double y) {
	return x + y;
}

int Math::Add(double x, double y, double z) {
	return int(x + y + z);
}
int Math::Mul(int x, int y) {
	return x * y;
}
int Math::Mul(int x, int y, int z) {
	return x * y * z;
}
int Math::Mul(double x, double y) {
	return x * y;
}
int Math::Mul(double x, double y, double z) {
	return x * y * z;
}
int Math::Add(int count, ...){
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}
char* Math::Add(const char* s1, const char* s2) {
	char* result = (char*)malloc(strlen(s1) + strlen(s2) + 1);
	if (!result) return nullptr;
	memcpy(result, s1, strlen(s1));
	memcpy(result + strlen(s1), s2, strlen(s2) + 1);
	return result;
}