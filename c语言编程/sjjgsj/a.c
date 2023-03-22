#define MAX 30        // 线路途径站点最大数目
#define MAXVEX 100    // 顶点或站点最大数目
#define MAXLine 30    // 线路最大数目
typedef int EdgeType; // 边上的权值类型

typedef struct Line // 线路信息
{
    int LineNumber;        // 线路编号
    char name[20];         // 线路名
    int fare;              // 票价
    int FirstTime[2];      // 首班时间
    int LastTime[2];       // 末班时间
    Station Stations[MAX]; // 所有途径站点
} Line;

typedef struct Station // 站点信息
{
    char StationName[20]; // 站点名称
    int StationNumber;    // 站点编号
    int InLineNumber[10]; // 站点所在线路编号
} Station;

typedef struct EdgeNode // 边表结点
{
    int adjvex;            // 邻接点域,顶点对应的下标
    EdgeType weight;       // 存储权值,非网图可以不需要
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

typedef struct LineList // 线路表
{
    int numLine;            // 图中当前线路数
    Line lineList[MAXLine]; // 线路数组
} LineList;
