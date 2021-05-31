/*
nums�� ���ϸ��� ���� ��ȣ�� ��� 1���� �迭�Դϴ�.
nums�� ����(N)�� 1 �̻� 10,000 ������ �ڿ����̸�, �׻� ¦���� �־����ϴ�.
���ϸ��� ���� ��ȣ�� 1 �̻� 200,000 ������ �ڿ����� ��Ÿ���ϴ�.
���� ���� ������ ���ϸ��� �����ϴ� ����� ���� ������ ��쿡��, ������ �� �ִ� ���ϸ� ���� ������ �ִ� �ϳ��� return �ϸ� �˴ϴ�.

�ߺ����� �������� �ʴ� �����̳ʸ� �̿��ϸ� ���� �ذ� ����
*/

#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> box;

    for (int i = 0; i < nums.size(); i++) {
        box.insert(nums[i]);
    }

    if (box.size() <= nums.size() / 2) {
        answer = box.size();
    }
    else {
        answer = nums.size() / 2;
    }

    return answer;
}