#include <iostream>
#include <queue>
using namespace std;

class Stack {
	public:
		void push(int data);
		void pop();
		int top();
	private:
		
		class heap_element {
			public:
				int data;
				long long time_stamp;
				heap_element(int d, long long t) {
					data = d;
					time_stamp = t;
				}
				heap_element() {
				}
				bool operator<(const heap_element& that) const {
					return time_stamp < that.time_stamp;
				}
		};
		priority_queue<heap_element, vector<heap_element > > max_heap;
		long long time_stamp;
};

void Stack::push(int data) {
	++time_stamp;
	max_heap.push(heap_element(data, time_stamp));
}

void Stack::pop() {
	max_heap.pop();
}


int Stack::top() {
	return max_heap.top().data;
}


int main() {
	// your code goes here
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << " \n";
	s.pop();
	cout << s.top() << " ";
 	return 0;
}
