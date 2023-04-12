#define STATION_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 30        // 线路途径站点最大数目
#define MAXVEX 100    // 顶点或站点最大数目
typedef int EdgeType; // 边上的权值类型

typedef struct Station // 站点信息
{
    char StationName[20]; // 站点名称
    int StationNumber;    // 站点编号
    int InLineNumber[10]; // 站点所在线路编号
} Station;
