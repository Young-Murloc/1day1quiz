/*
�ſ� ���� �����ϴ� Leo�� ��� ������ ���ں� ������ K �̻����� ����� �ͽ��ϴ�. ��� ������ ���ں� ������ K �̻����� ����� ���� Leo�� ���ں� ������ ���� ���� �� ���� ������ �Ʒ��� ���� Ư���� ������� ���� ���ο� ������ ����ϴ�.

���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
Leo�� ��� ������ ���ں� ������ K �̻��� �� ������ �ݺ��Ͽ� �����ϴ�.

Leo�� ���� ������ ���ں� ������ ���� �迭 scoville�� ���ϴ� ���ں� ���� K�� �־��� ��, ��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

��/�켱����ť�� ���� �ð��� ���δ�

-> �ּڰ��� top���� ���� ���� �켱����ť�� ��� -> �ּڰ��� K�� �� -> ���� ���� or ���
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    int min = 0;
    int min2 = 0;
    int sco = 0;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (!pq.empty()) {
        if (pq.top() >= K) {
            break;
        }

        if (pq.top() < K && pq.size() == 1) {
            return -1;
        }

        min = pq.top();
        pq.pop();

        min2 = pq.top();
        pq.pop();

        sco = min + (min2 * 2);

        pq.push(sco);

        answer++;
    }

    return answer;
}