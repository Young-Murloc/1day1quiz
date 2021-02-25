/*
Summer/Winter Coding(~2018)
���� ��ų�̶� � ��ų�� ���� ���� ���� ����� �ϴ� ��ų�� ���մϴ�.

���� ��� ���� ��ų ������ ����ũ �� ����Ʈ�� ��Ʈ �� ����϶�, ����� ������ ���� ����Ʈ�� ��Ʈ�� ����� �ϰ�, ����Ʈ�� ��Ʈ�� ������ ���� ����ũ�� ����� �մϴ�.

�� ������ ���� �ٸ� ��ų(���� ��)�� ������ ������� ��� �� �ֽ��ϴ�. ���� ����ũ �� ���� �� ����Ʈ�� ��Ʈ �� ����� ���� ��ųƮ���� ����������, ��� �� ����ũ�� ����Ʈ�� ��Ʈ �� ����ũ �� ���� �� ����� ���� ��ųƮ���� �Ұ����մϴ�.

���� ��ų ���� skill�� �������� ���� ��ųƮ��1�� ���� �迭 skill_trees�� �Ű������� �־��� ��, ������ ��ųƮ�� ������ return �ϴ� solution �Լ��� �ۼ����ּ���.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    int temp = 0;

    for (int i = 0; i < skill_trees.size(); i++) {        //������ ��ų Ʈ�� ��ŭ �ݺ�
        for (int j = 0; j < skill.size() - 1; j++) {        //��ȿ�� ��ų Ʈ�� ��ŭ �ݺ�
            if (skill_trees[i].find(skill[j]) > skill_trees[i].find(skill[j + 1])) {
                answer--;                           //�־��� ��ų Ʈ�� �ȿ� ��ȿ�� ��ų Ʈ���� ������� �ִ��� Ȯ��
                break;
            }
        }
    }

    return answer;
}