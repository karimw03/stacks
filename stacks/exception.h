#ifndef exception_h
#define exception_h
#include <string>

class StackException {
public:
	std::string error;
	StackException(const std::string& err) : error(err) {}
};

#endif