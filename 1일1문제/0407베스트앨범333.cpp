/*
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

제한사항
genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다.

map을 이용하여 각각의 키값 밸류값을 저장
밸류값이 중복되면 문제 X
키값이 중복되면 문제 O

소스코드가 더럽기 때문에 추후 다시 풀어볼것
*/

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<int, string> numbersGenres;      // <번호,장르>
    map<string, int> genresPlays;        // 각 장르별로 총 플레이 횟수 저장

    int max = 0;
    string genresName = "";

    int count = 0;              // 무한루프에서 탈출하기 위한 변수

    for (int i = 0; i < genres.size(); i++) {             // 번호 장르 입력
        numbersGenres.insert(pair<int, string>(i, genres[i]));        // 번호,장르 입력
        genresPlays[genres[i]] += plays[i];
    }

    while (true) {
        for (auto iter = genresPlays.begin(); iter != genresPlays.end(); iter++) {        // 가장 많이 재생된 장르 찾아서 변수에 삽입
            if (max < iter->second) {
                genresName = iter->first;
                max = iter->second;
            }
        }

        genresPlays[genresName] = -1;           // answer에 삽입될 장르는 표시

        int maxPlay = 0;
        int maxPlaysNumber = 0;
        int checkNumber = 0;
        for (int i = 0; i < numbersGenres.size(); i++) {
            if (numbersGenres[i] == genresName) {
                if (maxPlay < plays[i]) {
                    maxPlay = plays[i];
                    maxPlaysNumber = i;
                    checkNumber = i;
                }
            }
        }

        answer.push_back(maxPlaysNumber);

        maxPlay = -1;
        maxPlaysNumber = -1;
        for (int i = 0; i < numbersGenres.size(); i++) {
            if (numbersGenres[i] == genresName) {
                if (maxPlay < plays[i]) {
                    if (i != checkNumber) {
                        maxPlay = plays[i];
                        maxPlaysNumber = i;
                    }
                }
            }
        }

        if (maxPlaysNumber != -1) {
            answer.push_back(maxPlaysNumber);
        }

        count++;
        max = 0;

        if (count == genresPlays.size()) {
            break;
        }
    }

    return answer;
}