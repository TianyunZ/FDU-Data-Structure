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
    void createALGraph(vector< vector<int> > a, int n, int e)
	{
		int i, j;
		ArcNode<T>* p;
		G = new ALGraph<T>();
		G->n = n;
		G->e = e;
		//cout << '#';
		for (i = 0; i < G->n; i++)
			G->adjlist[i].firstarc = NULL;//����ͷ�ڵ���ָ�����ֵ
		for (int k = 0; k < a.size(); k++)
		{
		    //cout << '*';
		    i = a[k][1];
            p = new ArcNode<T>();
            p->adjvex = a[k][0];
            p->weight = 1;
            p->nextarc = G->adjlist[i].firstarc;
            G->adjlist[i].firstarc = p;
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
		Visited[v] ++;
		p = G->adjlist[v].firstarc;
		while (p)
		{
			w = p->adjvex;
			if (Visited[w] == 0)
                DFS1(G, w, Visited);
			p = p->nextarc;
		}
	}
	friend int Circle(GraphClass<T>& Gp);
};
template <typename T> int Circle(GraphClass<T>& Gp){
    int v = 1;
    int * Visited = new int[Gp.G->n];
    for(int i = 0; i < Gp.G->n; i++)
        Visited[i] = 0;
    Gp.DFS1(Gp.G, 0, Visited);
    for(int i = 0; i < Gp.G->n; i++){
        if(Visited[i]>1)
            return 0;
    }
    for(int i = 0; i < Gp.G->n; i++)
        Visited[i] = 0;
    for(;v < Gp.G->n; v++){
        Gp.DFS1(Gp.G, v, Visited);
        for(int i = 0; i < Gp.G->n; i++){
            if(Visited[i]>1)
                return 0;
        }
        for(int i = 0; i < Gp.G->n; i++)
            Visited[i] = 0;
    }
    return 1;
}
istream& read_num(istream &in, vector<string>& num)
{
	//��ȡ�ļ���һ��vector
	if (in)
	{
		string x;
		while (in >> x){
            //cout << '*';
            num.push_back(x);
		}
	}
	return in;
}
int main()
{
    vector<string> num;
    freopen("13-2data.in.txt", "r", stdin);
    freopen("13-2output.o.txt", "w", stdout);
	read_num(cin, num);
    /*for(int i = 0; i < num.size(); i ++){
        for(int j = 0; j < num[i].size(); j++)
            cout << num[i][j];
    }
    cout << ' ' << endl;*/
    for(int i = 0; i < num.size(); i++){
        //cout << '!';
        GraphClass<int> Gp;
        int n = num[i][0] - '0';
        //cout << n << endl;
        int e = 0;
        vector< vector<int> > vs;
        for(int j = 3; j < num[i].size(); j++){
            //cout << '!';
            if(num[i][j] == '['){
                e ++;
                int k = j+1;
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
        /*for(int x = 0; x < vs.size(); x ++){
            for(int y = 0; y < vs[x].size(); y++)
                cout << vs[x][y] << ' ';
        }
        cout << ' ' << endl;*/
        Gp.createALGraph(vs, n, e);
        if(Circle<int>(Gp) == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
