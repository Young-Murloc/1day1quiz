/*
점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다. 다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다. 학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다. 예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다. 체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.

전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.

제한사항
전체 학생의 수는 2명 이상 30명 이하입니다.
체육복을 도난당한 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
여벌의 체육복을 가져온 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다.
여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.

그리디 알고리즘 사용
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    map<int, int> student;
    map<int, int>::iterator iter;

    for (int i = 1; i <= n; i++) {                // 전체 학생 입력
        student[i]++;
    }

    for (int i = 0; i < lost.size(); i++) {       // 체육복 도난 당한 학생 입력
        student[lost[i]]--;
    }

    for (int i = 0; i < reserve.size(); i++) {    // 여분 체육복 가져온 학생 입력
        student[reserve[i]]++;
    }

    for (iter = student.begin(); iter != student.end(); iter++) {     // 체육복을 전달하는 과정 2개 이상 가진 친구가 앞 뒤 친구중 0개 가진 친구에게 전달
        if (iter->second >= 2) {
            student[iter->first]--;
            if (student[iter->first - 1] == 0) {
                student[iter->first - 1]++;
            }
            else if (student[iter->first + 1] == 0) {
                student[iter->first + 1]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {            // 체육복이 한개 이상 있는 친구 검사
        if (student[i] >= 1) {
            answer++;
        }
    }

    return answer;
}