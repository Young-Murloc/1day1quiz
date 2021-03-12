/*
일반적인 프린터는 인쇄 요청이 들어온 순서대로 인쇄합니다. 그렇기 때문에 중요한 문서가 나중에 인쇄될 수 있습니다. 이런 문제를 보완하기 위해 중요도가 높은 문서를 먼저 인쇄하는 프린터를 개발했습니다. 이 새롭게 개발한 프린터는 아래와 같은 방식으로 인쇄 작업을 수행합니다.

1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
3. 그렇지 않으면 J를 인쇄합니다.
예를 들어, 4개의 문서(A, B, C, D)가 순서대로 인쇄 대기목록에 있고 중요도가 2 1 3 2 라면 C D A B 순으로 인쇄하게 됩니다.

내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 알고 싶습니다. 위의 예에서 C는 1번째로, A는 3번째로 인쇄됩니다.

현재 대기목록에 있는 문서의 중요도가 순서대로 담긴 배열 priorities와 내가 인쇄를 요청한 문서가 현재 대기목록의 어떤 위치에 있는지를 알려주는 location이 매개변수로 주어질 때, 내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 return 하도록 solution 함수를 작성해주세요.
*/
#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;         //인쇄수
    deque<pair<int, int>> dq;        //1.중요도 2.순서
    deque<pair<int, int>>::iterator iter;

    for (int i = 0; i < priorities.size(); i++) {
        dq.push_back(make_pair(priorities[i], i));
    }

    while (1) {
        for (iter = dq.begin(); iter < dq.end(); iter++) {
            if (iter->first > dq.front().first) {
                dq.push_back(dq.front());
                dq.pop_front();
                break;
            }
        }

        if (iter == dq.end()) {
            answer++;
            if (dq.front().second == location) {
                return answer;
            }
            else {
                dq.pop_front();
            }
        }
    }
}
/*
실패 구문
while(!dq.empty()){
        iter = dq.begin();
        while(1){
            iter++;

            if(iter->first > dq.front().first){     //J보다 중요도 높은 원소 존재
                dq.push_back(dq.front());
                dq.pop_front();
                break;
            }

            if(iter == dq.end()){       //그렇지 않을 경우 출력
                if(dq.front().second == location){
                    answer++;
                    return answer;
                }
                else{
                    dq.pop_front();
                    answer++;
                    break;
                }
            }
        }
    }
*/