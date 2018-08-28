#include <stdio.h>
#include <vector>
using namespace std;
int n, m;
void dfs(int, int);
vector <pair<int, int>> home;
vector <pair<int, int>> chicken;
bool check[14];
int ans = 0x7fffffff;
int main() {
	int temp;
	scanf("%d %d", &n,&m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &temp);
			if (temp == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (temp == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		check[i] = 1;
		dfs(1, 2);
		check[i] = 0;
	}
}
void dfs(int count, int index) {
	if (count == m) {	//거리가 작으면 답이 될 수 있음
		//거리 계산 min 저장
		
	}
	else {
		check[index] = 1;
		dfs(count + 1, index + 1);
		check[index] = 0;
	}
}