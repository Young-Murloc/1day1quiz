/*
���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
ex) �ϼ��ؾ� �ϴ� �̸��� �� ���ڸ� AAA, �� ���ڸ� AAAA

���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.

�� - ���� ���ĺ�
�� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
�� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
�� - Ŀ���� ���������� �̵�
���� ��� �Ʒ��� ������� "JAZ"�� ���� �� �ֽ��ϴ�.

- ù ��° ��ġ���� ���̽�ƽ�� ���� 9�� �����Ͽ� J�� �ϼ��մϴ�.
- ���̽�ƽ�� �������� 1�� �����Ͽ� Ŀ���� ������ ���� ��ġ�� �̵���ŵ�ϴ�.
- ������ ��ġ���� ���̽�ƽ�� �Ʒ��� 1�� �����Ͽ� Z�� �ϼ��մϴ�.
���� 11�� �̵����� "JAZ"�� ���� �� �ְ�, �̶��� �ּ� �̵��Դϴ�.
������� �ϴ� �̸� name�� �Ű������� �־��� ��, �̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��

<���ǻ���>
�׸��� �˰���
���������� �̵��ϰų� �������� �̵��Ҷ� �����ؾ��ϴ� �ε����� ó��, ���������� �����ϼ� �ֱ� ������ ���� ó���� �������
numeric ���, accumulate�� ��� stl�� ���Ҹ� �����ؼ� ����Ҷ� �����ϰ� ���
*/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>                  // accumulate ���� ������ ��
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    vector<int> makeName;
    int left, right = 0;
    int idxL = 0;
    int idxR = 0;

    for (int i = 0; i < name.length(); i++) {
        makeName.push_back(min(name[i] - 65, 91 - name[i]));
    }

    if (makeName[0] != 0) {
        answer += makeName[0];
        makeName[0] = 0;
    }

    while (true) {
        if (accumulate(makeName.begin(), makeName.end(), 0) == 0) {
            break;
        }

        left = 1;
        right = 1;

        while (true) {        //���� �̵�
            if (idxR + right >= makeName.size()) {
                idxR = 0;
            }

            if (makeName[idxR + right] == 0) {
                right++;
            }
            else {
                break;
            }
        }

        idxR += right;

        while (true) {                            //���� �̵� -> ������ ó������ ���������� �̵��ϴ� ��� ���
            if (idxL - left < 0) {
                idxL = makeName.size();
            }

            if (makeName[idxL - left] == 0) {
                left++;
            }
            else {
                break;
            }
        }

        idxL -= left;

        if (right <= left) {
            answer += right + makeName[idxR];
            makeName[idxR] = 0;
            idxL = idxR;
        }
        else {
            answer += left + makeName[idxL];
            makeName[idxL] = 0;
            idxR = idxL;
        }
    }

    return answer;
}