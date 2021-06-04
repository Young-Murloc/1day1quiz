/*
���� ��Ģ�� ��Ű�� ���ڿ��� �ùٸ� ��ȣ ���ڿ��̶�� �����մϴ�.

(), [], {} �� ��� �ùٸ� ��ȣ ���ڿ��Դϴ�.
���� A�� �ùٸ� ��ȣ ���ڿ��̶��, (A), [A], {A} �� �ùٸ� ��ȣ ���ڿ��Դϴ�. ���� ���, [] �� �ùٸ� ��ȣ ���ڿ��̹Ƿ�, ([]) �� �ùٸ� ��ȣ ���ڿ��Դϴ�.
���� A, B�� �ùٸ� ��ȣ ���ڿ��̶��, AB �� �ùٸ� ��ȣ ���ڿ��Դϴ�. ���� ���, {} �� ([]) �� �ùٸ� ��ȣ ���ڿ��̹Ƿ�, {}([]) �� �ùٸ� ��ȣ ���ڿ��Դϴ�.
���ȣ, �߰�ȣ, �׸��� �Ұ�ȣ�� �̷���� ���ڿ� s�� �Ű������� �־����ϴ�. �� s�� �������� x (0 �� x < (s�� ����)) ĭ��ŭ ȸ�������� �� s�� �ùٸ� ��ȣ ���ڿ��� �ǰ� �ϴ� x�� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

deque�� �̿��Ͽ� ���ڿ� ȸ��
*/

#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> dq;
    int count = 0;      // count => ���� ������ ����

    vector<char> vec;

    for (int i = 0; i < s.length(); i++) {
        dq.push_back(s[i]);
    }

    count = dq.size();

    for (int i = 0; i < count; i++) {
        dq.push_back(dq.front());
        dq.pop_front();

        auto itr = dq.begin();
        vec.push_back(*itr);
        itr++;

        for (auto itr = dq.begin() + 1; itr != dq.end(); itr++) {
            if (*itr == ')' || *itr == '}' || *itr == ']') {
                if (*itr == ')') {
                    if (vec.back() == '(') {
                        vec.pop_back();
                    }
                }
                else if (*itr == '}') {
                    if (vec.back() == '{') {
                        vec.pop_back();
                    }
                }
                else {
                    if (vec.back() == '[') {
                        vec.pop_back();
                    }
                }
            }
            else {
                vec.push_back(*itr);
            }
        }

        if (vec.size() == 0) {
            answer++;
        }

        vec.clear();
    }

    if (s.length() % 2 != 0)
        return 0;

    return answer;
}