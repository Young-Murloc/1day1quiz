/*
stack/queue
���α׷��ӽ� �������� ��� ���� �۾��� ���� ���Դϴ�. �� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� �ֽ��ϴ�.

��, �� ����� ���߼ӵ��� ��� �ٸ��� ������ �ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�, �̶� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����˴ϴ�.

���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� ���� �迭 progresses�� �� �۾��� ���� �ӵ��� ���� ���� �迭 speeds�� �־��� �� �� �������� �� ���� ����� �����Ǵ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
�۾��� ����(progresses, speeds�迭�� ����)�� 100�� �����Դϴ�.
�۾� ������ 100 �̸��� �ڿ����Դϴ�.
�۾� �ӵ��� 100 ������ �ڿ����Դϴ�.
������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����ٰ� �����մϴ�. ���� ��� �������� 95%�� �۾��� ���� �ӵ��� �Ϸ翡 4%��� ������ 2�� �ڿ� �̷�����ϴ�.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> days;
    int day = 0;

    int count = 1;

    for (int i = 0; i < progresses.size(); i++) {                 //���� �ӵ��� ���� �ϼ��Ǵµ� �ɸ��� �ð� ���
        day = 0;
        while (1) {
            if (progresses[i] < 100) {
                day++;
                progresses[i] += speeds[i];
            }
            else {
                days.push_back(day);
                break;
            }
        }
    }

    for (int i = 0; i < days.size() - 1; i++) {                     //�ɸ� �ð��� ����ϱ� ���ϰ� ����
        if (days[i] > days[i + 1]) {
            days[i + 1] = days[i];
        }
    }

    for (int i = 0; i < days.size() - 1; i++) {                       //����� �ɸ� �ð��� ������� �� ����

        if (days[i] == days[i + 1]) {
            count++;
        }

        if (days[i] != days[i + 1]) {
            answer.push_back(count);
            count = 1;
        }

        if (i == days.size() - 2) {
            answer.push_back(count);
        }
    }

    return answer;
}