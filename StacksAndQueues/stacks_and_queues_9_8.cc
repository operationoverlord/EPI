#include <iostream>
#include <vector>
using namespace std;

class Q {
	private:
		int s = 0;
		int front = 0;
		int back = 0;
		vector<int> data;
	void resize();
	public:
		void enqueue(int e);
		void dequeue();
		int get_size() {
			return s;
		}
		
		Q() {
		
		}
		
		Q(int capacity) {
			data.resize(capacity);
		}
};

void Q::enqueue(int e) {
	if(s < data.size()) {
		data[back] = e;
		back = (back + 1) % data.size();
		++s;
	} else {
		resize();
		enqueue(e);
	}
}

void Q::dequeue() {
	if(s == 0) {
		cout << "qeueue is empty!\n";
	} else {
		front = (front + 1) % data.size();
		--s;
	}
}

void Q::resize() {
	vector<int> new_data(data.size() * 2);
	for(int i = 0; i < s; ++i) {
		new_data[i] = data[front];
		front = (front + 1) % data.size();
	}
	front = 0;
	back = s;
	data = new_data;
}


int main() {
	// your code goes here
	Q q(2);
	q.dequeue();
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	cout << q.get_size();
	return 0;
}
