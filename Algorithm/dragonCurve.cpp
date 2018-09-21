#include<stdio.h>
using namespace std;
typedef struct info {
	int x;
	int y;
	int dir;
	int gene;
}Info;
Info info[20];
bool map[101][101];
int point[500000][2];
int final;
int main()
{
	int num;
	scanf("%d", &num);
	for (int n = 0; n < num; n++) {
		scanf("%d %d %d %d", &info[n].x, &info[n].y, &info[n].dir, &info[n].gene);
	}
	for (int n = 0; n < num; n++) {
		final = 0;
		point[final][0] = info[n].x;
		point[final][1] = info[n].y;
		map[info[n].y][info[n].x] = true;
		final++;
		switch (info[n].dir)
		{
		case 0:
			if (info[n].x + 1 <= 100) {
				point[final][0] = info[n].x + 1;
				point[final][1] = info[n].y;
				map[info[n].y][info[n].x + 1] = true;
			}
			break;
		case 1:
			if (info[n].y - 1 >= 0) {
				point[final][0] = info[n].x;
				point[final][1] = info[n].y - 1;
				map[info[n].y - 1][info[n].x] = true;
			}
			break;
		case 2:
			if (info[n].x - 1 >= 0) {
				point[final][0] = info[n].x - 1;
				point[final][1] = info[n].y;
				map[info[n].y][info[n].x - 1] = true;
			}
			break;
		case 3:
			if (info[n].y + 1 <= 100) {
				point[final][0] = info[n].x;
				point[final][1] = info[n].y + 1;
				map[info[n].y + 1][info[n].x] = true;
			}
			break;
		}
		final++;
		for (int i = 0; i < info[n].gene; i++) {
			int x = point[final-1][0];
			int y = point[final-1][1];
			int j = final - 2;
			for (j; j >= 0; j--) {
				int tempX = point[j][0];
				int tempY = point[j][1];
				int newX = x + (y - tempY);
				int newY = y - (x - tempX);
				if ((0 <= newX) && (newX <= 100) && (0 <= newY) && (newY <= 100)) {
					point[final][0] = newX;
					point[final][1] = newY;
					final++;
					map[newY][newX] = true;
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			printf("%d", map[i][j]);
			if (map[i][j]&&map[i+1][j]&&map[i+1][j]&&map[i+1][j+1]) {
				answer++;
			}
		}
		printf("\n");
	}
	printf("%d\n", answer);
}