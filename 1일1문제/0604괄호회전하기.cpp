/*
다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.

(), [], {} 는 모두 올바른 괄호 문자열입니다.
만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다. 예를 들어, [] 가 올바른 괄호 문자열이므로, ([]) 도 올바른 괄호 문자열입니다.
만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다. 예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.
대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다. 이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.

deque를 이용하여 문자열 회전
*/

#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> dq;
    int count = 0;      // count => 덱의 사이즈 저장

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