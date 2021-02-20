/*
1937년 Collatz란 사람에 의해 제기된 이 추측은, 주어진 수가 1이 될때까지 다음 작업을 반복하면, 모든 수를 1로 만들 수 있다는 추측입니다. 작업은 다음과 같습니다.
예를 들어, 입력된 수가 6이라면 6→3→10→5→16→8→4→2→1 이 되어 총 8번 만에 1이 됩니다. 위 작업을 몇 번이나 반복해야하는지 반환하는 함수, solution을 완성해 주세요. 단, 작업을 500번을 반복해도 1이 되지 않는다면 –1을 반환해 주세요.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    int count = 0;

    while (true) {
        if (count == 450) {
            answer = -1;
            break;
        }

        if (num == 1) {
            answer = count;
            break;
        }

        if (num % 2 == 0) {       //짝수
            num = num / 2;
        }
        else {
            num = num * 3 + 1;
        }

        count++;
    }

    return answer;
}