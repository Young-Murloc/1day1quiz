/*
��ȣ�� �ٸ��� ¦�������ٴ� ���� '(' ���ڷ� �������� �ݵ�� ¦��� ')' ���ڷ� ������ �Ѵٴ� ���Դϴ�. ���� ���

"()()" �Ǵ� "(())()" �� �ùٸ� ��ȣ�Դϴ�.
")()(" �Ǵ� "(()(" �� �ùٸ��� ���� ��ȣ�Դϴ�.
'(' �Ǵ� ')' �θ� �̷���� ���ڿ� s�� �־����� ��, ���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return �ϰ�, �ùٸ��� ���� ��ȣ�̸� false�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
���ڿ� s�� ���� : 100,000 ������ �ڿ���
���ڿ� s�� '(' �Ǵ� ')' �θ� �̷���� �ֽ��ϴ�.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    vector<int> stack;
    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            sum += 1;
            stack.push_back(sum);
        }
        else {
            sum += -1;
            stack.push_back(sum);
        }
    }

    for (int i = 0; i < stack.size(); i++) {
        if (stack[i] == -1) {
            answer = false;
        }
    }

    if (sum != 0) {
        answer = false;
    }

    return answer;
}