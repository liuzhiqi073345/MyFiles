 // algo3-7.cpp ���ʽ��ֵ(��ΧΪint���ͣ����븺��Ҫ��(0-����)��ʾ)
 typedef int SElemType; // ջԪ������Ϊ���ͣ���algo3-6.cpp
 #include"c1.h"
 #include"c3-1.h" // ˳��ջ�Ĵ洢�ṹ
 #include"bo3-1.cpp" // ˳��ջ�Ļ�������
 #include"func3-2.cpp"

 SElemType EvaluateExpression()
 { // �������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ
   SqStack OPTR,OPND;
   SElemType a,b,d,x; // ��algo3-6.cpp
   char c; // ����ɼ��̽��յ��ַ�����algo3-6.cpp
   char z[11]; // ��������ַ�������algo3-6.cpp
   int i; // ��algo3-6.cpp
   InitStack(OPTR); // ��ʼ�������ջOPTR��������ջOPND
   InitStack(OPND);
   Push(OPTR,'\n'); // �����з�ѹ�������ջOPTR��ջ��(��)
   c=getchar(); // �ɼ��̶���1���ַ���c
   GetTop(OPTR,x); // �������ջOPTR��ջ��Ԫ�ظ���x
   while(c!='\n'||x!='\n') // c��x�����ǻ��з�
   {
     if(In(c)) // c��7�������֮һ
       switch(Precede(x,c)) // �ж�x��c������Ȩ
       {
         case'<' :Push(OPTR,c); // ջ��Ԫ��x������Ȩ�ͣ���ջc
                  c=getchar();  // �ɼ��̶�����һ���ַ���c
                  break;
         case'=' :Pop(OPTR,x); // x='('��c=')'���������'('��x(�����ӵ�)
                  c=getchar(); // �ɼ��̶�����һ���ַ���c(�ӵ�')')
                  break;
         case'>' :Pop(OPTR,x); // ջ��Ԫ��x������Ȩ�ߣ����������ջOPTR��ջ��Ԫ�ظ�x(��)
                  Pop(OPND,b); // ���ε���������ջOPND��ջ��Ԫ�ظ�b��a
                  Pop(OPND,a);
                  Push(OPND,Operate(a,x,b)); // ������a x b��������������������ջ
       }
     else if(c>='0'&&c<='9') // c�ǲ�������������algo3-6.cpp
     {
       i=0;
       while(c>='0'&&c<='9') // ����������
       {
         z[i++]=c;
         c=getchar();
       }
       z[i]=0; // �ַ���������
       d=atoi(z); // ��z�б������ֵ���ַ���תΪ���ʹ���d
       Push(OPND,d); // ��dѹ��������ջOPND
     }
     else // c�ǷǷ��ַ�������ͬalgo3-6.cpp
     {
       printf("���ַǷ��ַ�\n");
       exit(ERROR);
     }
     GetTop(OPTR,x); // �������ջOPTR��ջ��Ԫ�ظ���x
   }
   Pop(OPND,x); // ����������ջOPND��ջ��Ԫ��(������)��x(�Ĵ˴�)
   if(!StackEmpty(OPND)) // ������ջOPND����(�����ջOPTR��ʣ'\n')
   {
     printf("���ʽ����ȷ\n");
     exit(ERROR);
   }
   return x;
 }

 void main()
 {
   printf("�������������ʽ,����Ҫ��(0-����)��ʾ\n");
   printf("%d\n",EvaluateExpression());
 }
