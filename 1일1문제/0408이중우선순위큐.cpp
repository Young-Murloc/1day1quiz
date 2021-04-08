/*
���� �켱���� ť�� ���� ������ �� �� �ִ� �ڷᱸ���� ���մϴ�.

��ɾ�	���� ž(����)
I ����	ť�� �־��� ���ڸ� �����մϴ�.
D 1	ť���� �ִ��� �����մϴ�.
D -1	ť���� �ּڰ��� �����մϴ�.
���� �켱���� ť�� �� ���� operations�� �Ű������� �־��� ��, ��� ������ ó���� �� ť�� ��������� [0,0] ������� ������ [�ִ�, �ּڰ�]�� return �ϵ��� solution �Լ��� �������ּ���.

���ѻ���
operations�� ���̰� 1 �̻� 1,000,000 ������ ���ڿ� �迭�Դϴ�.
operations�� ���Ҵ� ť�� ������ ������ ��Ÿ���ϴ�.
���Ҵ� ����ɾ� �����͡� �������� �־����ϴ�.- �ִ�/�ּڰ��� �����ϴ� ���꿡�� �ִ�/�ּڰ��� �� �̻��� ���, �ϳ��� �����մϴ�.
�� ť�� �����͸� �����϶�� ������ �־��� ���, �ش� ������ �����մϴ�.

priority_queue�� �̿��Ͽ� ó���� ���� -> �������� ������������ ����� �� ������ �켱���� ť�� �� -> ���������� ���� �� ��� ���� �߻�

deque�� �̿��Ͽ� ������ ���ָ鼭 ���� -> ���������� �ϳ��� deque�� �̿��Ͽ� �ּڰ� �ִ� �� -> ����
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
            if (stringBuffer == "I") {     //����
                checkOP = true;
            }
            else if (stringBuffer == "D") {                       //����
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
<����>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pqLess;         //��������, top -> �ִ�
    priority_queue<int,vector<int>,greater<int>> pqGreater;      //��������, top -> �ּڰ�
    string stringBuffer = "";
    bool checkOP = true;

    int max = -2147483648;
    int min = 2147483647;

    for(int i=0; i<operations.size(); i++){
        istringstream ss(operations[i]);
        checkOP = true;
        while(getline(ss,stringBuffer,' ')){
            if(stringBuffer == "I"){     //����
                checkOP = true;
            }
            else if(stringBuffer == "D"){                       //����
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