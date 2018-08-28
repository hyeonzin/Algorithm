#include<stdio.h>
#include<string.h>
int ja[4][8];
bool visited[4];
int order[20];
int orderdir[20];
void dfs(int index, int dir);
int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 0; t < testcase; t++) {
		int num;
		scanf("%d", &num);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &ja[i][j]);
			}
		}
		for (int i = 0; i < num; i++) {
			scanf("%d %d", &order[i],&orderdir[i]);
		}
		for (int i = 0; i < num; i++) {
			memset(visited, 0, sizeof(visited));
			dfs(order[i], orderdir[i]);
		}
		int answer = 0;
		for (int i = 0; i < 4; i++) {
			if (ja[i][0] == 1) {
				switch (i)
				{
				case 0:
					answer += 1;
					break;
				case 1:
					answer += 2;
					break;
				case 2:
					answer += 4;
					break;
				case 3:
					answer += 8;
					break;
				}
			}
		}
		printf("#%d %d\n", t + 1, answer);
	}
}
void dfs(int index, int dir) { //index 1234
	if (!visited[index - 1]) {
		int temp[8] = { 0 };
		memcpy(temp, ja[index - 1], sizeof(temp));	//회전하기 전꺼랑 비교해야함
		visited[index - 1] = true;

		if (dir == 1) { //시계방향
			int temp = ja[index - 1][7];
			for (int i = 7; i > 0; i--) {
				ja[index - 1][i] = ja[index - 1][i - 1];
			}
			ja[index - 1][0] = temp;
		}
		else { //반시계방향
			int temp = ja[index - 1][0];
			for (int i = 0; i < 7; i++) {
				ja[index - 1][i] = ja[index - 1][i + 1];
			}
			ja[index - 1][7] = temp;
		}

		if ((index <= 3) && (!visited[index])&&(temp[2] != ja[index][6])) {//오른쪽
			dfs(index + 1, dir*-1);
		}
		if ((1<index)&&(!visited[index-2])&&(temp[6] != ja[index - 2][2])) {//왼쪽
			dfs(index - 1, dir*-1);
		}

	}
}