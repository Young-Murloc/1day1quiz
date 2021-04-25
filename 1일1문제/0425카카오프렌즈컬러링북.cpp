#include <vector>

using namespace std;

void dp(vector<vector<long long>>& pic, int x, int y, int temp, int& number);

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<long long>> pic(m,vector<long long>(n,0));
    
    vector<int> answer(2);
    int domain = 0;        // 영역
    int temp = 0;               // 같은 영역인지 확인하기 위한 변수
    int number = 0;
    int max = 0;
    
    for(int i=0; i<pic.size(); i++){
        for(int j=0; j<pic[0].size(); j++){
            pic[i][j] = picture[i][j];
        }
    }
    
    for(int i=0; i<m; i++){
        number = 0;
        for(int j=0; j<n; j++){
            if(pic[i][j] != 0){
                dp(pic,i,j,pic[i][j],number);
                domain++;
            }
        }
        
        if(max<number)
            max = number;
    }
    
    answer[0] = domain;
    answer[1] = max;
    
    return answer;
}

void dp(vector<vector<long long>>& pic, int x, int y, int temp, int& number){
    if(x<0 || y<0 || x>=pic.size() || y>=pic[0].size()){
        return;
    }
    
    if(pic[x][y] == temp){
        number++;
        pic[x][y] = 0;
        
        dp(pic,x-1,y,temp,number);
        dp(pic,x+1,y,temp,number);
        dp(pic,x,y-1,temp,number);
        dp(pic,x,y+1,temp,number);
    }
}
