/*
�Ϲ����� �����ʹ� �μ� ��û�� ���� ������� �μ��մϴ�. �׷��� ������ �߿��� ������ ���߿� �μ�� �� �ֽ��ϴ�. �̷� ������ �����ϱ� ���� �߿䵵�� ���� ������ ���� �μ��ϴ� �����͸� �����߽��ϴ�. �� ���Ӱ� ������ �����ʹ� �Ʒ��� ���� ������� �μ� �۾��� �����մϴ�.

1. �μ� ������� ���� �տ� �ִ� ����(J)�� ����Ͽ��� �����ϴ�.
2. ������ �μ� ����Ͽ��� J���� �߿䵵�� ���� ������ �� ���� �����ϸ� J�� ������� ���� �������� �ֽ��ϴ�.
3. �׷��� ������ J�� �μ��մϴ�.
���� ���, 4���� ����(A, B, C, D)�� ������� �μ� ����Ͽ� �ְ� �߿䵵�� 2 1 3 2 ��� C D A B ������ �μ��ϰ� �˴ϴ�.

���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� �˰� �ͽ��ϴ�. ���� ������ C�� 1��°��, A�� 3��°�� �μ�˴ϴ�.

���� ����Ͽ� �ִ� ������ �߿䵵�� ������� ��� �迭 priorities�� ���� �μ⸦ ��û�� ������ ���� ������� � ��ġ�� �ִ����� �˷��ִ� location�� �Ű������� �־��� ��, ���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
*/
#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;         //�μ��
    deque<pair<int, int>> dq;        //1.�߿䵵 2.����
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
���� ����
while(!dq.empty()){
        iter = dq.begin();
        while(1){
            iter++;

            if(iter->first > dq.front().first){     //J���� �߿䵵 ���� ���� ����
                dq.push_back(dq.front());
                dq.pop_front();
                break;
            }

            if(iter == dq.end()){       //�׷��� ���� ��� ���
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