/*
String�� �迭 seoul�� element�� "Kim"�� ��ġ x�� ã��, "�輭���� x�� �ִ�"�� String�� ��ȯ�ϴ� �Լ�, solution�� �ϼ��ϼ���. seoul�� "Kim"�� ���� �� ���� ��Ÿ���� �߸��� ���� �ԷµǴ� ���� �����ϴ�
*/
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "�輭���� ";

    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim")
            answer += to_string(i);
    }

    answer += "�� �ִ�";

    return answer;
}