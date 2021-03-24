/*
���ڿ� s���� �������� ���е� ���ڵ��� ����Ǿ� �ֽ��ϴ�. str�� ��Ÿ���� ���� �� �ּҰ��� �ִ밪�� ã�� �̸� "(�ּҰ�) (�ִ밪)"������ ���ڿ��� ��ȯ�ϴ� �Լ�, solution�� �ϼ��ϼ���.
������� s�� "1 2 3 4"��� "1 4"�� �����ϰ�, "-1 -2 -3 -4"��� "-4 -1"�� �����ϸ� �˴ϴ�.

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

    while (ss >> token) {             //token�� �ڷ����� �´� ������ ���� ������ ss���� �ڷ� ����
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