 #pragma once

template<class T>
struct ListNode
{
	T data;
	ListNode<T>* pred;
	ListNode<T>* succ;

	ListNode() {};
	ListNode(T e, ListNode<T>* p = NULL, ListNode<T>* s = NULL)
		:data(e), pred(p), succ(s) {};
	ListNode<T>* insertAsPred(T const& e);
	ListNode<T>* insertAsSucc(T const& e);
};

template<class T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e) {
	ListNode<T>* x = new ListNode<T>(e, pred, this);
	pred->succ = x; pred = x;
	return x;
}

template<class T>
ListNode<T>* ListNode<T>::insertAsSucc(T const& e) {
	ListNode<T>* x = new ListNode<T>(e, this, succ);
	succ->pred = x; succ = x;
	return x;
}
