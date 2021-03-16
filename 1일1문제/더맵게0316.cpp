/*
매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다. 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.

섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.

Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.

힙/우선순위큐를 통해 시간을 줄인다

-> 최솟값이 top으로 오기 위해 우선순위큐를 사용 -> 최솟값과 K값 비교 -> 음식 섞기 or 출력
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    int min = 0;
    int min2 = 0;
    int sco = 0;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (!pq.empty()) {
        if (pq.top() >= K) {
            break;
        }

        if (pq.top() < K && pq.size() == 1) {
            return -1;
        }

        min = pq.top();
        pq.pop();

        min2 = pq.top();
        pq.pop();

        sco = min + (min2 * 2);

        pq.push(sco);

        answer++;
    }

    return answer;
}