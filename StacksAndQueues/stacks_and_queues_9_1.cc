#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct max_stack {
	stack<T> data_stack;
	stack<T> max_elements;
	T top();
	void push(T d);
	void pop();
	T get_max();
};

template <typename T>
void max_stack<T>::push(T d) {
	T max_e = d;
	if(!max_elements.empty()) {
		max_e = max(max_e, max_elements.top());
	}
	max_elements.push(max_e);
	data_stack.push(d);
}
template <typename T>
void max_stack<T>::pop() {
	data_stack.pop();
	max_elements.pop();
}

template <typename T>
T max_stack<T>::get_max() {
	return max_elements.top();
}

int main() {
	// your code goes here
	max_stack<int> s;
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.get_max() << "\n";
	s.pop();
	s.pop();
	cout << s.get_max() << "\n";
	return 0;
}
