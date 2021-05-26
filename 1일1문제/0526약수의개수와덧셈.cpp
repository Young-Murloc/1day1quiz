/*
두 정수 left와 right가 매개변수로 주어집니다. left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.

약수 구하는 최적화된 방법 고민
*/

#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int count = 0;

    int j = 0;

    for (int i = left; i <= right; i++) {
        count = 0;
        j = 0;

        for (j = 1; j * j < i; j++) {
            if (i % j == 0) {
                count += 2;
            }
        }

        if (j * j == i) {
            count++;
        }

        if (count % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }

    return answer;
}