 // main3-8.cpp ѭ���ҿ����Ӵ洢�ռ��˳����У�����bo3-8.cpp��������
 #include"c1.h"
 typedef int QElemType;
 #include"c3-4.h"
 #include"bo3-4.cpp" // ��������(1)�����ѭ��ͬ
 #include"bo3-8.cpp" // ��������(2)�����ѭ����ͬ

 void print(QElemType i)
 {
   printf("%d ",i);
 }

 void main()
 {
   Status j;
   int i,n=11;
   QElemType d;
   SqQueue2 Q;
   InitQueue(Q);
   printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   printf("���г���Ϊ��%d\n",QueueLength(Q));
   printf("������%d�����Ͷ���Ԫ��:\n",n);
   for(i=0;i<n;i++)
   {
     scanf("%d",&d);
     EnQueue(Q,d);
   }
   printf("���г���Ϊ��%d\n",QueueLength(Q));
   printf("���ڶ��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   printf("���ڶ����е�Ԫ��Ϊ: \n");
   QueueTraverse(Q,print);
   for(i=1;i<=3;i++)
     DeQueue(Q,d);
   printf("�ɶ�ͷɾ��3��Ԫ�أ����ɾ����Ԫ��Ϊ%d\n",d);
   printf("���ڶ����е�Ԫ��Ϊ: \n");
   QueueTraverse(Q,print);
   j=GetHead(Q,d);
   if(j)
     printf("��ͷԪ��Ϊ: %d\n",d);
   else
     printf("�޶�ͷԪ��(�ն���)\n");
   for(i=1;i<=5;i++)
     EnQueue(Q,i);
   printf("�������β����1��5�����ڶ����е�Ԫ��Ϊ: \n");
   QueueTraverse(Q,print);
   ClearQueue(Q);
   printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   j=GetHead(Q,d);
   if(j)
     printf("��ͷԪ��Ϊ: %d\n",d);
   else
     printf("�޶�ͷԪ��(�ն���)\n");
   DestroyQueue(Q);
 }
