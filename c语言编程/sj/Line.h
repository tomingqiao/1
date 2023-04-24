#define LINE_H

#include "Station.h"
#define MAX 30

typedef struct Line // 线路信息
{
    int LineNumber;        // 线路编号
    char name[20];         //线路名称
    int fare;              // 票价
    int FirstTime[2];      // 首班时间
    int LastTime[2];       // 末班时间
    Station Stations[MAX]; // 所有途径站点
} Line;

