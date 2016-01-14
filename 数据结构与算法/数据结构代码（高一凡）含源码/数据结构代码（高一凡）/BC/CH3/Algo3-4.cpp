 // algo3-4.cpp �б༭����ʵ���㷨3.2
 typedef char SElemType;
 #include"c1.h"
 #include"c3-1.h"
 #include"bo3-1.cpp"
 FILE *fp;

 void copy(SElemType c)
 { // ���ַ�c����fp��ָ���ļ���
   fputc(c,fp);
 }

 void LineEdit()
 { // �����ַ�ջs�����ն˽���һ�в��������ù��̵����������㷨3.2
   SqStack s;
   char ch;
   InitStack(s);
   printf("������һ���ı��ļ�,^Z��������:\n");
   ch=getchar();
   while(ch!=EOF)
   { // ��ȫ��û����(EOFΪ^Z����ȫ�Ľ�����)
     while(ch!=EOF&&ch!='\n')
     { // ��ȫ��û������û����ĩ(���ǻ��з�)
       switch(ch)
       {
         case '#':if(!StackEmpty(s))
                    Pop(s,ch); // ����ջ�ǿ�ʱ��ջ,c����ch���
                  break;
         case '@':ClearStack(s); // ����sΪ��ջ
                  break;
         default :Push(s,ch); // �����ַ���ջ
       }
       ch=getchar(); // ���ն˽�����һ���ַ�
     }
     StackTraverse(s,copy); // ����ջ�׵�ջ����ջ���ַ��������ļ�
     fputc('\n',fp); // ���ļ�����һ�����з�
     ClearStack(s); // ����sΪ��ջ
     if(ch!=EOF)
       ch=getchar();
   }
   DestroyStack(s);
 }

 void main()
 {
   fp=fopen("ed.txt","w"); // �ڵ�ǰĿ¼�½���ed.txt�ļ�������д���ݣ�
   if(fp)                  // ������ͬ���ļ�����ɾ��ԭ�ļ�
   {
     LineEdit();
     fclose(fp); // �ر�fp��ָ���ļ�
   }
   else
     printf("�����ļ�ʧ��!\n");
 }
