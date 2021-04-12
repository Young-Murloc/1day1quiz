/*
�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �ֽ��ϴ�. �Ʒ��� ���� ��Ģ�� �̿��Ͽ� begin���� target���� ��ȯ�ϴ� ���� ª�� ��ȯ ������ ã������ �մϴ�.

1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.
���� ��� begin�� "hit", target�� "cog", words�� ["hot","dot","dog","lot","log","cog"]��� "hit" -> "hot" -> "dot" -> "dog" -> "cog"�� ���� 4�ܰ踦 ���� ��ȯ�� �� �ֽ��ϴ�.

�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �Ű������� �־��� ��, �ּ� �� �ܰ��� ������ ���� begin�� target���� ��ȯ�� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

1. DFS�� ����
2. ����� �ܾ bool ���·� ���� -> ���ϱ� ������ ���ư��� �ʱ� ���ؼ�
3. ��͸� ���� ���� ���� answer �� ����
*/

#include <string>
#include <vector>

using namespace std;

int answer = 51;

void dfs(string begin, string target, vector<string> words, vector<bool>& useWords, int count = 0) {
    for (int i = 0; i < words.size(); i++) {
        int check = 0;

        for (int j = 0; j < words[i].size(); j++) {       // �ѱ��ڸ� ������ Ȯ��
            if (!useWords[i] && begin[j] != words[i][j]) {
                check++;
            }
        }

        if (check == 1) {
            if (target == words[i] && answer > count + 1) {
                answer = count + 1;
                return;
            }

            useWords[i] = true;
            dfs(words[i], target, words, useWords, count + 1);
            useWords[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> useWords(words.size(), false);
    dfs(begin, target, words, useWords);

    if (answer == 51) {
        answer = 0;
    }

    return answer;
}