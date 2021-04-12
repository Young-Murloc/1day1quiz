/*
네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

제한사항
컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
computer[i][i]는 항상 1입니다.
*/

#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& computers, int n) {        // 연결된 모든 노드의 탐색을 위해 dfs 사용
    if (computers[n][n] == 0) {                           // 노드가 이미 연결된 네트워크로 처리시 결과에 적용되지 않기 위해 false 반환
        return false;
    }

    computers[n][n] = 0;                                // 시작하는 노드를 0으로 만들어줌 -> 네트워크 하나 생성

    for (int i = 0; i < computers.size(); i++) {              // 컴퓨터 배열 만큼 연결됨(1),끊어짐(0) 존재 -> 컴퓨터 배열 크기 만큼 전부 비교
        if (computers[n][i] == 1) {                       // 현재 노드와 연결된 노드 발견 -> 재귀를 통해 해당 노드와 연결된 노드를 찾아서 0으로 바꿈
            dfs(computers, i);
        }
    }

    return true;                                        // 연결된 노드를 전부 0으로 변환시 종료 -> 네트워크 하나 마무리
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < computers.size(); i++) {
        if (computers[i][i] == 1 && dfs(computers, i)) {     // computers[i][i]==1 -> 해당 노드가 네트워크 첫 노드인지 확인 / dfs를 통해 해당 네트워크에 속한 노드 값 변경
            answer++;                                   // 네트워크 하나 추가
        }
    }

    return answer;
}

/*
네트워크가 분리되어 있는지 확인
computer[i][i]가 항상 1인점을 사용
DFS, 재귀를 이용하여 풀이


#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool dfs(vector<vector<int>>& computers, int n){
    if(!computers[n][n]){
        return false;
    }
    computers[n][n] = 0;
    
    for(int i=0; i<computers.size(); i++){
        if(computers[n][i]){
            dfs(computers,i);
        }
    }
    return true;
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(computers[i][i] && dfs(computers,i)){
            answer++;
        }
    }
    
    return answer;
}
*/