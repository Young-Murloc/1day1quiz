/*
īī���� ���Ӻ��� �Ϲݱ� �ű� ���񽺷� ��Ʈ ������ ����ϱ�� �ߴ�. ��Ʈ ������ ��Ʈ�ǿ� ��Ʈ�� �� ���� ���� �� ������ �հ�� �Ƿ��� �ܷ�� ��������, ��ΰ� ������ ��� �� �ִ�.
�� �Ի��� ������ �ڵ� �Ƿ��� �����޾� ������ �ٽ� �κ��� ���� ��� ������ �ð� �Ǿ���. ��Ʈ ������ ���� ��� ������ �Ʒ��� ����.

��Ʈ ������ �� 3���� ��ȸ�� �����ȴ�.
�� ��ȸ���� ���� �� �ִ� ������ 0������ 10�������̴�.
������ �Բ� Single(S), Double(D), Triple(T) ������ �����ϰ� �� ���� ��÷ �� �������� 1����, 2����, 3���� (����1 , ����2 , ����3 )���� ���ȴ�.
�ɼ����� ��Ÿ��(*) , ������(#)�� �����ϸ� ��Ÿ��(*) ��÷ �� �ش� ������ �ٷ� ���� ���� ������ �� 2��� �����. ������(#) ��÷ �� �ش� ������ ���̳ʽ��ȴ�.
��Ÿ��(*)�� ù ��° ��ȸ������ ���� �� �ִ�. �� ��� ù ��° ��Ÿ��(*)�� ������ 2�谡 �ȴ�. (���� 4�� ����)
��Ÿ��(*)�� ȿ���� �ٸ� ��Ÿ��(*)�� ȿ���� ��ø�� �� �ִ�. �� ��� ��ø�� ��Ÿ��(*) ������ 4�谡 �ȴ�. (���� 4�� ����)
��Ÿ��(*)�� ȿ���� ������(#)�� ȿ���� ��ø�� �� �ִ�. �� ��� ��ø�� ������(#)�� ������ -2�谡 �ȴ�. (���� 5�� ����)
Single(S), Double(D), Triple(T)�� �������� �ϳ��� �����Ѵ�.
��Ÿ��(*), ������(#)�� �������� �� �� �ϳ��� ������ �� ������, �������� ���� ���� �ִ�.
0~10�� ������ ���� S, D, T, *, #�� ������ ���ڿ��� �Էµ� �� �������� ��ȯ�ϴ� �Լ��� �ۼ��϶�.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string temp = "";
    int num = -1;
    vector<int> vec;
    int count = 0;

    for (int i = 0; i < dartResult.length(); i++) {

        if (dartResult[i] >= 48 && dartResult[i] <= 57) {
            temp += dartResult[i];
            num = stoi(temp);

            if (num > 10) {
                temp = dartResult[i];
                num = stoi(temp);
            }
        }

        if (dartResult[i] == 83) {        // S
            vec.push_back(num);
            count++;
        }

        if (dartResult[i] == 68) {        // D
            vec.push_back(num * num);
            count++;
        }

        if (dartResult[i] == 84) {        // T
            vec.push_back(num * num * num);
            count++;
        }

        if (dartResult[i] == 42) {        // *
            if (count >= 1) {
                vec[count - 1] = vec[count - 1] * 2;
                vec[count - 2] = vec[count - 2] * 2;
            }
            else {
                vec[count - 1] = vec[count - 1] * 2;
            }
        }

        if (dartResult[i] == 35) {        // #
            vec[count - 1] = vec[count - 1] * -1;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        answer += vec[i];
    }

    return answer;
}