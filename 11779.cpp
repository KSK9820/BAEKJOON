//다익스트라-우선순위큐
//최단거리가 가장 짧은 노드를 선택 하는 과정 -> 우선순위 큐를 이용하는 방식

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1001
#define INF 1e9

vector<pair<int, int>>graph[MAX];
int Route[MAX];
vector<int> printRoute;
int d[MAX];
int n, m, s, e;

void dijkstra() {
	priority_queue<pair<int, int>>pq;	//거리, 노드 인덱스
	pq.push(make_pair(0,s));
	d[s] = 0;

	while (!pq.empty()) {
		//priority_queue는 큰 것이 앞에 오도록 하는 max heap
		int dist = -pq.top().first;	//가중치가 작은게 앞으로 오도록
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;
		
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				Route[graph[now][i].first] = now;
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
				//큐에 음수를 넣는 이유는 가장 작은값을 제일 위에 두기 위해서
			}
		}
	}
	
	
}

void print() {
	cout << d[e] << endl;

	int tmp = e;
	while (tmp) {
		printRoute.push_back(tmp);
		tmp = Route[tmp];
	}
	cout << printRoute.size() << endl;

	for (int i = printRoute.size() - 1; i >= 0; i--)
		cout << printRoute[i] << " ";

}

int main(void) {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) d[i] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back(make_pair(b, c));
	}
	cin >> s >> e;

	fill(d, d + MAX, INF);

	dijkstra();

	print();

	return 0;
}