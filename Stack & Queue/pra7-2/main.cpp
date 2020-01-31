#include <iostream>
#include <stdlib.h>
using namespace std;

int q[20];

void print(int n){
    for (int i = 1; i <= n; i ++){
        cout << '(' << i << ',' << q[i] << ')' << ' ';
    }
    cout << ' ' << endl;
    for (int i = 1; i <= n; i ++){
        for (int j=1; j<=n; j++){
            if (q[i] == j)
                cout << 'Q' << ' ';
            else
                cout << 'X' << ' ';
        }
        cout << ' ' << endl;
    }
}

int find(int i, int j){
    if (i == 1 && j == 1)
        return 1;
    for (int k = 1; k < i; k++){
        if (q[k] == j || abs(i-k) == abs(q[k]-j)){
            return 0;
        }
    }
    return 1;
}

void queen(int i, int n){
    if (i > n)
        print(n);
    else{
        for (int j = 1; j <= n; j ++){
            if (find(i, j)){
                q[i] = j;
                queen(i+1, n);
            }
        }
    }
}

int main()
{
    cout << "please input n:" << endl;
    int n;
    cin >> n;
    queen(1, n);
    return 0;
}
