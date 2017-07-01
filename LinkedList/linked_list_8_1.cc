#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
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

p_list_int merge_lists(p_list_int l1, p_list_int l2) {
	p_list_int result(new ListNode<int>());
	p_list_int head = result;
	while(l1 && l2) {
		if(l1->data < l2->data) {
			head->next = l1;
			if(head != result)
				l1->prev = head;
			l1 = l1->next;
		} else {
			head->next = l2;
			if(head != result)
				l2->prev = head;
			l2 = l2->next;
		}
		head = head->next;
	}
	if(l1) {
		head->next = l1;
		if(head != result)
			l1->prev = head;
	} else if(l2){
		head->next = l2;
		if(head != result)
			l2->prev = head;
	}
	return result->next;
}

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

int main() {
	// your code goes here
	p_list_int p = NULL;	
	p_list_int l1 = NULL, l2 = NULL;
	int m, n;
	cin >> m;
	cin >> n;
	l1 = build_list(l1, m);
	l2 = build_list(l2, n);
	p_list_int r = merge_lists(l1, l2);
	while(r) {
		cout << r->data << " ";
		r = r->next;
	}
	return 0;
}
