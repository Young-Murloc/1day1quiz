/*
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

1. 만들수 있는 모든 숫자 구하기 ->
        next_permutation 함수 이용
2. 중복 숫자 제거하기 ->
        unique => 중복된 숫자를 뒤로 보내면서 가장 0에 가까운 쓰레기 값의 자리를 리턴
        erase => 매개변수로 받은 위치에 있는 원소 삭제
3. 소수 판별하기 ->
        에라토스테네스의_체를 이용하여 풀이 https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int number) {           // 소수가 아닐 경우 true, 소수의 경우 false
    if (number < 2) return false;

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> charNum;
    vector<int> num;
    string temp = "";

    for (int i = 0; i < numbers.size(); i++) {
        charNum.push_back(numbers[i]);
    }

    sort(charNum.begin(), charNum.end());

    do {
        temp = "";
        for (int i = 0; i < charNum.size(); i++) {
            temp.push_back(charNum[i]);     //string 삽입
            num.push_back(stoi(temp));      //int 삽입
        }
    } while (next_permutation(charNum.begin(), charNum.end()));

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for (int i = 0; i < num.size(); i++) {
        if (isPrime(num[i])) {
            answer++;
        }
    }

    return answer;
}