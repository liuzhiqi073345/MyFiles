 // algo5-2.cpp �䳤������(������ʵ�θ����ɱ�)���ʾ��
 #include"c1.h"
 #include<stdarg.h> // ʵ�ֱ䳤������Ҫ������ͷ�ļ�
 typedef int ElemType; 
 ElemType Max(int num,...) // ...��ʾ�䳤������λ���βα�����,ǰ�����������һ���̶�����
 { // �������ܣ�����num�����е����ֵ
   va_list ap; // ����ap�Ǳ䳤����������(C���Ե���������)
   int i;
   ElemType m,n;
   if(num<1)
     exit(ERROR);
   va_start(ap,num); // apָ��̶�����num�����ʵ�α�
   m=va_arg(ap,ElemType); // ���ζ�ȡap��ָ��ʵ��(�Զ���Ϊ�ָ���)��ΪElemType����ʵ��,ap�����
   for(i=1;i<num;++i)
   {
     n=va_arg(ap,ElemType); // ͬ��
     if(m<n)
       m=n;
   }
   va_end(ap); // ��va_start()��ԣ������Ա䳤������Ķ�ȡ��ap����ָ��䳤������
   return m;
 }

 void main()
 {
   printf("1.���ֵΪ%d\n",Max(4,7,9,5,8)); // ��4�����������ֵ��ap���ָ��7,9,5,8��
   printf("2.���ֵΪ%d\n",Max(3,17,36,25)); // ��3�����������ֵ��ap���ָ��17,36,25��
 }
