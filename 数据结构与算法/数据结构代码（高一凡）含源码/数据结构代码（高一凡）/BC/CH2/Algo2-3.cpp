 // algo2-3.cpp ʵ���㷨2.7�ĳ���
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h"
 #include"bo2-1.cpp"
 #include"func2-3.cpp" // ����equal()��comp()��print()��print2()��print1()����
 void MergeList(SqList La,SqList Lb,SqList &Lc) // �㷨2.7
 { // ��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
   // �鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
   ElemType *pa,*pa_last,*pb,*pb_last,*pc;
   pa=La.elem;
   pb=Lb.elem;
   Lc.listsize=Lc.length=La.length+Lb.length; // ����InitList()�����ձ�Lc
   pc=Lc.elem=(ElemType *)malloc(Lc.listsize*sizeof(ElemType));
   if(!Lc.elem) // �洢����ʧ��
     exit(OVERFLOW);
   pa_last=La.elem+La.length-1;
   pb_last=Lb.elem+Lb.length-1;
   while(pa<=pa_last&&pb<=pb_last) // ��La�ͱ�Lb���ǿ�
   { // �鲢
     if(*pa<=*pb)
       *pc++=*pa++; // ��pa��ָ��Ԫ��ֵ����pc��ָ��Ԫ��pa��pc�ֱ�+1(ָ����һ����Ԫ)
     else
       *pc++=*pb++; // ��pb��ָ��Ԫ��ֵ����pc��ָ��Ԫ��pa��pc�ֱ�+1(ָ����һ����Ԫ)
   } // ��������whileѭ��ֻ����һ����ִ��
   while(pa<=pa_last) // ��La�ǿ��ұ�Lb��
     *pc++=*pa++; // ����La��ʣ��Ԫ��
   while(pb<=pb_last) // ��Lb�ǿ��ұ�La��
     *pc++=*pb++; // ����Lb��ʣ��Ԫ��
 }

 void main()
 {
   SqList La,Lb,Lc;
   int j;
   InitList(La); // �����ձ�La
   for(j=1;j<=5;j++) // �ڱ�La�в���5��Ԫ�أ�����Ϊ1��2��3��4��5
     ListInsert(La,j,j);
   printf("La= "); // �����La������
   ListTraverse(La,print1);
   InitList(Lb); // �����ձ�Lb
   for(j=1;j<=5;j++) // �ڱ�Lb�в���5��Ԫ�أ�����Ϊ2��4��6��8��10
     ListInsert(Lb,j,2*j);
   printf("Lb= "); // �����Lb������
   ListTraverse(Lb,print1); // �ɰ��ǵݼ����еı�La��Lb�õ����ǵݼ����еı�Lc
   MergeList(La,Lb,Lc);
   printf("Lc= "); // �����Lc������
   ListTraverse(Lc,print1);
 }
