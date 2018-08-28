#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int map[50][50];
bool check[50][50];
int col, row;
int nowC, nowR;
int time;
int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 0; t < testcase; t++) {
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		queue <pair<int, int>> que;
		scanf("%d %d %d %d %d", &col, &row,&nowC,&nowR,&time);
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		que.push(make_pair(nowC, nowR));
		for (int i = 0; i < time; i++) {
			queue <pair<int, int>> tmpQ;

			while (!que.empty()) {
				int c = que.front().first;
				int r = que.front().second;
				int temp = map[c][r];
				check[c][r] = true;
				que.pop();

				if ((temp == 1) || (temp == 2) || (temp == 4) || (temp == 7)) { //위
					if ((c - 1 >= 0)&&(check[c-1][r]==false)) {
						int tmp = map[c - 1][r];
						if ((tmp == 1) || (tmp == 2) || (tmp == 5) || (tmp == 6)) {
							tmpQ.push(make_pair(c - 1, r));
						}
					}
				}
				if ((temp == 1) || (temp == 3) || (temp == 4) || (temp == 5)) { //오른
					if ((r + 1 < row) && (check[c][r+1] == false)) {
						int tmp = map[c][r + 1];
						if ((tmp == 1) || (tmp == 3) || (tmp == 6) || (tmp == 7)) {
							tmpQ.push(make_pair(c , r+1));
						}
					}
				}
				if ((temp == 1) || (temp == 2) || (temp == 5) || (temp == 6)) {	//아래
					if ((c + 1 < col) && (check[c + 1][r] == false)) {
						int tmp = map[c + 1][r];
						if ((tmp == 1) || (tmp == 2) || (tmp == 4) || (tmp == 7)) {
							tmpQ.push(make_pair(c + 1, r));
						}
					}
				}
				if ((temp == 1) || (temp == 3) || (temp == 6) || (temp == 7)) {	//왼
					if ((r - 1 >= 0) && (check[c][r-1] == false)) {
						int tmp = map[c][r - 1];
						if ((tmp == 1) || (tmp == 3) || (tmp == 4) || (tmp == 5)) {
							tmpQ.push(make_pair(c, r-1));
						}
					}
				}
			}
			que = tmpQ;
		}
		int answer = 0;
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (check[i][j] == true)
					answer++;
			}
		}
		printf("#%d %d\n", t + 1, answer);
	}
}