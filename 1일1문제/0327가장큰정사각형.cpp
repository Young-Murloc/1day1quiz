/*
dp로 풀기
*/

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
