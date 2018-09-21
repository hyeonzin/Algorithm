#include<stdio.h>

int find_1(int *A, int len, int k) {
	for (int i = 0; i < len; i++) {
		if (A[i] == k) {
			return 1;
		}
	}
	return -1;
}

void quick(int * A, int s, int e) {

	int pivot = s;
	int i = s + 1, j = e,tmp;
	while (i < j) {
		while (A[i] < A[pivot]&&i<=e)
			i++;
		while (A[j] > A[pivot]&&j>=s+1)
			j--;
		if (i < j) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	if (A[pivot] > A[j]) {
		tmp = A[pivot];
		A[pivot] = A[j];
		A[j] = tmp;
	}
	if(s<j-1)
		quick(A, s, j - 1);
	if(j+1<e)
		quick(A, j + 1, e);
}

int binary_search(int *A, int len, int k) {
	quick(A, 0, 9);

	int low=0, high=9;
	while (low<=high) {
		if (A[(low + high) / 2] == k)
			return 1;
		else if (A[(low + high) / 2] < k)
			low = (low + high) / 2+1;
		else
			high = (low + high) / 2-1;
	}
	return -1;
}

int find_2(int *A, int len, int k) {
	
	return binary_search(A,len,k);
}

int main() {

	int arr[15] = { 3, 10, 9, 1, 2, 6, 4, 8, 5, 7 };
	int k;

	int ans = -1;

	scanf("%d", &k);

	ans = find_1(arr, 10, k);

	if (ans == -1)
		printf("배열에 %d이(가) 없습니다.\n", k);
	else
		printf("배열에 %d이(가) 존재합니다.\n", k);


	ans = -1;

	ans = find_2(arr, 10, k);


	if (ans == -1)
		printf("배열에 %d이(가) 없습니다.\n", k);
	else
		printf("배열에 %d이(가) 존재합니다.\n", k);

	return 0;
}