/*
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.

모든 티켓을 확인하기 위해 DFS알고리즘 사용
사용한 티켓 확인하는 변수 필요
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool dfs(string start, vector<vector<string>> tickets, vector<bool>& useTickets, vector<string>& temp, vector<string>& answer, int count) {
    temp.push_back(start);

    if (count == tickets.size()) {
        answer = temp;
        return true;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start && useTickets[i] == false) {
            useTickets[i] = true;

            bool check = dfs(tickets[i][1], tickets, useTickets, temp, answer, count + 1);

            if (check) {
                return true;
            }

            useTickets[i] = false;
        }
    }

    temp.pop_back();

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> temp;
    vector<bool> useTickets(tickets.size(), false);

    sort(tickets.begin(), tickets.end());

    dfs("ICN", tickets, useTickets, temp, answer, 0);

    return answer;
}