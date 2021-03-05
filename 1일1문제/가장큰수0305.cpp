/*
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

n*2 시간 복잡도는 실패 -> 기존의 정렬 말고 퀵, 병합 사용
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void qsort(vector<string>& num, vector<int>& numbers, int s, int e) {         // nlogn 시간 걸리는 퀵 정렬
    long long pivot = stol(num[s]);
    int bs = s;
    int be = e;

    while (s < e) {
        while (pivot <= stol(num[e]) && s < e) e--;
        if (s > e) break;
        while (pivot >= stol(num[s]) && s < e) s++;
        if (s > e) break;

        swap(num[s], num[e]);
        swap(numbers[s], numbers[e]);
    }

    swap(num[bs], num[s]);
    swap(numbers[bs], numbers[s]);

    if (bs < s) {
        qsort(num, numbers, bs, s - 1);
    }

    if (be > e) {
        qsort(num, numbers, s + 1, be);
    }
}

string solution(vector<int> numbers) {
    string answer = "";

    int max = 0;
    string maxNum = "";
    string temp = "";
    vector<string> num;

    for (int i = 0; i < numbers.size(); i++) {            //가장 큰 자릿수 고르기
        if (max < numbers[i]) {
            max = numbers[i];
        }
    }

    for (int i = 0; i < 3; i++) {                         //가장 큰 자릿수 곱하기 3
        maxNum += to_string(max);
    }

    for (int i = 0; i < numbers.size(); i++) {            //가장 큰 자릿수를 기준으로 동등한 자릿수를 가지도록 나머지 숫자 변경
        temp = to_string(numbers[i]);

        while (temp.size() != maxNum.size()) {
            temp += to_string(numbers[i]);
        }

        num.push_back(temp);
    }

    qsort(num, numbers, 0, num.size() - 1);             //퀵정렬(num,numbers 동시에 수행)
    reverse(numbers.begin(), numbers.end());            //정렬된것을 뒤집기


    if (numbers[0] == 0) {
        return "0";
    }

    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }

    return answer;
}