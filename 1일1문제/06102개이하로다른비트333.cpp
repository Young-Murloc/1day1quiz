/*
�������� ��� �迭 numbers�� �Ű������� �־����ϴ�. numbers�� ��� ���鿡 ���Ͽ� �� ���� f ���� �迭�� ���ʴ�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

¦�� 2n -> 2n+1

Ȧ�� n -> n-1 �ڸ��� ��Ʈ�� ���ϱ�
ex) f(101111) = 000111
*/

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long bit;

    for (int i = 0; i < numbers.size(); i++) {
        bit = 1;

        if (numbers[i] % 2 == 0) {
            answer.push_back(numbers[i] + 1);
        }
        else {
            while (true) {
                if ((numbers[i] & bit) == 0)
                    break;

                bit *= 2;
            }

            bit = bit / 2;
            answer.push_back(numbers[i] + bit);
        }
    }

    return answer;
}