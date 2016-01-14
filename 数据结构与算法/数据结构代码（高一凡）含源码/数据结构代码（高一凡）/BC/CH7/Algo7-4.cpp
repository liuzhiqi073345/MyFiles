 // algo7-4.cpp �������ͼ��һ���������С�ʵ���㷨7.12�ĳ���
 #include"c1.h"
 #define MAX_NAME 5 // �����ַ�������󳤶�
 typedef int InfoType;
 typedef char VertexType[MAX_NAME]; // �ַ�������
 #include"c7-21.h" // �ڽӱ�洢�ṹ
 #include"bo7-2.cpp" // �ڽӱ�洢�ṹ�Ļ�������
 #include"func7-1.cpp"

 typedef int SElemType; // ջԪ������
 #include"c3-1.h" // ˳��ջ�Ĵ洢�ṹ
 #include"bo3-1.cpp" // ˳��ջ�Ļ�������
 Status TopologicalSort(ALGraph G)
 { // ����ͼG�����ڽӱ�洢�ṹ����G�޻�·�������G�Ķ����һ���������в�����OK��
   // ���򷵻�ERROR���㷨7.12
   int i,k,count=0; // ���������������ֵΪ0
   int indegree[MAX_VERTEX_NUM]; // ������飬��Ÿ����㵱ǰ�����
   SqStack S;
   ArcNode *p;
   FindInDegree(G,indegree); // �Ը����������indegree[]����func7-1.cpp��
   InitStack(S); // ��ʼ������ȶ���ջS
   for(i=0;i<G.vexnum;++i) // �����ж���i
     if(!indegree[i]) // �������Ϊ0
       Push(S,i); // ��i������ȶ���ջS
   while(!StackEmpty(S)) // ������ȶ���ջS����
   {
     Pop(S,i); // ��ջ1������ȶ������ţ������丳��i
     printf("%s ",G.vertices[i].data); // ���i�Ŷ���
     ++count; // �����������+1
     for(p=G.vertices[i].firstarc;p;p=p->nextarc)
     { // ��i�Ŷ����ÿ���ڽӶ���
       k=p->data.adjvex; // �����Ϊk
       if(!(--indegree[k])) // k����ȼ�1������Ϊ0����k��ջS
	 Push(S,k);
     }
   }
   if(count<G.vexnum) // ����ȶ���ջS�ѿգ�ͼG���ж���δ���
   {
     printf("������ͼ�л�·\n");
     return ERROR;
   }
   else
   {
     printf("Ϊһ���������С�\n");
     return OK;
   }
 }

 void main()
 {
   ALGraph f;
   printf("��ѡ������ͼ\n");
   CreateGraph(f); // ��������ͼf����bo7-2.cpp��
   Display(f); // �������ͼf����bo7-2.cpp��
   TopologicalSort(f); // �������ͼf��1����������
 }
