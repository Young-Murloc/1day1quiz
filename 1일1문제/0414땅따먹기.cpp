/*
땅따먹기 게임을 하려고 합니다. 땅따먹기 게임의 땅(land)은 총 N행 4열로 이루어져 있고, 모든 칸에는 점수가 쓰여 있습니다. 1행부터 땅을 밟으며 한 행씩 내려올 때, 각 행의 4칸 중 한 칸만 밟으면서 내려와야 합니다. 단, 땅따먹기 게임에는 한 행씩 내려올 때, 같은 열을 연속해서 밟을 수 없는 특수 규칙이 있습니다.

예를 들면,

| 1 | 2 | 3 | 5 |

| 5 | 6 | 7 | 8 |

| 4 | 3 | 2 | 1 |

로 땅이 주어졌다면, 1행에서 네번째 칸 (5)를 밟았으면, 2행의 네번째 칸 (8)은 밟을 수 없습니다.

마지막 행까지 모두 내려왔을 때, 얻을 수 있는 점수의 최대값을 return하는 solution 함수를 완성해 주세요. 위 예의 경우, 1행의 네번째 칸 (5), 2행의 세번째 칸 (7), 3행의 첫번째 칸 (4) 땅을 밟아 16점이 최고점이 되므로 16을 return 하면 됩니다.

다이나믹 프로그래밍 / bottom to top / memorization
top to bottom이 가능한가?
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