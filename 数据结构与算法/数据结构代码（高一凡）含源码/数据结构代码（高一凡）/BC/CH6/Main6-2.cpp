 // main6-2.cpp ����bo6-2.cpp��������������������ѡ����������(��һ�ַ���)
 #define CHAR // �ַ���
 // #define INT // ����(����ѡһ)
 #include"c1.h"
 #ifdef CHAR
   typedef char TElemType;
   TElemType Nil=' '; // �ַ����Կո��Ϊ��
   #define form "%c" // ��������ĸ�ʽΪ%c
 #endif
 #ifdef INT
   typedef int TElemType;
   TElemType Nil=0; // ������0Ϊ��
   #define form "%d" // ��������ĸ�ʽΪ%d
 #endif
 #include"c6-2.h"
 #include"bo6-2.cpp"

 void visitT(TElemType e)
 {
   printf(form" ",e);
 }

 void main()
 {
   int i;
   BiTree T,p,c;
   TElemType e1,e2;
   InitBiTree(T);
   printf("����ն�������,���շ�%d(1:�� 0:��)�������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
     printf("�������ĸ�Ϊ: "form"\n",e1);
   else
     printf("���գ��޸�\n");
 #ifdef CHAR
   printf("���������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
 #endif
 #ifdef INT
   printf("���������������(��:1 2 0 0 0��ʾ1Ϊ�����,2Ϊ�������Ķ�����)\n");
 #endif
   CreateBiTree(T);
   printf("������������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
     printf("�������ĸ�Ϊ: "form"\n",e1);
   else
     printf("���գ��޸�\n");
   printf("����ݹ����������:\n");
   InOrderTraverse(T,visitT);
   printf("\n����ݹ����������:\n");
   PostOrderTraverse(T,visitT);
   printf("\n������һ������ֵ: ");
   scanf("%*c"form,&e1);
   p=Point(T,e1); // pΪe1��ָ��
   printf("����ֵΪ"form"\n",Value(p));
   printf("���ı�˽���ֵ����������ֵ: ");
   scanf("%*c"form"%*c",&e2); // ��һ��%*c�Ե��س�����Ϊ����CreateBiTree()��׼��
   Assign(p,e2);
   printf("�������������:\n");
   LevelOrderTraverse(T,visitT);
   e1=Parent(T,e2);
   if(e1!=Nil)
     printf("%c��˫����"form"\n",e2,e1);
   else
     printf(form"û��˫��\n",e2);
   e1=LeftChild(T,e2);
   if(e1!=Nil)
     printf(form"��������"form"\n",e2,e1);
   else
     printf(form"û������\n",e2);
   e1=RightChild(T,e2);
   if(e1!=Nil)
     printf(form"���Һ�����"form"\n",e2,e1);
   else
     printf(form"û���Һ���\n",e2);
   e1=LeftSibling(T,e2);
   if(e1!=Nil)
     printf(form"�����ֵ���"form"\n",e2,e1);
   else
     printf(form"û�����ֵ�\n",e2);
   e1=RightSibling(T,e2);
   if(e1!=Nil)
     printf(form"�����ֵ���"form"\n",e2,e1);
   else
     printf(form"û�����ֵ�\n",e2);
   InitBiTree(c);
   printf("����һ��������Ϊ�յĶ�����c:\n");
 #ifdef CHAR
   printf("���������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
 #endif
 #ifdef INT
   printf("���������������(��:1 2 0 0 0��ʾ1Ϊ�����,2Ϊ�������Ķ�����)\n");
 #endif
   CreateBiTree(c);
   printf("����ݹ����������c:\n");
   PreOrderTraverse(c,visitT);
   printf("\n�������������c:\n");
   LevelOrderTraverse(c,visitT);
   printf("��c�嵽��T��,��������T����c��˫�׽�� cΪ��(0)����(1)����: ");
   scanf("%*c"form"%d",&e1,&i);
   p=Point(T,e1); // p��T����c��˫�׽��ָ��
   InsertChild(p,i,c);
   printf("����ݹ����������:\n");
   PreOrderTraverse(T,visitT);
   printf("\n����ǵݹ����������:\n");
   InOrderTraverse1(T,visitT);
   printf("ɾ������,�������ɾ��������˫�׽��  ��(0)����(1)����: ");
   scanf("%*c"form"%d",&e1,&i);
   p=Point(T,e1);
   DeleteChild(p,i);
   printf("����ݹ����������:\n");
   PreOrderTraverse(T,visitT);
   printf("\n����ǵݹ����������(��һ�ַ���):\n");
   InOrderTraverse2(T,visitT);
   DestroyBiTree(T);
 }