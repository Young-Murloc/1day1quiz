/*
S�翡���� �� �μ��� �ʿ��� ��ǰ�� ������ �ֱ� ���� �μ����� ��ǰ�� �����ϴµ� �ʿ��� �ݾ��� �����߽��ϴ�. �׷���, ��ü ������ ������ �ֱ� ������ ��� �μ��� ��ǰ�� ������ �� ���� �����ϴ�. �׷��� �ִ��� ���� �μ��� ��ǰ�� ������ �� �� �ֵ��� �Ϸ��� �մϴ�.

��ǰ�� ������ �� ���� �� �μ��� ��û�� �ݾ׸�ŭ�� ��� ������ ��� �մϴ�. ���� ��� 1,000���� ��û�� �μ����� ��Ȯ�� 1,000���� �����ؾ� �ϸ�, 1,000������ ���� �ݾ��� ������ �� ���� �����ϴ�.

�μ����� ��û�� �ݾ��� ����ִ� �迭 d�� ���� budget�� �Ű������� �־��� ��, �ִ� �� ���� �μ��� ��ǰ�� ������ �� �ִ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
d�� �μ����� ��û�� �ݾ��� ����ִ� �迭�̸�, ����(��ü �μ��� ����)�� 1 �̻� 100 �����Դϴ�.
d�� �� ���Ҵ� �μ����� ��û�� �ݾ��� ��Ÿ����, �μ��� ��û �ݾ��� 1 �̻� 100,000 ������ �ڿ����Դϴ�.
budget�� ������ ��Ÿ����, 1 �̻� 10,000,000 ������ �ڿ����Դϴ�.

dp�� �̿��ؼ� �ذ��Ҽ� ������?
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int count = 0;

    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++) {
        count += d[i];
        answer++;

        if (count == budget)
            break;
        else if (count > budget) {
            answer--;
            break;
        }
    }

    return answer;
}

/*
dp �̿� Ǯ�� ������
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void dp(vector<int> d, int budget, int sum, int count, int index, vector<int>& temp){
    if(d.size() <= index || sum > budget || count > d.size())
        return;

    sum += d[index];
    count++;

    if(sum <= budget){
        temp.push_back(count);

        for(int i=index+1; i<d.size(); i++){
            dp(d,budget,sum,count,i,temp);
        }
    }
}

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    int count = 0;
    int index = 0;
    vector<int> temp;


    for(int i=0; i<d.size(); i++){
        dp(d,budget,sum,count,i,temp);
    }

    for(int i=0; i<temp.size(); i++){
        if(answer<temp[i])
            answer = temp[i];
    }

    return answer;
}
*/