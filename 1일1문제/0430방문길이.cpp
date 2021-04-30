/*
게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.

U: 위쪽으로 한 칸 가기

D: 아래쪽으로 한 칸 가기

R: 오른쪽으로 한 칸 가기

L: 왼쪽으로 한 칸 가기

캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다. 좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.

명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.

제한사항
dirs는 string형으로 주어지며, 'U', 'D', 'R', 'L' 이외에 문자는 주어지지 않습니다.
dirs의 길이는 500 이하의 자연수입니다.

출발 지점 x1,y1 + 도착 지점 x2,y2 벡터로 저장
-5~5 안에 속하는지 확인 후 map에 저장
길을 저장하기 위해선 (x1,y1,x2,y2), (x2,y2,x1,y1) 두개를 저장
마지막에 map의 크기를 나누기 2하면 원하는 값 출력
*/

#include <string>
#include <tuple>
#include <map>
#include <vector>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    map<vector<int>, int> map;
    vector<int> vec;

    for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == 'U') {
            y2++;
        }
        else if (dirs[i] == 'D') {
            y2--;
        }
        else if (dirs[i] == 'R') {
            x2++;
        }
        else {
            x2--;
        }

        if (y2 > 5 || y2 < -5 || x2 > 5 || x2 < -5) {
            x2 = x1;
            y2 = y1;
        }
        else {
            vec.push_back(x1);
            vec.push_back(y1);
            vec.push_back(x2);
            vec.push_back(y2);

            map[vec]++;

            vec.clear();

            vec.push_back(x2);
            vec.push_back(y2);
            vec.push_back(x1);
            vec.push_back(y1);

            x1 = x2;
            y1 = y2;

            map[vec]++;
            vec.clear();
        }
    }

    answer = map.size() / 2;

    return answer;
}