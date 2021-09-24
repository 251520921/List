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