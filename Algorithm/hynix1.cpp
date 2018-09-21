/*
SK 하이닉스
1. 자연수 n을 입력받아 (1 <= n <= 1000) 이진수로 변환하여 출력하는 프로그램을 작성하시오. (15점)
*/
#include<stdio.h>

void binary(int num) {

	if (num == 0) {
		return;
	}
	else{
		binary(num / 2);
		printf("%d", num % 2);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	// 재귀 함수 부분
	binary(n);

	printf("\n");


	// while 부분

	int temp = n;
	int i = 1;
	int answer = 0;

	while (temp) {
		int res = temp % 2;
		temp = temp / 2;
		answer += res*i;
		i *= 10;
	}
	printf("%d\n", answer);
	return 0;
}