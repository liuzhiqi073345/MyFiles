 // algo3-6.cpp ���ʽ��ֵ(�����ֵ��0��9֮�䣬�м����������ֵ��-128��127֮��)���㷨3.4
 typedef char SElemType; // ջԪ��Ϊ�ַ���
 #include"c1.h"
 #include"c3-1.h"
 #include"bo3-1.cpp"
 #include"func3-2.cpp"

 SElemType EvaluateExpression() // �㷨3.4���иĶ�
 { // �������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ
   SqStack OPTR,OPND;
   SElemType a,b,c,x;
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
     else if(c>='0'&&c<='9') // c�ǲ�����
     {
       Push(OPND,c-48); // ���ò�������ֵ(����ASCII��)ѹ��������ջOPND
       c=getchar(); // �ɼ��̶�����һ���ַ���c
     }
     else // c�ǷǷ��ַ�
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
   printf("�������������ʽ(�����ֵҪ��0��9֮�䡢�м�����ֵ����������-128��127֮��)\n");
   printf("%d\n",EvaluateExpression()); // ����ֵ(8λ2���ƣ�1���ֽ�)�����͸�ʽ���
 }
