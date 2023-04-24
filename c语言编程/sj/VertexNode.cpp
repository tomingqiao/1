#include "VertexNode.h"

void AdjInitate(GraphAdjList *G){
    int i;
    G->numEdges = 0;
    G->numVertexes = 0;
    for(i = 0; i < MAXVEX; i++){
        G->adjList[i].firstedge = nullptr;
    }
};

int CreateGraph(GraphAdjList *graph,Line **line, FILE *file){
    int vexnum, Linenum;
    int i = 0, j = 0;
    AdjInitate(graph);
    //读取站点总数以及线路总数
    fscanf(file, "%d", &vexnum);
    fscanf(file, "%d", &Linenum);
    //读取所有站点编号，站点名称
    while(i < vexnum){
        char stationname[20];
        int stationnumber;
        fscanf(file,"%s %d",stationname, &stationnumber);
        add_Station(graph, i, stationnumber, stationname);
        while(fgetc(file) != '\n')
            continue;
        i++;
    }
    //读取线路信息
    while(j <Linenum){
        line[j] = (Line *)malloc(sizeof (Line));
        fscanf(file,"%d %s %d %d %d %d %d", &line[j]->LineNumber, line[j]->name, &line[j]->fare, &line[j]->FirstTime[0], &line[j]->FirstTime[1], &line[j]->LastTime[0], &line[j]->LastTime[1]);
        int v1, v2;
        fscanf(file, "%d", &v1);
        int k = 0;
        i = 0;
        while(fgetc(file) != '\n'){
            while (graph->adjList[i].data.StationNumber != v1){
                i++;
            }
            line[j]->Stations[k++] = graph->adjList[i].data;
            i = 0;
            fscanf(file, "%d", &v2);
            add_edge(graph, v1, v2);
            v1 = v2;
        }
        j++;
    }
    return 0;
}

int WriteFile(FILE *file, AdjList *Adj){

    return 0;
}

int add_Station(GraphAdjList *graph, int i, int stationnumber, char name[]){
    //在邻接表数组的第i个位置插入顶点元素
    if(i >= 0 && i < MAXVEX){
        graph->adjList[i].data.StationNumber = stationnumber;
        strcpy(graph->adjList[i].data.StationName, name);
        graph->numVertexes++;
        return 0;
    }
    else {
        printf("顶点越界");
        return  -1;
    }
}

int add_edge(GraphAdjList *graph, int v1, int v2){
    EdgeNode *p;
    if(v1 < 0 || v1 >= graph->numVertexes || v2 < 0 || v2 >= graph->numVertexes){
        printf("参数v1或v2越界");
        return -1;
    }
    p = (EdgeNode *) malloc(sizeof(EdgeNode));
    p->adjvex = v2;
    p->weight = 1;
    p->next = graph->adjList[v1].firstedge;
    graph->adjList[v1].firstedge = p;
    graph->numEdges++;
    return 0;
}

int update_Line(Line * line, int LineNumber , char name[], int fare, int FirstTime[], int LastTime[], Station Stations[]){
    //输入需要修改的信息
    
    return 0;
}

