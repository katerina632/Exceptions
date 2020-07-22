#pragma once
#include<stdexcept>
#include<iostream>
#include<string>
#include <new>

using namespace std;
class DivByZeroException :public exception {
public:
	DivByZeroException() :exception() {}
	const char* what()const override {
		return "Division by 0!";
	}
};

class RootOfNegativeNumberException :public exception {
public:
	RootOfNegativeNumberException() :exception() {}
	const char* what()const override {
		return "The root of a negative number!";
	}
};
class IsAllocatedMemory :public bad_alloc {
public:
	IsAllocatedMemory() :bad_alloc() {}
	const char* what() const override {
		return "Memory is not allocated!";
	}
};

class WorkWithFileException :public exception {
	string fileName;
public:
	WorkWithFileException(const char* message, string fileName) :fileName(fileName), exception(message) {}
	void Message()const {
		cout << "File name: " << fileName << endl;
		cout << what() << endl;
	}
};

class InvalidSizeException :public invalid_argument {
	int size;
public:
	InvalidSizeException(const char* message, int size) :invalid_argument(message), size(size) {}
	void Message()const {
		cout << what() << endl;
		cout << "Size = " << size << endl;
	}
};

class InvalidIndexException :public out_of_range {
	int index;
public:
	InvalidIndexException(const char* message, int index) :out_of_range(message), index(index) {}
	void Message()const {
		cout << what() << endl;
		cout << "Index: " << index << endl;
	}
};

class InvalidArgument :public invalid_argument {
public:
	InvalidArgument(const char* message) :invalid_argument(message) {}
};

class OverFlowException :public logic_error {
public:
	OverFlowException(const char* message) :logic_error(message) {}
};

class IsEmptyException :public exception {
public:
	IsEmptyException(const char* message) :exception(message) {}
};


