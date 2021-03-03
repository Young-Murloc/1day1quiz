/*
������ ������ �������� �����濡 �����Ͽ����ϴ�. �� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.

�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
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
Map �����̳� ��� (�ӵ� �� ����)
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