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
	
	list.insertSort();		//插入排序还有点问题
	list.traverse(coutList);
	return 0;
}