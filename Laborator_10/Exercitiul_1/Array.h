#pragma once
#include <iostream>
#include <exception>
using namespace std;

class exceptie1 : public exception{
	virtual const char* what() const throw(){
		return "Indexul este inafara domeniului!";
	}
};

class Compare{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class Array{
private:
	T** List; 
	int Capacity; 
	int Size;
	exceptie1 index_out_of_bounds;
public:

	Array() {
		Capacity = 0;
		Size = 0;
	}// Lista nu e alocata, Capacity si Size = 0

	~Array() {
		for (int i = 0; i < Size; i++) {
			delete[] List[i];
		}
	}// destructor

	Array(int capacity) {
		Capacity = capacity;
		Size = 0;
		List = new T * [Capacity];
		for (int i = 0; i < Capacity; i++) {
			List[i] = new T;
		}
	}// Lista e alocata cu 'capacity' elemente

	Array(const Array<T>& otherArray) {
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < Size; i++) {
			List[i] = new T(*otherArray.List[i]);
		}
	}

	T& operator[] (int index) {
		try {

			if (index < 0 || index >= Size) {
				throw index_out_of_bounds;
			}
			return *List[index];
		}catch (exception& e){
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	const Array<T>& operator+=(const T& newElem) {
		List[Size++] = new T(newElem);
		return *this;
	}


	const Array<T>& Insert(int index, const T& newElem) {
		try {

			if (index < 0 || index >= Size) {
				throw index_out_of_bounds;
			}
			for (int i = Size; i > index; i--) {
				*List[i] = *List[i - 1];
			}
			*List[index] = newElem;
			Size++;
			return *this;
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	const Array<T>& Insert(int index, const Array<T> otherArray) {
		try {
			if (index < 0 || index >= Size) {
				throw index_out_of_bounds;
			}
			for (int i = otherArray.Size - 1; i >= 0; i--) {
				Insert(index, otherArray.List[i][0]);
			}
			return *this;
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	const Array<T>& Delete(int index) {
		try {

			if (index < 0 || index >= Size) {
				throw index_out_of_bounds;
			}
			for (int i = index; i < Size - 1; i++) {
				*List[i] = *List[i + 1];
			}
			Size--;
			return *this;
		}
		catch (exception& e) {
			cout << "Exceptie: " << e.what() << endl;
		}
	}

	bool operator=(const Array<T>& otherArray) {
		if (Size != otherArray.Size) {
			return false;
		}
		for (int i = 0; i < Size; i++) {
			if (*List[i] != *otherArray.List[i]) {
				return false;
			}
		}
		return true;
	}

	void Sort() {
		for (int i = 0; i < Size - 1; i++) {
			for (int j = 0; j < Size - i - 1; j++) {
				if (*List[j] > *List[j + 1]) {
					T temp = *List[j];
					*List[j] = *List[j + 1];
					*List[j + 1] = temp;
				}
			}
		}
	}

	void Sort(int(*compare)(const T&, const T&)) {
		for (int i = 0; i < Size - 1; i++) {
			for (int j = 0; j < Size - i - 1; j++) {
				if (compare(*List[j], *List[j + 1])) {
					T temp = *List[j];
					*List[j] = *List[j + 1];
					*List[j + 1] = temp;
				}
			}
		}
	}

	void Sort(Compare* comparator) {
		for (int i = 0; i < Size - 1; i++) {
			for (int j = 0; j < Size - i - 1; j++) {
				if (comparator->CompareElements(*List[j], *List[j + 1])) {
					T temp = *List[j];
					*List[j] = *List[j + 1];
					*List[j + 1] = temp;
				}
			}
		}
	}

	int BinarySearch(const T& elem) {
		Array<T> copy(*this);
		copy.Sort();
		int left = 0;
		int right = Size - 1;
		while (left <= right){
			int mid = (left + right) / 2; 
			if (*copy.List[mid] == elem) {
				return mid;
			}
			if (*copy.List[mid] < elem) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
			
		}
		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		Array<T> copy(*this);
		copy.Sort(compare);
		int left = 0;
		int right = Size - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (compare (*copy.List[mid], elem)) {
				return mid;
			}
			if (*copy.List[mid] < elem) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator) {
		Array<T> copy(*this);
		copy.Sort(comparator);
		int left = 0;
		int right = Size - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (comparator->CompareElements(*copy.List[mid], elem)) {
				return mid;
			}
			if (*copy.List[mid] < elem) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return -1;
	}

	int Find(const T& elem) {
		for (int i = 0; i < Size; i++) {
			if (*List[i] == elem) {
				return i;
			}
		}
		return -1;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&)){
		for (int i = 0; i < Size; i++) {
			if (compare (*List[i], elem)) {
				return i;
			}
		}
		return -1;
	}

	int Find(const T& elem, Compare* comparator) {
		for (int i = 0; i < Size; i++) {
			if (comparator->CompareElements(*List[i], elem)) {
				return i;
			}
		}
		return -1;
	}

	int GetSize() {
		return Size;
	}

	int GetCapacity() {
		return Capacity; 
	}
};
