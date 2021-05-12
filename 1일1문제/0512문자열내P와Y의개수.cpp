/*
대문자와 소문자가 섞여있는 문자열 s가 주어집니다. s에 'p'의 개수와 'y'의 개수를 비교해 같으면 True, 다르면 False를 return 하는 solution를 완성하세요. 'p', 'y' 모두 하나도 없는 경우는 항상 True를 리턴합니다. 단, 개수를 비교할 때 대문자와 소문자는 구별하지 않습니다.

예를 들어 s가 "pPoooyY"면 true를 return하고 "Pyy"라면 false를 return합니다.

map 컨테이너를 이용하면 쉽게 풀수 있는 문제
*/
#include <string>
#include <map>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    map<char, int> tempMap;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P')
            tempMap['p']++;
        else if (s[i] == 'y' || s[i] == 'Y')
            tempMap['y']++;
    }

    if (tempMap['p'] == tempMap['y'])
        answer = true;
    else
        answer = false;

    return answer;
}