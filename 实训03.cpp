#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int x, y, step;
};

int mazesolve(vector<vector<int>>& maze) {
	unsigned int n = maze.size();
	int m = maze[0].size();
	int sx[] = { 1,0,-1,0 };
	int sy[] = { 0,1,0,-1 };
	queue<node> q;
	vector<vector<bool>> visit{n,vector<bool>(m,false)};
	if (maze[0][0] == 1) return -1;
	q.push({ 0,0,0 });
	visit[0][0] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		if (now.x == n - 1 && now.y == m - 1)
			return now.step;
		
		for (int i = 0; i < 4; ++i) {
			int nx = now.x + sx[i];
			int ny = now.y + sy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 0 && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				q.push({ nx,ny,now.step + 1 });
			}
		}
	}
	return -1;
}

int main() {
	unsigned int n;
	int m;
	cin >> n >> m;
	vector<vector<int>> maze{ n,vector<int>(m,0) };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int tmp;
			cin >> tmp;
			maze[i][j]=tmp;
		}
	}
	
	int res = mazesolve(maze);
	if (res == -1)
		cout << "cant reach";
	else
		cout << res;

}
