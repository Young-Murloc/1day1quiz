/*
단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    if (s.size() % 2 != 0) {          //홀수
        if (s.size() == 1) {
            answer = s;
        }
        else {
            answer.push_back(s[s.size() / 2]);
        }
    }
    else {                       //짝수
        if (s.size() == 2) {
            answer = s;
        }
        else {
            answer.push_back(s[s.size() / 2 - 1]);
            answer.push_back(s[s.size() / 2]);
        }
    }

    return answer;
}