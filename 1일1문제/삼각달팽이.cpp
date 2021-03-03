/*
정수 n이 매개변수로 주어집니다. 다음 그림과 같이 밑변의 길이와 높이가 n인 삼각형에서 맨 위 꼭짓점부터 반시계 방향으로 달팽이 채우기를 진행한 후, 첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 return 하도록 solution 함수를 완성해주세요.

재귀 함수 사용하기?
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[n][n];

    int ori = n;

    //arr 저장시 필요한 변수
    int x = 0;
    int y = 0;
    int count = 0;

    //몇번째 숫자가 마지막 숫자인지 계산
    int lastNum = 0;
    int num = 1;

    //arr를 0으로 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        lastNum = lastNum + num;
        num++;
    }

    count++;


    while (1) {
        for (int i = 0; i < ori; i++) {
            arr[x][y] = count;
            count++;
            x++;

            if (count == lastNum + 1) {
                break;
            }
        }

        if (count == lastNum + 1) {
            break;
        }

        x--;
        y++;
        ori--;

        for (int i = 0; i < ori; i++) {
            arr[x][y] = count;
            count++;
            y++;

            if (count == lastNum + 1) {
                break;
            }
        }

        if (count == lastNum + 1) {
            break;
        }

        x--;
        y--;
        ori--;

        for (int i = 0; i < ori; i++) {
            arr[x][y] = count;
            count++;
            x--;

            if (count == lastNum + 1) {
                break;
            }
        }

        if (count == lastNum + 1) {
            break;
        }

        x += 2;
        y -= ori;
        ori--;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                answer.push_back(arr[i][j]);
            }
        }
        cout << endl;
    }

    return answer;
}