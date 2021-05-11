/*
주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다. 숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항
nums에 들어있는 숫자의 개수는 3개 이상 50개 이하입니다.
nums의 각 원소는 1 이상 1,000 이하의 자연수이며, 중복된 숫자가 들어있지 않습니다.

dfs를 이용
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