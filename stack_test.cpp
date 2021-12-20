#include "stack.hpp"
#include <deque>

int main() {
	ft::stack<int> s;
	ft::stack<int> s1;

	s.push(5);
	s1.push(10);
	s1.push(10);
	if (s > s1)
		std::cout << "s is greated" << std::endl;
	else
		std::cout << "s1 is greated" << std::endl;
	std::cout << s.top() << std::endl;
}
