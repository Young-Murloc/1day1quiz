/*
지원자가 지원서에 입력한 4가지의 정보와 획득한 코딩테스트 점수를 하나의 문자열로 구성한 값의 배열 info, 개발팀이 궁금해하는 문의조건이 문자열 형태로 담긴 배열 query가 매개변수로 주어질 때,
각 문의조건에 해당하는 사람들의 숫자를 순서대로 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

효율성 문제
1. 각각의 벡터에 조건을 저장
2. 임시 벡터에 조건에 맞는 벡터를 저장 후 비교?

완전탐색의 경우는 효율성이 떨어짐
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