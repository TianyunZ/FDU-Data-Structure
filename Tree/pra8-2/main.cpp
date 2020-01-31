#include <iostream>
#include <malloc.h>
#include <stack>
//��tag��ǵڼ������ӣ������ŵ�ջ�����õݹ�ʵ��
#define MaxSize 3

using namespace std;

struct BinNode{
    char data;
    int tag;
    BinNode * child[MaxSize];
    BinNode * parent;
};

int m = 0, k = 0;
BinNode * t;
stack<char> s;

void FindPath(BinNode * x){
    if(m < k){
        m = k;
        t = x;
    }
    for(int i = 0; i < MaxSize; i ++){
        if(x->child[i] != NULL){
            k++;
            FindPath(x->child[i]);
            k--;
        }
    }
}

void PrintPath(BinNode * x){
    while(x!=NULL){
        s.push(x->data);
        x = x->parent;
    }
    while(!s.empty()){
        cout << s.top() << "->";
        s.pop();
    }
}

void CreateBinTree(istream &in, BinNode * &BT){
    BinNode *P = NULL;
    stack<BinNode *> St;
    char ch;
    //��ʼ���Ķ�����Ϊ��
    BT = NULL;
    while(in >> ch && ch != '#'){
        //cout << ch;
        switch (ch){
            //��Ϊ����
            case '(':
                St.push(P);
                //cout << St.top()->data;
                P->tag = 1;
                break;
            case ')':
                St.pop();
                break;
                //��Ϊ�ҽ��
            case ',':
                St.top()->tag ++;
                break;
            default:
                P = (BinNode *)malloc(sizeof(BinNode));
                P->data = ch;
                for(int i = 0; i < MaxSize; i ++){
                    P->child[i] = NULL;
                }
                //cout << P->data;
                if (BT == NULL){
                    // pָ��������ĸ����
                    BT = P;
                }
                else{
                    switch(St.top()->tag){
                        case 1:
                            St.top()->child[0] = P;
                            //cout << '!';
                            break;
                        case 2:
                            St.top()->child[1] = P;
                            break;
                        case 3:
                            St.top()->child[2] = P;
                            break;
                    }
                }
        }
    }
}

void AddParent(BinNode * x){
    for(int i = 0; i < MaxSize; i ++){
        if(x->child[i] != NULL){
            x->child[i]->parent = x;
            AddParent(x->child[i]);
        }
    }
}

int main()
{
    BinNode * a;
    CreateBinTree(cin, a);
    AddParent(a);
    a->parent = NULL;
    FindPath(a);
    cout << t->data << endl;
    PrintPath(t);
    return 0;
}
