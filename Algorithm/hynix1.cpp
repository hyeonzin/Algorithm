/*
SK ���̴н�
1. �ڿ��� n�� �Է¹޾� (1 <= n <= 1000) �������� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. (15��)
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

	// ��� �Լ� �κ�
	binary(n);

	printf("\n");


	// while �κ�

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