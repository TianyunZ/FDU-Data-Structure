/*���������ַ�����s1��s2���ҳ����ٵ��޸Ĳ�����ʹ�������ַ�����Ϊ��ͬ���ַ�����ÿһ������Ϊ��һ���ַ������޸�һ���ַ���
���磺��about��, ��above��
�����2������above���е�v�޸�Ϊu��e�޸�Ϊt��*/
//�ݹ�

#include <iostream>
#include <string.h>

using namespace std;

int min(int a, int b, int c){
    return a<(b<c?b:c)?a:(b<c?b:c);
}

int modify(char* A, char* B){
    if(*A == '\0'){
        return strlen(B);
    }
    if(*B == '\0'){
        return strlen(A);
    }
    if (*A != *B){
            return 1 + min(modify(A+1,B),modify(A,B+1),modify(A+1,B+1));
    }
    else{
        return modify(A+1,B+1);
    }
}

int main()
{
    cout << "Please input two strings:" << endl;
    string s1, s2;
    int k = 0;
    cin >> s1 >> s2;
    k = modify(&s1[0], &s2[0]);
    cout << k << endl;
    return 0;
}
