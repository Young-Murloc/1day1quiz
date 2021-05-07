/*
���� ��� ���� A = {1, 2, 3}, ���� B = {2, 3, 4}��� �� ��, ������ A �� B = {2, 3}, ������ A �� B = {1, 2, 3, 4}�� �ǹǷ�, ���� A, B ������ ��ī�� ���絵 J(A, B) = 2/4 = 0.5�� �ȴ�. ���� A�� ���� B�� ��� �������� ��쿡�� �������� ���ǵ��� ������ ���� J(A, B) = 1�� �����Ѵ�.

��ī�� ���絵�� ������ �ߺ��� ����ϴ� �������տ� ���ؼ� Ȯ���� �� �ִ�. �������� A�� ���� "1"�� 3�� ������ �ְ�, �������� B�� ���� "1"�� 5�� ������ �ִٰ� ����. �� ���������� ������ A �� B�� ���� "1"�� min(3, 5)�� 3��, ������ A �� B�� ���� "1"�� max(3, 5)�� 5�� ������ �ȴ�. �������� A = {1, 1, 2, 2, 3}, �������� B = {1, 2, 2, 4, 5}��� �ϸ�, ������ A �� B = {1, 2, 2}, ������ A �� B = {1, 1, 2, 2, 3, 4, 5}�� �ǹǷ�, ��ī�� ���絵 J(A, B) = 3/7, �� 0.42�� �ȴ�.

�̸� �̿��Ͽ� ���ڿ� ������ ���絵�� ����ϴµ� �̿��� �� �ִ�. ���ڿ� "FRANCE"�� "FRENCH"�� �־����� ��, �̸� �� ���ھ� ��� ���������� ���� �� �ִ�. ���� {FR, RA, AN, NC, CE}, {FR, RE, EN, NC, CH}�� �Ǹ�, �������� {FR, NC}, �������� {FR, RA, AN, NC, CE, RE, EN, CH}�� �ǹǷ�, �� ���ڿ� ������ ��ī�� ���絵 J("FRANCE", "FRENCH") = 2/8 = 0.25�� �ȴ�.

�Է� ����
�Է����δ� str1�� str2�� �� ���ڿ��� ���´�. �� ���ڿ��� ���̴� 2 �̻�, 1,000 �����̴�.
�Է����� ���� ���ڿ��� �� ���ھ� ��� ���������� ���ҷ� �����. �̶� �����ڷ� �� ���� �ָ� ��ȿ�ϰ�, ��Ÿ �����̳� ����, Ư�� ���ڰ� ����ִ� ���� �� ���� ���� ������. ���� ��� "ab+"�� �Է����� ������, "ab"�� ���������� ���ҷ� ���, "b+"�� ������.
�������� ���� ���̸� ���� ��, �빮�ڿ� �ҹ����� ���̴� �����Ѵ�. "AB"�� "Ab", "ab"�� ���� ���ҷ� ����Ѵ�.
��� ����
�Է����� ���� �� ���ڿ��� ��ī�� ���絵�� ����Ѵ�. ���絵 ���� 0���� 1 ������ �Ǽ��̹Ƿ�, �̸� �ٷ�� ������ 65536�� ���� �Ŀ� �Ҽ��� �Ʒ��� ������ �����θ� ����Ѵ�.

�� �����̳ʸ� �̿��Ͽ� ������ �� �������� ���� ���Ѵ�
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> word1;
    map<string, int> word2;
    map<string, int> words;
    string temp = "";

    int uni = 0;        // ��
    int inter = 0;      // ��

    double jakad = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.length(); i++) {
        temp = str1.substr(i, 2);

        if (temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z') {
            word1[temp]++;
            words[temp]++;
            temp = "";
        }
    }

    for (int i = 0; i < str2.length(); i++) {
        temp = str2.substr(i, 2);

        if (temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z') {
            word2[temp]++;
            words[temp]++;
            temp = "";
        }
    }

    for (auto itr = words.begin(); itr != words.end(); itr++) {
        if (itr->second > 1) {
            inter += min(word1[itr->first], word2[itr->first]);
        }
    }

    for (auto itr = word1.begin(); itr != word1.end(); itr++) {
        uni += itr->second;
    }

    for (auto itr = word2.begin(); itr != word2.end(); itr++) {
        uni += itr->second;
    }

    if (words.size() == 0) {
        return 65536;
    }

    uni -= inter;
    cout << uni;

    jakad = (double)inter / (double)uni;

    return jakad * 65536;
}