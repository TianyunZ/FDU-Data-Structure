#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>

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
    int i = 1;
    t->data = a[0];
    t->lchild = t->rchild = NULL;
    q.push(t);
    while(t!=NULL || !q.empty()){
        if(i == k)
            break;
        t = q.front();
        q.pop();
        if(a[i] != -1){
            p = new BiNode();
            p->data = a[i];
            p->lchild = p->rchild = NULL;
            t->lchild = p;
            q.push(p);
            //cout << i << ' ';
        }
        i++;
        if(i == k)
            break;
        if(a[i] != -1){
            p = new BiNode();
            p->data = a[i];
            p->lchild = p->rchild = NULL;
            t->rchild = p;
            q.push(p);
            //cout << i << ' ';
        }
        i++;
    }
}
int m = 20;
//寻找最小最对差(固定一个点）
int MinDiffer(BiNode * t){
    int k1, k2, k;
    BiNode * p;
    k1 = k2 = 20;
    p = t;
    stack<BiNode * > s;
    s.push(t);
    //int i = 0;
    while(t!=NULL && !s.empty()){
        t = s.top();
        s.pop();
        if(t->rchild!=NULL)
            s.push(t->rchild);
        if(t->lchild!=NULL)
            s.push(t->lchild);
        if(t->lchild!=NULL){
            p = t->lchild;
            while(p->rchild!=NULL){
                p = p->rchild;
            }
            k1 = t->data - p->data;
        }
        if(t->rchild!=NULL){
            p = t->rchild;
            while(p->lchild!=NULL){
                p = p->lchild;
            }
            k2 = p->data - t->data;
        }
        //cout << i << endl;
        //i++;
        if(k2 > k1)
            k = k1;
        else
            k = k2;
        //cout << k << endl;
        if(k < m)
            m = k;
    }
}

void PreOrder(BiNode* t){
    if(t==NULL){
        return;
    }
    cout << t->data << endl;
    PreOrder(t->lchild);
    PreOrder(t->rchild);

}

int main()
{
    //cout << "please input the size and a string of int:" << endl;
    freopen("input_12_1.txt", "r", stdin);
    freopen("output_12_1.txt", "w", stdout);
    int i = 0;
    int x;
    int a[20];
    for(; cin >> x; i++){
        a[i] = x;
    }
    BiNode * head;
    head = new BiNode();
    CreateTree(&a[0], i, head);
    //PreOrder(head);
    MinDiffer(head);
    cout << m << endl;
    return 0;
}
