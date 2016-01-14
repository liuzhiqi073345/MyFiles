 // algo7-2.cpp ʵ���㷨7.9�ĳ���
 #include"c1.h"
 typedef int VRType;
 typedef char InfoType;
 #define MAX_NAME 3 // �����ַ�������󳤶�+1
 #define MAX_INFO 20 // �����Ϣ�ַ�������󳤶�+1
 typedef char VertexType[MAX_NAME];
 #include"c7-1.h"
 #include"bo7-1.cpp"

 typedef struct
 { // ��¼�Ӷ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨��
   VertexType adjvex;
   VRType lowcost;
 }minside[MAX_VERTEX_NUM];

 int minimum(minside SZ,MGraph G)
 { // ��SZ.lowcost����С��ֵ������������SZ�е����
   int i=0,j,k,min;
   while(!SZ[i].lowcost)
     i++;
   min=SZ[i].lowcost; // ��һ����Ϊ0��ֵ
   k=i;
   for(j=i+1;j<G.vexnum;j++)
     if(SZ[j].lowcost>0&&min>SZ[j].lowcost) // �ҵ��µĴ���0����Сֵ
     {
       min=SZ[j].lowcost;
       k=j;
     }
   return k;
 }

 void MiniSpanTree_PRIM(MGraph G,VertexType u)
 { // ������ķ�㷨�ӵ�u���������������G����С������T�����T�ĸ����ߡ��㷨7.9
   int i,j,k;
   minside closedge;
   k=LocateVex(G,u);
   for(j=0;j<G.vexnum;++j) // ���������ʼ��
   {
     strcpy(closedge[j].adjvex,u);
     closedge[j].lowcost=G.arcs[k][j].adj;
   }
   closedge[k].lowcost=0; // ��ʼ,U={u}
   printf("��С�����������ĸ�����Ϊ:\n");
   for(i=1;i<G.vexnum;++i)
   { // ѡ������G.vexnum-1������
     k=minimum(closedge,G); // ���T����һ����㣺��k����
     printf("(%s-%s)\n",closedge[k].adjvex,G.vexs[k]); // ����������ı�
     closedge[k].lowcost=0; // ��k���㲢��U��
     for(j=0;j<G.vexnum;++j)
       if(G.arcs[k][j].adj<closedge[j].lowcost)
       { // �¶��㲢��U��������ѡ����С��
         strcpy(closedge[j].adjvex,G.vexs[k]);
         closedge[j].lowcost=G.arcs[k][j].adj;
       }
   }
 }

 void main()
 {
   MGraph g;
   CreateUDN(g); // ����������g
   Display(g); // ���������g
   MiniSpanTree_PRIM(g,g.vexs[0]); // ������ķ�㷨��g�ĵ�1��������������С�������ĸ�����
 }
