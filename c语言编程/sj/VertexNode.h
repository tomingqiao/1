#define   VERTEXNODE_H

#include "Line.h"
#define  MAXWEIGHT 100

typedef struct EdgeNode // 边表结点
{
    int adjvex;            // 邻接点域,顶点对应的下标
    EdgeType weight = MAXWEIGHT;       // 存储权值,非网图可以不需要
    struct EdgeNode *next; // 链域,指向下一个邻接点
} EdgeNode;

typedef struct VertexNode // 顶点表结点
{
    Station data;        // 顶点域，存储顶点信息，也就是站点信息
    EdgeNode *firstedge; // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct // 邻接表的数据结构
{
    AdjList adjList;           // 顶点表数组
    int numVertexes, numEdges; // 图中当前顶点数和边数
} GraphAdjList;

int add_Station(GraphAdjList *graph, int i, int stationnumber, char name[]);  //新增站点
int add_edge(GraphAdjList *graph, int v1, int v2);  //新增边（v1，v2）
void AdjInitate(GraphAdjList *G);    //初始化邻接表数组
int CreateGraph(GraphAdjList *graph,Line **line, FILE *file);   //从已有文件中读取出地铁线路
int WriteFile(FILE *file, AdjList *Adj);    //将顶点表数组中存储的地铁线路信息写入文件
int update_Line(Line * line, int LineNumber = 0, char name[] = nullptr, int fare = 0, int FirstTime[] = nullptr, int LastTime[] = nullptr, Station Stations[] = nullptr);  //修改线路信息