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
    int u;//边的起始
    int v;//边的终止
    T w;//权值
};
struct TreeNode{
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):data(x), left(NULL), right(NULL){}
};
struct VertexType//顶点类型
{
    int no;//顶点编号
    char data[MAXN];//顶点的其他信息
};
template<typename T>
struct MGragh//邻接矩阵类型
{
    T edges[MAXV][MAXV];//邻接矩阵的边数组
    int n, e;//顶点数n边数e
    VertexType vexs[MAXV];//存放定点信息
};
template<typename T>
struct ArcNode//边类结点
{
    int adjvex;//该边终点编号
    ArcNode * nextarc;//指向下一个边结点的指针
    T weight;//边权
};
template<typename T>
struct VNode//表头节点类型
{
    char data[MAXN];//表头节点信息
    ArcNode<T> * firstarc;//指向第一个边类结点的指针
};
template<typename T>
struct ALGraph//邻接表类型
{
    VNode<T> adjlist[MAXV];//邻接表数组
    int n, e;//图中顶点数n和边数e
};
template<typename T>
struct GraphClass//图的类型表
{
public:
    MGragh<T> g;//图的邻接矩阵
    ALGraph<T> * G;//图的邻接表
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
	}//通过边数组a，顶点数，边数建立图的邻接矩阵
    void createALGraph(vector< vector<int> > a, int n, int e)
	{
		int i, j;
		ArcNode<T>* p;
		G = new ALGraph<T>();
		G->n = n;
		G->e = e;
		//cout << '#';
		for (i = 0; i < G->n; i++)
			G->adjlist[i].firstarc = NULL;//所有头节点域指针设初值
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
	}//建立邻接表
	/*void DFS(int v)//深度优先生成树
	{
		int* Visited = new int[G->n];//辅助数组
		for (int i = 0; i < G->n; i++)
			Visited[i] = 0;  //辅助数组初始化
		DFS1(G, v, Visited);//递归的新方式！
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
	//读取文件入一个vector
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
