/*
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

그리디 알고리즘
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int count = 1;
    bool check = false;

    while (count <= k) {

        for (int i = 0; i < number.size() - 1; i++) {
            if (int(number[i]) < int(number[i + 1])) {
                number.erase(i, 1);
                check = true;
                break;
            }
        }

        if (check == false) {
            number.pop_back();
        }

        check = false;
        count++;
    }

    answer = number;

    return answer;
}