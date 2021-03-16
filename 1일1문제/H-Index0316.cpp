/*
H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. ��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.

� �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H-Index�Դϴ�.

� �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, �� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.

[9,9,9,9] -> 4
[0,1,1] -> 1

h�� �̻� h�� �̻� -> num ���� �� ���� -> ���� ū �� ����
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h = 0;
    vector<int> num;

    sort(citations.begin(), citations.end());       //01356

    for (int i = 0; i <= citations.back(); i++) {
        h = 0;

        for (int j = 0; j < citations.size(); j++) {
            if (i <= citations[j]) {
                h++;
            }
        }

        if (i <= h) {
            num.push_back(i);
        }
    }

    if (num.size() >= 1) {                  //0��� ä����������
        sort(num.begin(), num.end());
        answer = num.back();
    }

    return answer;
}