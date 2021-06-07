/*
����� ���� ����(�� ����) rows, ���� ����(�� ����) columns, �׸��� ȸ������ ��� queries�� �־��� ��, �� ȸ������ �迭�� ������ ��, �� ȸ���� ���� ��ġ�� �ٲ� ���ڵ� �� ���� ���� ���ڵ��� ������� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

1. �迭 ����
2. ��� ȸ�� -> ȸ���ϴ� ���� ���Ϳ� �ְ� board �迭�� �� ����?
3. ���� ������ answer�� ����
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