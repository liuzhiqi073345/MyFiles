 // algo7-1.cpp �����㷨7.7��7.8
 #include"c1.h"
 #define MAX_NAME 2 // �����ַ�������󳤶�+1
 typedef char VertexType[MAX_NAME];
 typedef VertexType TElemType; // ��������Ԫ������Ϊͼ�Ķ�������
 #include"c6-5.h" // ���ӣ��ֵܶ�������洢�ṹ
 #include"func6-2.cpp" // ���ӣ��ֵܶ�������洢�ṹ���ȸ���������
 typedef int InfoType; // Ȩֵ����
 #include"c7-21.h" // bo7-2.cpp���õĴ洢����
 #include"bo7-2.cpp" // �ڽӱ�Ļ�������

 void DFSTree(ALGraph G,int v,CSTree &T)
 { // �ӵ�v���������������ȱ���ͼG��������TΪ�������������㷨7.8
   Boolean first=TRUE;
   int w;
   CSTree p,q;
   visited[v]=TRUE;
   for(w=FirstAdjVex(G,G.vertices[v].data);w>=0;w=NextAdjVex(G,G.vertices[v].data,G.vertices[w].data)) // w����Ϊv���ڽӶ���
     if(!visited[w]) // w���㲻��������
     {
       p=(CSTree)malloc(sizeof(CSNode)); // ���亢�ӽ��
       strcpy(p->data,G.vertices[w].data);
       p->firstchild=NULL;
       p->nextsibling=NULL;
       if(first)
       { // w��v�ĵ�һ��δ�����ʵ��ڽӶ���
         T->firstchild=p;
         first=FALSE; // �Ǹ��ĵ�һ�����ӽ��
       }
       else // w��v������δ�����ʵ��ڽӶ���
	 q->nextsibling=p; // ����һ�ڽӶ�����ֵܽ��ý��(��1�β�ͨ���˴����Ժ�q�Ѹ�ֵ)
       q=p;
       DFSTree(G,w,q); // �ӵ�w���������������ȱ���ͼG��������������q
     }
 }

 void DFSForest(ALGraph G,CSTree &T)
 { // ��������ͼG�������������ɭ�ֵ�(����)����(��)�ֵ�����T���㷨7.7
   CSTree p,q;
   int v;
   T=NULL;
   for(v=0;v<G.vexnum;++v)
     visited[v]=FALSE; // ����ֵ��visited[]��bo7-2.cpp�ж���
   for(v=0;v<G.vexnum;++v) // �ӵ�0����������
     if(!visited[v]) // ��v�����㲻��������
     { // ��v����Ϊ�µ��������ĸ����
       p=(CSTree)malloc(sizeof(CSNode)); // ��������
       strcpy(p->data,G.vertices[v].data);
       p->firstchild=NULL;
       p->nextsibling=NULL;
       if(!T) // �ǵ�һ���������ĸ�(T�ĸ�)
         T=p;
       else // �������������ĸ�(ǰһ�õĸ��ģ��ֵܣ�)
	 q->nextsibling=p; // ��1�β�ͨ���˴����Ժ�q�Ѹ�ֵ
       q=p; // qָʾ��ǰ�������ĸ�
       DFSTree(G,v,p); // ������pΪ����������
     }
 }

 void print(char *i)
 {
   printf("%s ",i);
 }

 void main()
 {
   ALGraph g;
   CSTree t;
   printf("��ѡ������ͼ\n");
   CreateGraph(g); // ��������ͼg
   Display(g); // �������ͼg
   DFSForest(g,t); // ��������ͼg�������������ɭ�ֵĺ��ӡ��ֵ�����t
   printf("�����������ɭ�֣�\n");
   PreOrderTraverse(t,print); // �����������ɭ�ֵĺ��ӡ��ֵ�����t
   printf("\n");
 }
