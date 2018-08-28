#include<stdio.h>
#include<string.h>
int fee[4];
int year[12];
int check[14];
void dfs(int index,int category);	//category 1:하루  2:한달  3:세달
int answer;
int main() {
	int testcase;
	scanf("%d", &testcase);

	for (int t = 0; t < testcase; t++) {
		scanf("%d %d %d %d", &fee[0], &fee[1], &fee[2], &fee[3]);
		memset(check, 0, sizeof(check));
		for (int i = 0; i < 12; i++) {
			scanf("%d", &year[i]);
		}
		answer = fee[3];
		for (int i = 1; i < 4; i++) {
			dfs(0, i);
		}
		printf("#%d %d\n", t+1, answer);
	}
}
void dfs(int index,int category) {

	if ((check[index]==0)&&(year[index]!=0)) {
		switch (category)
		{
		case 1:
			check[index] = 1;
			break;
		case 2:
			check[index] = 2;
			break;
		case 3:
			check[index] = 3;
			check[index + 1] = 4;
			check[index + 2] = 4;
			break;
		}
	}
	if (index == 11) {
		int temp = 0;
		for (int i = 0; i < 12; i++) {
			if (check[i] == 1) {
				temp += fee[0] * year[i];
			}
			else if (check[i] == 2) {
				temp += fee[1];
			}
			else if (check[i] == 3) {
				temp += fee[2];
			}
		}
		if (temp < answer)
			answer = temp;
		check[index] = 0;
		return;
	}
	else {
		for (int i = 1; i < 4; i++) {
			dfs(index + 1, i);
		}
		check[index] = 0;
	}
}