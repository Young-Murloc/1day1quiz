/*
�Ǻ���ġ ���� F(0) = 0, F(1) = 1�� ��, 1 �̻��� n�� ���Ͽ� F(n) = F(n-1) + F(n-2) �� ����Ǵ� �� �Դϴ�.

�������

F(2) = F(0) + F(1) = 0 + 1 = 1
F(3) = F(1) + F(2) = 1 + 1 = 2
F(4) = F(2) + F(3) = 1 + 2 = 3
F(5) = F(3) + F(4) = 2 + 3 = 5
�� ���� �̾����ϴ�.

2 �̻��� n�� �ԷµǾ��� ��, n��° �Ǻ���ġ ���� 1234567���� ���� �������� �����ϴ� �Լ�, solution�� �ϼ��� �ּ���.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> dp;

int fibo(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = ((fibo(n - 1) % 1234567) + (fibo(n - 2) % 1234567)) % 1234567;          //���� �׻� int�� �����Ҽ� �ְ� (a+b)%c = ((a%c)+(b%c))%c

    return dp[n];
}

int solution(int n) {
    int answer = 0;
    dp.resize(n + 1, -1);          //�޸��� ���� �ʱ�ȭ

    answer = fibo(n);

    return answer;
}