 // c3-4.h ���е�˳��洢�ṹ(����Ԫ��ʱ���ƶ�Ԫ�أ�ֻ�ı��ͷԪ�ص�λ��)
 #define QUEUE_INIT_SIZE 10 // ���д洢�ռ�ĳ�ʼ������
 #define QUEUE_INCREMENT 2 // ���д洢�ռ�ķ�������
 struct SqQueue2
 {
   QElemType *base; // ��ʼ���Ķ�̬����洢�ռ�
   int front; // ͷָ�룬�����в���,ָ�����ͷԪ��
   int rear; // βָ�룬�����в���,ָ�����βԪ�ص���һ��λ��
   int queuesize; // ��ǰ����Ĵ洢����(��sizeof(QElemType)Ϊ��λ)
 };
