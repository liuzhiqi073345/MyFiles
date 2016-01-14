 // bo3-9.cpp ˳���ѭ������(�洢�ṹ��c3-4.h����)�Ļ�������(4��)
 int QueueLength(SqQueue2 Q)
 { // ����Q��Ԫ�ظ����������еĳ���
   return(Q.rear-Q.front);
 }

 void EnQueue(SqQueue2 &Q,QElemType e)
 { // ����Ԫ��eΪQ���µĶ�βԪ��
   if(Q.rear==Q.queuesize)
   { // �����������Ӵ洢��Ԫ
     Q.base=(QElemType *)realloc(Q.base,(Q.queuesize+QUEUE_INCREMENT)*sizeof(QElemType));
     if(!Q.base) // ���ӵ�Ԫʧ��
       exit(ERROR);
   }
   Q.base[Q.rear++]=e;
 }

 Status DeQueue(SqQueue2 &Q,QElemType &e)
 { // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
   if(Q.front==Q.rear) // ���п�
     return ERROR;
   e=Q.base[Q.front++];
   return OK;
 }

 void QueueTraverse(SqQueue2 Q,void(*vi)(QElemType))
 { // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()
   int i=Q.front;
   while(i!=Q.rear)
     vi(Q.base[i++]);
   printf("\n");
 }