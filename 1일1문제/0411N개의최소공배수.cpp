/*
두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다. 예를 들어 2와 7의 최소공배수는 14가 됩니다. 정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다. n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요.

최대공약수 -> 유클리드 호제법
최소공배수 -> 0이 아닌 두 수의 곱 / 두 수의 최대 공약수수
*/
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b,a %b);
    }
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    if(arr.size() == 1){
        answer = arr[0];
    }
    else{
        answer = arr[0];
        
        for(int i=0; i<arr.size(); i++){
            answer = lcm(answer,arr[i]);
        }
    }
    
    return answer;
}
