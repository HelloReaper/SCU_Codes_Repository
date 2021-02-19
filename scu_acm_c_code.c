#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 5
#define Max 100
#define Size 6
#define MapSize 5
//kruskal算法中边的结构体
typedef struct EdgeData{
    int head;
    int rear;
    int value;
}Edge;
//用以存放连通图的邻接表，结点
typedef struct Node{
    int num;
    struct Node *next;
}Node;

void LowerToUpper();
void DeleteSpace(char s[]);
int IsRADAR(int n);
int ReverseInt(int n);
void BrandToRADAR(int non);
void BessieRoutes(int n);
int GreatNumberMod_9(void);
void Only_Two_lucky_digital(int n);
int YorSeFulCircle(int n,int m);
int IsLegal(int current_row,int current_column,int queen[]);
void EightQueen(int current_column,int queen[],int *count);
int CaculateQueen(int queen[]);
void PrintQueen(int queen[]);
void move(char a,char b);
void HanNuoTa(int n,char a,char b,char c);
void Merge(int A[],int low,int mid,int high,int B[]);
void MergeTwo(int A[],int n,int low,int mid,int high);
void MergeSort(int A[],int n,int low,int high);
int Number_Triangle(int data[][Max],int MaxNum[][Max]);
void Prime(int map[][Size]);
int Binary_Search(int data[],int n,int goal);
int FindMinList(int dist[],int S[]);
void Dijkstra(int map[][MapSize],int origin,int dist[],int path[],int S[]);
void Flody(int map[][MapSize],int Short[][MapSize]);
int ClimbWooden(void);
int main(){
    //LowerToUpper();
    /*char s[100];
    int i=0;
    while((s[i++]=getchar())!='\n');
    s[i-1]='\0';
    DeleteSpace(s);
    puts(s);*/
    //printf("%d \n",IsRADAR(3));
    //BrandToRADAR(87);
    //BessieRoutes(N);
    //大数取余
    //printf("%d\n",GreatNumberMod_9());
    //Only_Two_lucky_digital(10);
    //约瑟夫环
    //printf("%d ",YorSeFulCircle(11,3));
    //八皇后问题
    /*int queen[8]={0},count=0;
    EightQueen(0,queen,&count);
    printf("%d ",count);*/
    //汉诺塔问题
    /*char A='A',B='B',C='C';
    int n=3;
    HanNuoTa(n,A,B,C);*/
    //归并排序
    /*int n=7,low=0,high=6;
    int A[7]={49,38,65,97,76,13,27};
    MergeSort(A,n,low,high);
    for(int i=0;i<7;i++)printf("%d ",A[i]);*/
    //数字三角
    /*
    int data[Max][Max]={{13},{11,8},{12,7,26},{6,14,15,8},{12,7,13,24,11}};
    int MaxNum[Max][Max];
    printf("%d \n",Number_Triangle(data,MaxNum));*/
    //最小生成树，prime算法
    // int map[][Size]={{0,6,1,5,INT_MAX,INT_MAX},
    //                  {6,0,5,INT_MAX,3,INT_MAX},
    //                  {1,5,0,5,6,4},
    //                  {5,INT_MAX,5,0,INT_MAX,2},
    //                  {INT_MAX,3,6,INT_MAX,0,6},
    //                  {INT_MAX,INT_MAX,4,2,6,0}
    //                  };
    // Prime(map);//prime算法
    //二分查找
    // int data[10]={1,2,3,4,5,6,7,8,9,10};
    // printf("%d ",Binary_Search(data,10,6));

    //构造最短路径的带权有向图邻接矩阵
    //Dijkstra算法求解单源最短路径
    int map[MapSize][MapSize]={INT_MAX,10,INT_MAX,INT_MAX,5,
                   INT_MAX,INT_MAX,1,INT_MAX,2,
                   INT_MAX,INT_MAX,INT_MAX,4,INT_MAX,
                   7,INT_MAX,6,INT_MAX,2,
                   INT_MAX,3,9,2,INT_MAX};
    // int origin=0,dist[MapSize]={0},path[MapSize],S[MapSize]={0};
    // printf("Input Origin Point: ");
    // scanf("%d",&origin);
    // for(int i=0;i<MapSize;i++)path[i]=origin;
    // S[origin]=1;//源点已加入S[]
    // Dijkstra(map,origin,dist,path,S);
    // for(int i=0;i<MapSize;i++)printf("%d  ",path[i]);

    //Floyd算法求解各个顶点之间的最短路径
    // int Short[MapSize][MapSize];
    // for(int i=0;i<MapSize;i++){
    //     for(int j=0;j<MapSize;j++){
    //         Short[i][j]=map[i][j];
    //     }
    // }
    // Flody(map,Short);
    // for(int i=0;i<MapSize;i++){
    //     for(int j=0;j<MapSize;j++){
    //         printf("%d ",Short[i][j]);
    //     }
    //     printf("\n");
    // }
    //
    //蜗牛爬杆
    //printf("it needs %d days\n",ClimbWooden());
    //将一个硬币抛n次，求没有连续两次向上的次数

    return 0;
}

//读入一些字符串，将其中的小写字母转成大写字母
void LowerToUpper(){
    int i=0;
    char c;
    while((c=getchar())!=EOF){
        if(c>'a'&&c<'z'){
            c=c-32;
        }
        i++;
        printf("%c",c);
    }
}

//读入一些字符串，将其中的空格去掉
void DeleteSpace(char s[]){
    int i=0,j=0;
    while(s[i]!='\0'){
        if((s[i])==' '){
            j=i;
            while(s[j]!='\0'){
                s[j]=s[j+1];
                j++;
            }
        }
        i++;
    }
}
//将一个数转化为回文数
void BrandToRADAR(int non){
    int t=non,i=0;
    while (!IsRADAR(t))
    {
        i++;
        t=t+ReverseInt(t);
    }
    printf("RADAR is %d\n",t);
    printf("The number of Trans is %d",i);
}
//判断是否回文数
int IsRADAR(int n){
    if(ReverseInt(n)==n)
        return 1;
    return 0;
}
//逆转一个int变量
int ReverseInt(int n){
    int result=0,x=n;
    while(x!=0){
        result=x%10+result*10;
        x=x/10;
    }
    return result;
}
//蛇形填充矩阵
void BessieRoutes(int n){
    int i=0,j=0;
    int w=1;
    int data[N][N]={0};
    data[0][0]=1;
    while(w<N*N){
        while(j+1<n&&data[i][j+1]==0)data[i][++j]=++w;//顺时针填写矩阵四周的元素，使用值0标识未填写的元素
        while(i+1<n&&data[i+1][j]==0)data[++i][j]=++w;
        while(j-1>=0&&data[i][j-1]==0)data[i][--j]=++w;
        while(i-1>=0&&data[i-1][j]==0)data[--i][j]=++w;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
}
//大数取余
int GreatNumberMod_9(void){
    char str[1000001];
    int i=0,ans=0;
    printf("Please input your number: \n");
    scanf("%s",str);
    while(str[i]!='\0'){
        ans=(ans*10+str[i]-'0')%9;
        i++;
    }
    return ans;
}
//从只由4和7两个数字组成的序列中，从小到大排序，找出第n个数据
/*
假设4为0,7为1，则：
4:0
7:1
44:00
47:01
74:10

在最左边加上1，则为2 3 4 5 6
4:10
7:11
44:100
47:101
74:110

*/
void Only_Two_lucky_digital(int n){
    int t=n+1,i=0;
    int ans=0;
    char Binary[100];
    while(t>0){
        Binary[i++]=t%2;
        t=t/2;
    }
    Binary[--i]='\0';//得到逆序二进制后，去掉最后一位，也就是正序最左边的1
    for(i=i-1;i>=0;i--){
        if(Binary[i]==0){
            ans+=4*pow(10,i);
        }
        else if(Binary[i]==1){
            ans+=7*pow(10,i);
        }
    }
    printf("%d \n",ans);
}

//求解约瑟夫环,n个人排队，第m个人淘汰,返回(0-n-1)的下标
int YorSeFulCircle(int n,int m){
    /*//递归解法
    if(n==1)return 0;
    else{
        return (YorSeFulCircle(n-1,m)+m)%n;
    }
    */
   //迭代解法
   int p=0;
   for(int i=1;i<=n;i++)
   {
       p=(p+m)%i;
   }
   return p;
}
//eightQueen Row is Legal?
int IsLegal(int current_row,int current_column,int queen[]){
    for(int pre_column=0;pre_column<current_column;pre_column++){//current_column之前的为已有皇后
        int row=queen[pre_column];
        if(row==current_row)return 0;//与已有皇后的行重合，非法
        else if(abs(current_row-row)==abs(current_column-pre_column))return 0;//与已有皇后的行差和列差相等，即位于同一斜线上
    }
    return 1;
}
//计算八皇后的摆放方式
void EightQueen(int current_column,int queen[],int *count){
    int max=0;
    for(int row=0;row<8;row++){
        if(IsLegal(row,current_column,queen)){
            queen[current_column]=row;
            if(current_column!=7){
                EightQueen(current_column+1,queen,count);//进行下一列皇后的摆放
            }
            else{ 
                (*count)++;//得到一种摆放方式，下一个循环得到其他摆放方式
                //PrintQueen(queen);//打印此时八皇后的位置
                //printf("%d\n",CaculateQueen(queen));
                if(CaculateQueen(queen)>max){
                    max=CaculateQueen(queen);
                    printf("%d\n",max);
                }
            }
        }
    }
}
//计算当前八皇后摆放的值
int CaculateQueen(int queen[]){
    //将8皇后二维矩阵，以1-64从左到右依次填充
    int max=0;
    for(int i=0;i<8;i++){
        if(queen[i]==0){//若是第一行
            max=max+i+1;
        }
        else{
            max=max+(queen[i])*8+i+1;
        }
    }
    return max;
}
//打印八皇后的位置
void PrintQueen(int queen[]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==queen[j])printf("*");
            else printf("-");
        }
        printf("\n");
    }
    printf("\n");
}
void move(char a,char b){
    printf("%c->%c\n",a,b);
}

//汉诺塔问题,将n个盘子经过b移到c
void HanNuoTa(int n,char a,char b,char c){
    if(n==1){
        move(a,c);//如果只有一个盘子直接从a移到c
    }
    else{
        //将上层的n-1个盘子从a，先移到b
        HanNuoTa(n-1,a,c,b);
        move(a,c);
        //递归重复这一过程，此时a空闲，b有n-1个，故类似的，问题变成了，将b上的n-1个盘，经过a，移到c
        HanNuoTa(n-1,b,a,c);
    }
}

//2路归并排序
//合并A中的两段有序表[low-mid],[mid-high],到B[]
void Merge(int A[],int low,int mid,int high,int B[]){
    for(int i=low;i<=high;i++){
        B[i]=A[i];
    }
    int k=low,i,j;
    for(i=low,j=mid+1;(i<=mid)&&(j<=high);k++){
        if(B[i]<B[j]){
            A[k]=B[i++];
        }
        else{
            A[k]=B[j++];
        }
    }
    while(i<=mid){
        A[k++]=B[i++];
    }
    while(i<=high){
        A[k++]=B[j++];
    }
}
//将A[]中的两段合并,A的长度为n
void MergeTwo(int A[],int n,int low,int mid,int high){
    int *B=calloc(n,sizeof(int));
    Merge(A,low,mid,high,B);
    free(B);
}
//2路归并排序
void MergeSort(int A[],int n,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A,n,low,mid);
        MergeSort(A,n,low+1,high);
        MergeTwo(A,n,low,mid,high);
    }
}

//数字三角,data[][]为数字三角矩阵，MaxNum[i][j]记录从data[i][j]到底部的最大路径的值
int Number_Triangle(int data[][Max],int MaxNum[][Max]){
    int i,j;
    for(i=Max-1;i>=0;i--)MaxNum[Max-1][i]=data[Max-1][i];//故MaxNum的底部最后一行与data相同
    //从倒数第二行往上计算data[i][j]到底部最后一行的最大值
    for(i=Max-2;i>=0;i--){
        for(j=0;j<=i;j++){
            MaxNum[i][j]=data[i][j]+(MaxNum[i+1][j]>MaxNum[i+1][j+1]?MaxNum[i+1][j]:MaxNum[i+1][j+1]);
        }
    }
    return MaxNum[0][0];
}
//最小生成树，prime算法，map为图的邻接矩阵
//将图中的每个节点依次从0开始编号，以0为起点，用prime算法构造最小生成树
void Prime(int map[][Size]){
    int cost[Size];//cost数组为未加入点到已加入集合的最短距离
    int i,j,mp=0,min;
    //从0开始的cost数组
    for(i=0;i<Size;i++){
        cost[i]=map[0][i];
    }
    printf("0");
    for(i=1;i<Size;i++)
    {
        min=INT_MAX;
        //找出需要加入集合的点
        for(j=0;j<Size;j++){
            if(cost[j]!=0){
                if(min>cost[j]){
                    min=cost[j];
                    mp=j;
                }
            }
        }
        //for(j=0;j<Size;j++)printf("%d ",cost[j]);
        //printf("\n");
        printf("->%d",mp);
        cost[mp]=0;//将新加入的点的cost设为0
        //更新cost[]数组
        for(j=0;j<Size;j++){
            if(map[mp][j]<cost[j]){
                cost[j]=map[mp][j];
            }
        }
    }
}

/*kruskal算法，未完成版

//对无向图中的边进行排序,value逆序，最小值最后一个
void EdgeSort(Edge sort_edge[]){
    int i,j,k=0,flag;
    Edge temp;
    temp.head=0;
    temp.rear=0;
    temp.value=0;
    for(i=0;i<Size*(Size-1)/2;i++){
        flag=0;
        for(j=Size*(Size-1)/2-1;j>0;j--){
            if(sort_edge[j].value>sort_edge[j-1].value){
                temp=sort_edge[j];
                sort_edge[j]=sort_edge[j-1];
                sort_edge[j-1]=temp;
                flag=1;
            }
        }
        if(flag==0)break;
    }

}
//找出最小边
int Get_min_Edge(Edge edge[],int k){
    int min=0;
    Edge e=edge[0];
    for(int i=0;i<k;i++){
        if(e.value>edge[i].value&&edge[i].value!=INT_MAX){
            e=edge[i];
            min=i;
        }
    }
    return min;
}
//判断是否以head和rear为首尾的边是否在同一个连通图中,List为邻接表
int IsSameConnectGraph(int head,int rear,Node List[]){
    int i,j;
    Node *p=List[head].next;
    while(p!=NULL){
        if(p->num==rear)//这条边的两个点都已经在一个连通图中了
            return 1;
    }
    return 0;
}
//最小生成树的kruskal算法
void Kruskal(int map[][Size]){
    Edge sort_edge[Size*(Size-1)/2]={{0,0,INT_MAX}};
    int i,j,k=0;
    //构建连通图邻接表，一个连通图为一个链表
    Node list[Size];
    //先将所有的边放入sort_edge中
    for(i=0;i<Size;i++){
        for(j=0;j<i;j++){
            if(map[i][j]!=INT_MAX){
                sort_edge[k].head=i;
                sort_edge[k].rear=j;
                sort_edge[k].value=map[i][j];
                k++;
            }
        }
    }
    //排序
    EdgeSort(sort_edge);
    //将筛选出的最小非连通图边加入到邻接表
    while (k>0)
    {
        k--;
        i=sort_edge[k].head;
        j=sort_edge[k].rear;
        if(!IsSameConnectGraph(i,j,list)){//如果不再同一个连通图中，则可以加入
            //****更新邻接表
            //** code
        }
    }
    //**此时最小生成树信息已经得出
}
*/

//马踏棋盘算法
//川大的这个题与一般的马踏棋盘算法不同，用两中移动方法，奇数用一种，偶数用一种，不过基本思路一样
//方案一 —— 深度优先搜索法
//我们可以采用深度优先法求解，深度优先搜索是指对每一个可能的分支路径深入到不能再深入为止，而且每个节点只能访问一次。
//如图１所示，当马在当前位置时(节点１)，将它下一跳的所有位置看作分支结点，然后选择一个分支结点进行移动，如节点２，然后再走该结点的分支结点，如节点３，如果节点３不能再走下去，则退回到节点２，再选择另一种走法，
// 如节点４，一直走下去，直至不能派生出其他的分支结点，也就是“马”走不通了。
// 此时则需要返回上一层结点，顺着该结点的下一条路径进行深度优先搜索下去，直至马把棋盘走遍。 

// 方案二 —— 贪心法
// 贪心法是指，在对问题求解时总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，该方法所做出的仅是在某种意义上的局部最优解。
// 我们在回溯法的基础上，用贪心法进行优化，在每个结点对其子结点进行选取时，优先选择“出口”最少的进行搜索，“出口”的意思是在这些子结点中它们的可行子结点的个数，
// 也就是“孙子”结点越少的越优先跳，因为这样选择时出口少的结点会越来越少，这样跳成功的机会就更大一些。
// （传说中的“先苦后甜”？？）实际体现就是，先沿着周边跳，逐渐向中间靠拢。

//       值得注意的是，这种启发式算法在马踏棋盘这种特殊的求哈密顿路径问题中有极好的效果，并称作Warnsdorff法则。
// 虽然求哈密顿路径是一个NP问题，但是对于较小规模的棋盘，Warnsdorff法则能够在大多数情况下与线性时间内求出一个解。

// 如下图，可以先选择3、4、5、6这几个“出口”少的先跳，跳完一步再选择“出口”少的往下跳，如没有可跳出则回溯上一结点.

//二分查找
int Binary_Search(int data[],int n,int goal){
    int mid,high=n-1,low=0;
    while(low<=high){
        mid=(low+high)/2;
        if(data[mid]==goal){
            return mid;
        }
        else if(data[mid]<goal){
            low=mid+1;
        }
        else if(data[mid]>goal){
            high=mid-1;
        }
    }
}
//找出dist[]数组中的最小值,S[]是已经选择顶点的集合
int FindMinList(int dist[],int S[]){
    int i,min=INT_MAX,m=-1;
    for(i=0;i<MapSize;i++){
        if(min>dist[i]&&S[i]==0){
            min=dist[i];
            m=i;
        }
    }
    return m;
}
//最短路径
//Dijkstra算法,有向图map的单源最短路径，源点为origin
//dist[]记录从源点到其他各顶点的最短路径长度
//path[i]表示从源点到顶点i之间最短路径的前驱结点
//S[]为已经选择的顶点集合，初始只有源点,在集合中值为1，不在则为0
void Dijkstra(int map[][MapSize],int origin,int dist[],int path[],int S[]){
    //首先对dist进行初始化
    int i,j=0,k=0;
    for(i=0;i<MapSize;i++)dist[i]=map[origin][i];
    //计算从源点到达其他顶点的最短路径，所以要执行n-1次
    for(i=1;i<MapSize;i++){
        j=FindMinList(dist,S);
        if(j==-1){
            printf("There is no min value in dist[],Or all points have been in S[]/n");
            break;
        }
        S[j]=1;//找出最近的顶点加入S集合中
        //修改源点到未加入S中顶点的最短路径dist[]
        //根据源点经过新加入点j后到达，其他未加入结点的距离是否小于dist[]中的值来修改
        for(k=0;k<MapSize;k++){
            if(S[k]==0&&map[j][k]!=INT_MAX){//加上map[j][k]!=INT_MAX这个条件是防止出现dist[j]+INT_MAX=负数的情况
                if(dist[j]+map[j][k]<dist[k])
                    dist[k]=dist[j]+map[j][k];
                    path[k]=j;
            }
        }
    }
}

//Flody算法求解图中各个顶点之间的最短距离
//实际上就是计算每个点到其他点之间的距离是否会比绕K点后的距离大，如果是就更新为该两点之间的最短距离
//Short[i][j]表示i结点到j结点之间的最短距离，初始化等于map[][]
void Flody(int map[][MapSize],int Short[][MapSize]){
    int i,j,k;
    for(k=0;k<MapSize;k++){
        for(i=0;i<MapSize;i++){
            for(j=0;j<MapSize;j++){
                if((Short[i][k]!=INT_MAX)&&(Short[k][j]!=INT_MAX)&&(Short[i][j]>Short[i][k]+Short[k][j]))
                    Short[i][j]=Short[i][k]+Short[k][j];
            }
        }
    }
}

//蜗牛爬杆，一天A米，晚上滑下来B米，杆高度为V米，求爬到顶的天数
//由条件得，若需要x天，则(a-b)*(x-1)+a>=v,x>=(v-a)/(a-b)+1;
int ClimbWooden(void){
    int a,b,v;
    printf("input A,B,V: ");
    scanf("%d%d%d",&a,&b,&v);
    int t1=a-b;
    int t2=v-a;
    if(t2%t1==0){
        return t2/t1+1;
    }
    else
        return ceil(t2/t1)+1;
}

