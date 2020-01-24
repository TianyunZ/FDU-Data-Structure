#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    cout<<"please input two strings:"<<endl;
    //char s1[100];
    //char s2[100];
    string s1,s2;
    int a[26]={0};
    int b[26]={0};
    char t;
    int size1,size2;
    cin>>s1>>s2;
   // cout<<s1<<' '<<s2;
    //size1=strlen(s1);
    //size2=strlen(s2);
    size1=s1.size();
    size2=s2.size();
    for(int i=0;i<size1;i++){
        a[s1[i]-'a']++;
    }
    for(int i=0;i<size2;i++){
        for(int j=i;j<size1+i;j++){
            b[s2[j]-'a']++;
        }
        for(int k=0;k<26;k++){
            if(a[k]!=b[k])
                break;
            if(k==25){
                cout<<"true";
                return 0;
            }
        }
        for(int k=0;k<26;k++){
            b[k]=0;
        }
    }
    cout<<"false";
    return 0;
}
