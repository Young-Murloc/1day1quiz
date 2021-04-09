/*
�̷��� A �� C �� B�� ������ ó���ϸ� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 9ms(= (3 + 7 + 17) / 3)�� �˴ϴ�.

�� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�]�� ���� 2���� �迭 jobs�� �Ű������� �־��� ��, �۾��� ��û���� ������� �ɸ� �ð��� ����� ���� ���̴� ������� ó���ϸ� ����� �󸶰� �Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���. (��, �Ҽ��� ������ ���� �����ϴ�)

���� ����
jobs�� ���̴� 1 �̻� 500 �����Դϴ�.
jobs�� �� ���� �ϳ��� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�] �Դϴ�.
�� �۾��� ���� �۾��� ��û�Ǵ� �ð��� 0 �̻� 1,000 �����Դϴ�.
�� �۾��� ���� �۾��� �ҿ�ð��� 1 �̻� 1,000 �����Դϴ�.
�ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�.

<���ǻ���>
�켱���� ť = ��û ��⿭
    �۾� �ð��� ������������ ����


*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct cmp {                                                 // 2���� �켱���� ť���� 2��° ���ҵ�� �������� ����
    bool operator()(vector<int> v1, vector<int> v2) {
        return v1[1] > v2[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;       // ���� �ð�
    int id = 0;         // jobs�� �ε��� ����
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;        //cmp ����ü ���

    sort(jobs.begin(), jobs.end());

    while (id < jobs.size() || !pq.empty()) {
        if (jobs.size() > id && time >= jobs[id][0]) {
            pq.push(jobs[id++]);        // ���� �Ŀ� id�� ����
            continue;
        }

        if (!pq.empty()) {                // �켱���� ť(��⿭)�� �������� answer�� �Է�
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else {
            time = jobs[id][0];
        }
    }

    return answer / jobs.size();
}