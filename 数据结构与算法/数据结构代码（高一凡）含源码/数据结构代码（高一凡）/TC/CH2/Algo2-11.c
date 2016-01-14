 /* algo2-11.c ʵ���㷨2.20��2.21�ĳ��� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-5.h"
 #include"bo2-6.c"
 #include"func2-3.c" /* ����equal()��comp()��print()��print2()��print1()���� */

 Status ListInsert_L(LinkList *L,int i,ElemType e) /* �㷨2.20 */
 { /* �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e */
   Link h,s;
   if(!LocatePos(*L,i-1,&h))
     return ERROR; /* iֵ���Ϸ� */
   MakeNode(&s,e); /* ������ʧ�����˳� */
   InsFirst(L,h,s); /* ���ڴӵ�i����㿪ʼ��������i-1�����������ͷ��� */
   return OK;
 }

 void MergeList_L(LinkList *La,LinkList *Lb,LinkList *Lc,int(*compare)(ElemType,ElemType))
 { /* ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С��鲢La��Lb�õ��µĵ��� */
   /* ���Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С��㷨2.21 */
   Link ha,hb,pa,pb,q;
   ElemType a,b;
   InitList(Lc); /* �洢�ռ����ʧ�����˳� */
   ha=GetHead(*La); /* ha��hb�ֱ�ָ��La��Lb��ͷ��� */
   hb=GetHead(*Lb);
   pa=NextPos(ha); /* pa��pb�ֱ�ָ��La��Lb����Ԫ��� */
   pb=NextPos(hb);
   while(pa&&pb) /* La��Lb���ǿ� */
   {
     a=GetCurElem(pa); /* a��bΪ�����е�ǰ�Ƚ�Ԫ��(��1��Ԫ��) */
     b=GetCurElem(pb);
     if(compare(a,b)<=0) /* a<=b */
     {
       DelFirst(La,ha,&q); /* ��ȥLa����Ԫ��㲢��q���� */
       q->next=NULL; /* ��q��next��ֵNULL���Ա����Append() */
       Append(Lc,q); /* ��q������Lc��β�� */
       pa=NextPos(ha); /* paָ��La�µ���Ԫ��� */
     }
     else /* a>b */
     {
       DelFirst(Lb,hb,&q); /* ��ȥLb����Ԫ��㲢��q���� */
       q->next=NULL; /* ��q��next��ֵNULL���Ա����Append() */
       Append(Lc,q); /* ��q������Lc��β�� */
       pb=NextPos(hb); /* pbָ��Lb�µ���Ԫ��� */
     }
   }
   if(pa) /* La�ǿ� */
     Append(Lc,pa); /* ����La��ʣ���� */
   else /* Lb�ǿ� */
     Append(Lc,pb); /* ����Lb��ʣ���� */
   free(ha); /* ����La��Lb */
   (*La).head=(*La).tail=NULL;
   (*La).len=0;
   free(hb);
   (*Lb).head=(*Lb).tail=NULL;
   (*Lb).len=0;
 }
 int diff(ElemType c1,ElemType c2)
 {
   return c1-c2;
 }

 void main()
 {
   LinkList La,Lb,Lc;
   int j;
   InitList(&La);
   for(j=1;j<=5;j++)
     ListInsert_L(&La,j,j); /* ˳����� 1��2��3��4��5 */
   printf("La=");
   ListTraverse(La,print);
   InitList(&Lb);
   for(j=1;j<=5;j++)
     ListInsert_L(&Lb,j,2*j); /* ˳����� 2��4��6��8��10 */
   printf("Lb=");
   ListTraverse(Lb,print);
   MergeList_L(&La,&Lb,&Lc,diff); /* �鲢La��Lb������Lc */
   printf("Lc=");
   ListTraverse(Lc,print);
   DestroyList(&Lc);
 }