 /* algo2-10.c ���������βָ���ѭ������ĺϲ�(�̿���ͼ2.13) */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-2.h"
 #include"bo2-4.c"
 #include"func2-3.c" /* ����equal()��comp()��print()��print2()��print1()���� */

 void MergeList(LinkList *La,LinkList Lb)
 { /* ��Lb�ϲ���La�ı�β����Laָʾ�±� */
   LinkList p=Lb->next;
   Lb->next=(*La)->next;
   (*La)->next=p->next;
   free(p);
   *La=Lb;
 }

 void main()
 {
   int n=5,i;
   LinkList La,Lb;
   InitList(&La);
   for(i=1;i<=n;i++)
     ListInsert(&La,i,i);
   printf("La="); /* �������La������ */
   ListTraverse(La,print);
   InitList(&Lb);
   for(i=1;i<=n;i++)
     ListInsert(&Lb,1,i*2);
   printf("Lb="); /* �������Lb������ */
   ListTraverse(Lb,print);
   MergeList(&La,Lb);
   printf("La+Lb="); /* ����ϲ������������� */
   ListTraverse(La,print);
 }
