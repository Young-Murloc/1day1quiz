/*
�����ڴ� ������ ������ ����� �ظ��Դϴ�. ������ ���ι��� ���ǰ�翡 ���� ������ ���� ������ �մϴ�. �����ڴ� 1�� �������� ������ �������� ������ ���� ����ϴ�.

1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��, ���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> stu1 = { 1,2,3,4,5 };
    vector<int> stu2 = { 2,1,2,3,2,4,2,5 };
    vector<int> stu3 = { 3,3,1,1,2,2,4,4,5,5 };

    vector<int> score = { 0,0,0 };

    int maxNumber = 0;

    for (int i = 0; i < 10000; i++) {
        if (stu1.size() == answers.size()) {
            break;
        }

        stu1.push_back(stu1[i]);
    }

    for (int i = 0; i < 10000; i++) {
        if (stu2.size() == answers.size()) {
            break;
        }

        stu2.push_back(stu2[i]);
    }

    for (int i = 0; i < 10000; i++) {
        if (stu3.size() == answers.size()) {
            break;
        }

        stu3.push_back(stu3[i]);
    }

    for (int i = 0; i < answers.size(); i++) {
        if (stu1[i] == answers[i]) score[0]++;
        if (stu2[i] == answers[i]) score[1]++;
        if (stu3[i] == answers[i]) score[2]++;
    }

    maxNumber = max({ score[0],score[1],score[2] });

    if (maxNumber == score[0]) {
        answer.push_back(1);
    }

    if (maxNumber == score[1]) {
        answer.push_back(2);
    }

    if (maxNumber == score[2]) {
        answer.push_back(3);
    }

    return answer;
}