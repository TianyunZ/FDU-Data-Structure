#include <iostream>
#include <malloc.h>
#include <stack>
#define MaxSize 20
using namespace std;

struct BinNode{
    int data;
    BinNode * lchild;
    BinNode * rchild;
};
BinNode * a;

void printtree(BinNode * b){
    cout << b->data;
    if(b->lchild != NULL){
        printtree(b->lchild);
    }
    if(b->rchild != NULL){
        printtree(b->rchild);
    }
}

void CreateBinTree(istream &in, BinNode * &BT){
    BinNode *P = NULL;
    stack<BinNode *> St;
    int k,j = 0;
    char ch;
    //初始化的二叉链为空
    BT = NULL;
    while(in >> ch && ch != '#'){
        //cout << ch;
        switch (ch){
            //作为左结点
            case '(':
                St.push(P);
                //cout << St.top()->data;
                k = 1;
                break;
            case ')':
                St.pop();
                break;
                //作为右结点
            case ',':
                k = 2;
                break;
            default:
                P = (BinNode *)malloc(sizeof(BinNode));
                P->data = ch-'0';
                P->lchild = P->rchild = NULL;
                //cout << P->data;
                if (BT == NULL){
                    // p指向二叉树的根结点
                    BT = P;
                }
                else{
                    switch(k){
                        case 1:
                            if(ch != ' '){
                                St.top()->lchild = P;
                                //cout << '!';
                            }
                            break;
                        case 2:
                            if(ch != ' ')
                                St.top()->rchild = P;
                            break;
                    }
                }
        }
    }
}

int q = 0,t;

void NodeSum(BinNode * b){
    if(b->lchild == NULL && b->rchild == NULL && t == 1){
        cout << b->data << endl;
        q = q + b->data;
    }
    if(b->lchild != NULL){
        t = 1;
        NodeSum(b->lchild);
    }
    if(b->rchild != NULL){
        t = 2;
        NodeSum(b->rchild);
    }
}

int main()
{
    //a = (BinNode *)malloc(sizeof(BinNode));
    CreateBinTree(cin, a);
    printtree(a);
    cout << ' ' << endl;
    NodeSum(a);
    cout << q << endl;
    return 0;
}
