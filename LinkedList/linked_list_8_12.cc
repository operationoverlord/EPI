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

p_list_int list_pivot(p_list_int head, int k) {
	p_list_int dummy_lower(new ListNode<int>());
	p_list_int dummy_upper(new ListNode<int>());
	p_list_int low_chaser = dummy_lower;
	p_list_int high_chaser = dummy_upper;
	p_list_int low_tail = dummy_lower;
	p_list_int chaser = head;
	while(chaser) {
		if(chaser->data < k) {
			low_chaser->next = chaser;
			low_chaser = chaser;
			low_tail = chaser;
		} else {
			high_chaser->next = chaser;
			high_chaser = chaser;
		}
		chaser = chaser->next;
	}
	if(high_chaser) {
		high_chaser->next = NULL;
	}
	if(low_tail) {
		low_tail->next = dummy_upper->next;
	}
	return dummy_lower->next;
}

int main() {
	// your code goes here
	p_list_int l = NULL;
	int m, n;
	cin >> m;
	l = build_list(l, m);
	p_list_int r = list_pivot(l, 1);
	while(r) {
		cout << r->data << " ";
		r = r->next;
	}

	return 0;
}
