#include <iostream>

template <typename T> class vectorClass {
	T* arr;
	int capacity;
	int current;
public:

	vectorClass() {
		arr = new T[1];
		capacity = 1;
		current = 0;
	}

	void push_back(T varToPush) {
		if (current == capacity) {

			capacity = capacity << 1;

			T* temp = new T[capacity];
			for (int i = 0; i < capacity / 2; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
		arr[current] = varToPush;
		current++;
	}

	void pop_back() {
		arr[--current] = { 0 };
	}

	void print() {
		std::cout << "vector : \n";
		for (int i = 0; i < current; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}

	int getCapacity() {
		return capacity;
	}
	
	int getSize() {
		return current;
	}

	T get(int index) {
		return arr[index] ;
	}
};

int main() {
	vectorClass <int> vector;
	vector.push_back(10);
	vector.push_back(10);
	vector.push_back(10);
	vector.push_back(10);
	vector.push_back(10);
	vector.print();
	std::cout << std::endl << vector.getCapacity() << ' ' << vector.getSize();
	vector.pop_back();
	std::cout << std::endl << vector.getCapacity() << ' ' << vector.getSize() << "\n\n";


	vectorClass <std::string> strings;
	strings.push_back("hello");
	strings.push_back("hey");
	strings.push_back("privet");

	strings.print();
	std::cout << std::endl << strings.getCapacity() << ' ' << strings.getSize();
	strings.pop_back();
	std::cout << std::endl << strings.getCapacity() << ' ' << strings.getSize() << std::endl;
	strings.print();

	std::cout << strings.get(1) << "\n";
	std::cout << vector.get(3) << "\n";
}