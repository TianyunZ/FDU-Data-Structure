#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct BiNode{
    int data;
    BiNode * lchild;
    BiNode * rchild;
};

//层次遍历生成树
void CreateTree(int a[], int k, BiNode * h){
    queue<BiNode *> q;
    BiNode * t = h;
    BiNode * p;
    int j = 1;
    t->data = a[0];
    t->lchild = t->rchild = NULL;
    q.push(t);
    while(t!=NULL || !q.empty()){
        if(j == k)
            break;
        t = q.front();
        q.pop();
        if(a[j] != -1){
            p = new BiNode();
            p->data = a[j];
            p->lchild = p->rchild = NULL;
            t->lchild = p;
            q.push(p);
            //cout << i << ' ';
        }
        j++;
        if(j == k)
            break;
        if(a[j] != -1){
            p = new BiNode();
            p->data = a[j];
            p->lchild = p->rchild = NULL;
            t->rchild = p;
            q.push(p);
            //cout << j << ' ';
        }
        j++;
    }
}

int a[20] = {0};
int i = 0;
void PreOrder(BiNode* t){
    if(t==NULL){
        return;
    }
    a[i] = a[i] + t->data;
    PreOrder(t->lchild);
    PreOrder(t->rchild);
}

//求子树和
void PlusTree(BiNode * t){
    stack<BiNode *> s;
    s.push(t);
    while(t!=NULL && !s.empty()){
        t = s.top();
        s.pop();
        if(t->rchild!=NULL)
            s.push(t->rchild);
        if(t->lchild!=NULL)
            s.push(t->lchild);
        PreOrder(t);
        i++;
    }
}

void FrequenPlus(int x){
    int b[20];
    int c[20];
    int m, k, num, t;
    m = k = 0;
    num = t = 1;
    sort(a, a+x);//sort函数的用法！
    /*for(int r = 0; r<x; r++){
        cout << a[r] << endl;
    }*/
    while(k < x-1){
        while(a[k] == a[k+1]){
            t ++;
            k ++;
        }
        b[m] = a[k];
        c[m] = t;
        m++;
        k++;
        if(num<t)
            num = t;
        t = 1;
    }
    if(a[k-1] != a[k])
    {
        b[m] = a[k];
        c[m] = 1;
    }
    for(int j = 0; j<=m; j++){
        if(c[j] == num)
            cout << b[j] << endl;
    }
}

int main()
{
    int k = 0, x;
    freopen("input_12_2.txt", "r", stdin);
    freopen("output_12_2.txt", "w", stdout);
    int d[20];
    for(; cin >> x; k++){
        d[k] = x;
    }
    BiNode * head;
    head = new BiNode();
    CreateTree(&d[0], k, head);
    PlusTree(head);
    FrequenPlus(k);
    return 0;
}

