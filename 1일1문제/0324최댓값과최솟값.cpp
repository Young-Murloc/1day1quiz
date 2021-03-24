/*
문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.

c++ -> sstring(stringstream) / c# -> spilt
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;

    stringstream ss(s);
    string token;

    int max = -2147483648;
    int min = 2147483647;

    while (ss >> token) {             //token의 자료형에 맞는 정보가 없을 때까지 ss에서 자료 추출
        numbers.push_back(stoi(token));
    }


    for (int i = 0; i < numbers.size(); i++) {
        if (max < numbers[i]) {
            max = numbers[i];
        }

        if (min > numbers[i]) {
            min = numbers[i];
        }
    }

    answer += to_string(min);
    answer += " ";
    answer += to_string(max);

    return answer;
}