/*
행렬의 세로 길이(행 개수) rows, 가로 길이(열 개수) columns, 그리고 회전들의 목록 queries가 주어질 때, 각 회전들을 배열에 적용한 뒤, 그 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

1. 배열 생성
2. 행렬 회전 -> 회전하는 값을 벡터에 넣고 board 배열에 재 삽입?
3. 가장 작은수 answer에 삽입

<해야할것>

회전 순서대로 덱 생성 후 회전
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
    int min = 10001;        // answer에 들어갈 최소값 저장

    int x, y;

    // 배열 생성
    for (int i = 0; i < rows; i++) {
        temp.clear();
        for (int j = 0; j < columns; j++) {
            temp.push_back(count);
            count++;
        }
        board.push_back(temp);
    }

    // 배열 회전
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