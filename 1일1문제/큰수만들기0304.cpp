/*
� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

�׸��� �˰���
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int count = 1;
    bool check = false;

    while (count <= k) {

        for (int i = 0; i < number.size() - 1; i++) {
            if (int(number[i]) < int(number[i + 1])) {
                number.erase(i, 1);
                check = true;
                break;
            }
        }

        if (check == false) {
            number.pop_back();
        }

        check = false;
        count++;
    }

    answer = number;

    return answer;
}