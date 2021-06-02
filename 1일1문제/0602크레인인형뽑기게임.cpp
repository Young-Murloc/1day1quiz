/*
ũ���� �۵� �� ������ �������� �ʴ� ���� ������ ���� ������ ���� ������ ũ������ �۵���Ű�� ��쿡�� �ƹ��� �ϵ� �Ͼ�� �ʽ��ϴ�. ���� �ٱ��ϴ� ��� ������ �� �� ���� ��ŭ ����� ũ�ٰ� �����մϴ�. (�׸������� ȭ��ǥ�� �������� 5ĭ������ ǥ���Ͽ���)

���� ȭ���� ������ ���°� ��� 2���� �迭 board�� ������ ���� ���� ũ������ �۵���Ų ��ġ�� ��� �迭 moves�� �Ű������� �־��� ��, ũ������ ��� �۵���Ų �� ��Ʈ���� ����� ������ ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���� �ݺ����� ���� board Ž��
rowŽ���� ���� ������ ����
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