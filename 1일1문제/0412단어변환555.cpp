/*
두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 "hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

1. DFS로 접근
2. 사용한 단어를 bool 형태로 저장 -> 변하기 전으로 돌아가지 않기 위해서
3. 재귀를 통해 제일 작은 answer 값 갱신
*/

#include <string>
#include <vector>

using namespace std;

int answer = 51;

void dfs(string begin, string target, vector<string> words, vector<bool>& useWords, int count = 0) {
    for (int i = 0; i < words.size(); i++) {
        int check = 0;

        for (int j = 0; j < words[i].size(); j++) {       // 한글자만 변한지 확인
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