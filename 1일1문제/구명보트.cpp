/*
무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.

예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만 1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.

구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.

사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때, 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    vector<int>::iterator iter;
    int weight = 0;     //구명 보트 현 무게
    int count = 0;      //구명 보트 타고간 사람 수
    int size = people.size();   //중복 호출을 막기 위해

    sort(people.begin(), people.end(), greater<int>());       //내림차순 정렬

    iter = people.begin();          //삭제 하는 시간을 줄이기 위해 iter 사용

    while (1) {
        if (*iter <= limit / 2) {         //무게 제한의 절반인 값이 들어올 경우 나머지 사람들은 무조건 2명씩 구명 보트 탑승 가능, 1명 남을 경우 1번 더 운행
            answer = answer + ((size - count) / 2) + ((size - count) % 2);
            return answer;
        }

        if (*iter + people.back() <= limit) {     //(맨앞 + 맨뒤 <= 무게 제한)이 성립하는 경우 맨 뒤 원소 삭제
            people.pop_back();
            count++;
        }

        count++;
        iter++;
        answer++;

        if (count == size) {
            return answer;
        }
    }
}