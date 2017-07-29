#include <iostream>
#include <stack>
using namespace std;

class Q {
	private:
		stack<int> s1;
		stack<int> s2;
		void switch_stack();
	public:
		void pop();
		void push(int e);
		int front();
};

void Q::push(int e) {
	s1.push(e);
}

void Q::pop() {
	if(s1.empty() && s2.empty()) {
		cout << "the queue is empty!\n";
	} else {
		switch_stack();
		s2.pop();
	}
}

void Q::switch_stack() {
	if(s2.empty()) {
		while(!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}	
}

int Q::front() {
	int result = -1;
	if(s1.empty() && s2.empty()) {
		cout << "empty queue!\n";
	}
	else {
		switch_stack();
		result = s2.top();
	}
	return result;
}

int main() {
	// your code goes here
	Q q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.front() << "\n";
	q.push(5);
	q.push(6);
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	cout << q.front() << "\n";
	return 0;
}
