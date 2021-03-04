/*
���� n�� �Ű������� �־����ϴ�. ���� �׸��� ���� �غ��� ���̿� ���̰� n�� �ﰢ������ �� �� ���������� �ݽð� �������� ������ ä��⸦ ������ ��, ù ����� ������ ����� ��� ������� ��ģ ���ο� �迭�� return �ϵ��� solution �Լ��� �ϼ����ּ���.

��� �Լ� ����ϱ�?
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[n][n];

    int ori = n;

    //arr ����� �ʿ��� ����
    int x = 0;
    int y = 0;
    int count = 0;

    //���° ���ڰ� ������ �������� ���
    int lastNum = 0;
    int num = 1;

    //arr�� 0���� �ʱ�ȭ
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