#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "请输入n,k和一组整数：\n";
    int n,k;
    vector<long long> number;
    cin>>n>>k;
    int i=0;
    long long t;
    long long x;
    while(cin>>x){
        number.push_back(x);
    }
    for(i=0;i<(n-1);i++){
        for(int j=n-1;j>i;j--){
            if(number[j]>number[j-1]){
                t=number[j];
                number[j]=number[j-1];
                number[j-1]=t;
            }
        }
    }
    for(i=0;i<k;i++){
        cout<<number[i]<<" ";
    }
    return 0;
}
//10 4 77 199999 47 -5 -65536 89 9 -214 43
