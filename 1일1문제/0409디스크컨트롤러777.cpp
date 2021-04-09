/*
이렇게 A → C → B의 순서로 처리하면 각 작업의 요청부터 종료까지 걸린 시간의 평균은 9ms(= (3 + 7 + 17) / 3)가 됩니다.

각 작업에 대해 [작업이 요청되는 시점, 작업의 소요시간]을 담은 2차원 배열 jobs가 매개변수로 주어질 때, 작업의 요청부터 종료까지 걸린 시간의 평균을 가장 줄이는 방법으로 처리하면 평균이 얼마가 되는지 return 하도록 solution 함수를 작성해주세요. (단, 소수점 이하의 수는 버립니다)

제한 사항
jobs의 길이는 1 이상 500 이하입니다.
jobs의 각 행은 하나의 작업에 대한 [작업이 요청되는 시점, 작업의 소요시간] 입니다.
각 작업에 대해 작업이 요청되는 시간은 0 이상 1,000 이하입니다.
각 작업에 대해 작업의 소요시간은 1 이상 1,000 이하입니다.
하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.

<주의사항>
우선순위 큐 = 요청 대기열
    작업 시간을 오름차순으로 정렬


*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct cmp {                                                 // 2차원 우선순위 큐에서 2번째 원소들로 오름차순 정렬
    bool operator()(vector<int> v1, vector<int> v2) {
        return v1[1] > v2[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;       // 현재 시간
    int id = 0;         // jobs의 인덱스 역할
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;        //cmp 구조체 사용

    sort(jobs.begin(), jobs.end());

    while (id < jobs.size() || !pq.empty()) {
        if (jobs.size() > id && time >= jobs[id][0]) {
            pq.push(jobs[id++]);        // 넣은 후에 id값 증가
            continue;
        }

        if (!pq.empty()) {                // 우선순위 큐(대기열)이 빌때까지 answer에 입력
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else {
            time = jobs[id][0];
        }
    }

    return answer / jobs.size();
}