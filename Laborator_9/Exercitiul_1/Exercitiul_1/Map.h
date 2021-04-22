#pragma once
#include <iostream>

template<typename  T1, typename  T2>
class Map {
public:
	struct element {
		T1 key;
		T2 value;
		int index;
	}elements[100];
	unsigned int size = 0;
	
	T2& operator [](T1 t1)  {
		for (auto &ele : elements) {
			if (t1 == ele.key) {
				return ele.value;
			}
		}
		elements[size].index = size;
		elements[size].key = t1;
		return elements[size++].value;
	}

	void Set(T1 key_p, T2 value_p) {
		for (auto &ele : elements) {
			if (key_p == ele.key) {
				ele.value = value_p;
			}
		}
		elements[size].index = size;
		elements[size].key = key_p;
		elements[size++].value = value_p;
	}

	bool Get(const T1& key, T2& value) {
		for (auto &ele : elements) {
			if (key == ele.key) {
				value = ele.value;
				return true;
			}
		}
		return false;
	}

	unsigned int Count() {
		return size;
	}

	void Clear() {
		while (size){
			Delete(elements[0].key);
		}
	}

	bool Delete(T1 &key) {
		for (auto &ele : elements) {
			if (ele.key == key) {
				for (int j = ele.index; j < size - 1; j++) {
					elements[j].key = elements[j + 1].key;
					elements[j].value = elements[j + 1].value;
				}
				
				size--;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<T1, T2>& map) {
		for (auto ele : map.elements) {
			bool ok = true;
			for (auto ele2 : elements) {
				if (ele.key == ele2.key) {
					ok = false;
				}
			}
			if (ok) {
				return false;
			}
		}
		return true;
	}
	
	auto begin() {
		return &elements[0];
	};
	auto end() {
		return &elements[size];
	};
};