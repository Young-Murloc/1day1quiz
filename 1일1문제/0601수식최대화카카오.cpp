/*
expression�� ���̰� 3 �̻� 100 ������ ���ڿ��Դϴ�.
expression�� ���鹮��, ��ȣ���� ���� ������ ���ڿ� 3������ ������(+, -, *) ������ �̷���� �ùٸ� ����ǥ���(������ �� ��� ���̿� �����ȣ�� ����ϴ� ���)���� ǥ���� ������Դϴ�. �߸��� ������� �Է����� �־����� �ʽ��ϴ�.
��, "402+-561*"ó�� �߸��� ������ �ùٸ� ����ǥ����� �ƴϹǷ� �־����� �ʽ��ϴ�.
expression�� �ǿ�����(operand)�� 0 �̻� 999 ������ �����Դϴ�.
��, "100-2145*458+12"ó�� 999�� �ʰ��ϴ� �ǿ����ڰ� ���Ե� ������ �Է����� �־����� �ʽ��ϴ�.
"-56+100"ó�� �ǿ����ڰ� ������ ���ĵ� �Է����� �־����� �ʽ��ϴ�.
expression�� ��� 1�� �̻��� �����ڸ� �����ϰ� �ֽ��ϴ�.
������ �켱������ ��� �����ϴ���, expression�� �߰� ��갪�� ���� �ᱣ���� ������ 263 - 1 ���ϰ� �ǵ��� �Է��� �־����ϴ�.
���� �����ڳ����� �տ� �ִ� ���� �켱������ �� �����ϴ�
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> exp, location;
    string n = "";

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            num.push_back(stoi(n));
            n = "";
            if (find(exp.begin(), exp.end(), expression[i]) == exp.end())
                exp.push_back(expression[i]);
            location.push_back(expression[i]);
        }
        else
            n += expression[i];
    }

    num.push_back(stoi(n));
    sort(exp.begin(), exp.end());

    do
    {
        vector<long long> tmp_num = num;
        vector<char> tmp_loc = location;

        for (int i = 0; i < exp.size(); i++)
        {
            for (int j = 0; j < tmp_loc.size(); j++)
            {
                if (exp[i] == tmp_loc[j])
                {
                    if (tmp_loc[j] == '+')
                        tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    else if (tmp_loc[j] == '-')
                        tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    else if (tmp_loc[j] == '*')
                        tmp_num[j] = tmp_num[j] * tmp_num[j + 1];

                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_loc.erase(tmp_loc.begin() + j);
                    j--;
                }
            }
        }

        if (answer < abs(tmp_num[0]))
            answer = abs(tmp_num[0]);
    } while (next_permutation(exp.begin(), exp.end()));

    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

long long cal(long long a, long long b, char op){
    if(op == '+'){
        return a+b;
    }
    else if(op == '-'){
        return a-b;
    }
    else{
        return a*b;
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> op;
    string numTemp;

    for(int i=0; i<expression.length(); i++){
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
            num.push_back(atoi(numTemp.c_str()));
            numTemp = "";
            op.push_back(expression[i]);
        }
        else{
            numTemp += expression[i];
        }
    }
    num.push_back(atoi(numTemp.c_str()));



    return answer;
}
*/