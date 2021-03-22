/*
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

제한 사항
phone_book의 길이는 1 이상 1,000,000 이하입니다.
각 전화번호의 길이는 1 이상 20 이하입니다.
같은 전화번호가 중복해서 들어있지 않습니다.

hash_map == unordered_map
구버전       신버전
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> book;                 // 각 길이에 맞는 접두사 저장을 위한 변수
    unordered_map<string, int>::iterator iter;

    unordered_map<int, int> length;                  // 필요한 접두사 길이 저장을 위한 변수
    unordered_map<int, int>::iterator iter_length;

    for (int i = 0; i < phone_book.size(); i++) {         // 필요한 접두사 길이 저장
        length[phone_book[i].length()]++;
    }

    for (int i = 0; i < phone_book.size(); i++) {         //각 원소 접근 후 필요 길이 만큼 저장
        for (iter_length = length.begin(); iter_length != length.end(); iter_length++) {
            if (phone_book[i].length() >= iter_length->first) {
                book[phone_book[i].substr(0, iter_length->first)]++;
            }
        }
    }

    for (int i = 0; i < phone_book.size(); i++) {         //해당 원소가 접두사로 포함되있는지 검사
        if (book[phone_book[i]] >= 2) {
            return false;
        }
    }

    return answer;
}