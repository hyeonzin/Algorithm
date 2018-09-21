/*
2018.09.21
오현진
정렬구현
*/
#include<stdio.h>
void bubble(int *,int n);
void insertion(int *, int n);
void selection(int *, int n);
int main() {
	int num[1000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	//bubble(num, n);
	//insertion(num, n);
	selection(num, n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", num[i]);
	}

}
void bubble(int * num,int n){

	int temp;

	for (int j = n - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (num[i] > num[i + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}
	}
}
void insertion(int * num, int n) {
	int temp;
	for (int i = 1; i < n; i++) {
		for (int j = i; j >0; j--) {
			if (num[j] < num[j-1]) {
				temp = num[j];
				num[j] = num[j-1];
				num[j-1] = temp;
			}
		}
	}
}
void selection(int * num, int n) {
	int min;
	int temp;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (num[min] > num[j]) {
				min = j;
			}
		}
		temp = num[min];
		num[min] = num[i];
		num[i] = temp;
	}
}