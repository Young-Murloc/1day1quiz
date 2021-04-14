/*
�����Ա� ������ �Ϸ��� �մϴ�. �����Ա� ������ ��(land)�� �� N�� 4���� �̷���� �ְ�, ��� ĭ���� ������ ���� �ֽ��ϴ�. 1����� ���� ������ �� �྿ ������ ��, �� ���� 4ĭ �� �� ĭ�� �����鼭 �����;� �մϴ�. ��, �����Ա� ���ӿ��� �� �྿ ������ ��, ���� ���� �����ؼ� ���� �� ���� Ư�� ��Ģ�� �ֽ��ϴ�.

���� ���,

| 1 | 2 | 3 | 5 |

| 5 | 6 | 7 | 8 |

| 4 | 3 | 2 | 1 |

�� ���� �־����ٸ�, 1�࿡�� �׹�° ĭ (5)�� �������, 2���� �׹�° ĭ (8)�� ���� �� �����ϴ�.

������ ����� ��� �������� ��, ���� �� �ִ� ������ �ִ밪�� return�ϴ� solution �Լ��� �ϼ��� �ּ���. �� ���� ���, 1���� �׹�° ĭ (5), 2���� ����° ĭ (7), 3���� ù��° ĭ (4) ���� ��� 16���� �ְ����� �ǹǷ� 16�� return �ϸ� �˴ϴ�.

���̳��� ���α׷��� / bottom to top / memorization
top to bottom�� �����Ѱ�?
*/

#include <vector>
#include <algorithm>

using namespace std;

int dp[100000][4];

void DP(vector<vector<int>> land) {

    for (int i = 0; i < land.size() - 1; i++) {
        dp[i + 1][0] = max(max(dp[i][1], dp[i][2]), dp[i][3]) + land[i + 1][0];
        dp[i + 1][1] = max(max(dp[i][0], dp[i][2]), dp[i][3]) + land[i + 1][1];
        dp[i + 1][2] = max(max(dp[i][0], dp[i][1]), dp[i][3]) + land[i + 1][2];
        dp[i + 1][3] = max(max(dp[i][0], dp[i][1]), dp[i][2]) + land[i + 1][3];
    }

    return;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;

    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];

    DP(land);

    for (int i = 0; i < 4; i++) {
        if (answer < dp[land.size() - 1][i]) {
            answer = dp[land.size() - 1][i];
        }
    }

    return answer;
}