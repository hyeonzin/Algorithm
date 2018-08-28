#include<stdio.h>
#include<string.h>
int main() {
	int testcase;
	int testnum[1001];
	int num;
	int answer;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		scanf("%d", &num);
		answer = 0;
		memset(testnum, 0, sizeof(testnum));
		for (int j = 1; j <= num; j++) {
			scanf("%d", &testnum[j]);
		}
		for (int j = 1; j <= num; j++) {
			if (testnum[j] == 0) {
				//´ÙÀ½
			}
			else {
				int tmp = j;
				int tmpValue = testnum[j];
				while (1) {
					if (testnum[tmp] == 0)
						break;
					testnum[tmp] = 0;
					tmp = tmpValue;
					tmpValue = testnum[tmp];
				}
				answer++;
			}
		}
		printf("%d\n", answer);
	}
}