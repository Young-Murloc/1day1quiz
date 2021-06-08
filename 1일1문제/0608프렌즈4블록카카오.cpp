/*
각 문자는 라이언(R), 무지(M), 어피치(A), 프로도(F), 네오(N), 튜브(T), 제이지(J), 콘(C)을 의미한다

입력으로 블록의 첫 배치가 주어졌을 때, 지워지는 블록은 모두 몇 개인지 판단하는 프로그램을 제작하라.

일치하는 타일 종합 후 삭제
*/

#include <string>
#include <vector>

using namespace std;
vector<vector<int>> square;
vector<string> board;
int answer = 0;

void detectSquare(int m, int n) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            char c = board[i][j];
            if (c == '0')
                continue;
            if (c == board[i][j + 1] && c == board[i + 1][j + 1] && c == board[i + 1][j]) {
                square.push_back({ i, j });
            }
        }
    }
    if (square.size() != 0) {
        // 삭제
        for (int i = 0; i < square.size(); i++) {
            int row = square[i][0];
            int col = square[i][1];
            if (board[row][col] != '0') {
                board[row][col] = '0';
                answer++;
            }
            if (board[row + 1][col] != '0') {
                board[row + 1][col] = '0';
                answer++;
            }
            if (board[row][col + 1] != '0') {
                board[row][col + 1] = '0';
                answer++;
            }
            if (board[row + 1][col + 1] != '0') {
                board[row + 1][col + 1] = '0';
                answer++;
            }
        }

        // 내리기
        int down = 0;
        bool fill = false;
        for (int j = 0; j < n; j++) {
            fill = false;
            for (int i = m - 1; i >= 0; i--) {
                if (board[i][j] == '0') {
                    if (!fill) {
                        fill = true;
                        down = i;
                    }
                }
                else {
                    if (fill) {
                        board[down][j] = board[i][j];
                        board[i][j] = '0';
                        down--;
                    }
                }
            }
        }
        square.clear();
        detectSquare(m, n);
    }
}

int solution(int m, int n, vector<string> b) {
    board = b;
    detectSquare(m, n);
    return answer;
}

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(int x, int y, vector<string> board, char tile, vector<pair<int,int>>& vec){
    if((board[x+1][y] == tile)&&(board[x][y+1] == tile)&&(board[x+1][y+1] == tile)){
        vec.push_back(pair<int,int>(x,y));
        vec.push_back(pair<int,int>(x+1,y));
        vec.push_back(pair<int,int>(x,y+1));
        vec.push_back(pair<int,int>(x+1,y+1));
        return true;
    }
    else{
        return false;
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<pair<int,int>> vec;

    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            if(check(i,j,board,board[i][j],vec)){

            }
        }
    }



    for(int i=0; i<vec.size(); i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }

    return answer;
}
*/