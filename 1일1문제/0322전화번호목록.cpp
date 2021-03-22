/*
��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.

������ : 119
���ؿ� : 97 674 223
������ : 11 9552 4421
��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
phone_book�� ���̴� 1 �̻� 1,000,000 �����Դϴ�.
�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.

hash_map == unordered_map
������       �Ź���
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> book;                 // �� ���̿� �´� ���λ� ������ ���� ����
    unordered_map<string, int>::iterator iter;

    unordered_map<int, int> length;                  // �ʿ��� ���λ� ���� ������ ���� ����
    unordered_map<int, int>::iterator iter_length;

    for (int i = 0; i < phone_book.size(); i++) {         // �ʿ��� ���λ� ���� ����
        length[phone_book[i].length()]++;
    }

    for (int i = 0; i < phone_book.size(); i++) {         //�� ���� ���� �� �ʿ� ���� ��ŭ ����
        for (iter_length = length.begin(); iter_length != length.end(); iter_length++) {
            if (phone_book[i].length() >= iter_length->first) {
                book[phone_book[i].substr(0, iter_length->first)]++;
            }
        }
    }

    for (int i = 0; i < phone_book.size(); i++) {         //�ش� ���Ұ� ���λ�� ���Ե��ִ��� �˻�
        if (book[phone_book[i]] >= 2) {
            return false;
        }
    }

    return answer;
}