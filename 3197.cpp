#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAX = 1500;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int R, C;
string lake[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;

	vector<pair<int, int>> swan;
	queue<pair<int, int>> waterQ;
	for (int i = 0; i < R; i++)
	{
		cin >> lake[i];

		for (int j = 0; j < C; j++)
		{
			if (lake[i][j] == 'L')
			{
				swan.push_back({ i, j });
			}
            //왜 이걸 해줘야하는걸까..?
            //얼음이 아니면 waterQ에 넣어준다
			if (lake[i][j] == '.'|| lake[i][j]=='L')
			{
				waterQ.push({ i, j });
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(swan[0]);

	bool visited[MAX][MAX] = { false, };
	visited[swan[0].first][swan[0].second] = true;
	
	int day = 0;
	while (1)
	{
		//printf("while문 돌아요\n");
        queue<pair<int, int>> nextQ;

		bool flag = false;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == swan[1].first && x == swan[1].second)
			{
				//다른 백조 만나면 while 끝내기
                flag = true;
				break;
			}
            //백조 최대한 움직여보기
			for (int i = 0; i < 4; i++)
			{
				//2차원 배열이라서 visited[x][y]가 아니라 바꿔서 visited[y][x] 해주기
                int nextY = y + moveDir[i].y;
				int nextX = x + moveDir[i].x;

				if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C || visited[nextY][nextX])
					continue;

				visited[nextY][nextX] = true;

				// 물에 인접한 얼음이므로 다음 날에 백조가 탐색할 곳이므로 nextQ에 넣어준다
				if (lake[nextY][nextX] == 'X')
				{
					nextQ.push({ nextY, nextX });
					continue;
				}

				q.push({ nextY, nextX });
			}
		}
		
		if (flag)
			break;

		q = nextQ; //백조가 다음 날에 탐색할 곳이기 때문에 nextQ에 넣어준 것 q로 옮겨주기
        //아래에서 얼음을 물로 녺여주고 . 이 되니까 다음날 됐을 때 다시 탐색~!

		// 얼음을 녹이는 과정
        //얼음 녹이는 과정인데 왜 물 이였을때 넣었던 queue 사이즈를 이용하지.. -> 물 옆에 있는 얼음을 녹이는 과정이니까?
		int waterQSize = waterQ.size();
        //printf("물 사이즈: %d \n",waterQSize);
		while (waterQSize--)
		{
			int y = waterQ.front().first;
			int x = waterQ.front().second;
			waterQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextY = y + moveDir[i].y;
				int nextX = x + moveDir[i].x;

				if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
				{
					continue;
				}

				if (lake[nextY][nextX] == 'X')
				{
					lake[nextY][nextX] = '.';
					waterQ.push({ nextY, nextX });
				}
			}
		}
        //여기까지가 하루만에 일어나는 일
		day++;
	}

	cout << day << "\n";
	return 0;
}