 // algo7-9.cpp ʵ�ֽ̿���ͼ7.33�ĳ���(��ӹ�������̨��)
 #define MAX_NAME 9 // �����ַ�������󳤶�+1
 #define MAX_INFO 20 // �����Ϣ�ַ�������󳤶�+1
 typedef int VRType;
 typedef char VertexType[MAX_NAME];
 typedef char InfoType;
 #include"c1.h"
 #include"c7-1.h" // �ڽӾ���洢��ʾ
 #include"bo7-1.cpp" // �ڽӾ���洢��ʾ�Ļ�������

 typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 3ά����
 typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 2ά����
 #include"func7-2.cpp" // ���������и��Զ���֮����̾����Floyd�㷨

 void path(MGraph G,PathMatrix P,int i,int j)
 { // �������Ϊi�������е����Ϊj���յ�������·����;�������ĳ���
   int k;
   int m=i; // ��������Ÿ���m
   printf("���ξ����ĳ��У�\n");
   while(m!=j) // û���յ����
   {
     G.arcs[m][m].adj=INFINITY; // �Խ�Ԫ�ظ�ֵ�����
     for(k=0;k<G.vexnum;k++)
       if(G.arcs[m][k].adj<INFINITY&&P[m][j][k]) // m��k��ֱ��ͨ·����k��m��j�����·����
       {
         printf("%s ",G.vexs[m]);
         G.arcs[m][k].adj=G.arcs[k][m].adj=INFINITY; // ��ֱ��ͨ·��Ϊ��ͨ
         m=k; // �����ĳ�����Ÿ���m����������
         break;
       }
   }
   printf("%s\n",G.vexs[j]); // ����յ����
 }

 void main()
 {
   MGraph g;
   int i,j,k,q=1;
   PathMatrix p; // 3ά����
   DistancMatrix d; // 2ά����
   printf("�����ļ���Ϊmap.txt\n");
   CreateFUDN(g); // ͨ���ļ�����������g
   for(i=0;i<g.vexnum;i++)
     g.arcs[i][i].adj=0; // ShortestPath_FLOYD()Ҫ��Խ�Ԫ��ֵΪ0����Ϊ������ͬ�������Ϊ0
   ShortestPath_FLOYD(g,p,d); // ��ÿ�Զ��������·������func7-2.cpp��
   while(q)
   {
     printf("��ѡ��1 ��ѯ  0 ����\n");
     scanf("%d",&q);
     if(q)
     {
       for(i=0;i<g.vexnum;i++)
       {
         printf("%2d %-9s",i+1,g.vexs[i]);
         if(i%6==5) // ���6�����ݾͻ���
           printf("\n");
       }
       printf("\n������Ҫ��ѯ�������д��� �յ���д���: ");
       scanf("%d%d",&i,&j);
       if(d[i-1][j-1]<INFINITY) // ��ͨ·
       {
         printf("%s��%s����̾���Ϊ%d\n",g.vexs[i-1],g.vexs[j-1],d[i-1][j-1]);
         path(g,p,i-1,j-1); // �����·�����������е��յ������;�������ĳ���
       }
       else
         printf("%s��%sû��·����ͨ\n",g.vexs[i-1],g.vexs[j-1]);
       printf("��%s��%s�йص�p����:\n",g.vexs[i-1],g.vexs[j-1]);
       for(k=0;k<g.vexnum;k++)
         printf("%2d",p[i-1][j-1][k]);
       printf("\n");
     }
   }
 }
