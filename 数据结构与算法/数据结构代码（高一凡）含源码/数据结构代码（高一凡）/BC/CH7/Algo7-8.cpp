 // algo7-8.cpp ��³˹�����㷨��������ͨ������С�������ĳ���
 #include"c1.h"
 typedef int VRType;
 typedef char InfoType;
 #define MAX_NAME 3 // �����ַ�������󳤶�+1
 #define MAX_INFO 20 // �����Ϣ�ַ�������󳤶�+1
 typedef char VertexType[MAX_NAME];
 #include"c7-1.h"
 #include"bo7-1.cpp"
 void kruskal(MGraph G)
 {
   int set[MAX_VERTEX_NUM],i,j;
   int k=0,a=0,b=0,min=G.arcs[a][b].adj;
   for(i=0;i<G.vexnum;i++)
     set[i]=i; // ��̬��������ֱ����ڸ�������
   printf("��С�����������ĸ�����Ϊ:\n");
   while(k<G.vexnum-1) // ��С�������ı���С�ڶ�����-1
   { // Ѱ����СȨֵ�ı�
     for(i=0;i<G.vexnum;++i)
       for(j=i+1;j<G.vexnum;++j) // ��������ֻ�������ǲ���
	 if(G.arcs[i][j].adj<min)
	 {
	   min=G.arcs[i][j].adj; // ��СȨֵ
	   a=i; // �ߵ�һ������
	   b=j; // �ߵ���һ������
	 }
     min=G.arcs[a][b].adj=INFINITY; // ɾ���������иñߣ��´β��ٲ���
     if(set[a]!=set[b]) // �ߵ������㲻����ͬһ����
     {
       printf("%s-%s\n",G.vexs[a],G.vexs[b]); // ����ñ�
       k++; // ����+1
       for(i=0;i<G.vexnum;i++)
         if(set[i]==set[b]) // ������b���ڼ��ϲ��붥��a������
           set[i]=set[a];
     }
   }
 }

 void main()
 {
   MGraph g;
   CreateUDN(g); // ����������g
   Display(g); // ���������g
   kruskal(g); // �ÿ�³˹�����㷨���g����С�������ĸ�����
 }
