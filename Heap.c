#include "Heap.h"
//小堆
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n) {
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
	for (int i = 0; i < n; i++) {
		HeapPush(hp, a[hp->_size]);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	free(hp->_a);
	hp->_capacity = 0;
	hp->_size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		hp->_capacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType)* hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}
// 堆的删除
void HeapPop(Heap* hp) {
	assert(hp);
	assert(!HeapEmpty(hp));
	int tmp = hp->_a[0];
	hp->_a[0]= hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;
	hp->_size--;
	AdjustDown(hp->_a, hp->_size,0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp){
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp) {
	assert(hp);
	return hp->_size == 0;
}
void AdjustDown(HPDataType* data, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		if(child + 1<size&&data[child] > data[child + 1]){
			child++;
		}
		if ( data[child] < data[parent]) {
			
			int tmp = data[child];
			data[child] = data[parent];
			data[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
			
		}else {
				break;
			}
	}
}
void AdjustUp(HPDataType* data, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (data[child] < data[parent]) {
			int tmp = data[child];
			data[child] = data[parent];
			data[parent] = tmp;
		}
		else {
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}

}

void HeapSort(int* a, int n) {
	int parent = (n - 1 -1)/2;
	while(parent>=0){
		AdjustDown(a, n,parent);
		parent--;
	}
	while (n>0) {
		int tmp = a[0];
		a[0] = a[n - 1];
		a[n - 1] = tmp;
		n--;
		AdjustDown(a, n, 0);
	}
}
