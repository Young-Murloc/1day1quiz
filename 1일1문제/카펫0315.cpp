/*
Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;      //크기
    int x = 0;      //가로
    int y = 0;      //세로

    if (yellow == 0) {        //가로가 세로보다 같거나 길다
        y = 2;
        x = 2;
    }
    else {
        y = 3;
        x = 3;
    }

    while (1) {
        if ((x * y) == size) {
            if (((x - 2) * (y - 2)) == yellow) {          //세로 길이에 칠해질 노란색 격자 수가 맞는지 검증
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }

        if ((x * y) < size) {                         //가로 * 세로가 크기를 넘지 못할 경우 가로 길이 증가
            x++;
        }
        else {                                   //가로 * 세로가 크기를 넘을 경우 가로와 세로 + 1 초기화
            y++;
            x = y;
        }
    }

    return answer;
}