/*
�ڿ��� n�� �־����� ��, n�� ���� ū ���ڴ� ������ ���� ���� �մϴ�.

���� 1. n�� ���� ū ���ڴ� n���� ū �ڿ��� �Դϴ�.
���� 2. n�� ���� ū ���ڿ� n�� 2������ ��ȯ���� �� 1�� ������ �����ϴ�.
���� 3. n�� ���� ū ���ڴ� ���� 1, 2�� �����ϴ� �� �� ���� ���� �� �Դϴ�.
���� �� 78(1001110)�� ���� ū ���ڴ� 83(1010011)�Դϴ�.

�ڿ��� n�� �Ű������� �־��� ��, n�� ���� ū ���ڸ� return �ϴ� solution �Լ��� �ϼ����ּ���.

���� ����
n�� 1,000,000 ������ �ڿ��� �Դϴ�.
*/
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;

    bitset<32> bit;
    int oriNum = 0;
    int cmpNum = 0;

    bit = bitset<32>(n);

    for (int i = 0; i < bit.size(); i++) {
        if (bit[i] == 1)
            oriNum++;
    }

    while (oriNum != cmpNum) {
        n++;
        cmpNum = 0;
        bit = bitset<32>(n);
        for (int i = 0; i < bit.size(); i++) {
            if (bit[i] == 1)
                cmpNum++;
        }
    }

    answer = n;

    return answer;
}