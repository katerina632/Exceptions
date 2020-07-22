#pragma once
#include <iostream>
#include "Exceptions.h"

using namespace std;

template <typename T>
class Stack
{
private:

	T* data;
	int topIndex;
	int maxSize;

public:

	Stack()
	{
		data = nullptr;
		topIndex = -1;
		maxSize = 0;
	}

	Stack(int max)
	{
		if (max < 1)
			max = 1;
		maxSize = max;
		data = new T[maxSize];
		topIndex = -1;
	}

	~Stack()
	{
		delete[] data;
	}

	Stack(const Stack& st)
	{
		data = new T[st.topIndex + 1];
		throw IsAllocatedMemory();

		topIndex = st.topIndex;
		maxSize = st.maxSize;

		for (int i = 0; i < GetCount(); i++)
			data[i] = st.data[i];
	}


	Stack& operator=(const Stack& st)
	{
		if (this == &st)
			return *this;

		if (topIndex >= 0)
		{
			topIndex = -1;
			delete[] data;
		}

		data = new T[st.topIndex + 1];
		throw IsAllocatedMemory();

		topIndex = st.topIndex;
		maxSize = st.maxSize;

		for (int i = 0; i < GetCount(); i++)
			data[i] = st.data[i];

		return *this;
	}

	void Push(T item)
	{
		if (maxSize == 0) {

			T* temp = data;

			data = new T[GetCount() + 1];
			throw IsAllocatedMemory();

			topIndex++;

			for (int i = 0; i < topIndex; i++)
				data[i] = temp[i];

			data[topIndex] = item;

			if (topIndex >= 0)
				delete[] temp;

		}
		else if (!IsFull())
		{
			data[++topIndex] = item;

		}
		else throw OverFlowException("Stack is full!\n");


	}


	T Pop()
	{
		if (!IsEmpty())
			return data[topIndex--];

		throw IsEmptyException("Stack is empty!\n");
	}

	T Peek()
	{
		if (!IsEmpty())
			return data[topIndex];

		throw IsEmptyException("Stack is empty!\n");
	}


	const int GetCount()
	{
		return topIndex + 1;
	}

	bool IsEmpty() const {

		return topIndex == -1;
	}

	bool IsFull() const
	{
		return maxSize != 0 && topIndex == maxSize - 1;
	}

};





