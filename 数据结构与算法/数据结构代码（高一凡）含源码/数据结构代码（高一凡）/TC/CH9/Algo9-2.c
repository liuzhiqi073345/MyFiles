 /* algo9-2.c ����bo9-1.c(�������)�ĳ��� */
 #include"c1.h"
 #define N 11 /* ����Ԫ�ظ��� */
 typedef int KeyType; /* ��ؼ�����Ϊ���� */
 typedef struct
 {
   KeyType key; /* ���йؼ����� */
 }ElemType; /* ����Ԫ������ */
 #include"c9-7.h"
 #include"c9-1.h"
 #include"bo9-1.c"

 void print(ElemType c) /* Traverse()���õĺ��� */
 {
   printf("%d ",c.key);
 }

 void main()
 {
   SSTable st;
   int i;
   KeyType s;
   ElemType r[N]={5,13,19,21,37,56,64,75,80,88,92}; /* ����Ԫ��(�Խ̿���p.219������Ϊ��) */
   Creat_Ord(&st,r,N); /* ��ȫ����������ǽ���̬���ұ�st */
   Traverse(st,print); /* ˳������ǽ���̬���ұ�st */
   printf("\n");
   printf("�����������ֵ�Ĺؼ���: ");
   scanf("%d",&s);
   i=Search_Bin(st,s); /* �۰��������� */
   if(i)
     printf("%d �ǵ�%d����¼�Ĺؼ���\n",st.elem[i].key,i);
   else
     printf("û�ҵ�\n");
   Destroy(&st);
 }
