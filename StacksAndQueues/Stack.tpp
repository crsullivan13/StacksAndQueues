#include <iostream>
#include <stdexcept>

template<typename T>
Stack<T>::Stack()
{
	m_top = nullptr;
}

template<typename T>
void Stack<T>::push(T entry)
{
	Node<T>* temp = new Node<T>(entry);
	temp->setNext(m_top);
	m_top = temp;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	if(m_top == nullptr){
		return true;
	}

	return false;
}

template<typename T>
void Stack<T>::pop()
{
	if(!isEmpty()){
		Node<T>* temp = m_top;
		m_top = m_top->getNext();
		delete temp;
	} else {
		throw(std::runtime_error("Attempted to pop on an empty stack."));
	}
}

template<typename T>
Stack<T>::~Stack()
{
	while(!isEmpty()){
		pop();
	}
}

template<typename T>
T Stack<T>::peek() const
{
	if(!isEmpty()){
		return (m_top->getEntry());
	} else {
		throw(std::runtime_error("Attempted to peek an empty stack."));
	}
}