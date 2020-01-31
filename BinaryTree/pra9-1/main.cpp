#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define N 20
//¹¹Ôì¶þ²æÊ÷
//µÝ¹é
using namespace std;

typedef struct BinNode{
    int data;
    BinNode * lchild;
    BinNode * rchild;
};
BinNode * root;
void CreateTree(BinNode * &t, int sfron[], int smid[], int size){
    BinNode * p;
    p = new BinNode();
    p->data = sfron[0];
    p->lchild = NULL;
    p->rchild = NULL;
    t = p;
    int i = 0;
    while(smid[i] != t->data){
        i++;
    }
    if (size == 1){
        return;
    }

    if(i != 0)
        CreateTree(t->lchild, &sfron[1], &smid[0], i);

    if(i+1 < size)
        CreateTree(t->rchild, &sfron[i+1], &smid[i+1], size-1-i);
}

void PrintTree(BinNode * t){
    if(t != NULL){
        PrintTree(t->lchild);
        PrintTree(t->rchild);
        cout << t->data << ' ';
    }
}

int main()
{
    cout << "Please input the length and two string of numbers:" << endl;
    int k;
    cin >> k;
    int sfron[k], smid[k];
    for(int i = 0; i <k ;i ++){
        cin >> sfron[i];
    }
    for (int i = 0; i < k ;i ++){
        cin >> smid[i];
    }
    CreateTree(root, &sfron[0], &smid[0], k);
    PrintTree(root);
    //cout << root->data;
    return 0;
}
/*
11
4 0 1 3 2 5 7 6 8 10 9
0 1 2 3 4 5 6 7 8 9 10
*/
