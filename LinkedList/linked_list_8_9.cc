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

p_list_int get_k_last_node(p_list_int head, int k) {
	p_list_int result = NULL;
	p_list_int chase = head;
	for(int i = 1; i < k && chase; ++i) {
		chase = chase->next;
	}
	while(chase && chase->next) {
		head = head->next;
		chase = chase->next;
	}
	if(chase) {
		result = head;
	}
	return result;
}

void shift_cyclic(p_list_int* head, int k) {
	p_list_int k_last = get_k_last_node(*head, k + 1);
	if(k_last) {
		p_list_int start = k_last->next;
		p_list_int end = start;
		while(end && end->next) {
			end = end->next;
		}
		k_last->next = NULL;
		end->next = *head;
		*head = start;
	}
}

int main() {
	// your code goes here
	p_list_int l = NULL;
	int m, n;
	cin >> m;
	l = build_list(l, m);
	shift_cyclic(&l, 3);
	while(l) {
		cout << l->data << " ";
		l = l->next;
	}
	return 0;
}
