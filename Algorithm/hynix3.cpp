#include<stdio.h>
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map[10][10];
bool check[10][10];
int main() {
	int n;
	int x = 0, y = 0;
	int dir = 0;
	printf("n을 입력하세요 :");
	scanf("%d", &n);
	int val = n*n;
	while (1) {
		if (val == 0)
			break;
		if (!check[y][x]&&(0<=x)&&(x<n)&&(0<=y)&&(y<n)) {
			map[y][x] = val--;
			check[y][x] = 1;
			x=x + dx[dir];
			y = y + dy[dir];

		}
		else {
			x = x - dx[dir];
			y = y - dy[dir];
			dir = (dir + 1) % 4;
			x = x + dx[dir];
			y = y + dy[dir];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", map[i][j]);
		}
		printf("\n");
	}
}