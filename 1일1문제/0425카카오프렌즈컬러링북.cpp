/*
카카오 프렌즈 컬러링북
출판사의 편집자인 어피치는 네오에게 컬러링북에 들어갈 원화를 그려달라고 부탁하여 여러 장의 그림을 받았다. 여러 장의 그림을 난이도 순으로 컬러링북에 넣고 싶었던 어피치는 영역이 많으면 색칠하기가 까다로워 어려워진다는 사실을 발견하고 그림의 난이도를 영역의 수로 정의하였다. (영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)

그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성해보자.

alt text

위의 그림은 총 12개 영역으로 이루어져 있으며, 가장 넓은 영역은 어피치의 얼굴면으로 넓이는 120이다.

입력 형식
입력은 그림의 크기를 나타내는 m과 n, 그리고 그림을 나타내는 m × n 크기의 2차원 배열 picture로 주어진다. 제한조건은 아래와 같다.

1 <= m, n <= 100
picture의 원소는 0 이상 2^31 - 1 이하의 임의의 값이다.
picture의 원소 중 값이 0인 경우는 색칠하지 않는 영역을 뜻한다.
*/

// 문제가 이상한것 같음 1번 코드에서 count를 이중 for문 안에서 생성 및 초기화를 해주면 문제 해결이 되고 for문 밖에 생성 및 첫번째 for문에서 초기화시 오답이라고 뜸
// 이유가 뭔지 모

// 1번
#include <vector>

using namespace std;

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

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<long long>> pic(m,vector<long long>(n,0));

    vector<int> answer(2);
    int domain = 0;        // 영역
    int max = 0;

    for(int i=0; i<pic.size(); i++){
        for(int j=0; j<pic[0].size(); j++){
            pic[i][j] = picture[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(pic[i][j] != 0){
                int number = 0;
                dp(pic,i,j,pic[i][j],number);
                domain++;
                
                if(max<number)
                max = number;
            }
        }
    }

    answer[0] = domain;
    answer[1] = max;

    return answer;
}

// 2번
#include <vector>

using namespace std;

void dp(vector<vector<int>>& picture, int m, int n, int target, int& count){
    if(m < 0 || n < 0 || m >= picture.size() || n >= picture[0].size() || picture[m][n] != target){
        return;
    }
    
    picture[m][n] = 0;
    count++;
    
    dp(picture,m-1,n,target,count);
    dp(picture,m+1,n,target,count);
    dp(picture,m,n-1,target,count);
    dp(picture,m,n+1,target,count);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j] != 0){
                int count = 0;
                dp(picture,i,j,picture[i][j],count);
                number_of_area++;
                
                if(max_size_of_one_area < count){
                    max_size_of_one_area = count;
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

/*
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
*/
