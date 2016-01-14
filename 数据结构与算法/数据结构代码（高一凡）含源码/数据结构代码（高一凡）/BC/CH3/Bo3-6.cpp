 // bo3-6.cpp �õ�����Ļ�������ʵ��������(�洢�ṹ��c3-2.h����)�Ļ�������(9��)
 typedef QElemType ElemType;
 #define LinkList QueuePtr // ���嵥�������������Ӧ�������е�������ͬ
 #define LNode QNode
 #include"bo2-2.cpp" // ������Ļ�������
 void InitQueue(LinkQueue &Q)
 { // ����һ���ն���Q
   InitList(Q.front); // ���õ�����Ļ�������
   Q.rear=Q.front;
 }

 void DestroyQueue(LinkQueue &Q)
 { // ���ٶ���Q(���ۿշ����)
   DestroyList(Q.front);
   Q.rear=Q.front;
 }

 void ClearQueue(LinkQueue &Q)
 { // ��Q��Ϊ�ն���
   ClearList(Q.front);
   Q.rear=Q.front;
 }

 Status QueueEmpty(LinkQueue Q)
 { // ��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
   return ListEmpty(Q.front);
 }

 int QueueLength(LinkQueue Q)
 { // ����еĳ���
   return ListLength(Q.front);
 }

 Status GetHead(LinkQueue Q,QElemType &e)
 { // �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
   return GetElem(Q.front,1,e);
 }

 void EnQueue(LinkQueue &Q,QElemType e)
 { // ����Ԫ��eΪQ���µĶ�βԪ��
   QueuePtr p;
   if(!(p=(QueuePtr)malloc(sizeof(QNode)))) // �洢����ʧ��
     exit(OVERFLOW);
   p->data=e;
   p->next=NULL;
   Q.rear->next=p;
   Q.rear=p;
 }

 Status DeQueue(LinkQueue &Q,QElemType &e)
 { // �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
   if(Q.front->next==Q.rear) // ���н���1��Ԫ��(ɾ����Ҳ�Ƕ�βԪ��)
     Q.rear=Q.front; // ���βָ��ָ��ͷ���
   return ListDelete(Q.front,1,e);
 }

 void QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
 { // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()
   ListTraverse(Q.front,vi);
 }
