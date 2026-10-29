#pragma once

class CircularQueue
{
private:
	char* data;
	int capacity;
	int count;
	int head;
	int tail;

public:
	CircularQueue(int capacity = 10);
	CircularQueue(const CircularQueue& other);
	~CircularQueue();

	CircularQueue& operator=(const CircularQueue& other);

	bool IsEmpty() const;
	bool IsFull() const;

	bool Push(char value);
	char Pop();
	char Peek() const;

	void Rotate();
	void Rotate(int steps);

	int GetCount() const;
	int GetCapacity() const;
	void Clear();
	void Print() const;
};
