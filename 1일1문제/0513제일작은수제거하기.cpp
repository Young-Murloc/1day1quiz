/*
������ ������ �迭, arr ���� ���� ���� ���� ������ �迭�� �����ϴ� �Լ�, solution�� �ϼ����ּ���. ��, �����Ϸ��� �迭�� �� �迭�� ��쿣 �迭�� -1�� ä�� �����ϼ���. ������� arr�� [4,3,2,1]�� ���� [4,3,2]�� ���� �ϰ�, [10]�� [-1]�� ���� �մϴ�.

���� ����
arr�� ���� 1 �̻��� �迭�Դϴ�.
�ε��� i, j�� ���� i �� j�̸� arr[i] �� arr[j] �Դϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = 1000;
    int index = 0;

    if (arr.size() == 1) {
        answer.push_back(-1);
    }
    else {
        for (int i = 0; i < arr.size(); i++) {
            if (min > arr[i]) {
                min = arr[i];
                index = i;
            }
        }
        arr.erase(arr.begin() + index);

        answer = arr;
    }

    return answer;
}