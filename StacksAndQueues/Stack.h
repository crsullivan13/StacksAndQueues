#pragma once
#ifndef STACK_H
#define STACK_H
#include "Node.h"

template<typename T>
class Stack
{
private:
	Node<T>* m_top;


public:
	Stack<T>();

	~Stack();

	void push(T entry);

	void pop();

	T peek() const;

	bool isEmpty() const;




};
#include "Stack.tpp"
#endif