#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class MaxQueue {
	public:
		void deque_element();
		void enque(int e);
		int get_max();
	private:
		queue<int> normal_queue;
		deque<int> max_queue;
};

void MaxQueue::deque_element() {
	if(normal_queue.empty()) {
		cout << "queue empty!\n";
	} else {
		int front_element = normal_queue.front();
		normal_queue.pop();
		if(front_element == max_queue.front()) {
			max_queue.pop_front();
		}
	}
}

void MaxQueue::enque(int e) {
	normal_queue.push(e);
	while(!max_queue.empty() && max_queue.back() < e) {
		max_queue.pop_back();
	}
	max_queue.push_back(e);
}

int MaxQueue::get_max() {
	if(max_queue.empty()) {
		cout << "queue empty!!\n";
		return -1;
	} else {
		return max_queue.front();
	}
}

int main() {
	MaxQueue q;
	q.enque(1);
	q.enque(2);
	q.enque(3);
	cout << q.get_max() << "\n"; 
	q.deque_element();
	q.deque_element();
	cout << q.get_max() << "\n"; 
	q.deque_element();
	cout << q.get_max() << "\n"; 
	// your code goes here
	return 0;
}
