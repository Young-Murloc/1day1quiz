/*
크레인 작동 시 인형이 집어지지 않는 경우는 없으나 만약 인형이 없는 곳에서 크레인을 작동시키는 경우에는 아무런 일도 일어나지 않습니다. 또한 바구니는 모든 인형이 들어갈 수 있을 만큼 충분히 크다고 가정합니다. (그림에서는 화면표시 제약으로 5칸만으로 표현하였음)

게임 화면의 격자의 상태가 담긴 2차원 배열 board와 인형을 집기 위해 크레인을 작동시킨 위치가 담긴 배열 moves가 매개변수로 주어질 때, 크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 return 하도록 solution 함수를 완성해주세요.

이중 반복문을 통해 board 탐색
row탐색중 인형 뽑을시 정지
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> con;

    for (int i = 0; i < moves.size(); i++) {
        int row = board.size();
        int col = moves[i] - 1;

        for (int j = 0; j < row; j++) {
            if (board[j][col] != 0) {
                if (!con.empty()) {
                    if (con[con.size() - 1] == board[j][col]) {
                        con.pop_back();
                        answer += 2;
                    }
                    else {
                        con.push_back(board[j][col]);
                    }
                }
                else {
                    con.push_back(board[j][col]);
                }
                board[j][col] = 0;
                break;
            }
            else {
                continue;
            }
        }
    }

    return answer;
}