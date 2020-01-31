//ตÝน้
#include <iostream>
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
//BinNode *r;
/*void LinkTree(BinNode * t){
    if(t!= NULL){
        if(t->lchild == NULL){
            t->lchild = r;
        }
        LinkTree(t->lchild);
        if(t->rchild != NULL){
            r = t->rchild;
            t->rchild = NULL;
        }
        LinkTree(t->rchild);
    }
}*/

void createInThread (BinNode * t, BinNode *& pre ) {
    if ( t == NULL )
        return;
	if ( t->lchild == NULL ) {
           t->lchild = pre;
           if(pre!=NULL)
                t->ltag = 1;
    }
    if ( pre != NULL && pre->rchild == NULL ) {
           pre->rchild = t;
           pre->rtag = 1;
    }
    pre = t;
    if (t->ltag == 0)
        createInThread ( t->lchild,  pre );
    if (t->rtag == 0)
        createInThread ( t->rchild,  pre );
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
