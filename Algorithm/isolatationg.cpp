#include<stdio.h>
using namespace std;
typedef struct bug{
	int col;
	int row;
	int num;
	int dir;
}Bug;
int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		int cell, time, num;
		Bug bug[1000];
		scanf("%d %d %d", &cell, &time, &num);
		for (int j = 0; j < num; j++) {
			scanf("%d %d %d %d", &bug[j].col, &bug[j].row, &bug[j].num, &bug[j].dir);
		}
		//입력 끝
		for (int j = 0; j < time; j++) {	//시간마다
			for (int k = 0; k < num; k++) {	//미생물 군집의 수 만큼
				switch (bug[k].dir)
				{
				case 1:
					bug[k].col--;
					if (bug[k].col == 0) {
						bug[k].num = bug[k].num / 2;
						bug[k].dir = 2;
					}
					break;
				case 2:
					bug[k].col++;
					if ( bug[k].col == cell-1) {
						bug[k].num = bug[k].num / 2;
						bug[k].dir = 1;
					}
					break;
				case 3:
					bug[k].row--;
					if (bug[k].row == 0) {
						bug[k].num = bug[k].num / 2;
						bug[k].dir = 4;
					}
					break;
				case 4:
					bug[k].row++;
					if (bug[k].row == cell-1) {
						bug[k].num = bug[k].num / 2;
						bug[k].dir = 3;
					}
					break;
				default:
					break;
				}
			}
			for (int m = 0; m < num; m++) {	//같은 위치에 있는 것끼리 더하기 (최대 네개까지 가능 ->단순비교ㄴㄴ)
				int max = bug[m].num;
				for (int k = m+1; k < num; k++) {
					if ((bug[m].col == bug[k].col) && (bug[m].row == bug[k].row)) {
						if (max < bug[k].num) {
							max = bug[k].num;
							bug[m].num += bug[k].num;
							bug[m].dir = bug[k].dir;
							bug[k].num = 0;
							bug[k].dir = 0;
						}
						else {
							bug[m].num += bug[k].num;
							bug[k].num = 0;
							bug[k].dir = 0;
						}
					}
					
				}
			}
		}
		int answer = 0;
		for (int j = 0; j < num; j++) {
			answer += bug[j].num;
		}
		printf("#%d %d\n", i + 1, answer);
	}
}