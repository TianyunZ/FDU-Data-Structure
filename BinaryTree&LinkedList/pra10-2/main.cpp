//·ÇµÝ¹é
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct BinNode{
    int data;
    BinNode * lchild;
    BinNode * rchild;
    int ltag = 0;
    int rtag = 0;
};

void CreateTree(BinNode * &root, int a[], int size){
    queue<BinNode *> q;
    BinNode * p, * t;
    int i = 0;
    root = new BinNode();
    t = root;
    t->data = a[i++];
    t->lchild = t->rchild = NULL;
    q.push(t);
    while(!q.empty()&&i<size){
        int num = q.size();
        for(int j = 0; j<num; j++){
            t = q.front();
            q.pop();
            if(a[i]!=-1&&i<size){
                p = new BinNode();
                p->data = a[i];
                p->lchild = p->rchild = NULL;
                t->lchild = p;
                q.push(p);
                i++;
            }
            else
                i++;
            if(a[i]!=-1&&i<size){
                p = new BinNode();
                p->data = a[i];
                p->lchild = p->rchild = NULL;
                t->rchild = p;
                q.push(p);
                i++;
            }
            else
                i++;
        }
    }
}

void PrintTree(BinNode * t){
    if(t!= NULL){
        cout << t->data << ' ';
        PrintTree(t->lchild);
        PrintTree(t->rchild);
    }
}



void createInThread (BinNode * t, BinNode *& pre ) {
    stack<BinNode *> s;
    queue<BinNode *> q;
    BinNode * p;
    if ( t == NULL )
        return;
    s.push(t);
    while(!s.empty()){
        p = s.top();
        q.push(p);
        s.pop();
        if( p->rchild!= NULL){
            s.push(p->lchild);
        }
        if( p->lchild != NULL){
            s.push(p->lchild);
        }
    }
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p->rchild == NULL){
            p->rchild = q.front();
            if(q.front()!= NULL)
                p->ltag = 1;
        }
    }
}

void PrintLink(BinNode * t){
    while(t!=NULL){
        cout << t->data << ' ';
        if (t->ltag == 0)
            t = t->lchild;
        else
            t = t->rchild;
    }
}

int main()
{
    cout << "please input a string of numbers:" << endl;
    BinNode * root;
    vector<int> a;
    int size;
    int x;
    while(cin >> x){
        a.push_back(x);
    }
    size = a.size();
    int b[size];
    for(int i = 0; i<size;  i ++){
        b[i] = a[i];
    }
    CreateTree(root, &b[0], size);
    //PrintTree(root);
    BinNode *pre = NULL;
    if ( root != NULL ) {
        createInThread ( root, pre );
        pre->rchild = NULL;
    }
    PrintLink(root);
    return 0;
}
