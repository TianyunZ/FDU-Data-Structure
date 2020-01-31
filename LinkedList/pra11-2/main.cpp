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
	void CreateBTNode(char *str)//用字符数组作为形参来进行构造
	{

		//BTNode<T> *st[MAXSIZE];//采用顺序栈的方式
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
			case'('://新建节点有孩子
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
				p = new BTNode<T>();//新建一个节点
				p->lchild = p->rchild = NULL;
				p->data = c;
				if (r == NULL)
				{
					r = p;
				}
				else
				{
					switch (k)//k作为左右孩子节点的标识
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
			j++;//继续扫描其他字符
		}

	}
	void DispBTNode()//输出所有节点
	{
		DispBTNode1(r);
	}
	BTNode<T>*FindNode(T x)//查找值为x的结点
	{
		return FindNode1(r, x);
	}
	int BTNodeHeight()//求二叉树高度的算法
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
	void DispBTNode1(BTNode<T>*t)//采用递归的方法
	{
		if (t != NULL)
		{
			if (t->lchild == NULL&&t->rchild == NULL)
				cout << t->data;
			if (t->lchild != NULL || t->rchild != NULL)
			{
				cout << t->data;
				cout << "(";
				DispBTNode1(t->lchild);//递归输出左子树
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
//第二题算法
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
BTNode<T>* HFM(vector<T> v, int n)//n为数据大小
{
	int m = 2 * n - 1;
	sort(v.begin(), v.end());//先排序
	vector<BTNode<T>*> vs;//存储哈夫曼树结点，当其中只有一个节点代表存储完毕，返回即可
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
	//以上初始化
	if (vs.size() == n)//情况最开始
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
