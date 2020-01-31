#include <iostream>
#include <fstream>
#define MAX_SIZE 100000
#define Max 1000
using namespace std;
#include <string>
#include <stack>
#include <iterator>
#include <queue>
template <typename T>
struct BTNode
{
	T data;
	BTNode*lchild;
	BTNode*rchild;
	BTNode(T val) {
		data = val;
		lchild = NULL;
		rchild = NULL;
	}
	BTNode() {}
};
template <typename T>
class BTNodeClass
{
public:
	/*template <typename T>
	friend void sort(vector<BTNode<T>*> v);
	template <typename T>
	friend BTNode<T>* HFM(vector<T> v, int n);
	template <typename T>
	friend vector<int> sumslice(BTNode<T>* t);
	template <typename T>
	friend void ConstructTree(T a[], int n, int i, BTNode<T>* t);
	template <typename T>
	friend bool isFullBT(BTNode<T>* t);
	template <typename T>
	friend void swapchild(BTNode<T>* bt);

	BTNodeClass() { r = NULL; }
	~BTNodeClass() { DestroyBTree(r); }

	*/
	BTNode<T>*r;
	void CreateBTNode(char *str)//���ַ�������Ϊ�β������й���
	{

		//BTNode<T> *st[MAXSIZE];//����˳��ջ�ķ�ʽ
		stack<BTNode<T>*> st;
		BTNode<T> *p;
		int k = 0, j = 0;
		char c;
		st.push(NULL);
		while (str[j] != '\0')
		{
			c = str[j];
			switch (c)
			{
			case'('://�½��ڵ��к���
					//top++;
					//st[top] = p;
				st.push(p);
				k = 1;
				break;
			case')':
				//top--;
				st.pop();
				break;
			case',':
				k = 2; break;
			default:
				p = new BTNode<T>();//�½�һ���ڵ�
				p->lchild = p->rchild = NULL;
				p->data = c;
				if (r == NULL)
				{
					r = p;
				}
				else
				{
					switch (k)//k��Ϊ���Һ��ӽڵ�ı�ʶ
					{
						//case 1: st[top]->lchild = p; break;

					case 1:
						if (st.top() != NULL)
							st.top()->lchild = p; break;
						//case 2:st[top]->rchild = p; break;
					case 2:if (st.top() != NULL)
						st.top()->rchild = p; break;
					}
				}
				break;
			}
			j++;//����ɨ�������ַ�
		}

	}
	void DispBTNode()//������нڵ�
	{
		DispBTNode1(r);
	}
	BTNode<T>*FindNode(T x)//����ֵΪx�Ľ��
	{
		return FindNode1(r, x);
	}
	int BTNodeHeight()//��������߶ȵ��㷨
	{
		return BTNodeHeight1(r);
	}
	/*template<typename T>
	friend void PreOrder(BTNodeClass<T> &bt);
	template <typename T>
	friend void PreOrder1(BTNode<T>*t);
	template <typename T>
	friend int sum(BTNodeClass<T> &bt);
	template <typename T>
	friend void longestpath(BTNode<T> *bt);
	template <typename T>
	friend int BTNodeHeight1(BTNode<T>*t);
	template <typename T>*/
	friend void Create(T a[], int n, BTNodeClass<T> &bt);
private:
	void DestroyBTree(BTNode<T>*r)
	{
		if (r != NULL)
		{
			DestroyBTree(r->lchild);
			DestroyBTree(r->rchild);
			delete r;
		}
	}
	void DispBTNode1(BTNode<T>*t)//���õݹ�ķ���
	{
		if (t != NULL)
		{
			if (t->lchild == NULL&&t->rchild == NULL)
				cout << t->data;
			if (t->lchild != NULL || t->rchild != NULL)
			{
				cout << t->data;
				cout << "(";
				DispBTNode1(t->lchild);//�ݹ����������
				if (t->rchild != NULL)
					cout << ",";
				DispBTNode1(t->rchild);
				cout << ")";
			}
		}
	}
	BTNode<T>*FindNode1(BTNode<T>*t, T x)
	{
		BTNode<T>*p;
		if (t == NULL)
			return NULL;
		else if (t->data == x)
		{
			return t;
		}
		else
		{
			p = FindNode1(t->lchild, x);
			if (p != NULL)
				return p;
			else
				return FindNode1(t->rchild, x);
		}
	}


};
//�ڶ����㷨
template <typename T>
void sort(vector<BTNode<T>*> &v)
{
	BTNode<T> *temp;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{

			if (v[j]->data <v[i]->data)
			{
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}
template <typename T>
BTNode<T>* HFM(vector<T> v, int n)//nΪ���ݴ�С
{
	int m = 2 * n - 1;
	sort(v.begin(), v.end());//������
	vector<BTNode<T>*> vs;//�洢����������㣬������ֻ��һ���ڵ����洢��ϣ����ؼ���
	for (int i = 0; i < n; i++)
	{
		BTNode<T> *node = new BTNode<T>(v[i]);
		vs.push_back(node);
	}
	/*for (int i = n; i < m; i++)
	{
		BTNode<T> *node = new BTNode<T>();
		node->lchild = NULL;
		node->rchild = NULL;
		vs.push_back(node);
	}*/
	//���ϳ�ʼ��
	if (vs.size() == n)//����ʼ
	{
		T tp;
		tp = vs[0]->data + vs[1]->data;
		BTNode<T>* rt = new BTNode<T>(tp);
		rt->lchild = vs[0];
		rt->rchild = vs[1];
		BTNode<T>* k = vs.begin();
		vs.erase(k);
		BTNode<T>* m = vs.begin();
		vs.erase(m);
		vs.push_back(rt);
	}
	while (vs.size() > 1)
		{
			sort(vs);
			T tp;
			tp = vs[0]->data + vs[1]->data;
			BTNode<T>* rt = new BTNode<T>(tp);
			rt->lchild = vs[0];
			rt->rchild = vs[1];
			BTNode<T>* k = vs.begin();
			vs.erase(k);
			BTNode<T>* m = vs.begin();
			vs.erase(m);
			vs.push_back(rt);
		}
		return vs[0];

}


/*#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct BinNode{
    int data;
    BinNode * lchild;
    BinNode * rchild;
};

int HuffmanTree(BinNode * &t, int h[], int size){
    sort(h, h+size);
    queue<int> q;
    int a, b;
    int weight = 0;
    int j = 0;
    for(int i = 0; i < size; i++){
        q.push(h[i]);
    }
    while(q.size() > 1){
        a = q.front();
        q.pop();
        b = q.front();
        q.pop();
        weight = weight + a + b;
        q.push(a+b);
        j++;
        for(int i = 0; i < size-j; i++){
            h[i] = q.front();
            q.pop();
        }
        sort(h, h+size-j);
        for(int i = 0; i < size-j; i++){
            q.push(h[i]);
        }
    }
    return weight;
}

int main()
{
    cout << "Hello world!" << endl;
    int k;
    cin >> k;
    int a[k];
    for(int j = 0; j < k; j++){
        cin >> a[j];
    }
    BinNode * root;
    cout << HuffmanTree(root, &a[0], k);
    return 0;
}*/
