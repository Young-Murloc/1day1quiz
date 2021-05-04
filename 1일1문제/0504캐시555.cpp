/*
캐시 크기(cacheSize)와 도시이름 배열(cities)을 입력받는다.
cacheSize는 정수이며, 범위는 0 ≦ cacheSize ≦ 30 이다.
cities는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.
각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며, 대소문자 구분을 하지 않는다. 도시 이름은 최대 20자로 이루어져 있다.
출력 형식
입력된 도시이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.
조건
캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
cache hit일 경우 실행시간은 1이다.
cache miss일 경우 실행시간은 5이다.
*/

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    bool isHit;

    if (cacheSize == 0) {
        return cities.size() * 5;
    }

    for (int i = 0; i < cities.size(); i++) {
        isHit = false;
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        for (auto itr = dq.begin(); itr != dq.end(); itr++) {
            if (*itr == cities[i]) {
                isHit = true;
                dq.erase(itr);
                break;
            }
        }

        if (isHit) {      // hit
            answer += 1;
        }
        else {           // miss
            if (dq.size() == cacheSize) {
                dq.pop_front();
            }
            answer += 5;
        }

        dq.push_back(cities[i]);
    }

    return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if (cacheSize == 0) {
        return cities.size() * 5;
    }

    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        auto itr = find(cache.begin(), cache.end(), cities[i]);

        if (itr == cache.end()) {     // miss
            if (cache.size() == cacheSize) {
                cache.erase(cache.begin());
            }

            answer += 5;
        }
        else {                   // hit
            cache.erase(itr);
            answer += 1;
        }

        cache.push_back(cities[i]);
    }

    return answer;
}
*/