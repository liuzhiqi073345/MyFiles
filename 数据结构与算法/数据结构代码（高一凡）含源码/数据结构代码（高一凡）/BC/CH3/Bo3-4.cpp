 // bo3-4.cpp ˳�����(�洢�ṹ��c3-4.h����)�Ļ�������(5��)
 void InitQueue(SqQueue2 &Q)
 { // ����һ���ն���Q
   if(!(Q.base=(QElemType *)malloc(QUEUE_INIT_SIZE*sizeof(QElemType)))) // �洢����ʧ��
     exit(ERROR);
   Q.front=Q.rear=0;
   Q.queuesize=QUEUE_INIT_SIZE;
 }

 void DestroyQueue(SqQueue2 &Q)
 { // ���ٶ���Q��Q���ٴ���
   if(Q.base)
     free(Q.base);
   Q.base=NULL;
   Q.front=Q.rear=Q.queuesize=0;
 }

 void ClearQueue(SqQueue2 &Q)
 { // ��Q��Ϊ�ն���
   Q.front=Q.rear=0;
 }

 Status QueueEmpty(SqQueue2 Q)
 { // ������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
   if(Q.front==Q.rear) // ���пյı�־
     return TRUE;
   else
     return FALSE;
 }

 Status GetHead(SqQueue2 Q,QElemType &e)
 { // �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
   if(Q.front==Q.rear) // ���п�
     return ERROR;
   e=Q.base[Q.front];
   return OK;
 }

