/*
���ڸ� ���ڰ� ���� ���� ������ ������ֽ��ϴ�. ����� ���� ������ �ٿ� �Ҽ��� �� �� ���� �� �ִ��� �˾Ƴ��� �մϴ�.

�� ���� ������ ���� ���ڰ� ���� ���ڿ� numbers�� �־����� ��, ���� �������� ���� �� �ִ� �Ҽ��� �� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

1. ����� �ִ� ��� ���� ���ϱ� ->
        next_permutation �Լ� �̿�
2. �ߺ� ���� �����ϱ� ->
        unique => �ߺ��� ���ڸ� �ڷ� �����鼭 ���� 0�� ����� ������ ���� �ڸ��� ����
        erase => �Ű������� ���� ��ġ�� �ִ� ���� ����
3. �Ҽ� �Ǻ��ϱ� ->
        �����佺�׳׽���_ü�� �̿��Ͽ� Ǯ�� https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int number) {           // �Ҽ��� �ƴ� ��� true, �Ҽ��� ��� false
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
            temp.push_back(charNum[i]);     //string ����
            num.push_back(stoi(temp));      //int ����
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