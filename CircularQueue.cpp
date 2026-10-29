#include "CircularQueue.h"
#include <iostream>

using namespace std;

CircularQueue::CircularQueue(int capacity)
{
	this->capacity = (capacity > 0 ? capacity : 10);
	this->data = new char[this->capacity];
	this->count = 0;
	this->head = 0;
	this->tail = 0;
}

CircularQueue::CircularQueue(const CircularQueue& other)
{
	this->capacity = other.capacity;
	this->count = other.count;
	this->head = other.head;
	this->tail = other.tail;

	this->data = new char[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->data[i] = other.data[i];
	}
}

CircularQueue::~CircularQueue()
{
	delete[] this->data;
}

CircularQueue& CircularQueue::operator=(const CircularQueue& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] this->data;

	this->capacity = other.capacity;
	this->count = other.count;
	this->head = other.head;
	this->tail = other.tail;

	this->data = new char[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->data[i] = other.data[i];
	}

	return *this;
}

bool CircularQueue::IsEmpty() const
{
	return this->count == 0;
}

bool CircularQueue::IsFull() const
{
	return this->count == this->capacity;
}

bool CircularQueue::Push(char value)
{
	if (this->IsFull())
	{
		return false;
	}

	this->data[this->tail] = value;
	this->tail = (this->tail + 1) % this->capacity;
	this->count++;
	return true;
}

char CircularQueue::Pop()
{
	if (this->IsEmpty())
	{
		return '\0';
	}

	char value = this->data[this->head];
	this->head = (this->head + 1) % this->capacity;
	this->count--;
	return value;
}

char CircularQueue::Peek() const
{
	if (this->IsEmpty())
	{
		return '\0';
	}

	return this->data[this->head];
}

void CircularQueue::Rotate()
{
	if (this->IsEmpty())
	{
		return;
	}

	char value = this->Pop();
	this->Push(value);
}

void CircularQueue::Rotate(int steps)
{
	for (int i = 0; i < steps; i++)
	{
		this->Rotate();
	}
}

int CircularQueue::GetCount() const
{
	return this->count;
}

int CircularQueue::GetCapacity() const
{
	return this->capacity;
}

void CircularQueue::Clear()
{
	this->count = 0;
	this->head = 0;
	this->tail = 0;
}

void CircularQueue::Print() const
{
	if (this->IsEmpty())
	{
		cout << "[ Черга порожня ]" << endl;
		return;
	}

	cout << "[ ";
	for (int i = 0; i < this->count; i++)
	{
		int index = (this->head + i) % this->capacity;
		cout << this->data[index] << " ";
	}
	cout << "]" << endl;
}
