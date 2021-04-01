#pragma once
template <class T>
class Vector{
	T* List;
	int count = 0;
	//int size;
	
public:
	
	Vector(int size) {
		List = new T  [size];
	}
	void push(T value) { List[count++] = value; };
	T& pop() { 
		if (count != 0) {
			return List[--count];
		}

	}
	void remove(int index) {
		if (index >= 0 && index < count)
			for (int i = index; i < count - 1; i++) {
				List[i] = List[i + 1];
			}
		count--;
	}

	void print() {
		for (int i = 0; i < count; i++) {
			std::cout << List[i] << " ";
		}
		std::cout << std::endl;
	}

	void insert(T val, int index) {
		for (int i = count; i > index; i--) {
			List[i] = List[i - 1];
		}
		List[index] = val;
		count++;
	}
	int count_ele() {
		return count;
	}

	const T& get(int index) {
		if (index >= 0 && index < count) {
			return List[index];
		}
	}

	void set(T obj, int index) {
		if (index > 0 && index < count) {
			List[index] = obj;
		}
	}

	typedef bool(*CompareCallBack)(const T& t1, const T& t2);
	void sort(CompareCallBack cmp = nullptr) {
		if (cmp) {
			for (int i = 0; i < count - 1; i++) {
				for (int j = 0; j < count - i - 1; j++) {
					if (cmp(List[j], List[j + 1])) {
						T temp = List[j];
						List[j] = List[j + 1];
						List[j + 1] = temp;
					}
				}
			}
		}
		else{
			for (int i = 0; i < count - 1; i++) {
				for (int j = 0; j < count - i - 1; j++) {
					if (List[j] <List[j + 1]) {
						T temp = List[j];
						List[j] = List[j + 1];
						List[j + 1] = temp;
					}
				}
			}
		}
	}

	int firstIndexOf(const T& obj, CompareCallBack cmp = nullptr) {
		if (cmp) {
			for (int i = 0; i < count; i++) {
				if (cmp(obj, List[i])) {
					return i;
				}
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (obj == List[i]) {
					return i;
				}
			}
		}
	}

};


