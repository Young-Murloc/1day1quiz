/*
����� ���� ����(�� ����) rows, ���� ����(�� ����) columns, �׸��� ȸ������ ��� queries�� �־��� ��, �� ȸ������ �迭�� ������ ��, �� ȸ���� ���� ��ġ�� �ٲ� ���ڵ� �� ���� ���� ���ڵ��� ������� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

1. �迭 ����
2. ��� ȸ�� -> ȸ���ϴ� ���� ���Ϳ� �ְ� board �迭�� �� ����?
3. ���� ������ answer�� ����

<�ؾ��Ұ�>

ȸ�� ������� �� ���� �� ȸ��
*/

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board;
    vector<int> temp;
    deque<int> dq;
    int count = 1;
    int min = 10001;        // answer�� �� �ּҰ� ����

    int x, y;

    // �迭 ����
    for (int i = 0; i < rows; i++) {
        temp.clear();
        for (int j = 0; j < columns; j++) {
            temp.push_back(count);
            count++;
        }
        board.push_back(temp);
    }

    // �迭 ȸ��
    for (int i = 0; i < queries.size(); i++) {
        min = 10001;
        dq.clear();

        for (int j = queries[i][0] - 1; j <= queries[i][2] - 1; j++) {
            if (j == queries[i][0] - 1 || j == queries[i][2] - 1) {
                for (int t = queries[i][1] - 1; t <= queries[i][3] - 1; t++) {
                    dq.push_back(board[j][t]);
                }
            }
            else {
                dq.push_back(board[j][queries[i][1] - 1]);
                dq.push_back(board[j][queries[i][3] - 1]);
            }
        }

        for (int z = 0; z < dq.size(); z++) {
            if (min > dq[z]) {
                min = dq[z];
            }
        }

        answer.push_back(min);


        for (int z = 0; z < dq.size(); z++) {
            cout << dq[z] << endl;
        }

        return answer;

        for (int j = queries[i][0] - 1; j <= queries[i][2] - 1; j++) {
            if (j == queries[i][0] - 1 || j == queries[i][2] - 1) {
                for (int t = queries[i][1] - 1; t <= queries[i][3] - 1; t++) {
                    board[j][t] = dq.front();
                    dq.pop_front();
                }
            }
            else {
                board[j][queries[i][1] - 1] = dq.front();
                dq.pop_front();
                board[j][queries[i][3] - 1] = dq.front();
                dq.pop_front();
            }
        }
    }

    return answer;
}