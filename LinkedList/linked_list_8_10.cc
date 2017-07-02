#include <iostream>
#include <memory>
using namespace std;

template<typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T> > next;
	shared_ptr<ListNode<T> > prev;
	ListNode<T>(T t) {
		data = t;
	}
	ListNode<T>() {
 
	}
};
 
typedef shared_ptr<ListNode<int> > p_list_int;

p_list_int build_list(p_list_int l, int n) {
	p_list_int result = NULL;
	for(int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		p_list_int pt(new ListNode<int>());
		pt->data = t;
		if(l) {
			l->next = pt;
			pt->prev = l;
		} else {
			l = pt;
			result = l;
		}
		l = pt;
	}
	return result;
}

void even_odd_merge(p_list_int head) {
	p_list_int even_chaser = head;
	p_list_int odd_chaser = head? head->next:NULL;
	p_list_int odd_head = odd_chaser;
	p_list_int even_tail = head;
	while(odd_chaser && even_chaser) {
		p_list_int next_even = even_chaser->next?even_chaser->next->next:NULL;
		p_list_int next_odd = odd_chaser->next?odd_chaser->next->next:NULL;
		even_tail = even_chaser;
		even_chaser->next = next_even;
		odd_chaser->next = next_odd;
		even_chaser = next_even;
		odd_chaser = next_odd;
	}
	if(even_chaser) {
		even_tail = even_chaser;
	}
	if(even_tail) {
		even_tail->next = odd_head;
	}
}

int main() {
	// your code goes here
	p_list_int l = NULL;
	int m, n;
	cin >> m;
	l = build_list(l, m);
	even_odd_merge(l);
	while(l) {
		cout << l->data << " ";
		l = l->next;
	}
	return 0;
}
