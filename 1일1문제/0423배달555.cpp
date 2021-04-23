/*
N���� ������ �̷���� ���� �ֽ��ϴ�. �� ������ �� �������� 1���� N������ ��ȣ�� ���� �ϳ��� �ο��Ǿ� �ֽ��ϴ�. �� ������ ��������� ������ �� �ִ� ���η� ����Ǿ� �ִµ�, ���� �ٸ� ���� ���� �̵��� ���� �� ���θ� ������ �մϴ�. ���θ� ���� �� �ɸ��� �ð��� ���κ��� �ٸ��ϴ�. ���� 1�� ������ �ִ� ���������� �� ������ ���� ����� �Ϸ��� �մϴ�. �� �����κ��� ���� �ֹ��� �������� �ϴµ�, N���� ���� �߿��� K �ð� ���Ϸ� ����� ������ ���������� �ֹ��� �������� �մϴ�. ������ N = 5, K = 3�� ����� �����Դϴ�.
������ ���� N�� 1 �̻� 50 ������ �ڿ����Դϴ�.
road�� ����(���� ������ ����)�� 1 �̻� 2,000 �����Դϴ�.
road�� �� ���Ҵ� ������ �����ϰ� �ִ� �� ������ ������ ��Ÿ���ϴ�.
road�� ���̰� 3�� �迭�̸�, ������� (a, b, c)�� ��Ÿ���ϴ�.
a, b(1 �� a, b �� N, a != b)�� ���ΰ� �����ϴ� �� ������ ��ȣ�̸�, c(1 �� c �� 10,000, c�� �ڿ���)�� ���θ� �����µ� �ɸ��� �ð��Դϴ�.
�� ���� a, b�� �����ϴ� ���δ� ���� ���� ���� �� �ֽ��ϴ�.
�� ������ ������ ���� �� �ߺ��ؼ� �־����� �ʽ��ϴ�.
K�� ���� ����� ������ �ð��� ��Ÿ����, 1 �̻� 500,000 �����Դϴ�.
������ �� �������� �׻� �̵� ������ ��ΰ� �����մϴ�.
1�� ������ �ִ� �������� K ������ �ð��� ����� ������ ������ ������ return �ϸ� �˴ϴ�.

���ͽ�Ʈ�� �˰��� ���

1. ���� ���� ���������� ����� ��� �������� �Ÿ��� ���ؼ� ������Ʈ, ���� ��带 �湮�� ���� üũ
2. �湮�� ������� ����Ǿ� �ִ� ���� �� ����� ���� ���Ե�� ���� ������ �湮�� �������� ����
3. 2�� ������ ���ؼ� ���ŵ� �� �ִ� �������� �Ÿ��� ����
4. 2~3�� �ݺ�
https://yabmoons.tistory.com/364


*/
#include <vector>
#include <queue>

using namespace std;

int distNumber[51];
vector<pair<int, int>> adj[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    fill(&distNumber[0], &distNumber[50] + 1, 1000000);           // distNumber ����ϴµ� �ɸ��� �ð��� ���� �ϴ� ���� �ʱ�ȭ
    priority_queue<pair<int, int>> pq;                           // �켱����ť ����

    for (int i = 0; i < road.size(); i++) {                           // ���� ��� ����?
        adj[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        adj[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }

    distNumber[1] = 0;
    pq.push(make_pair(0, 1));                // ù��° ��� �߰�

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