/*
문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 예를 들어 strings가 ["sun", "bed", "car"]이고 n이 1이면 각 단어의 인덱스 1의 문자 "u", "e", "a"로 strings를 정렬합니다.

제한 조건
strings는 길이 1 이상, 50이하인 배열입니다.
strings의 원소는 소문자 알파벳으로 이루어져 있습니다.
strings의 원소는 길이 1 이상, 100이하인 문자열입니다.
모든 strings의 원소의 길이는 n보다 큽니다.
인덱스 1의 문자가 같은 문자열이 여럿 일 경우, 사전순으로 앞선 문자열이 앞쪽에 위치합니다.

value값 기준으로 sort
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, string>& a, const pair<string, string>& b) {
    if (a.second == b.second) return a.first < b.first;

    return a.second < b.second;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    map<string, string> temp;
    string tempS;

    for (int i = 0; i < strings.size(); i++) {
        tempS = strings[i][n];
        temp[strings[i]] = tempS;
    }

    vector<pair<string, string>> v(temp.begin(), temp.end());

    sort(v.begin(), v.end(), cmp);

    for (auto itr = v.begin(); itr != v.end(); itr++) {
        answer.push_back(itr->first);
    }

    return answer;
}