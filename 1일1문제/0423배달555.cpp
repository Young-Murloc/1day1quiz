/*
N개의 마을로 이루어진 나라가 있습니다. 이 나라의 각 마을에는 1부터 N까지의 번호가 각각 하나씩 부여되어 있습니다. 각 마을은 양방향으로 통행할 수 있는 도로로 연결되어 있는데, 서로 다른 마을 간에 이동할 때는 이 도로를 지나야 합니다. 도로를 지날 때 걸리는 시간은 도로별로 다릅니다. 현재 1번 마을에 있는 음식점에서 각 마을로 음식 배달을 하려고 합니다. 각 마을로부터 음식 주문을 받으려고 하는데, N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만 주문을 받으려고 합니다. 다음은 N = 5, K = 3인 경우의 예시입니다.
마을의 개수 N은 1 이상 50 이하의 자연수입니다.
road의 길이(도로 정보의 개수)는 1 이상 2,000 이하입니다.
road의 각 원소는 마을을 연결하고 있는 각 도로의 정보를 나타냅니다.
road는 길이가 3인 배열이며, 순서대로 (a, b, c)를 나타냅니다.
a, b(1 ≤ a, b ≤ N, a != b)는 도로가 연결하는 두 마을의 번호이며, c(1 ≤ c ≤ 10,000, c는 자연수)는 도로를 지나는데 걸리는 시간입니다.
두 마을 a, b를 연결하는 도로는 여러 개가 있을 수 있습니다.
한 도로의 정보가 여러 번 중복해서 주어지지 않습니다.
K는 음식 배달이 가능한 시간을 나타내며, 1 이상 500,000 이하입니다.
임의의 두 마을간에 항상 이동 가능한 경로가 존재합니다.
1번 마을에 있는 음식점이 K 이하의 시간에 배달이 가능한 마을의 개수를 return 하면 됩니다.

다익스트라 알고리즘 사용

1. 시작 노드와 직접적으로 연결된 모든 정점들의 거리를 비교해서 업데이트, 시작 노드를 방문한 노드로 체크
2. 방문한 정점들과 연결되어 있는 정점 중 비용이 가장 적게드는 정점 선택후 방문한 정점으로 선택
3. 2번 과정에 의해서 갱신될 수 있는 정점들의 거리를 갱신
4. 2~3번 반복
https://yabmoons.tistory.com/364


*/
#include <vector>
#include <queue>

using namespace std;

int distNumber[51];
vector<pair<int, int>> adj[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    fill(&distNumber[0], &distNumber[50] + 1, 1000000);           // distNumber 배달하는데 걸리는 시간을 저장 하는 변수 초기화
    priority_queue<pair<int, int>> pq;                           // 우선순위큐 선언

    for (int i = 0; i < road.size(); i++) {                           // 인접 노드 저장?
        adj[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        adj[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }

    distNumber[1] = 0;
    pq.push(make_pair(0, 1));                // 첫번째 노드 추가

    while (!pq.empty()) {
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if (dist > distNumber[now]) continue;
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i].first;
            int nextDist = dist + adj[now][i].second;

            if (nextDist < distNumber[next]) {
                distNumber[next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (distNumber[i] <= K) answer++;
    }

    return answer;
}