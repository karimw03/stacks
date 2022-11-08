#ifndef stackNode_h
#define stackNode_h

template <class T>
class StackNode{
public:
	StackNode(const T& e = T(), StackNode* n = NULL) : item(e), next(n) {}
	T item;
	StackNode* next;
};

#endif