/*
���� ĳ���͸� 4���� ��ɾ ���� �����̷� �մϴ�. ��ɾ�� ������ �����ϴ�.

U: �������� �� ĭ ����

D: �Ʒ������� �� ĭ ����

R: ���������� �� ĭ ����

L: �������� �� ĭ ����

ĳ���ʹ� ��ǥ����� (0, 0) ��ġ���� �����մϴ�. ��ǥ����� ���� ���� ��(-5, 5), ���� �Ʒ�(-5, -5), ������ ��(5, 5), ������ �Ʒ�(5, -5)�� �̷���� �ֽ��ϴ�.

��ɾ �Ű����� dirs�� �־��� ��, ���� ĳ���Ͱ� ó�� �ɾ ���� ���̸� ���Ͽ� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
dirs�� string������ �־�����, 'U', 'D', 'R', 'L' �̿ܿ� ���ڴ� �־����� �ʽ��ϴ�.
dirs�� ���̴� 500 ������ �ڿ����Դϴ�.

��� ���� x1,y1 + ���� ���� x2,y2 ���ͷ� ����
-5~5 �ȿ� ���ϴ��� Ȯ�� �� map�� ����
���� �����ϱ� ���ؼ� (x1,y1,x2,y2), (x2,y2,x1,y1) �ΰ��� ����
�������� map�� ũ�⸦ ������ 2�ϸ� ���ϴ� �� ���
*/

#include <string>
#include <tuple>
#include <map>
#include <vector>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    map<vector<int>, int> map;
    vector<int> vec;

    for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == 'U') {
            y2++;
        }
        else if (dirs[i] == 'D') {
            y2--;
        }
        else if (dirs[i] == 'R') {
            x2++;
        }
        else {
            x2--;
        }

        if (y2 > 5 || y2 < -5 || x2 > 5 || x2 < -5) {
            x2 = x1;
            y2 = y1;
        }
        else {
            vec.push_back(x1);
            vec.push_back(y1);
            vec.push_back(x2);
            vec.push_back(y2);

            map[vec]++;

            vec.clear();

            vec.push_back(x2);
            vec.push_back(y2);
            vec.push_back(x1);
            vec.push_back(y1);

            x1 = x2;
            y1 = y2;

            map[vec]++;
            vec.clear();
        }
    }

    answer = map.size() / 2;

    return answer;
}