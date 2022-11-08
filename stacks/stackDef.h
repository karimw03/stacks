#ifndef stackDef_h
#define stackDef_h
#include "stack.h"
#include "stackNode.h"
#include <iostream>
using std::cout;
using std::endl;

template <class T>
Stack<T>::Stack() : topPtr(NULL) {}

template <class T>
bool Stack<T>::isEmpty() const
{
	return topPtr == NULL;
}

template <class T>
void Stack<T>::push(const T& newItem) {

	StackNode<T>* newPtr = new StackNode<T>;
	newPtr->item = newItem; 
	newPtr->next = topPtr; 
	topPtr = newPtr; 
}

template <class T>
void Stack<T>::pop() {
	if (isEmpty())
		throw StackException("StackException: stack empty on pop");
	else {
		StackNode<T>* tmp = topPtr;
		topPtr = topPtr->next;
		delete tmp;
	}
}

template <class T>
void Stack<T>::topAndPop(T& stackTop) {
	if (isEmpty())
		throw StackException("StackException: stack empty on topAndPop");
	else {
		stackTop = topPtr->item;
		StackNode<T>* tmp = topPtr;
		topPtr = topPtr->next; // update the stack top
		delete tmp;
	}
}

template <class T>
void Stack<T>::getTop(T& stackTop) const {
	if (isEmpty())
		throw StackException("StackException: stack empty on getTop");
	else
		stackTop = topPtr->item;
}

template <class T>
Stack<T>::~Stack() {
	
	while (!isEmpty())
		pop();
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) {
	if (this != &rhs) {
		if (!rhs.topPtr)
			topPtr = NULL;
		else {
			topPtr = new StackNode<T>;
			topPtr->item = rhs.topPtr->item;
			StackNode<T>* q = rhs.topPtr->next;
			StackNode<T>* p = topPtr;
			while (q) {
				p->next = new StackNode<T>;
				p->next->item = q->item;
				p = p->next;
				q = q->next;
			}
			p->next = NULL;
		}
	}
	return *this;
}

template <class T>
Stack<T>::Stack(const Stack& rhs) {
	*this = rhs; 
}

template <class T>
int Stack<T>::countElements() {
		int counter = 0;
		StackNode<T>* current = topPtr;
		while (current != NULL) {
			counter++;
			current = current->next;
		}
		return counter;
}

template<class T>
void Stack<T>::print() const {
	const StackNode<T>* p = topPtr;

	while (p) {
		cout << p->item << endl;
		p = p->next;
	}
}

template <class T>
void Stack<T>::makeEmpty() {
	while (!isEmpty())
		pop();
}

template <class T>
void Stack<T>:: reverse() {
	StackNode<T>* current = topPtr;
	StackNode<T>* previous = NULL;
	StackNode<T>* next = NULL;

	while (current) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	topPtr = previous;
}



#endif