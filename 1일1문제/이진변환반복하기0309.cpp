/*
0과 1로 이루어진 어떤 문자열 x에 대한 이진 변환을 다음과 같이 정의합니다.

x의 모든 0을 제거합니다.
x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.
예를 들어, x = "0111010"이라면, x에 이진 변환을 가하면 x = "0111010" -> "1111" -> "100" 이 됩니다.

0과 1로 이루어진 문자열 s가 매개변수로 주어집니다. s가 "1"이 될 때까지 계속해서 s에 이진 변환을 가했을 때, 이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 각각 배열에 담아 return 하도록 solution 함수를 완성해주세요.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int zeroCheck(string* s) {               //제거할 0의 개수 
    int zero = 0;
    string::iterator iter = s->begin();

    while (iter != s->end()) {
        if (*iter == '0') {
            s->erase(iter);
            zero++;
        }
        else {
            iter++;
        }
    }

    return zero;
}

string tenToTwo(string s) {              //이진 변환 결과
    string temp = "";
    int length = s.size();

    while (length != 1) {
        if (length % 2 == 0) {
            temp.push_back('0');
        }
        else {
            temp.push_back('1');
        }

        length = length / 2;
    }

    temp.push_back('1');

    reverse(temp.begin(), temp.end());

    return temp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;  //이진 변환 횟수
    int zero = 0;   //이진 변환시 제거된 0의 개수

    while (s != "1") {
        zero = zero + zeroCheck(&s);     //제거한 0 개수
        s = tenToTwo(s);                //이진 변환
        count++;
    }

    answer.push_back(count);
    answer.push_back(zero);

    return answer;
}