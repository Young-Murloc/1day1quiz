/*
�־��� ���� �� 3���� ���� ������ �� �Ҽ��� �Ǵ� ����� ������ ���Ϸ��� �մϴ�. ���ڵ��� ����ִ� �迭 nums�� �Ű������� �־��� ��, nums�� �ִ� ���ڵ� �� ���� �ٸ� 3���� ��� ������ �� �Ҽ��� �Ǵ� ����� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
nums�� ����ִ� ������ ������ 3�� �̻� 50�� �����Դϴ�.
nums�� �� ���Ҵ� 1 �̻� 1,000 ������ �ڿ����̸�, �ߺ��� ���ڰ� ������� �ʽ��ϴ�.

dfs�� �̿�
*/

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

void dp(vector<int>& nums, vector<int>& output, int index = 0, int count = 0, int sum = 0) {
    if (index >= nums.size())
        return;

    sum += nums[index];

    for (int i = index; i < nums.size(); i++) {
        if (count == 2) {
            output.push_back(sum);
            return;
        }
        else {
            dp(nums, output, i + 1, count + 1, sum);
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> output;

    for (int i = 0; i < nums.size() - 2; i++) {
        dp(nums, output, i);
    }

    for (auto a : output) {
        if (isPrime(a))
            answer++;
    }

    return answer;
}