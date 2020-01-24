#include <iostream>
#include <vector>

using namespace std;

int middle(int c[],int k){
    int t,x;
    int v[k];
    for(int i=0;i<k;i++){
        v[i]=c[i];
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k-1-i;j++){
            if(v[j]<v[j+1]){
                t=v[j];
                v[j]=v[j+1];
                v[j+1]=t;
            }
        }
    }
    if(k%2==0){
        x=k/2-1;
        return (v[x]+v[x+1])/2;
    }
    if(k%2!=0){
        x=k/2;
        return v[x];
    }
}

int main()
{
    cout << "请输入区间长度和数组：" << endl;
    vector<int> vec;
    vector<int> mid;
    int x;
    int k,i,p;
    i=0;
    cin>>k;
    while(cin>>x){
        vec.push_back(x);
    }
   // cout<<vec.size();
    while(i+k<=vec.size()){
        p=middle(&vec[i],k);
        mid.push_back(p);
        i++;

    }
    cout<<"[ ";//''只能包含单个字符！
    for(int j=0;j<i;j++){
        cout<<mid[j]<<' ';
    }
    cout<<']';
    return 0;
}
