#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout<<"ÇëÊäÈëÒ»¸ö×Ö·û´®:\n";
    vector<char> vec;
    int a[26]={0};
    int l=0;
    int t=0;
    int k;
    char x;
    while(cin>>x){
        vec.push_back(x);
    }
    for(int j=0;j<vec.size();j++){
        for(int i=j;i<vec.size();i++){
            k=vec[i]-'a';
            if(a[k]==0)
                a[k]=1;
            else{
                t=i-j;
                if(l<t)
                    l=t;
                for(int m=0;m<26;m++){
                    a[m]=0;
                }
                break;
            }
        }
    }

    cout<<l<<endl;
    return 0;
}
//abdaoecas
