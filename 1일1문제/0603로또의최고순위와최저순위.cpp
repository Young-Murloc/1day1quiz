/*
�ο찡 ������ �ζ� ��ȣ�� ���� �迭 lottos, ��÷ ��ȣ�� ���� �迭 win_nums�� �Ű������� �־����ϴ�. �̶�, ��÷ ������ �ְ� ������ ���� ������ ���ʴ�� �迭�� ��Ƽ� return �ϵ��� solution �Լ��� �ϼ����ּ���.

�ߺ����� �ʴ� ���� ������ �����̳� map�� �̿��ϸ� ���� �ذ� ����
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int prize(int num) {
    if (num == 6)
        return 1;
    else if (num == 5)
        return 2;
    else if (num == 4)
        return 3;
    else if (num == 3)
        return 4;
    else if (num == 2)
        return 5;
    else
        return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int, int> check;
    int min = 0;
    int max = 0;

    for (int i = 0; i < lottos.size(); i++) {
        check[lottos[i]]++;
        check[win_nums[i]]++;
    }

    for (auto itr = check.begin(); itr != check.end(); itr++) {
        if (itr->second >= 2 && itr->first != 0) {
            min++;
        }

        if (itr->first == 0) {
            max = itr->second;
        }
    }

    max += min;

    answer.push_back(prize(max));

    answer.push_back(prize(min));

    return answer;
}