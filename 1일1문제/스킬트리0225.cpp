/*
Summer/Winter Coding(~2018)
선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻합니다.

예를 들어 선행 스킬 순서가 스파크 → 라이트닝 볼트 → 썬더일때, 썬더를 배우려면 먼저 라이트닝 볼트를 배워야 하고, 라이트닝 볼트를 배우려면 먼저 스파크를 배워야 합니다.

위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다. 따라서 스파크 → 힐링 → 라이트닝 볼트 → 썬더와 같은 스킬트리는 가능하지만, 썬더 → 스파크나 라이트닝 볼트 → 스파크 → 힐링 → 썬더와 같은 스킬트리는 불가능합니다.

선행 스킬 순서 skill과 유저들이 만든 스킬트리1를 담은 배열 skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 return 하는 solution 함수를 작성해주세요.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    int temp = 0;

    for (int i = 0; i < skill_trees.size(); i++) {        //설계한 스킬 트리 만큼 반복
        for (int j = 0; j < skill.size() - 1; j++) {        //유효한 스킬 트리 만큼 반복
            if (skill_trees[i].find(skill[j]) > skill_trees[i].find(skill[j + 1])) {
                answer--;                           //주어진 스킬 트리 안에 유효한 스킬 트리가 순서대로 있는지 확인
                break;
            }
        }
    }

    return answer;
}