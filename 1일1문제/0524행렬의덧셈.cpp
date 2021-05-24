/*
행렬의 덧셈은 행과 열의 크기가 같은 두 행렬의 같은 행, 같은 열의 값을 서로 더한 결과가 됩니다. 2개의 행렬 arr1과 arr2를 입력받아, 행렬 덧셈의 결과를 반환하는 함수, solution을 완성해주세요.

제한 조건
행렬 arr1, arr2의 행과 열의 길이는 500을 넘지 않습니다.

두 입력 변수의 크기가 동일하기 때문에 2중배열을 통해 쉽게 구할 수 있다
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> temp;

    for (int i = 0; i < arr1.size(); i++) {
        temp.clear();

        for (int j = 0; j < arr1[i].size(); j++) {
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }

        answer.push_back(temp);
    }

    return answer;
}