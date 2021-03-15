/*
Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������, ��ü ī���� ũ��� ������� ���߽��ϴ�.

Leo�� �� ī�꿡�� ���� ������ �� brown, ����� ������ �� yellow�� �Ű������� �־��� �� ī���� ����, ���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;      //ũ��
    int x = 0;      //����
    int y = 0;      //����

    if (yellow == 0) {        //���ΰ� ���κ��� ���ų� ���
        y = 2;
        x = 2;
    }
    else {
        y = 3;
        x = 3;
    }

    while (1) {
        if ((x * y) == size) {
            if (((x - 2) * (y - 2)) == yellow) {          //���� ���̿� ĥ���� ����� ���� ���� �´��� ����
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }

        if ((x * y) < size) {                         //���� * ���ΰ� ũ�⸦ ���� ���� ��� ���� ���� ����
            x++;
        }
        else {                                   //���� * ���ΰ� ũ�⸦ ���� ��� ���ο� ���� + 1 �ʱ�ȭ
            y++;
            x = y;
        }
    }

    return answer;
}