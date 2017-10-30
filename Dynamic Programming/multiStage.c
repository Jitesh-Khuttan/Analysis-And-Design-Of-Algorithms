// Program: Find Shortest Path in Multistage Graph
// Algorithm method: Dynamic Programming
// Programmer: Kapil Sunil Zad

#include<conio.h>
#include<stdio.h>
//#include<dos.h>
#include<graphics.h>
#include<values.h>

#define MAXVERTEX 10
#define MAXSTAGE 5
#define INFINITY MAXINT

#define TRUE 1
#define FALSE 0

union REGS regs, outregs;
/*adjmatrix[i][j] is an adjacency cum weight matrix,
  it contains the weight between nodes i and j,
  if there is no edge between i and j it contains 0*/
int adjmatrix[MAXVERTEX][MAXVERTEX];
int vcount, nstages, stagesize[MAXSTAGE];

struct Vertex
{
    char label[2];
    int x;
    int y;
    int cost;
    int index;
    int stage;
    struct Vertex * parent;
}v[MAXVERTEX];

void initializemouse()
{
    //init mouse
    regs.x.ax = 0x00;
    int86(0x33, &regs, &outregs);
    if(outregs.x.ax != 0)
    {
        //display mouse pointer
        regs.x.ax = 0x01;
        int86(0x33, &regs, &outregs);
    }
    else
    {
        printf("Error initializing mouse.");
        exit(0);
    }
}

int isclick()
{
    //get mouse status
    regs.x.ax = 0x03;
    int86(0x33, &regs, &outregs);

    if((outregs.x.bx & 0x01) == 1)
    {
        delay(300);
        return 1;
    }
    else return 0;
}

void drawvertex(struct Vertex * v, int bgcolor)
{
    regs.x.ax = 0x02; // hide mouse
    int86(0x33, &regs, &outregs);

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, bgcolor);
    fillellipse(v->x, v->y, 10, 10);
    setcolor(BLUE);
    outtextxy(v->x-3, v->y-3, v->label);

    regs.x.ax = 0x01; // show mouse
    int86(0x33, &regs, &outregs);
}

void drawedge(struct Vertex * u, struct Vertex * v, int vertcolor, int edgecolor)
{
    setcolor(edgecolor);
    line(u->x, u->y, v->x, v->y);
    drawvertex(u, vertcolor);
    drawvertex(v, vertcolor);
}

void drawgraph()
{
    int i, j, xdisp=0, ydisp=0, flag[MAXVERTEX][MAXVERTEX];
    char *wt;

    for(i=0; i<MAXVERTEX; i++)
        for(j=0; j<MAXVERTEX; j++)
            flag[i][j] = 0;

    for(i=0; i<vcount; i++)
    {
        for(j=0; j<vcount; j++)
        {
            if(adjmatrix[i][j] != 0 && flag[j][i] != 1)
            {
                setcolor(LIGHTBLUE);
                line(v[i].x, v[i].y, v[j].x, v[j].y);

                xdisp = -((v[i].x - v[j].x)/2);
                ydisp = -((v[i].y - v[j].y)/2);

                setcolor(WHITE);
                sprintf(wt, "%d", adjmatrix[i][j]);
                outtextxy(v[i].x+xdisp, v[i].y+ydisp,wt);
                flag[i][j]=flag[j][i]=1;
            }
        }
    }
    for(i=0; i<vcount; i++)
        drawvertex(&v[i], CYAN);
}

void getstagesize()
{
    int i;
    vcount = 0;

    printf("Enter the number of stages: ");
    scanf("%d", &nstages);

    printf("\nNumber of vertices in Stage [0] : 1\n");
    stagesize[0]=1;
    for(i=1; i<nstages-1; i++)
    {
        printf("\nNumber of vertices in Stage [%d] : ", i);
        scanf("%d", &stagesize[i]);
        vcount += stagesize[i];
    }
    printf("\nNumber of vertices in Stage [%d] : 1", i);
    stagesize[i]=1;
    //first and last stage contains 1 vertex each
    vcount += 2;
    getch();
}

void getvertices()
{
    int currstage=0; // current stage no.
    int stageVCnt=0; // no. of vertices entered in curr. stage
    int count = 0;   // total no. of vertices entered
    char lbl = 'A';
    initializemouse();

    setcolor(WHITE);
    outtextxy(4, 1, "Point and click to add vertices");

    gotoxy(1, 2);
    printf("Enter 1 vertice of Stage [%d]  ", currstage);

    do
    {
        if(isclick())
        {
            sprintf(v[count].label,"%c",lbl++);
            v[count].x = outregs.x.cx;
            v[count].y = outregs.x.dx;
            v[count].index = count;
            v[count].stage = currstage;
            drawvertex(&v[count], CYAN);
            stageVCnt++;
            if(stageVCnt == stagesize[currstage])
            {
                currstage++;
                stageVCnt=0;
                if(count != vcount)
                {
                    gotoxy(1, 2);
                    printf("Enter %d vertice/s of Stage [%d] ", stagesize[currstage], currstage);
                }
            }
            count++;
        }
    }while(count<vcount);

    regs.x.ax = 0x02; // hide mouse
    int86(0x33, &regs, &outregs);
}

void getedges()
{
    int row, col;

    cleardevice();
    gotoxy(1, 1);
    printf("Enter Edges:\n");
    printf("(enter the weight, else enter 0 for no edge)\n");

    for(row=0; row<vcount; row++)
    {
        printf("\n");
        for(col=0; col<vcount; col++)
        {
            if(row != col)
            {
                if(adjmatrix[col][row] == -1)
                {
                    if(v[col].stage == v[row].stage+1)
                    {
                        printf("(%s, %s) : ", v[row].label, v[col].label);
                        scanf("%d", &adjmatrix[row][col]);
                    }
                    else
                        adjmatrix[row][col] = 0;
                }
                else adjmatrix[row][col] = adjmatrix[col][row];
            }
            else adjmatrix[row][col] = 0;
        }
    }
}

void PressKeyToContinue()
{
    setcolor(WHITE);    outtextxy(1, 460,"Press any key to continue...");
    getch();
    setcolor(BLACK);    outtextxy(1, 460,"Press any key to continue...");
}

// find shortest path in multistage graph using forward approach
void FindMultiStagePath()
{
    int i, k, c, weight;
    struct Vertex * u;
    struct Vertex * adj;

    for(k=0; k<vcount; k++)
    {
        v[k].cost = INFINITY;
        v[k].parent = NULL;
    }

    v[vcount-1].cost = 0; //v[vcount-1] is the dest. vertex
    gotoxy(1, 1);

    // consider all vertices starting from last to first
    for(k=vcount-1; k>=0; k--)
    {
        // highlight current vertex whose cost we will calculate
        drawvertex(&v[k], YELLOW); delay(500);

        // now only consider the next stage vertices
        for(i=k+1; i<vcount; i++)
        {
            weight = adjmatrix[k][i];
            if(weight != 0)
            {
                // highlight current edge being considered (red colored)
                drawedge(&v[k], &v[i], YELLOW, LIGHTMAGENTA);
                delay(1500);
                c = weight + v[i].cost;
                if(v[k].cost > c)
                {
                    v[k].cost = c;
                    v[k].parent = &v[i];
                }
            }
        }

        printf("Cost(%s)=%d  ", v[k].label, v[k].cost);
        // highlight edge with least cost (yellow colored)
        if(v[k].parent != NULL)
            drawedge(&v[k], v[k].parent, YELLOW, YELLOW);
        PressKeyToContinue();
    }
}

void DrawShortestPath()
{
    int xdisp, ydisp; char * wt;
    struct Vertex * v1; // current stage vertex
    struct Vertex * v2; // vertex in next stage with least cost

    v1 = &v[0];

    while(v1->parent != NULL)
    {
        v2 = v1->parent;
        drawedge(v1, v2, GREEN, GREEN);

        xdisp = -((v1->x - v2->x)/2);
        ydisp = -((v1->y - v2->y)/2);

        setcolor(WHITE);
        sprintf(wt, "%d", adjmatrix[v1->index][v2->index]);
        outtextxy(v1->x+xdisp, v1->y+ydisp, wt);
        v1 = v2;
        delay(2000);
    }
}

int main()
{
    int gd = DETECT, gm, i, j;
    initgraph(&gd, &gm, "c:\\tc\\bgi");

    for(i=0; i<MAXVERTEX; i++)
        for(j=0; j<MAXVERTEX; j++)
            adjmatrix[i][j] = -1; //-1: empty

    getstagesize();
    cleardevice();

    getvertices();
    getedges();

    cleardevice();
    drawgraph();
    PressKeyToContinue();

    FindMultiStagePath();

    DrawShortestPath();

    cleardevice();
    DrawShortestPath();
    PressKeyToContinue();

    closegraph();
    return 0;
}

