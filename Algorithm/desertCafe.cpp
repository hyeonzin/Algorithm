#include <stdio.h>
#include<string.h>
int map[20][20];
int desert[100];
int desertN;
int odd, even;
int n;
int answer;
void dfs(int col,int row,int dir, int count);
int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int m = 0; m < testcase; m++) {
		scanf("%d", &n);
		memset(map, 0, sizeof(map));
		answer = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < n - 2; i++) {
			for (int j = 1; j < n - 1; j++) {
				desert[desertN++] = map[i][j];
				dfs(i, j, 1, 0);
				desertN--;
			}
		}
	
		printf("#%d %d\n", m + 1, answer);
	}
}
void dfs(int col, int row, int dir, int count) {
	switch (dir)
	{
	case 1:
		if ((col+1 != n)&&(row+1!=n)) {
			for (int i = 0; i < desertN; i++) {
				if (desert[i] == map[col+1][row+1])
					return;
			}
			desert[desertN++] = map[col+1][row+1];
			odd++;
			dfs(col + 1, row + 1, 1, count+1);
			dfs(col + 1, row + 1, 2, 0);
			odd--;
			desertN--;
		}
		break;
	case 2:
		if ((col + 1 != n) && (row != 0)) {
			for (int i = 0; i < desertN; i++) {
				if (desert[i] == map[col+1][row-1])
					return;
			}
			desert[desertN++] = map[col+1][row-1];
			even++;
			dfs(col + 1, row - 1, 2, count + 1);
			dfs(col + 1, row - 1, 3, 0);
			even--;
			desertN--;
		}
		break;
	case 3:
		if ((col != 0) && (row != 0)) {
			for (int i = 0; i < desertN; i++) {
				if (desert[i] == map[col-1][row-1])
					return;
			}
			if (count + 1 == odd) {
				desert[desertN++] = map[col-1][row-1];
				dfs(col - 1, row - 1, 4, 0);
				desertN--;
			}
			else {
				desert[desertN++] = map[col-1][row-1];
				dfs(col - 1, row - 1, 3, count + 1);
				desertN--;
			}
		}
		break;
	case 4:
		if ((col != 0) && (row + 1 != n)) {
			if (count + 1 == even) {
				//ÇÑ¹ÙÄû µ¼
				int tmp = (odd + even) * 2;
				if (answer < tmp)
					answer = tmp;
			}
			else {
				for (int i = 0; i < desertN; i++) {
					if (desert[i] == map[col - 1][row + 1])
						return;
				}
				desert[desertN++] = map[col-1][row+1];
				dfs(col - 1, row + 1, 4, count + 1);
				desertN--;
			}
		}
		break;
	default:
		break;
	}
}