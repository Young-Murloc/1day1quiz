/*
���ε��� ���� ������� ����Ʈ�� �̿��Ͽ� �����Ϸ��� �մϴ�. ����Ʈ�� �۾Ƽ� �� ���� �ִ� 2�� �ۿ� Ż �� ����, ���� ���ѵ� �ֽ��ϴ�.

���� ���, ������� �����԰� [70kg, 50kg, 80kg, 50kg]�̰� ����Ʈ�� ���� ������ 100kg�̶�� 2��° ����� 4��° ����� ���� Ż �� ������ 1��° ����� 3��° ����� ������ ���� 150kg�̹Ƿ� ����Ʈ�� ���� ������ �ʰ��Ͽ� ���� Ż �� �����ϴ�.

����Ʈ�� �ִ��� ���� ����Ͽ� ��� ����� �����Ϸ��� �մϴ�.

������� �����Ը� ���� �迭 people�� ����Ʈ�� ���� ���� limit�� �Ű������� �־��� ��, ��� ����� �����ϱ� ���� �ʿ��� ����Ʈ ������ �ּڰ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    vector<int>::iterator iter;
    int weight = 0;     //���� ��Ʈ �� ����
    int count = 0;      //���� ��Ʈ Ÿ�� ��� ��
    int size = people.size();   //�ߺ� ȣ���� ���� ����

    sort(people.begin(), people.end(), greater<int>());       //�������� ����

    iter = people.begin();          //���� �ϴ� �ð��� ���̱� ���� iter ���

    while (1) {
        if (*iter <= limit / 2) {         //���� ������ ������ ���� ���� ��� ������ ������� ������ 2�� ���� ��Ʈ ž�� ����, 1�� ���� ��� 1�� �� ����
            answer = answer + ((size - count) / 2) + ((size - count) % 2);
            return answer;
        }

        if (*iter + people.back() <= limit) {     //(�Ǿ� + �ǵ� <= ���� ����)�� �����ϴ� ��� �� �� ���� ����
            people.pop_back();
            count++;
        }

        count++;
        iter++;
        answer++;

        if (count == size) {
            return answer;
        }
    }
}