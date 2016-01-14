 /* func3-3.c algo3-12.c��algo3-13.c�õ��ĺ����������� */
 #include"c1.h"
 typedef struct /* ����ElemTypeΪ�ṹ������ */
 {
   int OccurTime; /* �¼�����ʱ�� */
   int NType; /* �¼����ͣ�Qu��ʾ�����¼���0��Qu-1��ʾQu�����ڵ��뿪�¼� */
 }Event,ElemType; /* �¼����ͣ���������LinkList������Ԫ������ */

 #include"c2-5.h" /* ��ʵ��Ӧ�ýǶȳ������¶������������ṹ */
 typedef LinkList EventList; /* �¼�����ָ�����ͣ�����Ϊ�������� */
 #include"bo2-6.c" /* ����c2-5.h�洢�ṹ�Ļ������� */

 typedef struct
 {
   int ArrivalTime; /* ����ʱ�� */
   int Duration; /* ������������ʱ�� */
 }QElemType; /* ������е�����Ԫ������QElemTypeΪ�ṹ������ */

 #include"c3-2.h" /* �����д洢�ṹ */
 #include"bo3-2.c" /* �����л������� */

 /* �������õ�����Ҫ����(ȫ��) */
 EventList ev; /* �¼���ͷָ�� */
 Event en,et; /* �¼�,��ʱ���� */
 /*FILE *fp; /* �ļ���ָ�룬����ָ��b.txt��d.txt�ļ� */

 long int TotalTime=0; /* �ۼƿͻ�����ʱ��(��ֵΪ0) */
 int CloseTime,CustomerNum=0; /* ����Ӫҵʱ��(��λ�Ƿ�),�ͻ���(��ֵΪ0) */

 int cmp(Event a,Event b)
 { /* ���¼�a�ķ���ʱ��<��=��>�¼�b�ķ���ʱ�̷ֱ𷵻�-1��0��1 */
   if(a.OccurTime==b.OccurTime)
     return 0;
   else
     return (a.OccurTime-b.OccurTime)/abs(a.OccurTime-b.OccurTime);
 }

 void Random(int *d,int *i)
 { /* ������������� */
   *d=rand()%Blsj+1; /* 1��Blsj֮��������(����ҵ���ʱ��) */
   *i=rand()%(Khjg+1); /* 0��Khjg֮��������(�ͻ������ʱ����) */
 }

 void OpenForDay();
 void CustomerArrived();
 void CustomerDeparture();

 void Bank_Simulation()
 { /* ����ҵ��ģ�⺯�� */
   Link p;
   OpenForDay(); /* ��ʼ���¼���ev�Ҳ����1�������¼�����ʼ������ */
   while(!ListEmpty(ev)) /* �¼���ev���� */
   {
     DelFirst(&ev,ev.head,&p); /* ɾ���¼���ev�ĵ�1����㣬����p������ָ�룬��bo2-6.c�� */
 /*  if(p->data.OccurTime<50) /* ���ǰ50�����ڷ������¼����ļ�d.txt�� */
 /*    fprintf(fp,"p->data.OccurTime=%3d p->data.NType=%d\n",p->data.OccurTime,p->data.NType); */
     en.OccurTime=GetCurElem(p).OccurTime; /* GetCurElem()��bo2-6.c�У�����p->data(ElemType����) */
     en.NType=GetCurElem(p).NType;
     if(en.NType==Qu) /* �����¼� */
       CustomerArrived(); /* ����ͻ������¼� */
     else /* ��ĳ�����뿪���¼� */
       CustomerDeparture(); /* ����ͻ��뿪�¼� */
   } /* ���㲢���ƽ������ʱ�� */
   printf("������=%d �����ڵ���Ŀͻ���ʱ����=0��%d���� ÿ���ͻ�����ҵ���ʱ��=1��%d����\n",Qu,Khjg,Blsj);
   printf("�ͻ�����:%d, ���пͻ�����ʱ:%ld����,ƽ��ÿ�˺�ʱ:%d����,",CustomerNum,TotalTime,TotalTime/CustomerNum);
   printf("���һ���ͻ��뿪��ʱ��:%d��\n",en.OccurTime);
 }
