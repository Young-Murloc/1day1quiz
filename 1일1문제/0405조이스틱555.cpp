/*
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동
예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요

<주의사항>
그리디 알고리즘
오른쪽으로 이동하거나 왼쪽으로 이동할때 조작해야하는 인덱스가 처음, 마지막으로 움직일수 있기 때문에 관련 처리를 해줘야함
numeric 헤더, accumulate의 경우 stl의 원소를 종합해서 계산할때 유용하게 사용
*/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>                  // accumulate 벡터 원소의 합
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

        while (true) {        //우측 이동
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

        while (true) {                            //좌측 이동 -> 문장의 처음에서 마지막으로 이동하는 경우 고려
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