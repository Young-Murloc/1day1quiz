/*
124 ���� �ֽ��ϴ�. 124 ���󿡼��� 10������ �ƴ� ������ ���� �ڽŵ鸸�� ��Ģ���� ���� ǥ���մϴ�.

124 ���󿡴� �ڿ����� �����մϴ�.
124 ���󿡴� ��� ���� ǥ���� �� 1, 2, 4�� ����մϴ�.
���� �� 124 ���󿡼� ����ϴ� ���ڴ� ������ ���� ��ȯ�˴ϴ�.
�ڿ��� n�� �Ű������� �־��� ��, n�� 124 ���󿡼� ����ϴ� ���ڷ� �ٲ� ���� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.


<���� �ڵ�>
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

        if (oriNum % 3 != 0) {        //3�� ����� �ƴ� ���
            res = oriNum % 3;
            oriNum = oriNum / 3;
            number.push_back(res);
        }
        else {                       //3�� ����� ���
            res = (oriNum - 1) % 3;
            oriNum = (oriNum - 1) / 3;
            number.push_back(res + 1);
        }

    }


    for (int i = 0; i < number.size(); i++) {                 //answer�� ����
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