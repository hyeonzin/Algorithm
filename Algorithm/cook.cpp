#include<stdio.h>
#include<string.h>
int num;
int map[16][16];
bool check[16];
void dfs(int count, int index);
int min = 0x7fffffff;
int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int t = 0; t < testcase; t++) {
		scanf("%d", &num);
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		min = 0x7fffffff;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		dfs(0, 0);

		printf("#%d %d\n", t + 1, min);
	}
}
void dfs(int count, int index) {

	check[index] = 1;

	if (count+1 == num / 2) {
		int odd = 0, even = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (check[i] && check[j]) {	//같은 조
					odd += map[i][j];
				}
				else if ((!check[i]) && (!check[j])) { //같은 조
					even += map[i][j];
				}
			}
		}
		int res = odd - even;
		if (res>0) {
			if (min > res) {
				min = res;
			}
		}
		else {
			if (min > -res) {
				min = -res;
			}
		}
	}
	else {
		for (int i = index + 1; i < num; i++) {
			dfs(count + 1, i);
		}
	}
	check[index] = 0;
}