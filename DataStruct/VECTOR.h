#pragma once
#include <iostream>

using namespace std;

template <typename T>
class VECTOR
{
private:
	int size;
	int capacity;
	T * bufferPointer;

public :
	VECTOR()
	{
		size = 0;
		capacity = 0;
		bufferPointer = nullptr;
	}

	void PushBack(T data)
	{
		if (capacity == 0)
		{
			Resize(1);
		}
		else if(size >= capacity)
		{
			capacity = capacity * 2;

			Resize(capacity);
		}

		bufferPointer[size++] = data;
	}

	void Resize(int newSize)
	{
		// 1. capacity�� ���ο� size���� �����մϴ�.
		capacity = newSize;

		// 2. ���ο� ������ ������ �����ؼ� ���Ӱ� �������
		//    �޸� ������ ����Ű���� �����մϴ�.
		T* tempBuffer = new T[capacity];
		
		// 3. ���ο� �޸� ������ ���� �ʱ�ȭ�մϴ�.
		for (int i = 0; i < capacity; i++)
		{
			tempBuffer[i] = NULL;
		}

		// 4. ���� �迭�� �ִ� ���� �����ؼ� ���ο� �迭��
		//    �־��ݴϴ�.
		for (int i = 0; i < size; i++)
		{
			tempBuffer[i] = bufferPointer[i];
		}

		// 5. bufferPointer�� �޸� �ּҸ� �����մϴ�.
		if (bufferPointer != nullptr)
		{
			delete [] bufferPointer;
		}

		// [] ---->  [][]
		bufferPointer = tempBuffer;
	}

};