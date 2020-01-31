#include <iostream>
#include <queue>

using namespace std;

typedef struct BinNode{
    int data;
    BinNode * lchild;
    BinNode * rchild;
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
                //cout << p->data;
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
int temp;

void FindData(BinNode * t, int x, int y){
    if(t != NULL){
        if(t->data == x || t->data == y){
            temp++;
        }
        FindData(t->lchild, x, y);
        FindData(t->rchild, x, y);
    }
}

int k;
void  MinParent(BinNode * t, int x, int y){
    if(t->data == x || t->data == y){
        k = t->data;
    }
    temp = 0;
    FindData(t->lchild, x, y);
    if(temp == 1){
        k = t->data;
    }
    if(temp == 2){
        MinParent(t->lchild, x, y);
    }
    if (temp == 0){
        MinParent(t->rchild, x, y);
    }
}

void PrintTree(BinNode * t){
    if(t!= NULL){
        cout << t->data << ' ';
        PrintTree(t->lchild);
        PrintTree(t->rchild);
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
    int b[size-2];
    for(int i = 0; i<size-2; i ++){
        b[i] = a[i];
    }
    CreateTree(root, &b[0], size-2);
    //PrintTree(root);
    MinParent(root, a[size-2], a[size-1]);
    cout << k;
    return 0;
}
//3 5 1 6 2 0 8 -1 -1 7 4 6 4
