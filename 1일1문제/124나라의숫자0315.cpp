/*
124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.

124 나라에는 자연수만 존재합니다.
124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.
예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.
자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 return 하도록 solution 함수를 완성해 주세요.


<실패 코드>
#include <sstream>
stringstream tmp;
tmp << number[i];
answer.push_back(*tmp.str().c_str());
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> number;

    int oriNum = 0;
    int res = 0;

    oriNum = n;

    while (1) {
        if (oriNum == 0) break;

        if (oriNum % 3 != 0) {        //3의 배수가 아닌 경우
            res = oriNum % 3;
            oriNum = oriNum / 3;
            number.push_back(res);
        }
        else {                       //3의 배수인 경우
            res = (oriNum - 1) % 3;
            oriNum = (oriNum - 1) / 3;
            number.push_back(res + 1);
        }

    }


    for (int i = 0; i < number.size(); i++) {                 //answer의 삽입
        if (number[i] == 3) {
            answer += '4';
        }
        else {
            answer += to_string(number[i]);
        }
    }


    reverse(answer.begin(), answer.end());

    return answer;
}