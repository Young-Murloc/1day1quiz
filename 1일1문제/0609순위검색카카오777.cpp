/*
�����ڰ� �������� �Է��� 4������ ������ ȹ���� �ڵ��׽�Ʈ ������ �ϳ��� ���ڿ��� ������ ���� �迭 info, �������� �ñ����ϴ� ���������� ���ڿ� ���·� ��� �迭 query�� �Ű������� �־��� ��,
�� �������ǿ� �ش��ϴ� ������� ���ڸ� ������� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

ȿ���� ����
1. ������ ���Ϳ� ������ ����
2. �ӽ� ���Ϳ� ���ǿ� �´� ���͸� ���� �� ��?

����Ž���� ���� ȿ������ ������
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> infoV;
    vector<vector<string>> queryV;
    vector<string> tempV;
    string tempS;

    for (int i = 0; i < info.size(); i++) {
        tempS = "";

        for (int j = 0; j < info[i].size(); j++) {
            if ((int)info[i][j] != 32) {
                tempS += info[i][j];
            }
            else {
                tempV.push_back(tempS);
                tempS = "";
            }
        }

        tempV.push_back(tempS);
        infoV.push_back(tempV);
        tempV.clear();
    }

    for (int i = 0; i < query.size(); i++) {
        tempS = "";

        for (int j = 0; j < query[i].size(); j++) {
            if ((int)query[i][j] != 32) {
                tempS += query[i][j];
            }
            else {
                if (tempS != "and") {
                    tempV.push_back(tempS);
                }
                tempS = "";
            }
        }

        tempV.push_back(tempS);
        queryV.push_back(tempV);
        tempV.clear();
    }

    for (int i = 0; i < queryV.size(); i++) {
        for (int j = 0; j < queryV[i].size(); j++) {
            cout << queryV[i][j] << " ";
        }
        cout << endl;
    }

    return answer;
}