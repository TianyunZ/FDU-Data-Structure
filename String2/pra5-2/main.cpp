#include <iostream>
#include <string.h>

using namespace std;

int manacher(char s[], int rad[], int length){
    for (int i = 1, j = 0, k; i < length; i +=k) {
        while (s[i-j-1] == s[i+j+1])
            ++ j;
        rad[i] = j;
        for (k = 1; k <= rad[i] && rad[i-k] != rad[i]-k; ++k){ // 利用类似镜像的方法缩短了时间
            rad[i+k] = min(rad[i-k], rad[i]-k);
        }
        j = max(j-k, 0);
    }
    return 0;
}

int main()
{
    cout << "please input a string with #:" << '\n' << "for example: #a#b#c#" << endl;
    char s[20]={'\0'};
    char x;
    int i = 0;
    int max = 0;
    while (cin >> x){
        s[i] =x;
        i ++;
    }
    s[i] = '\0';
    int size = i;
    int rad[size] = {1};
    manacher(s, rad, size);
    for (i = 0; i < size; i ++){
        if (rad[i] > max)
            max = rad[i];
    }
    cout << "最大回文子串长度为：" << max << endl;
    return 0;
}
