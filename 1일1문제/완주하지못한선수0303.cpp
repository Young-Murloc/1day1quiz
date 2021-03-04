/*
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> P, vector<string> C) {
    string answer = "";

    sort(P.begin(), P.end());
    sort(C.begin(), C.end());

    while (1) {
        if (P.back() == C.back()) {
            P.pop_back();
            C.pop_back();
        }
        else {
            return P.back();
        }
    }
}

/*
Map 컨테이너 사용 (속도 더 빠름)
==================
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> P, vector<string> C) {
    string answer = "";

    unordered_map<string,int> M;

    for(int i=0; i<C.size(); i++){
        M[C[i]]++;
    }

    for(int i=0; i<P.size(); i++){
        M[P[i]]--;
    }

    for(auto iter = M.begin(); iter != M.end(); iter++){

        if(iter->second != 0){
            return iter->first;
        }
    }
}
*/