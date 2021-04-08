/*
이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.

명령어	수신 탑(높이)
I 숫자	큐에 주어진 숫자를 삽입합니다.
D 1	큐에서 최댓값을 삭제합니다.
D -1	큐에서 최솟값을 삭제합니다.
이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때, 모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.

제한사항
operations는 길이가 1 이상 1,000,000 이하인 문자열 배열입니다.
operations의 원소는 큐가 수행할 연산을 나타냅니다.
원소는 “명령어 데이터” 형식으로 주어집니다.- 최댓값/최솟값을 삭제하는 연산에서 최댓값/최솟값이 둘 이상인 경우, 하나만 삭제합니다.
빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시합니다.

priority_queue를 이용하여 처음에 접근 -> 오름차순 내림차순으로 만들어 논 각각의 우선순위 큐를 비교 -> 최종적으로 나온 값 계산 문제 발생

deque를 이용하여 정렬을 해주면서 접근 -> 최종적으로 하나의 deque를 이용하여 최솟값 최댓값 비교 -> 정답
*/

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    string stringBuffer = "";
    bool checkOP = true;

    int max = -2147483648;
    int min = 2147483647;

    for (int i = 0; i < operations.size(); i++) {
        istringstream ss(operations[i]);
        checkOP = true;
        while (getline(ss, stringBuffer, ' ')) {
            if (stringBuffer == "I") {     //삽입
                checkOP = true;
            }
            else if (stringBuffer == "D") {                       //삭제
                checkOP = false;
            }
            else {
                if (checkOP) {
                    dq.push_back(stoi(stringBuffer));
                }
                else {
                    sort(dq.begin(), dq.end());
                    if (stringBuffer == "1") {
                        if (!dq.empty()) {
                            dq.pop_back();
                        }
                    }
                    else {
                        if (!dq.empty()) {
                            dq.pop_front();
                        }
                    }
                }
            }
        }
    }

    sort(dq.begin(), dq.end());

    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }

    return answer;
}

/*
<실패>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pqLess;         //내림차순, top -> 최댓값
    priority_queue<int,vector<int>,greater<int>> pqGreater;      //오름차순, top -> 최솟값
    string stringBuffer = "";
    bool checkOP = true;

    int max = -2147483648;
    int min = 2147483647;

    for(int i=0; i<operations.size(); i++){
        istringstream ss(operations[i]);
        checkOP = true;
        while(getline(ss,stringBuffer,' ')){
            if(stringBuffer == "I"){     //삽입
                checkOP = true;
            }
            else if(stringBuffer == "D"){                       //삭제
                checkOP = false;
            }
            else{
                if(checkOP){
                    pqLess.push(stoi(stringBuffer));
                    pqGreater.push(stoi(stringBuffer));
                }
                else{
                    if(stringBuffer == "1"){
                        pqLess.pop();
                        if(pqGreater.size()==1){
                            pqGreater.pop();
                        }
                    }
                    else{
                        pqGreater.pop();
                        if(pqLess.size()==1){
                            pqLess.pop();
                        }
                    }
                }
            }
        }
    }

    while(!pqGreater.empty()){
        cout<<pqGreater.top()<<endl;
        pqGreater.pop();
    }

    cout<<endl;

    while(!pqLess.empty()){
        cout<<pqLess.top()<<endl;
        pqLess.pop();
    }


    return answer;
}
*/