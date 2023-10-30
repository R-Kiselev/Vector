#include <iostream>
#include <string>

template <typename T> class vector {
private :
	T* arr;
	int capacity;
	int size;

	// creates a new array if size equals capacity
	// the capacity of the new array is 2 times greater
	void checkSize() {
		if (size >= capacity) {

			capacity = capacity << 1;

			T* temp = new T[capacity];
			for (int i = 0; i < capacity / 2; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
	}

public:
	vector(int capacity = 4) {
		this->capacity = capacity;
		size = 0;
		arr = new T[capacity];
	}

	~vector() {
		delete[] arr;
		arr = nullptr;
	}

	void push_back(T value) {
		this->checkSize();
		arr[size] = value;
		size++;
	}

	void insert(int index, T value) {
		size++;
		this->checkSize(); 
		//10 20 30 40			  size = 4, capacity = 4
		//10 20 30 40 .. .. .. .. size = 5, capacity = 8
		//10 50 20 30 40
		for (int i = index; i < size; i++) {
			arr[size - i] = arr[size - i - 1];
		}
		arr[index] = value;
	}

	void pop_back() {
		arr[size] = { 0 };
		size--;
	}

	void print() {
		std::cout << "vector : \n";
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}

	int getCapacity() {
		return capacity;
	}
	
	int getSize() {
		return size;
	}

	T get(int index) {
		if (index > size) {
			throw std::string{ "out_of_range" };
		}
		return arr[index] ;
	}
};

int main() {
	setlocale(LC_ALL, ".1251");

	vector <int> vector_name(2);
	vector_name.push_back(10);
	vector_name.push_back(20);
	vector_name.push_back(30);
	vector_name.push_back(40);
	vector_name.print();

	std::cout << vector_name.getCapacity() << ' ' << vector_name.getSize() << "\n";
	vector_name.insert(1, 50);
	std::cout << vector_name.getCapacity() << ' ' << vector_name.getSize() << "\n";

	vector_name.print();
	
	try {
		std::cout << "Value of 1 element : " << vector_name.get(1) << "\n";
	}
	catch (std::string& error_message) {
		std::cout << error_message << "\n";
	}
	std::cout << "\n";
	// for strings 

	vector <std::string> strings;
	strings.push_back("привет");
	strings.push_back("hey");
	strings.push_back("privet");

	strings.print();
	std::cout << strings.getCapacity() << ' ' << strings.getSize() << "\n";
	strings.pop_back();
	std::cout << strings.getCapacity() << ' ' << strings.getSize() << "\n";
	strings.print();

	std::cout << "Value of 1 element : " << strings.get(1) << "\n";
}


/*
	class vector <std::string> strings;
	strings.push_back("привет");
	strings.push_back("hey");
	strings.push_back("privet");

	strings.print();
	std::cout << std::endl << strings.getCapacity() << ' ' << strings.getSize();
	strings.pop_back();
	std::cout << std::endl << strings.getCapacity() << ' ' << strings.getSize() << std::endl;
	strings.print();

	std::cout << strings.get(1) << "\n";
	std::cout << vector.get(3) << "\n";







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
*/