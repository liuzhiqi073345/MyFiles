 /* main3-4.c ˳�����(��ѭ��)������bo3-4.c��bo3-9.c�������� */
 #include"c1.h"
 typedef int QElemType;
 #include"c3-4.h"
 #include"bo3-4.c" /* ��������(1) */
 #include"bo3-9.c" /* ��������(2) */

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
   InitQueue(&Q);
   printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   printf("���г���Ϊ��%d\n",QueueLength(Q));
   printf("������%d�����Ͷ���Ԫ��:\n",n);
   for(i=0;i<n;i++)
   {
     scanf("%d",&d);
     EnQueue(&Q,d);
   }
   printf("���г���Ϊ��%d\n",QueueLength(Q));
   printf("���ڶ��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   printf("���ڶ����е�Ԫ��Ϊ: \n");
   QueueTraverse(Q,print);
   DeQueue(&Q,&d);
   printf("ɾ����ͷԪ��%d\n",d);
   printf("�����е�Ԫ��Ϊ: \n");
   QueueTraverse(Q,print);
   j=GetHead(Q,&d);
   if(j)
     printf("��ͷԪ��Ϊ: %d\n",d);
   else
     printf("�޶�ͷԪ��(�ն���)\n");
   ClearQueue(&Q);
   printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
   j=GetHead(Q,&d);
   if(j)
     printf("��ͷԪ��Ϊ: %d\n",d);
   else
     printf("�޶�ͷԪ��(�ն���)\n");
   DestroyQueue(&Q);
 }
