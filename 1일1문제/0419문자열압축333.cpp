/*
������ ó�� �������� �ǰ� ���� "����ġ"�� ���ڿ��� �����ϴ� ����� ���� ���θ� �ϰ� �ֽ��ϴ�. �ֱٿ� �뷮�� ������ ó���� ���� ������ ��ս� ���� ����� ���� ���θ� �ϰ� �ִµ�, ���ڿ����� ���� ���� �����ؼ� ��Ÿ���� ���� �� ������ ������ �ݺ��Ǵ� ������ ǥ���Ͽ� �� ª�� ���ڿ��� �ٿ��� ǥ���ϴ� �˰����� �����ϰ� �ֽ��ϴ�.
������ ���� "aabbaccc"�� ��� "2a2ba3c"(���ڰ� �ݺ����� �ʾ� �ѹ��� ��Ÿ�� ��� 1�� ������)�� ���� ǥ���� �� �ִµ�, �̷��� ����� �ݺ��Ǵ� ���ڰ� ���� ��� ������� ���ٴ� ������ �ֽ��ϴ�. ���� ���, "abcabcdede"�� ���� ���ڿ��� ���� ������� �ʽ��ϴ�. "����ġ"�� �̷��� ������ �ذ��ϱ� ���� ���ڿ��� 1�� �̻��� ������ �߶� �����Ͽ� �� ª�� ���ڿ��� ǥ���� �� �ִ��� ����� ã�ƺ����� �մϴ�.

���� ���, "ababcdcdababcdcd"�� ��� ���ڸ� 1�� ������ �ڸ��� ���� ������� ������, 2�� ������ �߶� �����Ѵٸ� "2ab2cd2ab2cd"�� ǥ���� �� �ֽ��ϴ�. �ٸ� ������� 8�� ������ �߶� �����Ѵٸ� "2ababcdcd"�� ǥ���� �� ������, �̶��� ���� ª�� �����Ͽ� ǥ���� �� �ִ� ����Դϴ�.

�ٸ� ����, "abcabcdede"�� ���� ���, ���ڸ� 2�� ������ �߶� �����ϸ� "abcabc2de"�� ������, 3�� ������ �ڸ��ٸ� "2abcdede"�� �Ǿ� 3�� ������ ���� ª�� ���� ����� �˴ϴ�. �̶� 3�� ������ �ڸ��� �������� ���� ���ڿ��� �״�� �ٿ��ָ� �˴ϴ�.

������ ���ڿ� s�� �Ű������� �־��� ��, ���� ������ ������� 1�� �̻� ������ ���ڿ��� �߶� �����Ͽ� ǥ���� ���ڿ� �� ���� ª�� ���� ���̸� return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 100000;
    int middle = s.length() / 2;
    int end = s.length();

    vector<string> temp;
    int count = 0;
    string tempString;
    string div;

    if (middle == 0) {            // ���ڿ� �ϳ� ���� ��� �˻縦 ���� middle = 1
        middle = 1;
    }

    for (int i = 1; i <= middle; i++) {
        temp.clear();
        count = 0;
        tempString = "";
        div = "";

        for (int j = 0; j < end; j += i) {
            temp.push_back(s.substr(j, i));
        }

        tempString = temp[0];
        for (int j = 0; j < temp.size(); j++) {
            if (tempString == temp[j]) {
                count++;
            }
            else {
                if (count == 1) {
                    div += tempString;
                }
                else {
                    div += to_string(count) + tempString;
                }

                tempString = temp[j];
                count = 1;
            }
        }

        if (count == 1) {
            div += tempString;
        }
        else {
            div += to_string(count) + tempString;
        }

        if (answer > div.length()) {
            answer = div.length();
        }
    }

    return answer;
}