/*
n���� ���� �ƴ� ������ �ֽ��ϴ�. �� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. ���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� �켱 Ž���� �̿�
    -> ����/��͸� �̿��Ͽ� ���� �� �� ����
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<int> numbers, int target, int depth, int sum, int& answer) {

    if (depth == numbers.size()) {
        if (target == sum) {
            answer++;
        }
        return;
    }

    dfs(numbers, target, depth + 1, sum + numbers[depth], answer);
    dfs(numbers, target, depth + 1, sum - numbers[depth], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(numbers, target, 0, 0, answer);

    return answer;
}