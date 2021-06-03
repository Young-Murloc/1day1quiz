/*
민우가 구매한 로또 번호를 담은 배열 lottos, 당첨 번호를 담은 배열 win_nums가 매개변수로 주어집니다. 이때, 당첨 가능한 최고 순위와 최저 순위를 차례대로 배열에 담아서 return 하도록 solution 함수를 완성해주세요.

중복되지 않는 값을 가지는 컨테이너 map을 이용하면 쉽게 해결 가능
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int prize(int num) {
    if (num == 6)
        return 1;
    else if (num == 5)
        return 2;
    else if (num == 4)
        return 3;
    else if (num == 3)
        return 4;
    else if (num == 2)
        return 5;
    else
        return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int, int> check;
    int min = 0;
    int max = 0;

    for (int i = 0; i < lottos.size(); i++) {
        check[lottos[i]]++;
        check[win_nums[i]]++;
    }

    for (auto itr = check.begin(); itr != check.end(); itr++) {
        if (itr->second >= 2 && itr->first != 0) {
            min++;
        }

        if (itr->first == 0) {
            max = itr->second;
        }
    }

    max += min;

    answer.push_back(prize(max));

    answer.push_back(prize(min));

    return answer;
}