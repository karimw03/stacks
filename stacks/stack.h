#ifndef stack_h
#define stack_h
#include "exception.h"
#include "stackNode.h"

template <class T>
class Stack {
public:
	Stack(); 
	
	Stack(const Stack& rhs); 
	
	~Stack(); 
	
	Stack& operator=(const Stack& rhs); 
	
	bool isEmpty() const;
	
	void push(const T& newItem);
	
	void pop();
	
	void topAndPop(T& stackTop);
	
	void getTop(T& stackTop) const;

	void print() const;

	void makeEmpty();
	
	int countElements();

	void reverse();

private:
	StackNode<T>* topPtr; 
};

#endif