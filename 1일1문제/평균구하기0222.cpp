/*
정수를 담고 있는 배열 arr의 평균값을 return하는 함수, solution을 완성해보세요.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int len = arr.size();


    for (int i = 0; i < len; i++) {
        answer += arr[i];
    }

    answer /= len;

    return answer;
}