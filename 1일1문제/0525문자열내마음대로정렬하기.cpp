/*
���ڿ��� ������ ����Ʈ strings��, ���� n�� �־����� ��, �� ���ڿ��� �ε��� n��° ���ڸ� �������� �������� �����Ϸ� �մϴ�. ���� ��� strings�� ["sun", "bed", "car"]�̰� n�� 1�̸� �� �ܾ��� �ε��� 1�� ���� "u", "e", "a"�� strings�� �����մϴ�.

���� ����
strings�� ���� 1 �̻�, 50������ �迭�Դϴ�.
strings�� ���Ҵ� �ҹ��� ���ĺ����� �̷���� �ֽ��ϴ�.
strings�� ���Ҵ� ���� 1 �̻�, 100������ ���ڿ��Դϴ�.
��� strings�� ������ ���̴� n���� Ů�ϴ�.
�ε��� 1�� ���ڰ� ���� ���ڿ��� ���� �� ���, ���������� �ռ� ���ڿ��� ���ʿ� ��ġ�մϴ�.

value�� �������� sort
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, string>& a, const pair<string, string>& b) {
    if (a.second == b.second) return a.first < b.first;

    return a.second < b.second;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    map<string, string> temp;
    string tempS;

    for (int i = 0; i < strings.size(); i++) {
        tempS = strings[i][n];
        temp[strings[i]] = tempS;
    }

    vector<pair<string, string>> v(temp.begin(), temp.end());

    sort(v.begin(), v.end(), cmp);

    for (auto itr = v.begin(); itr != v.end(); itr++) {
        answer.push_back(itr->first);
    }

    return answer;
}