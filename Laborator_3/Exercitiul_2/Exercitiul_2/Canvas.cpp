#include "Canvas.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Canvas::Canvas(int width, int height) {
	this->width = width;
	this->height = height;
	mt = (char**)malloc(height * sizeof(char*));
	for (int i = 0; i < height; i++) {
		mt[i] = (char*)malloc(width * sizeof(char));
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			mt[i][j] = 'a';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	int d = ray-1;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (((x - j) * (x - j) + (y - i) * (y - i)) - ray * ray <= d && ((x - j) * (x - j) + (y - i) * (y - i)) - ray * ray >= -d) {
				mt[i][j] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (sqrt((x - j) * (x - j) + (y - i) * (y - i)) <= ray) {
				mt[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	DrawLine(left, top, right, top, ch);
	DrawLine(left, bottom, right, bottom, ch);
	DrawLine(left, top, left, bottom, ch);
	DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = std::min(top, bottom); i <= std::max(top, bottom); i++) {
		DrawLine(left, i, right, i, ch);
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	mt[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch){
	int dx = abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int err = dx + dy;  
	while (true) {  
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::Print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << (char)mt[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			mt[i][j] = 32;
		}
	}
}

