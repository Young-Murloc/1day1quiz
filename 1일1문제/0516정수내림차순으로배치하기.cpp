/*
함수 solution은 정수 n을 매개변수로 입력받습니다. n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 예를들어 n이 118372면 873211을 리턴하면 됩니다.

제한 조건
n은 1이상 8000000000 이하인 자연수입니다.

정수 <-> 실수
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    long long div = 1000000000;
    int count = 0;
    
    while(div > 0){
        if(num.size() != 0 && n/div == 0){
            num.push_back(0);
        }
        
        if(n >= div){
            num.push_back(n / div);
            n = n % div;
        }
        
        div /= 10;
    }
    
    sort(num.begin(),num.end());
    
    div = 1;
    
    for(int i=0; i<num.size(); i++){
        if(num[i] == 0){
            count++;
        }
        else{
            answer += num[i] * div;
        }
        
        div *= 10;
    }
    
    return answer;
}
