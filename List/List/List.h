#pragma once
#include"ListNode.h"

template<class T>
class List {
private:
	int _size;
	ListNode<T>* header; ListNode<T>* trailer;

public:
	void init();
};

template<class T>
void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;

	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;
}