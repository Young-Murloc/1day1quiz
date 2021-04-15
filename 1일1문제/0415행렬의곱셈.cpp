/*
2���� ��� arr1�� arr2�� �Է¹޾�, arr1�� arr2�� ���� ����� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.

���� ����
��� arr1, arr2�� ��� ���� ���̴� 2 �̻� 100 �����Դϴ�.
��� arr1, arr2�� ���Ҵ� -10 �̻� 20 ������ �ڿ����Դϴ�.
���� �� �ִ� �迭�� �־����ϴ�.

��� �� -> 3�� �ݺ��� ��� -> ������ ������ ����
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int sum = 0;
    vector<int> temp;

    for (int i = 0; i < arr1.size(); i++) {
        temp.clear();
        for (int j = 0; j < arr2[0].size(); j++) {
            sum = 0;
            for (int k = 0; k < arr1[0].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }

    return answer;
}