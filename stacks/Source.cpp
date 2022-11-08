#include "stack.h"
#include "stackNode.h"
#include "exception.h"
#include "stackDef.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	Stack<int> s;
	for (int i = 0; i < 10; i++)
		s.push(i);
	
	Stack<int> s2 = s; 
	cout << "The size of s2 is: " << s2.countElements() << endl;
	
	cout << "Printing s2 with print func: " << endl;
	s2.print();
	
	Stack<int> test;
	test = s2;
	cout << "Printing assigned stack: " << endl;
	test.print();
	
	cout << "Printing s:" << endl;
	while (!s.isEmpty()) {
		int value;
		s.topAndPop(value);
		cout << value << endl;
	}
	
	s2.reverse();
	cout << "Printing reversed stack: " << endl;
	s2.print();

	s2.makeEmpty();
	cout << "printing emptied stack: " << endl;
	s2.print();
}