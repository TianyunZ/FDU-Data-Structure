#include <iostream>
#include <queue>
#include <string>
#include <sstream>
//二叉树每层的均值
using namespace std;

typedef struct BinNode{
    int data;
    BinNode * lchild;
    BinNode * rchild;
};

BinNode * root;

void Average(){
    vector<double> v;
    queue<BinNode *> q;
    q.push(root);
    while(!q.empty()){
        int num = q.size();
        long temp = 0;
        for (int i = 0; i < num; i++){
            BinNode* top = q.front();
            q.pop();
            if (top->lchild != NULL)
                q.push(top->lchild);
            if (top->rchild != NULL)
                q.push(top->rchild);
            temp += top->data;
        }
        v.push_back((double)temp / num);
    }
    for (int i=0; i < v.size(); i ++){
        cout << v[i] << ' ';
    }
}

void CreateTree(string a[], int size){
    queue<BinNode *> q;
    BinNode * t, * p;
    t = root;
    int k;
    stringstream ss;
    int i = 1;
    root = new BinNode;
    ss << a[0];
    ss >> root->data;
    ss.clear();
    root->lchild = root->rchild = NULL;
    q.push(root);

    while(!q.empty() && i<size){
        int num = q.size();
        for (int j = 0; j < num; j++){
            BinNode* top = q.front();
            q.pop();
            if (a[i] != "null"){
                p = new BinNode();
                p->lchild = NULL;
                p->rchild = NULL;
                ss << a[i];
                ss >> p->data;
                ss.clear();
                top->lchild = p;
                q.push(p);
                i++;
            }
            else{
                top->lchild = NULL;
                i ++;
            }
            if (a[i] != "null"){
                p = new BinNode;
                p->lchild = NULL;
                p->rchild = NULL;
                ss << a[i];
                ss >> p->data;
                ss.clear();
                top->rchild = p;
                q.push(p);
                i++;
            }
            else{
                top->rchild = NULL;
                i++;
            }
        }
    }
}

int main()
{
    cout << "Please input a string of numbers:" << endl;
    string t;
    string a[20];
    int i = 0;
    while(cin >> t){
        a[i] = t;
        i ++;
    }
    CreateTree(&a[0], i);
    Average();
    return 0;
}
