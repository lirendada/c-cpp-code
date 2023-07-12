#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <functional>
#include <queue>
using namespace std;

// 邻接矩阵
namespace matrix
{
	// V代表的是顶点的元素类型
	// W代表的是边的权值类型
	// MAX_W是边的权值，以INT_MAX代表无穷大
	// Direction代表的true为有向图，false为无向图
	template <class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
		typedef Graph<V, W, MAX_W, Direction> Self;
	public:
		// 图的创建
		// 1、IO输入 -- 不方便测试，更适合oj
		// 2、图结构关系写到文件，读取文件
		// 3、手动添加边，方便调试，这里选用这种方式
		Graph(const V* a, size_t n)
		{
			// 初始化顶点集合和顶点映射的下标
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(a[i]);
				_vIndexMap[a[i]] = i;
			}

			// 初始化矩阵
			_matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
				_matrix[i].resize(n, MAX_W);
		}

		// 下面函数的子函数，这个接收的参数是下标，这是为了给下面的算法用的
		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{
			_matrix[srci][dsti] = w;
			// 判断是否为无向图，是的话矩阵要对称赋值
			if (Direction == false)
			{
				_matrix[dsti][srci] = w;
			}
		}

		// 链接边的函数，接收的参数是顶点
		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_AddEdge(srci, dsti, w);
		}

		// 查找顶点映射的下标
		size_t GetVertexIndex(const V& v)
		{
			// 为了防止顶点不存在的情况，这里我们使用map的find函数
			auto it = _vIndexMap.find(v);
			if (it == _vIndexMap.end())
			{
				throw invalid_argument("顶点不存在");
				return -1;
			}
			else
			{
				return it->second;
			}
		}

		// 广度优先遍历
		void BFS()
		{
			// visited数组标记是否访问过节点
			vector<bool> visited;
			visited.resize(_vertexs.size(), false);
			queue<int> qe;

			size_t n = _vertexs.size();
			for(size_t i = 0; i < n; ++i)
			{
				if (visited[i] == false)
				{
					qe.push(i);
					visited[i] = true;
					while (!qe.empty())
					{
						int front = qe.front();
						qe.pop();
						cout << front << ":[" << _vertexs[front] << ']' << endl;

						// 遍历该顶点矩阵中的出边，将它们入队，并标记一下表示出现过
						for (size_t i = 0; i < n; ++i)
						{
							if (_matrix[front][i] != MAX_W && visited[i] == false)
							{
								qe.push(i);
								visited[i] = true;
							}
						}
					}
					cout << endl;
				}
			}
		}

		// 深度优先遍历
		void DFS()
		{
			vector<bool> visited(_vertexs.size(), false);

			// 遍历所有的顶点，判断是否都是true防止了遗漏一些不连通的子图
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (visited[i] == false)
				{
					// 交给子函数去递归解决
					_DFS(i, visited);
				}
			}
			cout << endl;
		}

		void _DFS(size_t srci, vector<bool>& visited)
		{
			cout << srci << ":[" << _vertexs[srci] << ']' << endl;
			visited[srci] = true;
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (_matrix[srci][i] != MAX_W && visited[i] == false)
				{
					_DFS(i, visited);
				}
			}
		}

		// 为下面一些算法如Kruskal算法做准备的
		struct Edge
		{
			size_t _srci;
			size_t _dsti;
			W _weight;

			Edge(size_t srci, size_t dsti, const W& weight)
				:_srci(srci)
				, _dsti(dsti)
				, _weight(weight)
			{}

			// 下面要比较边的大小，所以要重载一下比较
			bool operator>(const Edge& e) const
			{
				return _weight > e._weight;
			}
		};

		Graph() = default;

		// Kruskal算法
		// minTree是接收的未初始化的图，所以我们要有默认的构造函数
		W Kruskal(Self& minTree)
		{
			// 初始化一下最小生成树的模板
			size_t n = _vertexs.size();
			minTree._vIndexMap = _vIndexMap;
			minTree._vertexs = _vertexs;
			minTree._matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				// 默认这些顶点都是不相通的
				minTree._matrix[i].resize(n, MAX_W);
			}

			// 由于我们要从小到大排序，所以得传仿函数过去
			priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
			
			// 将矩阵中的边入队列
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					// 由于是无向图，我们只需要将上三角行列式中的边加入即可
					if (i < j && _matrix[i][j] != MAX_W)
					{
						pq.push(Edge(i, j, _matrix[i][j]));
					}
				}
			}

			// 贪心算法，从最小的边开始选
			int size = 0;    // 选出n-1条边，所以用size来计数
			W sum = W();    // 最后结束的时候返回最小生成树的总权值
			UnionFindSet ufs(n);    // 并查集

			while (!pq.empty())
			{
				Edge min = pq.top();
				pq.pop();

				// 判断是否成环
				if (!ufs.IsInSameSet(min._srci, min._dsti))
				{
					cout << minTree._vertexs[min._srci] << "->" << minTree._vertexs[min._dsti] << ":" << min._weight << endl;
					
					// 将边加上去（注意这里调用的是_AddEdge，接收的参数是下标而不是顶点的版本）
					minTree._AddEdge(min._srci, min._dsti, min._weight);

					// 再将两个点算入并查集
					ufs.Union(min._srci, min._dsti);

					sum += min._weight;
					++size;
				}
				else
				{
					cout << "构成环： ";
					cout << minTree._vertexs[min._srci] << "->" << minTree._vertexs[min._dsti] << ":" << min._weight << endl;
				}
			}

			// 若成功生成最小生成树则返回sum，否则返回默认值
			if (size == n - 1)
				return sum;
			else
				return W();
		}

		// Prim算法
		// minTree是接收的未初始化的图，所以我们要有默认的构造函数
		// src是首个顶点
		W Prim(Self& minTree, const V& src)
		{
			size_t srci = GetVertexIndex(src);

			// 初始化图，与Kruskal算法一样
			size_t n = _vertexs.size();
			minTree._vertexs = _vertexs;
			minTree._vIndexMap = _vIndexMap;
			minTree._matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
				minTree._matrix[i].resize(n, MAX_W);

			// 使用vector来存储顶点的确认情况：是否在生成树中已经确认（默认是不确认）
			// true表示确认存在
			// false表示还不确认存在
			vector<bool> vState(n, false);
			vState[srci] = true;    // 注意将首个顶点设置为true

			// 初始化优先级队列（与Kruskal算法一样）
			// 先将与首个顶点邻接的边入队列
			priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
			for (size_t i = 0; i < n; ++i)
			{
				if (_matrix[srci][i] != MAX_W)
					pq.push(Edge(srci, i, _matrix[srci][i]));
			}

			size_t size = 0;
			W sum = W();
			cout << "Prim开始选边" << endl;
			while (!pq.empty())
			{
				Edge min = pq.top();
				pq.pop();

				// 判断一下是否成环
				// 若这条边的目标节点下标是已经确认的，说明是成环的，反之不成环
				if (vState[min._dsti] == true)
				{
					cout << "构成环：";
					cout << minTree._vertexs[min._srci] << "->" << minTree._vertexs[min._dsti] << ":" << min._weight << endl;
				}
				else
				{
					cout << minTree._vertexs[min._srci] << "->" << minTree._vertexs[min._dsti] << ":" << min._weight << endl;
					
				    // 将边添加到生成树中去	
					minTree._AddEdge(min._srci, min._dsti, min._weight);
					vState[min._dsti] = true;  // 将目的顶点设为确认
					sum += min._weight;
					size++;

					if (size == n - 1)
						break;

					// 将目的顶点的邻接边入队列，继续循环
					for (size_t i = 0; i < n; ++i)
					{
						if (_matrix[min._dsti][i] != MAX_W && vState[i] == false)
							pq.push(Edge(min._dsti, i, _matrix[min._dsti][i]));
					}
				}
			}

			// 若成功生成最小生成树则返回sum，否则返回默认值
			if (size == n - 1)
				return sum;
			else
				return W();
		}

		// 为了方便观察，要实现一个打印函数
		void Print()
		{
			// 顶点
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			// 矩阵
			// 横下标
			cout << "  ";
			for (int i = 0; i < _vertexs.size(); ++i)
			{
				//cout << i << " ";
				printf("%4d", i);
			}
			cout << endl;

			for (int i = 0; i < _matrix.size(); ++i)
			{
				cout << i << " "; // 竖下标
				for (int j = 0; j < _matrix[i].size(); ++j)
				{
					//cout << _matrix[i][j] << " ";
					if (_matrix[i][j] == MAX_W)
					{
						//cout << "* ";
						printf("%4c", '*');
					}
					else
					{
						//cout << _matrix[i][j] << " ";
						printf("%4d", _matrix[i][j]);
					}
				}
				cout << endl;
			}
			cout << endl;
		}

		// Dijkstra算法
		// 其中src代表单源节点
		// dist数组是存放src到每个节点的最短路径距离
		// pPath数组是存放每个节点的最短路径中的上一个节点下标
		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			// 一些初始化工作
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			dist[srci] = W(); // 将单源节点先设为0
			pPath.resize(n, -1);
			pPath[srci] = srci;

			// S中true表示该点已经确定
			vector<bool> S(n, false);

			// 这里采用直接遍历所有点，再在循环体中再来寻找最小值的方式
			// 因为如果是用优先级队列的话，不好调整
			for (size_t i = 0; i < n; ++i)
			{
				// 寻找每一遍中的最短边，得到
				size_t u = srci; // u是当前最小边的下标
				W min = MAX_W;
				for (size_t j = 0; j < n; ++j)
				{
					if (S[j] == false && dist[j] < min)
					{
						u = j;
						min = dist[j];
					}
				}
				S[u] = true; // 将当前得到的节点设置为已确定

				// 现在有了那个当前最短边的顶点的下标
				// 所以我们直接遍历这个点的邻接点
				// 并对这些邻接点进行松弛调整
				for (size_t k = 0; k < n; ++k)
				{
					// 1、若邻接点为确定的节点了，那么不需要调整
					// 2、若不相通也不需要调整
					// 3、若当前权值加上与邻接点的边的权值大于了原来邻接点的权值，那么也不需要调整
					if (S[k] == false
						&& _matrix[u][k] != MAX_W
						&& dist[u] + _matrix[u][k] < dist[k])
					{
						dist[k] = dist[u] + _matrix[u][k];
						pPath[k] = u; // 注意别忘了更新路径
					}
				}
			}
		}

		void PrintShortPath(const V& src, const vector<W>& dist, const vector<W>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();

			for (size_t i = 0; i < n; ++i)
			{
				if (srci != i)
				{
					vector<size_t> path;
					size_t parenti = i;
					while (parenti != srci)
					{
						path.push_back(parenti);
						parenti = pPath[parenti];
					}
					path.push_back(srci);

					// 先逆置一下，因为当前的访问顺序是从后到前的
					reverse(path.begin(), path.end());
					for (size_t j = 0; j < path.size(); ++j)
					{
						if (j < path.size() - 1)
							cout << _vertexs[path[j]] << "->";
						else
							cout << _vertexs[path[j]];
					}
					cout << "  权值为：" << dist[i] << endl;
				}
			}
		}

		//  BellmanFord算法（参数与Dijkstra是一样的）
		bool BellmanFord(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			// 一些初始化工作
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			dist[srci] = W();
			pPath.resize(n, -1);
			pPath[srci] = srci;

			// 为了防止改变其中一条路径时候影响到其他路径
			// 需要再次更新，总体最多更新n轮
			for (size_t i = 0; i < n; ++i)
			{
				bool flag = false;
				// 直接遍历判断是否需要松弛
				for (size_t j = 0; j < n; ++j)
				{
					for (size_t k = 0; k < n; ++k)
					{
						if (_matrix[j][k] != MAX_W && dist[j] + _matrix[j][k] < dist[k])
						{
							dist[k] = dist[j] + _matrix[j][k];
							pPath[k] = j;
							flag = true;
						}
					}
				}
				// 若没有更新路径，那么说明不会再有影响了，直接break
				if (flag == false)
					break;
			}

			// 判断一下是否有负权回路
			// 若还是有更新，说明有负权回路
			for (size_t j = 0; j < n; ++j)
			{
				for (size_t k = 0; k < n; ++k)
				{
					if (_matrix[j][k] != MAX_W && dist[j] + _matrix[j][k] < dist[k])
					{
						return false;
					}
				}
			}
			return true;
		}

		// Floyd-Warshall算法
		void Floyd(vector<vector<W>>& vvdist, vector<vector<W>>& vvpPath)
		{
			// 初始化
			size_t n = _vertexs.size();
			vvdist.resize(n);
			vvpPath.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				vvdist[i].resize(n, MAX_W);
				vvpPath[i].resize(n, -1);
			}

			// 将直接相连的路径初始化
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					if (_matrix[i][j] != MAX_W)
					{
						vvdist[i][j] = _matrix[i][j];
						vvpPath[i][j] = i;
					}

					if (i == j)
					{
						vvdist[i][j] = 0;
						vvpPath[i][j] = -1;
					}
				}
			}
			for (size_t k = 0; k < n; ++k)
			{
				for (size_t i = 0; i < n; ++i)
				{
					for (size_t j = 0; j < n; ++j)
					{

						// i->k + k->j 如果小于 i->j 的距离则可以更新
						if (vvdist[i][k] != MAX_W && vvdist[k][j] != MAX_W
							&& vvdist[i][k] + vvdist[k][j] < vvdist[i][j])
						{
							vvdist[i][j] = vvdist[i][k] + vvdist[k][j];
							vvpPath[i][j] = vvpPath[k][j];
						}

					}
				}
				// 打印权值和路径矩阵观察数据
				for (size_t i = 0; i < n; ++i)
				{
					for (size_t j = 0; j < n; ++j)
					{
						if (vvdist[i][j] == MAX_W)
						{
							//cout << "*" << " ";
							printf("%3c", '*');
						}
						else
						{
							//cout << vvDist[i][j] << " ";
							printf("%3d", vvdist[i][j]);
						}
					}
					cout << endl;
				}
				cout << endl;
				for (size_t i = 0; i < n; ++i)
				{
					for (size_t j = 0; j < n; ++j)
					{
						//cout << vvParentPath[i][j] << " ";
						printf("%3d", vvpPath[i][j]);
					}
					cout << endl;
				}
				cout << "=================================" << endl;
					
			}
		}
	private:
		vector<V> _vertexs;    // 顶点集合
		vector<vector<W>> _matrix;    // 存储边集合的矩阵
		map<V, size_t> _vIndexMap;    // 相应顶点映射的下标
	};

	void TestFloydWarShall()
	{
		const char* str = "12345";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('1', '2', 3);
		g.AddEdge('1', '3', 8);
		g.AddEdge('1', '5', -4);
		g.AddEdge('2', '4', 1);
		g.AddEdge('2', '5', 7);
		g.AddEdge('3', '2', 4);
		g.AddEdge('4', '1', 2);
		g.AddEdge('4', '3', -5);
		g.AddEdge('5', '4', 6);
		vector<vector<int>> vvDist;
		vector<vector<int>> vvParentPath;
		g.Floyd(vvDist, vvParentPath);
		// 打印任意两点之间的最短路径
		for (size_t i = 0; i < strlen(str); ++i)
		{
			g.PrintShortPath(str[i], vvDist[i], vvParentPath[i]);
			cout << endl;
		}
	}

	void TestGraphBellmanFord()
	{
		/*const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 6);
		g.AddEdge('s', 'y', 7);
		g.AddEdge('y', 'z', 9);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', 8);
		g.AddEdge('t', 'z', -4);
		g.AddEdge('x', 't', -2);
		vector<int> dist;
		vector<int> parentPath;
		if (g.BellmanFord('s', dist, parentPath))
		{
			g.PrintShortPath('s', dist, parentPath);
		}
		else
		{
			cout << "存在负权回路" << endl;
		}*/

		//微调图结构，带有负权回路的测试
		const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 6);
		g.AddEdge('s', 'y', 7);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('y', 'z', 9);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('y', 's', 1); // 新增
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', -8); // 更改
		g.AddEdge('t', 'z', -4);
		g.AddEdge('x', 't', -2);
		vector<int> dist;
		vector<int> parentPath;
		if (g.BellmanFord('s', dist, parentPath))
		{
		 g.PrintShortPath('s', dist, parentPath);
		}
		else
		{
		 cout << "存在负权回路" << endl;
		}
	}

	void TestGraphDijkstra()
	{
		const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('y', 't', 3);
		g.AddEdge('y', 'x', 9);
		g.AddEdge('y', 'z', 2);
		g.AddEdge('z', 's', 7);
		g.AddEdge('z', 'x', 6);
		g.AddEdge('t', 'y', 2);
		g.AddEdge('t', 'x', 1);
		g.AddEdge('x', 'z', 4);
		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrintShortPath('s', dist, parentPath);

		// 图中带有负权路径时，贪心策略则失效了。
		// 测试结果可以看到s->t->y之间的最短路径没更新出来
		/*const char* str = "sytx";
		 Graph<char, int, INT_MAX, true> g(str, strlen(str));
		 g.AddEdge('s', 't', 10);
		 g.AddEdge('s', 'y', 5);
		 g.AddEdge('t', 'y', -7);
		 g.AddEdge('y', 'x', 3);
		 vector<int> dist;
		 vector<int> parentPath;
		 g.Dijkstra('s', dist, parentPath);
		 g.PrinrtShotPath('s', dist, parentPath);*/
	}

	void TestGraphMinTree()
	{
		const char* str = "abcdefghi";
		Graph<char, int> g(str, strlen(str));
		g.AddEdge('a', 'b', 4);
		g.AddEdge('a', 'h', 8);
		//g.AddEdge('a', 'h', 9);
		g.AddEdge('b', 'c', 8);
		g.AddEdge('b', 'h', 11);
		g.AddEdge('c', 'i', 2);
		g.AddEdge('c', 'f', 4);
		g.AddEdge('c', 'd', 7);
		g.AddEdge('d', 'f', 14);
		g.AddEdge('d', 'e', 9);
		g.AddEdge('e', 'f', 10);
		g.AddEdge('f', 'g', 2);
		g.AddEdge('g', 'h', 1);
		g.AddEdge('g', 'i', 6);
		g.AddEdge('h', 'i', 7);

		Graph<char, int> kminTree;
		cout << "Kruskal:" << g.Kruskal(kminTree) << endl;
		kminTree.Print();

		Graph<char, int> pminTree;
		cout << "Prim:" << g.Prim(pminTree, 'a') << endl;
		pminTree.Print();
		cout << endl;

		/*for (size_t i = 0; i < strlen(str); ++i)
		{
			cout << "Prim:" << g.Prim(pminTree, str[i]) << endl;
		}*/
	}

	void TestGraph()
	{
		Graph<char, int, INT_MAX, true> g("0123", 4);
		g.AddEdge('0', '1', 1);
		g.AddEdge('0', '3', 4);
		g.AddEdge('1', '3', 2);
		g.AddEdge('1', '2', 9);
		g.AddEdge('2', '3', 8);
		g.AddEdge('2', '1', 5);
		g.AddEdge('2', '0', 3);
		g.AddEdge('3', '2', 6);
		g.Print();
	}

	void TestGraphBFS()
	{
		string a[] = { "张三", "李四", "王五", "赵六", "周七" };
		Graph<string, int, INT_MAX, true> g1(a, sizeof(a) / sizeof(string));
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.Print();
		g1.BFS();
	}

	void TestGraphDFS()
	{
		string a[] = { "张三", "李四", "王五", "liren", "赵六", "周七"};
		Graph<string, int, INT_MAX, true> g1(a, sizeof(a) / sizeof(string));
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.AddEdge("王五", "周七", 30);
		g1.DFS();
		g1.Print();
	}
}


// 邻接表
namespace Adjacency_table
{
	template <class W>
	struct Edge
	{
		//size_t _srcIndex;  // 这是入度的下标，一般不用实现
		size_t _dstIndex; // 代表出度下标
		W _weight; // 权值
		Edge<W>* _next; // 链表的下一个节点

		Edge(size_t dstIndex, W weight = W())
			:_dstIndex(dstIndex)
			, _weight(weight)
			, _next(nullptr)
		{}
	};

	// V代表的是顶点的元素类型
	// W代表的是边的权值类型
	// MAX_W是边的权值，以INT_MAX代表无穷大
	// Direction代表的true为有向图，false为无向图
	template <class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			_tables.resize(n, nullptr);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(a[i]);
				_vIndexMap[a[i]] = i;
			}
		}

		// 链接边的函数
		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			// 进行头插
			Edge* newEdge = new Edge(dsti, w);
			newEdge->_next = _tables[srci];
			_tables[srci] = newEdge;

			// 判断是否为无向图
			if (Direction == false)
			{
				// 同样进行头插
				Edge* newEdge = new Edge(srci, w);
				newEdge->_next = _tables[dsti];
				_tables[dsti] = newEdge;
			}
		}

		// 查找顶点映射的下标
		size_t GetVertexIndex(const V& v)
		{
			// 为了防止顶点不存在的情况，这里我们使用map的find函数
			auto it = _vIndexMap.find(v);
			if (it == _vIndexMap.end())
			{
				throw invalid_argument("顶点不存在");
				return -1;
			}
			else
			{
				return it->second;
			}
		}

		// 为了方便观察，要实现一个打印函数
		void Print()
		{
			// 顶点
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			for (size_t i = 0; i < _tables.size(); ++i)
			{
				cout << _vertexs[i] << "[" << i << "]->";
				Edge* cur = _tables[i];
				while (cur)
				{
					cout << "[" << _vertexs[cur->_dstIndex] << ":" << cur->_dstIndex << ":" << cur->_weight << "]->";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}
		}
	private:
		vector<V> _vertexs;    // 顶点集合
		map<V, size_t> _vIndexMap;    // 相应顶点映射的下标
		vector<Edge*> _tables;    // 存放边集合的指针数组
	};

	void TestGraph()
	{
		string a[] = { "张三", "李四", "王五", "赵六" };
		Graph<string, int, INT_MAX, true> g1(a, 4);
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.Print();
	}
}
