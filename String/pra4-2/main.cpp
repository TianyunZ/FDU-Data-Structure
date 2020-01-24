/*给定两个字符串，s1、s2，找出最少的修改步数，使得两个字符串成为相同的字符串，每一步定义为在一个字符串中修改一个字符。
例如：”about”, “above”
输出：2（将”above”中的v修改为u，e修改为t）*/
//递归

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
