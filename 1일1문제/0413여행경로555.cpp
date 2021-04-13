/*
�־��� �װ����� ��� �̿��Ͽ� �����θ� ¥���� �մϴ�. �׻� "ICN" ���׿��� ����մϴ�.

�װ��� ������ ��� 2���� �迭 tickets�� �Ű������� �־��� ��, �湮�ϴ� ���� ��θ� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��� ������ ���ĺ� �빮�� 3���ڷ� �̷�����ϴ�.
�־��� ���� ���� 3�� �̻� 10,000�� �����Դϴ�.
tickets�� �� �� [a, b]�� a ���׿��� b �������� ���� �װ����� �ִٴ� �ǹ��Դϴ�.
�־��� �װ����� ��� ����ؾ� �մϴ�.
���� ������ ��ΰ� 2�� �̻��� ��� ���ĺ� ������ �ռ��� ��θ� return �մϴ�.
��� ���ø� �湮�� �� ���� ���� �־����� �ʽ��ϴ�.

��� Ƽ���� Ȯ���ϱ� ���� DFS�˰��� ���
����� Ƽ�� Ȯ���ϴ� ���� �ʿ�
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool dfs(string start, vector<vector<string>> tickets, vector<bool>& useTickets, vector<string>& temp, vector<string>& answer, int count) {
    temp.push_back(start);

    if (count == tickets.size()) {
        answer = temp;
        return true;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start && useTickets[i] == false) {
            useTickets[i] = true;

            bool check = dfs(tickets[i][1], tickets, useTickets, temp, answer, count + 1);

            if (check) {
                return true;
            }

            useTickets[i] = false;
        }
    }

    temp.pop_back();

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> temp;
    vector<bool> useTickets(tickets.size(), false);

    sort(tickets.begin(), tickets.end());

    dfs("ICN", tickets, useTickets, temp, answer, 0);

    return answer;
}