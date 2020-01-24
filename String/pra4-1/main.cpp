/*给定一个仅由数字组成的字符串，从中按顺序取出四个数字，组成一个合法的IPv4的地址，列出所有可能的组合。
IPv4地址由四个[0, 255]内的整数组成，以点’.’作为分隔符。
例如：”25525512211”
返回：”255.255.12.211”, “255.255.122.11”*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please input a number string:" << endl;
    string s;
    cin >> s;
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    int size;
    int i = 1, j = 1, k = 1;
    size = s.size();
    if (size>12 || size<4){
        cout << "Wrong input!" << endl;
        return 0;
    }
    for (i=1; i<4; i++){
        if (i == 3){
            num1 = 100*(s[0]-'0')+10*(s[1]-'0')+s[2]-'0';
            if (num1 > 255)
                continue;
        }
        if (i == 2){
            num1 = 10*(s[0]-'0')+s[1]-'0';
        }
        if (i == 1){
            num1 = s[0]-'0';
        }
        for (j=1; j<4; j++){
            if (j == 3){
                num2 = 100*(s[i]-'0')+10*(s[i+1]-'0')+s[i+2]-'0';
                if (num2 > 255)
                    continue;
            }
            if (j == 2){
                num2 = 10*(s[i]-'0')+s[i+1]-'0';
            }
            if (j == 1){
                num2 = s[i]-'0';
            }
            for (k=1; k<4; k++){
                if (i+j+k < size-3)
                    continue;
                if (i+j+k == size)
                    break;
                if (k == 3){
                    num3 = 100*(s[i+j]-'0')+10*(s[i+j+1]-'0')+s[i+j+2]-'0';
                    if (num3 > 255)
                        continue;
                }
                if (k == 2){
                    num3 = 10*(s[i+j]-'0')+s[i+j+1]-'0';
                }
                if (k == 1){
                    num3 = s[i+j]-'0';
                }
                if (i+j+k == size-3){
                    num4 = 100*(s[size-3]-'0')+10*(s[size-2]-'0')+s[size-1]-'0';
                    if (num4 > 255)
                        continue;
                }
                if (i+j+k == size-2){
                    num4 = 10*(s[size-2]-'0')+s[size-1]-'0';
                }
                if (i+j+k == size-1){
                    num4 = s[size-1]-'0';
                }
                cout << num1 << '.' << num2 << '.' << num3 << '.' << num4 << endl;
            }
        }
    }

    return 0;
}
