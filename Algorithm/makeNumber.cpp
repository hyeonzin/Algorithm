#include<stdio.h>
#include<string.h>
int num;
int op[4];
int number[12];
int max=-0x7fffffff; //실수 : 최대값이 음수갇 될 수 있다
int min = 0x7fffffff;
void dfs(int numIndex, int opIndex, int sum);
int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 0; t < testcase; t++) {
		max = -0x7fffffff;
		min = 0x7ffff;
		memset(number, 0, sizeof(number));

		scanf("%d", &num);
		scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);
		for (int i = 0; i < num; i++) {
			scanf("%d", &number[i]);
		}
		for (int i = 0; i < 4; i++) {
			dfs(1, i, number[0]);
		}
		printf("#%d %d\n", t + 1, max- min);
	}
	return 0;
}
void dfs(int numIndex, int opIndex, int sum) {
	if (op[opIndex] > 0) {
		switch (opIndex)
		{
		case 0:
			sum = sum + number[numIndex];
			break;
		case 1:
			sum = sum - number[numIndex];
			break;
		case 2:
			sum = sum * number[numIndex];
			break;
		case 3:
			sum = sum / number[numIndex];
			break;
		}
		if (numIndex == num - 1) {
			if (sum < min)
				min = sum;
			if (sum > max)
				max = sum;
			return;
		}
		op[opIndex]--;
		for (int i = 0; i < 4; i++) {
			dfs(numIndex + 1, i, sum);
		}
		op[opIndex]++;
	}
	
}