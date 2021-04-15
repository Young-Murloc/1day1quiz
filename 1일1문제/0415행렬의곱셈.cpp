/*
2차원 행렬 arr1과 arr2를 입력받아, arr1에 arr2를 곱한 결과를 반환하는 함수, solution을 완성해주세요.

제한 조건
행렬 arr1, arr2의 행과 열의 길이는 2 이상 100 이하입니다.
행렬 arr1, arr2의 원소는 -10 이상 20 이하인 자연수입니다.
곱할 수 있는 배열만 주어집니다.

행렬 곱 -> 3차 반복문 사용 -> 각각의 범위를 주의
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int sum = 0;
    vector<int> temp;

    for (int i = 0; i < arr1.size(); i++) {
        temp.clear();
        for (int j = 0; j < arr2[0].size(); j++) {
            sum = 0;
            for (int k = 0; k < arr1[0].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }

    return answer;
}