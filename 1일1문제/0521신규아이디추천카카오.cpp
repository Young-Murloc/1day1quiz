/*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    vector<char> arr;

    int temp = 0;
    char tempChar;


    // 1단계
    for (int i = 0; i < new_id.size(); i++) {
        new_id[i] = tolower(new_id[i]);
    }

    // 2단계
    for (int i = 0; i < new_id.size(); i++) {
        temp = new_id[i];

        if ((temp >= 97 && temp <= 122) || (temp >= 48 && temp <= 57) || temp == 45 || temp == 46 || temp == 95)
            arr.push_back(new_id[i]);
    }

    // 3단계
    bool check = false;
    vector<char> tempVector;

    for (auto itr = arr.begin(); itr != arr.end(); itr++) {
        temp = *itr;

        tempVector.push_back(*itr);

        if (temp == 46)
            if (*(itr - 1) == '.')
                tempVector.pop_back();
    }

    arr.swap(tempVector);

    // 4단계
    if (arr[arr.size() - 1] == '.')
        arr.erase(arr.end() - 1);

    if (!arr.empty()) {
        if (arr[0] == '.')
            arr.erase(arr.begin());
    }

    // 5단계
    if (arr.empty())
        arr.push_back('a');

    // 6단계
    if (arr.size() >= 16) {
        arr.erase(arr.begin() + 15, arr.end());
    }

    if (arr[arr.size() - 1] == '.')
        arr.erase(arr.end() - 1);

    // 7단계
    if (arr.size() <= 2) {
        tempChar = arr[arr.size() - 1];

        for (int i = arr.size(); i < 3; i++)
            arr.push_back(tempChar);
    }

    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }

    return answer;
}