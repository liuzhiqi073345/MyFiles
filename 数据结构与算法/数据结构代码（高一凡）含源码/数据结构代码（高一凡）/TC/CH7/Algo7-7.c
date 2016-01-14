 /* algo7-7.c ʵ���㷨7.16�ĳ��� */
 #define MAX_NAME 5 /* �����ַ�������󳤶�+1 */
 #define MAX_INFO 20 /* �����Ϣ�ַ�������󳤶�+1 */
 typedef int VRType;
 typedef char VertexType[MAX_NAME];
 typedef char InfoType;
 #include"c1.h"
 #include"c7-1.h" /* �ڽӾ���洢��ʾ */
 #include"bo7-1.c" /* �ڽӾ���洢��ʾ�Ļ������� */
 typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM]; /* 3ά���� */
 typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; /* 2ά���� */
 #include"func7-2.c" /* ���������и��Զ���֮����̾����Floyd�㷨 */

 void main()
 {
   MGraph g;
   int i,j,k;
   PathMatrix p; /* 3ά���� */
   DistancMatrix d; /* 2ά���� */
   CreateDN(&g); /* ����������g */
   for(i=0;i<g.vexnum;i++)
     g.arcs[i][i].adj=0; /* ShortestPath_FLOYD()Ҫ��Խ�Ԫ��ֵΪ0����Ϊ������ͬ�������Ϊ0 */
   Display(g); /* ���������g */
   ShortestPath_FLOYD(g,p,d); /* ��ÿ�Զ��������·������func7-2.c�� */
   printf("d����:\n");
   for(i=0;i<g.vexnum;i++)
   {
     for(j=0;j<g.vexnum;j++)
       printf("%6d",d[i][j]);
     printf("\n");
   }
   for(i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
       if(i!=j)
         printf("%s��%s����̾���Ϊ%d\n",g.vexs[i],g.vexs[j],d[i][j]);
   printf("p����:\n");
   for(i=0;i<g.vexnum;i++)
     for(j=0;j<g.vexnum;j++)
       if(i!=j)
       {
         printf("��%s��%s������",g.vexs[i],g.vexs[j]);
         for(k=0;k<g.vexnum;k++)
           if(p[i][j][k]==1)
             printf("%s ",g.vexs[k]);
         printf("\n");
       }
 }
