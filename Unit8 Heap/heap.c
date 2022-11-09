#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int heap[SIZE];
int last = -1; //empty heap

void print() {
	for (int i = 0; i <= last; i++) {
		printf("[%d] : %d\n", i, heap[i]);
	}
}

void swap(int a_idx, int b_idx) {
	int tmp = heap[a_idx];
	heap[a_idx] = heap[b_idx];
	heap[b_idx] = tmp;
}

void reheapUp(int cur_idx) {
	int p_idx = (cur_idx - 1) / 2; // parent of a node index
	if (heap[p_idx] < heap[cur_idx]) { // ���� ��尡 �� ũ�� �������ش�.
		swap(p_idx, cur_idx);
		reheapUp(p_idx); // ��ͷ� Ʈ���� �ö󰡸� �ٲܰ� �ֳ� üũ���ش�.
	}
}

void reheapDown(int cur_idx) {
	int l_idx = cur_idx * 2 + 1;
	int r_idx = cur_idx * 2 + 2;
	int largest_idx = cur_idx;
	if (l_idx <= last && heap[largest_idx] < heap[l_idx]) {
		largest_idx = l_idx;
	}
	if (r_idx <= last && heap[largest_idx] < heap[r_idx]) {
		largest_idx = r_idx;
	}
	if (largest_idx != cur_idx) { // case of not changed
		swap(largest_idx, cur_idx);
		reheapDown(largest_idx);
	}
}

void insertHeap(int val) {
	if (last == SIZE - 1) {
		return;
	}
	last++;
	heap[last] = val;
	reheapUp(last);
}

int deleteHeap() { // �� ������ ������, �� ���� ���� ������ �ε����� ���� ��ü
	int ret = heap[0];
	heap[0] = heap[last];
	last--;
	reheapDown(0); // Ʈ���� �籸��
	return ret;
}

int main() {
	insertHeap(78); 
	insertHeap(56);
	insertHeap(32);
	insertHeap(45);
	insertHeap(8);
	insertHeap(23);
	insertHeap(19);
	print();
	puts("heap sort");
	int s = last;
	for (int i = 0; i <= s; i++) {
		printf("%d\t", deleteHeap());
	}
}