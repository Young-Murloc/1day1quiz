/*
���� ���� ������ �������� ū ��ο� ������. �׳డ ���� ������ ��õ���� �뼺���� �ŵ�����, ���� �ű� ������� ���� �ް��� ���̴�. ������ �ű� ����ڿ� ���� ����� ���̿� �������� ���̰� �ʹ� ū ���� ��������.

�� ������ ��� �ұ� ��� �� �׳�� �������� ���� �ð��� �÷��� ���̵��� �����ϱ�� �ߴ�. ���� ���� �����ڶ� ��κ��� ������ ���� ����������, �������� ���ϴ� �κп��� ���⿡ ������ ���Ҵ�. �������� ���� �������� ���ϴ� �ڵ带 �ϼ��϶�.

�������� ������ ���� �����Ѵ�.
���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� / ���������� ������ �÷��̾� ��
��ü ���������� ���� N, ������ �̿��ϴ� ����ڰ� ���� �����ִ� ���������� ��ȣ�� ��� �迭 stages�� �Ű������� �־��� ��, �������� ���� ������������ ������������ ���������� ��ȣ�� ����ִ� �迭�� return �ϵ��� solution �Լ��� �ϼ��϶�.

���ѻ���
���������� ���� N�� 1 �̻� 500 ������ �ڿ����̴�.
stages�� ���̴� 1 �̻� 200,000 �����̴�.
stages���� 1 �̻� N + 1 ������ �ڿ����� ����ִ�.
�� �ڿ����� ����ڰ� ���� ���� ���� ���������� ��ȣ�� ��Ÿ����.
��, N + 1 �� ������ ��������(N ��° ��������) ���� Ŭ���� �� ����ڸ� ��Ÿ����.
���� �������� ���� ���������� �ִٸ� ���� ��ȣ�� ���������� ���� ������ �ϸ� �ȴ�.
���������� ������ ������ ���� ��� �ش� ���������� �������� 0 ���� �����Ѵ�.

2 [1,1]
*/

/*
���� ���� ������ �������� ū ��ο� ������. �׳డ ���� ������ ��õ���� �뼺���� �ŵ�����, ���� �ű� ������� ���� �ް��� ���̴�. ������ �ű� ����ڿ� ���� ����� ���̿� �������� ���̰� �ʹ� ū ���� ��������.

�� ������ ��� �ұ� ��� �� �׳�� �������� ���� �ð��� �÷��� ���̵��� �����ϱ�� �ߴ�. ���� ���� �����ڶ� ��κ��� ������ ���� ����������, �������� ���ϴ� �κп��� ���⿡ ������ ���Ҵ�. �������� ���� �������� ���ϴ� �ڵ带 �ϼ��϶�.

�������� ������ ���� �����Ѵ�.
���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� / ���������� ������ �÷��̾� ��
��ü ���������� ���� N, ������ �̿��ϴ� ����ڰ� ���� �����ִ� ���������� ��ȣ�� ��� �迭 stages�� �Ű������� �־��� ��, �������� ���� ������������ ������������ ���������� ��ȣ�� ����ִ� �迭�� return �ϵ��� solution �Լ��� �ϼ��϶�.

���ѻ���
���������� ���� N�� 1 �̻� 500 ������ �ڿ����̴�.
stages�� ���̴� 1 �̻� 200,000 �����̴�.
stages���� 1 �̻� N + 1 ������ �ڿ����� ����ִ�.
�� �ڿ����� ����ڰ� ���� ���� ���� ���������� ��ȣ�� ��Ÿ����.
��, N + 1 �� ������ ��������(N ��° ��������) ���� Ŭ���� �� ����ڸ� ��Ÿ����.
���� �������� ���� ���������� �ִٸ� ���� ��ȣ�� ���������� ���� ������ �ϸ� �ȴ�.
���������� ������ ������ ���� ��� �ش� ���������� �������� 0 ���� �����Ѵ�.

***(int)a / (float)b = a/b(�Ǽ��� ���)***
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, float>& a, const pair<int, float>& b) {
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, float> rate;

    float fail = 0;
    float player = 0;

    for (int i = 1; i <= N; i++) {
        fail = 0;
        player = 0;

        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] >= i)
                player++;

            if (stages[j] == i)
                fail++;
        }

        if (player == 0) {
            rate[i] = 0;
        }
        else {
            rate[i] = fail / player;
        }
    }

    vector<pair<int, float>> vec(rate.begin(), rate.end());

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < vec.size(); i++) {
        answer.push_back(vec[i].first);
    }

    return answer;
}

/*
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> fail;
    vector<int> chall;
    map<int, int> order;

    int clear = 0;          // Ŭ������ ���
    int challenge = 0;      // ������ ���

    int lcmN = 0;

    for (int i = 0; i < N; i++) {
        clear = 0;
        challenge = 0;

        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] > i + 1)
                clear++;

            if (stages[j] >= i + 1)
                challenge++;
        }

        fail.push_back(challenge - clear);
        chall.push_back(challenge);
    }

    lcmN = chall[0];

    for (int i = 1; i < chall.size(); i++) {
        lcmN = lcm(lcmN, chall[i]);
    }

    //floating point exception
    for (int i = 0; i < chall.size(); i++) {
        int temp = lcmN / chall[i];

        order[i + 1] = temp * fail[i];
    }

    vector<pair<int, int>> vec(order.begin(), order.end());

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < vec.size(); i++) {
        answer.push_back(vec[i].first);
    }

    return answer;
}
*/