 /* algo2-4.c �޸��㷨2.7�ĵ�һ��ѭ������е��������Ϊ������䣬�ҵ� */
 /* *pa=*pbʱ��ֻ��������֮һ����Lc���˲����Ľ�����㷨2.1��ͬ */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h"
 #include"bo2-1.c"
 #include"func2-3.c" /* ����equal()��comp()��print()��print2()��print1()���� */

 void MergeList(SqList La,SqList Lb,SqList *Lc)
 { /* ��һ�ֺϲ����Ա�ķ���(�����㷨2.7�µ�Ҫ���޸��㷨2.7)��La��Lb��Lc��Ϊ���������еı� */
   ElemType  *pa,*pa_last,*pb,*pb_last,*pc;
   pa=La.elem;
   pb=Lb.elem;
   (*Lc).listsize=La.length+Lb.length; /* �˾����㷨2.7��ͬ */
   pc=(*Lc).elem=(ElemType *)malloc((*Lc).listsize*sizeof(ElemType));
   if(!(*Lc).elem)
     exit(OVERFLOW);
   pa_last=La.elem+La.length-1;
   pb_last=Lb.elem+Lb.length-1;
   while(pa<=pa_last&&pb<=pb_last) /* ��La�ͱ�Lb���ǿ� */
     switch(comp(*pa,*pb)) /* �˾����㷨2.7��ͬ */
     {
       case  0: pb++;
       case -1: *pc++=*pa++;
                break;
       case  1: *pc++=*pb++;
     }
   while(pa<=pa_last) /* ��La�ǿ��ұ�Lb�� */
     *pc++=*pa++;
   while(pb<=pb_last) /* ��Lb�ǿ��ұ�La�� */
     *pc++=*pb++;
   (*Lc).length=pc-(*Lc).elem; /* �Ӵ˾� */
 }

 void main()
 {
   SqList La,Lb,Lc;
   int j;
   InitList(&La); /* �����ձ�La */
   for(j=1;j<=5;j++) /* �ڱ�La�в���5��Ԫ�أ�����Ϊ1��2��3��4��5 */
     ListInsert(&La,j,j);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print1);
   InitList(&Lb); /* �����ձ�Lb */
   for(j=1;j<=5;j++) /* �ڱ�Lb�в���5��Ԫ�أ�����Ϊ2��4��6��8��10 */
     ListInsert(&Lb,j,2*j);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print1);
   MergeList(La,Lb,&Lc); /* �ɰ��������еı�La��Lb�õ����������еı�Lc */
   printf("Lc= "); /* �����Lc������ */
   ListTraverse(Lc,print1);
 }
