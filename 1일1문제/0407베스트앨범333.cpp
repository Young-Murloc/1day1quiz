/*
��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�. �뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.

���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
�뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, ����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���
genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
genres�� plays�� ���̴� ������, �̴� 1 �̻� 10,000 �����Դϴ�.
�帣 ������ 100�� �̸��Դϴ�.
�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
��� �帣�� ����� Ƚ���� �ٸ��ϴ�.

map�� �̿��Ͽ� ������ Ű�� ������� ����
������� �ߺ��Ǹ� ���� X
Ű���� �ߺ��Ǹ� ���� O

�ҽ��ڵ尡 ������ ������ ���� �ٽ� Ǯ���
*/

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<int, string> numbersGenres;      // <��ȣ,�帣>
    map<string, int> genresPlays;        // �� �帣���� �� �÷��� Ƚ�� ����

    int max = 0;
    string genresName = "";

    int count = 0;              // ���ѷ������� Ż���ϱ� ���� ����

    for (int i = 0; i < genres.size(); i++) {             // ��ȣ �帣 �Է�
        numbersGenres.insert(pair<int, string>(i, genres[i]));        // ��ȣ,�帣 �Է�
        genresPlays[genres[i]] += plays[i];
    }

    while (true) {
        for (auto iter = genresPlays.begin(); iter != genresPlays.end(); iter++) {        // ���� ���� ����� �帣 ã�Ƽ� ������ ����
            if (max < iter->second) {
                genresName = iter->first;
                max = iter->second;
            }
        }

        genresPlays[genresName] = -1;           // answer�� ���Ե� �帣�� ǥ��

        int maxPlay = 0;
        int maxPlaysNumber = 0;
        int checkNumber = 0;
        for (int i = 0; i < numbersGenres.size(); i++) {
            if (numbersGenres[i] == genresName) {
                if (maxPlay < plays[i]) {
                    maxPlay = plays[i];
                    maxPlaysNumber = i;
                    checkNumber = i;
                }
            }
        }

        answer.push_back(maxPlaysNumber);

        maxPlay = -1;
        maxPlaysNumber = -1;
        for (int i = 0; i < numbersGenres.size(); i++) {
            if (numbersGenres[i] == genresName) {
                if (maxPlay < plays[i]) {
                    if (i != checkNumber) {
                        maxPlay = plays[i];
                        maxPlaysNumber = i;
                    }
                }
            }
        }

        if (maxPlaysNumber != -1) {
            answer.push_back(maxPlaysNumber);
        }

        count++;
        max = 0;

        if (count == genresPlays.size()) {
            break;
        }
    }

    return answer;
}