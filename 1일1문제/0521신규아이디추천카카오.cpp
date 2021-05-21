/*
1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
     ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    vector<char> arr;

    int temp = 0;
    char tempChar;


    // 1�ܰ�
    for (int i = 0; i < new_id.size(); i++) {
        new_id[i] = tolower(new_id[i]);
    }

    // 2�ܰ�
    for (int i = 0; i < new_id.size(); i++) {
        temp = new_id[i];

        if ((temp >= 97 && temp <= 122) || (temp >= 48 && temp <= 57) || temp == 45 || temp == 46 || temp == 95)
            arr.push_back(new_id[i]);
    }

    // 3�ܰ�
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

    // 4�ܰ�
    if (arr[arr.size() - 1] == '.')
        arr.erase(arr.end() - 1);

    if (!arr.empty()) {
        if (arr[0] == '.')
            arr.erase(arr.begin());
    }

    // 5�ܰ�
    if (arr.empty())
        arr.push_back('a');

    // 6�ܰ�
    if (arr.size() >= 16) {
        arr.erase(arr.begin() + 15, arr.end());
    }

    if (arr[arr.size() - 1] == '.')
        arr.erase(arr.end() - 1);

    // 7�ܰ�
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