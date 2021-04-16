/*
īī���� ����ä�ù濡���� ģ���� �ƴ� ������ ��ȭ�� �� �� �ִµ�, ���� �г����� �ƴ� ������ �г����� ����Ͽ� ä�ù濡 �� �� �ִ�.

���Ի���� ��ũ��� īī���� ���� ä�ù��� ������ ����� ����, �پ��� ������� ������, ������ ���� ���Ѻ� �� �ִ� ������â�� ������ �ߴ�. ä�ù濡 ������ ������ ���� �޽����� ��µȴ�.

"[�г���]���� ���Խ��ϴ�."

ä�ù濡�� ������ ������ ���� �޽����� ��µȴ�.

"[�г���]���� �������ϴ�."

ä�ù濡�� �г����� �����ϴ� ����� ������ ���� �� �����̴�.

ä�ù��� ���� ��, ���ο� �г������� �ٽ� ����.
ä�ù濡�� �г����� �����Ѵ�.
�г����� ������ ���� ������ ä�ù濡 ��µǾ� �ִ� �޽����� �г��ӵ� ���� ����ȴ�.

���� ���, ä�ù濡 "Muzi"�� "Prodo"��� �г����� ����ϴ� ����� ������� ������ ä�ù濡�� ������ ���� �޽����� ��µȴ�.

"Muzi���� ���Խ��ϴ�."
"Prodo���� ���Խ��ϴ�."

ä�ù濡 �ִ� ����� ������ ä�ù濡�� ������ ���� �޽����� ���´�.

"Muzi���� ���Խ��ϴ�."
"Prodo���� ���Խ��ϴ�."
"Muzi���� �������ϴ�."

Muzi�� ������ �ٽ� ���� ��, Prodo ��� �г������� ���� ��� ������ ä�ù濡 �����ִ� Muzi�� Prodo�� ������ ���� ����ȴ�.

"Prodo���� ���Խ��ϴ�."
"Prodo���� ���Խ��ϴ�."
"Prodo���� �������ϴ�."
"Prodo���� ���Խ��ϴ�."

ä�ù��� �ߺ� �г����� ����ϱ� ������, ���� ä�ù濡�� Prodo��� �г����� ����ϴ� ����� �� ���� �ִ�. ����, ä�ù濡 �� ��°�� ���Դ� Prodo�� Ryan���� �г����� �����ϸ� ä�ù� �޽����� ������ ���� ����ȴ�.

"Prodo���� ���Խ��ϴ�."
"Ryan���� ���Խ��ϴ�."
"Prodo���� �������ϴ�."
"Prodo���� ���Խ��ϴ�."

ä�ù濡 ������ �����ų�, �г����� ������ ����� ��� ���ڿ� �迭 record�� �Ű������� �־��� ��, ��� ����� ó���� ��, ���������� ���� ������ ����� ���� �Ǵ� �޽����� ���ڿ� �迭 ���·� return �ϵ��� solution �Լ��� �ϼ��϶�.

����<pair>�� �� �����̳ʸ� �̿��Ͽ� ���� ���� �ذ�
*/

#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> action;
    map<string, string> uid;

    string temp;        // �߶��� ���ڿ� �ֱ�
    int count;          // ���� ���
    string act;         // ���Ϳ� �ֱ� ���� �ӽ� ����
    string userId;      // �ʿ� �ֱ� ���� �ӽ� ����
    string userName;    // �ʿ� �ֱ� ���� �ӽ� ����

    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        count = 0;
        act = "";
        userId = "";
        userName = "";
        while (ss >> temp) {
            if (count == 0) {
                act = temp;
            }
            else if (count == 1) {
                userId = temp;
                action.push_back(pair<string, string>(act, userId));
            }
            else {
                userName = temp;
                uid[userId] = userName;
            }

            count++;
        }
    }

    for (int i = 0; i < action.size(); i++) {
        string temp = "";

        if (action[i].first == "Enter") {
            temp += uid[action[i].second] + "���� ���Խ��ϴ�.";
            answer.push_back(temp);
        }
        else if (action[i].first == "Leave") {
            temp += uid[action[i].second] + "���� �������ϴ�.";
            answer.push_back(temp);
        }
    }

    return answer;
}