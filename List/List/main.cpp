#include <iostream>
#include "List.h"

void coutList(int& data) {
	std::cout << data << std::endl;
}

int main() {
	List<int> list;
	for (int i = 4; 0 < i; i--)
		list.insertAsLast(i);
//	list.selectionSort();
	
	list.insertSort();		//���������е�����
	list.traverse(coutList);
	return 0;
}