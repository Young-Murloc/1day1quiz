/*
행렬의 세로 길이(행 개수) rows, 가로 길이(열 개수) columns, 그리고 회전들의 목록 queries가 주어질 때, 각 회전들을 배열에 적용한 뒤, 그 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

1. 배열 생성
2. 행렬 회전 -> 회전하는 값을 벡터에 넣고 board 배열에 재 삽입?
3. 가장 작은수 answer에 삽입
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

        for (int j = queries[i][1] - 1; j < queries[i][3] - 1; j++) {
            dq.push_back(board[queries[i][0] - 1][j]);

            if (min > board[queries[i][0] - 1][j])
                min = board[queries[i][0] - 1][j];
        }

        for (int j = queries[i][0] - 1; j < queries[i][2] - 1; j++) {
            dq.push_back(board[j][queries[i][3] - 1]);

            if (min > board[j][queries[i][3] - 1])
                min = board[j][queries[i][3] - 1];
        }

        for (int j = queries[i][3] - 1; j > queries[i][1] - 1; j--) {
            dq.push_back(board[queries[i][2] - 1][j]);

            if (min > board[queries[i][2] - 1][j])
                min = board[queries[i][2] - 1][j];
        }

        for (int j = queries[i][2] - 1; j > queries[i][0] - 1; j--) {
            dq.push_back(board[j][queries[i][1] - 1]);

            if (min > board[j][queries[i][1] - 1])
                min = board[j][queries[i][1] - 1];
        }

        answer.push_back(min);

        dq.push_front(dq.back());
        dq.pop_back();

        auto itr = dq.begin();

        for (int j = queries[i][1] - 1; j < queries[i][3] - 1; j++) {
            board[queries[i][0] - 1][j] = *itr;
            itr++;
        }

        for (int j = queries[i][0] - 1; j < queries[i][2] - 1; j++) {
            board[j][queries[i][3] - 1] = *itr;
            itr++;
        }

        for (int j = queries[i][3] - 1; j > queries[i][1] - 1; j--) {
            board[queries[i][2] - 1][j] = *itr;
            itr++;
        }

        for (int j = queries[i][2] - 1; j > queries[i][0] - 1; j--) {
            board[j][queries[i][1] - 1] = *itr;
            itr++;
        }
    }

    return answer;
}