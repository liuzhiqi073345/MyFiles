 // bo3-8.cpp ѭ������(�洢�ṹ��c3-4.h����)�Ļ�������(4��)
 int QueueLength(SqQueue2 Q)
 { // ����Q��Ԫ�ظ����������еĳ���
   return(Q.rear-Q.front+Q.queuesize)%Q.queuesize;
 }

 void EnQueue(SqQueue2 &Q,QElemType e)
 { // ����Ԫ��eΪQ���µĶ�βԪ��
   int i;
   if((Q.rear+1)%Q.queuesize==Q.front)
   { // �����������Ӵ洢��Ԫ
     Q.base=(QElemType *)realloc(Q.base,(Q.queuesize+QUEUE_INCREMENT)*sizeof(QElemType));
     if(!Q.base) // ���ӵ�Ԫʧ��
       exit(ERROR);
     if(Q.front>Q.rear) // �γ�ѭ��
     {
       for(i=Q.queuesize-1;i>=Q.front;i--)
         Q.base[i+QUEUE_INCREMENT]=Q.base[i]; // �ƶ��߶�Ԫ�ص��µĸ߶�
       Q.front+=QUEUE_INCREMENT; // �ƶ���ͷָ��
     }
     Q.queuesize+=QUEUE_INCREMENT; // ���Ӷ��г���
   }
   Q.base[Q.rear]=e; // ��e�����β
   Q.rear=++Q.rear%Q.queuesize; // �ƶ���βָ��
 }

 Status DeQueue(SqQueue2 &Q,QElemType &e)
 { // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
   if(Q.front==Q.rear) // ���п�
     return ERROR;
   e=Q.base[Q.front]; // ��e���ض�ͷԪ��
   Q.front=++Q.front%Q.queuesize; // �ƶ���ͷָ��
   return OK;
 }

 void QueueTraverse(SqQueue2 Q,void(*vi)(QElemType))
 { // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()
   int i=Q.front; // iָ���ͷ
   while(i!=Q.rear) // û����β
   {
     vi(Q.base[i]); // ���ú���vi()
     i=++i%Q.queuesize; // ����ƶ�iָ��
   }
   printf("\n");
 }

