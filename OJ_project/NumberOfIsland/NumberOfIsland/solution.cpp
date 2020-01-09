#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class NumberOfIsland {
public:
	vector<vector<char>> grid;
	vector<vector<char>> mark;
	int width;
	int height;


	NumberOfIsland(int width, int height);
	NumberOfIsland();
	~NumberOfIsland();

	void DFS(vector<vector<char>> &grid, vector<vector<char>> &mark, int row, int col);
	void infect(vector<vector<char>> &grid,int row,int col);
	int GetNumber(vector<vector<char>> &grid, vector<vector<char>> &mark);
	int GetNumber2(vector<vector<char>> &grid);
};
NumberOfIsland::NumberOfIsland(int width,int height) {
	this->width = width;
	this->height = height;
	vector<char> temp(width, '0');
	for (int i = 0; i < height; i++) {
		mark.push_back(temp);
	}
}
NumberOfIsland::NumberOfIsland(){}
NumberOfIsland::~NumberOfIsland() {
	vector<vector<char>>().swap(grid);
	vector<vector<char>>().swap(mark);
}
int NumberOfIsland::GetNumber(vector<vector<char>> &grid, vector<vector<char>> &mark) {
	int count=0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (grid[i][j] == '1' &&  mark[i][j] == '0') {
				DFS(grid, mark, i, j);
				count++;
			}
		}
	}
	return count;
}
void NumberOfIsland::DFS(vector<vector<char>> &grid, vector<vector<char>> &mark, int row, int col) {
	int dx[4] = { 1,-1,0,0 },
		dy[4] = { 0,0,1,-1 };
	stack<pair<int, int >> s;
	pair<int, int> cur(row, col);
	s.push(cur);
	while (!s.empty()) {
		pair<int, int> temp;
		temp = s.top(); s.pop();
		mark[temp.first][temp.second] = '1';
		for (int i = 0; i < 4; i++) {
			int newx = temp.first + dx[i],
				newy = temp.second + dy[i];
			if (newx >= 0 && newx < height && newy >= 0 && newy < width) {
				if (grid[newx][newy] == '1' && mark[newx][newy] == '0')
					s.push(make_pair(newx, newy));
			}
		}
	}
}
int NumberOfIsland::GetNumber2(vector<vector<char>> &grid) {
	int count = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (grid[i][j] == '1') {
				infect(grid, i, j);
				count++;
			}
		}
	}
	return count;
}
void NumberOfIsland::infect(vector<vector<char>> &grid, int row, int col) {
	
	grid[row][col] = '2';
	int dx[4] = { 1,-1,0,0 },
		dy[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++) {
		int newx = row + dx[i],
			newy = col + dy[i];
		if (newx >= 0 && newx < height && newy >= 0 && newy < width) {
			if (grid[newx][newy] == '1') {
				infect(grid, newx, newy);
			}
		}
	}
	delete[] dx;
	delete[] dy;
}
int main(int argc, char **argv) {

	int h, w;
	cin >> h >> w;
	NumberOfIsland s(w,h);
	//s.height = h;
	//s.width = w;
	for (int i = 0; i < s.height; i++) {
		vector<char> v;
		for (int j = 0; j < s.width; j++) {
			char temp;
			cin >> temp;
			v.push_back(temp);
		}
		s.grid.push_back(v);
		v.clear();
	}
	printf("%d", s.GetNumber(s.grid,s.mark));
	system("pause");
	return 0;
}
