 /* main6-6.c ����bo6-6.c�������� */
 #define CHAR /* �ַ��� */
 /* #define INT /* ����(����ѡһ) */
 #ifdef CHAR
   typedef char TElemType;
   TElemType Nil=' '; /* �ַ����Կո��Ϊ�� */
   #define form "%c" /* ��������ĸ�ʽΪ%c */
 #endif
 #ifdef INT
   typedef int TElemType;
   TElemType Nil=0; /* ������0Ϊ�� */
   #define form "%d" /* ��������ĸ�ʽΪ%d */
 #endif
 #include"c1.h"
 #include"c6-6.h"
 #include"bo6-6.c"

 void visitT(BiPTree T)
 {
   if(T) /* T�ǿ� */
     printf(form" ",T->data);
 }

 void main()
 {
   int i;
   BiPTree T,c,q;
   TElemType e1,e2;
   InitBiTree(&T);
   printf("����ն�������,���շ�%d(1:�� 0:��)�������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
   e1=Root(T);
   if(e1!=Nil)
     printf("�������ĸ�Ϊ: "form"\n",e1);
   else
     printf("���գ��޸�\n");
 #ifdef CHAR
   printf("�밴�������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
 #endif
 #ifdef INT
   printf("�밴�������������(��:1 2 0 0 0��ʾ1Ϊ�����,2Ϊ�������Ķ�����)\n");
 #endif
   CreateBiTree(&T);
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
   printf("\n�������������:\n");
   LevelOrderTraverse(T,visitT);
   printf("\n������һ������ֵ: ");
   scanf("%*c"form,&e1);
   c=Point(T,e1); /* cΪe1��ָ�� */
   printf("����ֵΪ"form"\n",Value(c));
   printf("���ı�˽���ֵ����������ֵ: ");
   scanf("%*c"form"%*c",&e2);
   Assign(c,e2);
   printf("�������������:\n");
   LevelOrderTraverse(T,visitT);
   e1=Parent(T,e2);
   if(e1!=Nil)
     printf("\n"form"��˫����"form"\n",e2,e1);
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
   InitBiTree(&c);
   printf("����һ��������Ϊ�յĶ�����c:\n");
 #ifdef CHAR
   printf("���������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
 #endif
 #ifdef INT
   printf("���������������(��:1 2 0 0 0��ʾ1Ϊ�����,2Ϊ�������Ķ�����)\n");
 #endif
   CreateBiTree(&c);
   printf("����ݹ����������c:\n");
   PreOrderTraverse(c,visitT);
   printf("\n��c�嵽��T��,��������T����c��˫�׽�� cΪ��(0)����(1)����: ");
   scanf("%*c"form"%d",&e1,&i);
   q=Point(T,e1);
   InsertChild(q,i,c);
   printf("����ݹ����������:\n");
   PreOrderTraverse(T,visitT);
   printf("\nɾ������,�������ɾ��������˫�׽��  ��(0)����(1)����: ");
   scanf("%*c"form"%d",&e1,&i);
   q=Point(T,e1);
   DeleteChild(q,i);
   printf("����ݹ����������:\n");
   PreOrderTraverse(T,visitT);
   printf("\n");
   DestroyBiTree(&T);
 }
