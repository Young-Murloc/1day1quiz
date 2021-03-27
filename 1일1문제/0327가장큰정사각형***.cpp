/*
1와 0로 채워진 표(board)가 있습니다. 표 1칸은 1 x 1 의 정사각형으로 이루어져 있습니다. 표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return 하는 solution 함수를 완성해 주세요. (단, 정사각형이란 축에 평행한 정사각형을 말합니다.)

<주의사항>
dp를 이용한 문제
memoization를 이용한 문제

board[i][j]를 기준으로 dp[i-1][j], dp[i][j-1], dp[i-1][j-1]중 최솟값 + 1이 dp[i][j]가 된다
순차적으로 진행하여 최종적으로 가장 큰 dp[i][j] 값을 제곱한 값이 답이 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int dp[1000][1000];
    int row = board.size();
    int col = board[0].size();
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            dp[i][j] = board[i][j];
        }
    }
    
    answer = dp[0][0];
    
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if(dp[i][j] != 0){
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                answer = max(answer,dp[i][j]);    
            }
        }
    }
    
    return answer * answer;
}

/*
dp를 이요하지 않고 접근한 코드
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    vector<int> arr_x;
    vector<int> arr_y;
    int sum;
    
    int sum_x = 0;
    int sum_y = 0;
    
    int check = 0;
    
    int conti = 0;
    bool pass_x = false;
    bool pass_y = false;
    
    for(int i=0; i<board.size(); i++){              //가로 길이 입력
        sum = 0;
        for(int j=0; j<board[i].size(); j++){
            sum += board[i][j];
        }
        arr_x.push_back(sum);
    }
    
    for(int i=0; i<board[0].size(); i++){
        sum = 0;
        for(int j=0; j<board.size(); j++){
            sum += board[j][i];
        }
        arr_y.push_back(sum);
    }
    
    
    if(board.size() > board[0].size())
        check = board[0].size();
    else
        check = board.size();
    
    // check를 평균값으로 설정?
    
    for(check; check>0; check--){
        sum_x = 0;
        sum_y = 0;
        pass_x = false;
        pass_y = false;
        conti = 0;
        
        for(int j=0; j<arr_x.size(); j++){
            if(arr_x[j] >= check){
                sum_x++;
                conti++;
            }
            else{
                conti = 0;
            }
            
            if(conti >= check){
                pass_x = true;
            }
        }
        
        conti = 0;
        
        for(int j=0; j<arr_y.size(); j++){
            if(arr_y[j] >= check){
                sum_y++;
                conti++;
            }
            else{
                conti = 0;
            }
            
            if(conti >= check){
                pass_y = true;
            }
        }
        
        if(sum_x >= check && sum_y >= check && pass_x && pass_y){       // check를 넘는 값이 연속해서 check개보다 넘을 경우 pass = true
            return check*check;
        }
    }
    
    return 0;
}
*/
