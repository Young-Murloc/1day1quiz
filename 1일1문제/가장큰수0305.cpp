/*
0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ� �ּ���.

���� ���, �־��� ������ [6, 10, 2]��� [6102, 6210, 1062, 1026, 2610, 2106]�� ���� �� �ְ�, ���� ���� ū ���� 6210�Դϴ�.

0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־��� ��, ������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� return �ϵ��� solution �Լ��� �ۼ����ּ���.

n*2 �ð� ���⵵�� ���� -> ������ ���� ���� ��, ���� ���
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void qsort(vector<string>& num, vector<int>& numbers, int s, int e) {         // nlogn �ð� �ɸ��� �� ����
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

    for (int i = 0; i < numbers.size(); i++) {            //���� ū �ڸ��� ����
        if (max < numbers[i]) {
            max = numbers[i];
        }
    }

    for (int i = 0; i < 3; i++) {                         //���� ū �ڸ��� ���ϱ� 3
        maxNum += to_string(max);
    }

    for (int i = 0; i < numbers.size(); i++) {            //���� ū �ڸ����� �������� ������ �ڸ����� �������� ������ ���� ����
        temp = to_string(numbers[i]);

        while (temp.size() != maxNum.size()) {
            temp += to_string(numbers[i]);
        }

        num.push_back(temp);
    }

    qsort(num, numbers, 0, num.size() - 1);             //������(num,numbers ���ÿ� ����)
    reverse(numbers.begin(), numbers.end());            //���ĵȰ��� ������


    if (numbers[0] == 0) {
        return "0";
    }

    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }

    return answer;
}