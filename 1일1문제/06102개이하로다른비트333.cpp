/*
정수들이 담긴 배열 numbers가 매개변수로 주어집니다. numbers의 모든 수들에 대하여 각 수의 f 값을 배열에 차례대로 담아 return 하도록 solution 함수를 완성해주세요.

짝수 2n -> 2n+1

홀수 n -> n-1 자리의 비트수 더하기
ex) f(101111) = 000111
*/

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long bit;

    for (int i = 0; i < numbers.size(); i++) {
        bit = 1;

        if (numbers[i] % 2 == 0) {
            answer.push_back(numbers[i] + 1);
        }
        else {
            while (true) {
                if ((numbers[i] & bit) == 0)
                    break;

                bit *= 2;
            }

            bit = bit / 2;
            answer.push_back(numbers[i] + bit);
        }
    }

    return answer;
}