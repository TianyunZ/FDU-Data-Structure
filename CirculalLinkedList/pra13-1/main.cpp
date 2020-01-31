#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
#define MAXN 30
#define MAXV 20
using namespace std;

template<typename T>
struct Edge{
    int u;//�ߵ���ʼ
    int v;//�ߵ���ֹ
    T w;//Ȩֵ
};
struct TreeNode{
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):data(x), left(NULL), right(NULL){}
};
struct VertexType//��������
{
    int no;//������
    char data[MAXN];//�����������Ϣ
};
template<typename T>
struct MGragh//�ڽӾ�������
{
    T edges[MAXV][MAXV];//�ڽӾ���ı�����
    int n, e;//������n����e
    VertexType vexs[MAXV];//��Ŷ�����Ϣ
};
template<typename T>
struct ArcNode//������
{
    int adjvex;//�ñ��յ���
    ArcNode * nextarc;//ָ����һ���߽���ָ��
    T weight;//��Ȩ
};
template<typename T>
struct VNode//��ͷ�ڵ�����
{
    char data[MAXN];//��ͷ�ڵ���Ϣ
    ArcNode<T> * firstarc;//ָ���һ���������ָ��
};
template<typename T>
struct ALGraph//�ڽӱ�����
{
    VNode<T> adjlist[MAXV];//�ڽӱ�����
    int n, e;//ͼ�ж�����n�ͱ���e
};
template<typename T>
struct GraphClass//ͼ�����ͱ�
{
public:
    MGragh<T> g;//ͼ���ڽӾ���
    ALGraph<T> * G;//ͼ���ڽӱ�
    GraphClass(){G = NULL;}
    ~GraphClass(){}
    void CreateMGraph(vector<vector<int> >a, int n, int e)
	{
		int i, j;
		g.n = n;
		g.e = e;
		for (int i = 0; i < g.n; i++)
			for (int j = 0; j < g.n; j++)
				g.edges[i][j] = a[i][j];
	}//ͨ��������a������������������ͼ���ڽӾ���
    void createALGraph(vector<vector<int> > a, int n, int e)
	{
		int i, j;
		ArcNode<T>* p;
		G = new ALGraph<T>();
		G->n = n; G->e = e;
		for (i = 0; i < G->n; i++)
			G->adjlist[i].firstarc = NULL;//����ͷ�ڵ���ָ�����ֵ
		for (i = 0; i < G->n; i++)
		{
			for (j = G->n - 1; j >= 0; j--)
			{
				if (a[i][j] != 0 && a[i][j] != 9999)
				{
					p = new ArcNode<T>();
					p->adjvex = j;
					p->weight = a[i][j];
					p->nextarc = G->adjlist[i].firstarc;
					G->adjlist[i].firstarc = p;
				}
			}
		}
	}//�����ڽӱ�
	/*void DFS(int v)//�������������
	{
		int* Visited = new int[G->n];//��������
		for (int i = 0; i < G->n; i++)
			Visited[i] = 0;  //���������ʼ��
		DFS1(G, v, Visited);//�ݹ���·�ʽ��
	}*/

	void DFS1(ALGraph<T>*G, int v, int Visited[])
	{
		int w;
		ArcNode<T> * p;
		Visited[v] = 1;
		//cout << v << " ";
		p = G->adjlist[v].firstarc;
		while (p)
		{
			w = p->adjvex;
			if (Visited[w] == 0)
                DFS1(G, w, Visited);
			p = p->nextarc;
		}
	}
	friend int Connect(GraphClass<T>& Gp);
};
template<typename T> int Connect(GraphClass<T> & Gp){
    int sum = 1;
    int v = 0;
    int* Visited = new int[Gp.G->n];//��������
    for(int i = 0; i < Gp.G->n; i++)
        Visited[i] = 0;
    Gp.DFS1(Gp.G, v, Visited);
    while(v < Gp.G->n){
        if(Visited[v] != 0)
            v ++;
        else{
            Gp.DFS1(Gp.G, v, Visited);
            sum ++;
        }
    }
    return sum;
}
istream& read_num(istream &in, vector<string>& num)
{
	//��ȡ�ļ���һ��vector
	if (in)
	{
		string x;
		while (in >> x) num.push_back(x);
	}
	return in;
}

int main()
{
    vector<string> num;
	freopen("data.in.txt", "r", stdin);
    freopen("output.o.txt", "w", stdout);
	read_num(cin, num);
	for(int i = 0; i < num.size(); i++){
        GraphClass<int> Gp;
        vector<vector<int> > vs;
        int n = 0;
        for(int j = 1; j < num[i].size(); j++){
            if(num[i][j] == '['){
                n ++;
            }
        }
        for(int j = 1; j < num[i].size(); j++){
            if(num[i][j] == '['){
                int k = j + 1;
                vector<int> temp;
                while(num[i][k] != ']'){
                    if(num[i][k] != ','){
                        temp.push_back(num[i][k] - '0');
                    }
                    k ++;
                }
                vs.push_back(temp);
                temp.clear();
            }
        }
        int e = 0;
        for (int t = 0; t < vs.size(); t++){
			for (int j = t; j < vs.size(); j++){
				if (vs[t][j] == 1){
					e++;
				}
			}
		}
		Gp.createALGraph(vs, n, e);
		cout << Connect<int>(Gp) << endl;
	}
    return 0;
}
