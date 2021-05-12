/*
�빮�ڿ� �ҹ��ڰ� �����ִ� ���ڿ� s�� �־����ϴ�. s�� 'p'�� ������ 'y'�� ������ ���� ������ True, �ٸ��� False�� return �ϴ� solution�� �ϼ��ϼ���. 'p', 'y' ��� �ϳ��� ���� ���� �׻� True�� �����մϴ�. ��, ������ ���� �� �빮�ڿ� �ҹ��ڴ� �������� �ʽ��ϴ�.

���� ��� s�� "pPoooyY"�� true�� return�ϰ� "Pyy"��� false�� return�մϴ�.

map �����̳ʸ� �̿��ϸ� ���� Ǯ�� �ִ� ����
*/
#include <string>
#include <map>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    map<char, int> tempMap;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P')
            tempMap['p']++;
        else if (s[i] == 'y' || s[i] == 'Y')
            tempMap['y']++;
    }

    if (tempMap['p'] == tempMap['y'])
        answer = true;
    else
        answer = false;

    return answer;
}