/*
예를 들어 집합 A = {1, 2, 3}, 집합 B = {2, 3, 4}라고 할 때, 교집합 A ∩ B = {2, 3}, 합집합 A ∪ B = {1, 2, 3, 4}이 되므로, 집합 A, B 사이의 자카드 유사도 J(A, B) = 2/4 = 0.5가 된다. 집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의한다.

자카드 유사도는 원소의 중복을 허용하는 다중집합에 대해서 확장할 수 있다. 다중집합 A는 원소 "1"을 3개 가지고 있고, 다중집합 B는 원소 "1"을 5개 가지고 있다고 하자. 이 다중집합의 교집합 A ∩ B는 원소 "1"을 min(3, 5)인 3개, 합집합 A ∪ B는 원소 "1"을 max(3, 5)인 5개 가지게 된다. 다중집합 A = {1, 1, 2, 2, 3}, 다중집합 B = {1, 2, 2, 4, 5}라고 하면, 교집합 A ∩ B = {1, 2, 2}, 합집합 A ∪ B = {1, 1, 2, 2, 3, 4, 5}가 되므로, 자카드 유사도 J(A, B) = 3/7, 약 0.42가 된다.

이를 이용하여 문자열 사이의 유사도를 계산하는데 이용할 수 있다. 문자열 "FRANCE"와 "FRENCH"가 주어졌을 때, 이를 두 글자씩 끊어서 다중집합을 만들 수 있다. 각각 {FR, RA, AN, NC, CE}, {FR, RE, EN, NC, CH}가 되며, 교집합은 {FR, NC}, 합집합은 {FR, RA, AN, NC, CE, RE, EN, CH}가 되므로, 두 문자열 사이의 자카드 유사도 J("FRANCE", "FRENCH") = 2/8 = 0.25가 된다.

입력 형식
입력으로는 str1과 str2의 두 문자열이 들어온다. 각 문자열의 길이는 2 이상, 1,000 이하이다.
입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다. 이때 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다. 예를 들어 "ab+"가 입력으로 들어오면, "ab"만 다중집합의 원소로 삼고, "b+"는 버린다.
다중집합 원소 사이를 비교할 때, 대문자와 소문자의 차이는 무시한다. "AB"와 "Ab", "ab"는 같은 원소로 취급한다.
출력 형식
입력으로 들어온 두 문자열의 자카드 유사도를 출력한다. 유사도 값은 0에서 1 사이의 실수이므로, 이를 다루기 쉽도록 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력한다.

맵 컨테이너를 이용하여 합집합 및 교집합을 쉽게 구한다
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> word1;
    map<string, int> word2;
    map<string, int> words;
    string temp = "";

    int uni = 0;        // 합
    int inter = 0;      // 교

    double jakad = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.length(); i++) {
        temp = str1.substr(i, 2);

        if (temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z') {
            word1[temp]++;
            words[temp]++;
            temp = "";
        }
    }

    for (int i = 0; i < str2.length(); i++) {
        temp = str2.substr(i, 2);

        if (temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z') {
            word2[temp]++;
            words[temp]++;
            temp = "";
        }
    }

    for (auto itr = words.begin(); itr != words.end(); itr++) {
        if (itr->second > 1) {
            inter += min(word1[itr->first], word2[itr->first]);
        }
    }

    for (auto itr = word1.begin(); itr != word1.end(); itr++) {
        uni += itr->second;
    }

    for (auto itr = word2.begin(); itr != word2.end(); itr++) {
        uni += itr->second;
    }

    if (words.size() == 0) {
        return 65536;
    }

    uni -= inter;
    cout << uni;

    jakad = (double)inter / (double)uni;

    return jakad * 65536;
}