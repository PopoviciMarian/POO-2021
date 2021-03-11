#include <iostream>
#include "Sort.h"
#include <cstring>
#include <vector>
#include <time.h>
#include <stdarg.h>
#pragma warning(disable:4996)

void Sort::Print() {
	Nod* aux = head;
	while (aux != nullptr) {
		std::cout << aux->info << " ";
		aux = aux->next;
	}
	std::cout << std::endl;
}

Sort::Sort(int n, int min, int max) {
	head = new Nod();
	Nod* aux = head; 
	n--;
	srand(time(NULL));
	aux ->info = min + rand() % (max - (min - 1));
	while (n){
		Nod* temp = new Nod();
		temp ->info = min + rand() % (max - (min - 1));
		aux->next = temp;
		aux = aux->next;
		n--;
	}
}

Sort::Sort(std::initializer_list<int> l) {
	const int* ptr = l.begin();
	head = new Nod(*ptr);
	Nod* aux = head;
	ptr++;
	for (; ptr != l.end(); ptr++) {
		Nod* temp = new Nod(*ptr);
		aux->next = temp;
		aux = temp;
	 }
	
}

Sort::Sort(int v[], int size) {
	head = new Nod(v[0]);
	Nod* aux = head;
	int index = 1;
	while (index < size){
		aux->next = new Nod(v[index]);
		aux = aux->next;
		index++;
	}
}

Sort::Sort(int count, ...) {
	head = new Nod();
	Nod* aux = head;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count - 1; i++) {
		aux->info = va_arg(args, int);
		aux->next = new Nod();
		aux = aux->next;
	}
	aux->info = va_arg(args, int);
	va_end(args);
}

Sort::Sort(char s[]) {
	char* toc = strtok(s, ",");
	//std::cout << toc;
	head = new Nod(atoi(toc));
	Nod* aux = head;
	toc = strtok(NULL, ",");
	while (toc != NULL){
		aux->next = new Nod(atoi(toc));
		aux = aux->next;
		toc = strtok(NULL, ",");
	}
}

int Sort::GetElementsCount() {
	Nod* aux = head;
	int count = 0;
	while (aux != nullptr)	{
		aux = aux->next;
		count++;
	}
	return count;
}

int Sort::GetElementFromIndex(int index) {
	if (index >= 0 && index < GetElementsCount()) {
		Nod* aux = head;
		while (index) {
			aux=aux->next;
			index--;
		}
		return aux->info;
	}
	std::cout << "\n!!! OUT OF LIST !!!\n";
	return -1;
}



void Sort::InsertSort(bool ascendent) {
	int* v = new int[GetElementsCount()];
	Nod* aux = head;
	int index = 0;
	while(aux != nullptr){
		v[index] = aux->info;
		aux = aux->next;
		index++;
	}

	for (int i = 0; i < GetElementsCount(); i++) {
		int temp = v[i];
		int j = i - 1;
		while (j >= 0 && ((v[j] > temp && ascendent) || (v[j] < temp && !ascendent))) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = temp;
	}
	
	aux = head;
	index = 0;
	while (aux != nullptr) {
		aux->info = v[index];
		aux = aux->next;
		index++;
	}
}

void Sort::BubbleSort(bool ascendent) {
	int* v = new int[GetElementsCount()];
	Nod* aux = head;
	int index = 0;
	while (aux != nullptr) {
		v[index] = aux->info;
		aux = aux->next;
		index++;
	}

	for (int i = 0; i < GetElementsCount()-1; i++) {
		for (int j = 0; j < GetElementsCount() - i - 1; j++) {
			if ((v[j] > v[j + 1] && ascendent) || (v[j] < v[j+1] && !ascendent)) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}

	aux = head;
	index = 0;
	while (aux != nullptr) {
		aux->info = v[index];
		aux = aux->next;
		index++;
	}
}


void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high, bool ascedent) {
	int pivot = arr[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++){ 
		if ((arr[j] < pivot && ascedent) || (arr[j] > pivot && !ascedent)){
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high, bool ascedent){
	if (low < high){
		int pi = partition(arr, low, high , ascedent);
		quickSort(arr, low, pi - 1, ascedent);
		quickSort(arr, pi + 1, high, ascedent);
	}
}

void Sort::QuickSort(bool ascendent) {
	int* v = new int[GetElementsCount()];
	Nod* aux = head;
	int index = 0;
	while (aux != nullptr) {
		v[index] = aux->info;
		aux = aux->next;
		index++;
	}

	quickSort(v, 0, GetElementsCount() - 1, ascendent);

	aux = head;
	index = 0;
	while (aux != nullptr) {
		aux->info = v[index];
		aux = aux->next;
		index++;
	}

}