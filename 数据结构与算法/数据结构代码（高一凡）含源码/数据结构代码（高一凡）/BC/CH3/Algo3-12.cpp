 // algo3-12.cpp ����ҵ��ģ�⡣ʵ���㷨3.6��3.7�ĳ���
 #define Qu 4 // �ͻ�������
 #define Khjg 5 // �����ڵ���Ŀͻ���ʱ�������ֵ
 #define Blsj 30 // ÿ���ͻ�����ҵ���ʱ�����ֵ
 #include"func3-3.cpp" // ����algo3-12.cpp��algo3-13.cpp��ͬ�õ��ĺ����ͱ�����

 LinkQueue q[Qu]; // Qu���ͻ�����
 QElemType customer; // �ͻ���¼����ʱ����
 //FILE *fq; // �ļ���ָ�룬����ָ��a.txt�ļ�

 void OpenForDay()
 { // ��ʼ���¼�����ev�Ҳ����1�������¼�����ʼ��Qu������
   int i;
   InitList(ev); // ��ʼ���¼�����evΪ��
   en.OccurTime=0; // �趨��1λ�ͻ�����ʱ��Ϊ0(����һ���ţ����пͻ���)
 //fprintf(fq,"��λ�ͻ�����ʱ��=%3d,",en.OccurTime);
   en.NType=Qu; // ����
   OrderInsert(ev,en,cmp); // ����1�������¼�en��������¼���ev�У���bo2-6.cpp��
   for(i=0;i<Qu;++i) // ��ʼ��Qu������
     InitQueue(q[i]);
 }

 int Minimum(LinkQueue Q[])
 { // ������̶��е���ţ����в���ֵ�����ض��������С��
   int l[Qu];
   int i,k=0;
   for(i=0;i<Qu;i++)
     l[i]=QueueLength(Q[i]);
   for(i=1;i<Qu;i++)
     if(l[i]<l[0])
     {
       l[0]=l[i];
       k=i;
     }
   return k;
 }

 void CustomerArrived()
 { // ����ͻ������¼�en(en.NType=Qu)
   QElemType f;
   int durtime,intertime,i;
   ++CustomerNum; // �ͻ�����1
   Random(durtime,intertime); // ���ɵ�ǰ�ͻ�����ҵ���ʱ�����һ���ͻ������ʱ����2�������
   et.OccurTime=en.OccurTime+intertime; // ��һ�ͻ�et����ʱ��=��ǰ�ͻ�en�ĵ���ʱ��+ʱ����
   et.NType=Qu; // ��һ�ͻ������¼�
   i=Minimum(q); // �󳤶���̶��е���ţ��ȳ�Ϊ��С�����(�����¼�����ö�)
 //if(CustomerNum<=20) // ���ǰ20���ͻ�������Ϣ���ļ�a.txt��
 //  fprintf(fq,"����ҵ���ʱ��=%2d,���Ŷ���=%d\n��һ�ͻ�����ʱ��=%3d,",durtime,i,et.OccurTime);
   if(et.OccurTime<CloseTime) // ��һ�ͻ�����ʱ������δ����
     OrderInsert(ev,et,cmp); // ��������һ�ͻ������¼�et�����¼���ev�У���bo2-6.cpp��
   f.ArrivalTime=en.OccurTime; // ����ǰ�ͻ������¼�en��������Ԫ��f
   f.Duration=durtime;
   EnQueue(q[i],f); // ��f��ӵ���i����(i=0��Qu-1)
   if(QueueLength(q[i])==1) // ��Ԫ��Ϊ��ͷԪ��
   {
     et.OccurTime=en.OccurTime+durtime; // �趨һ���뿪�¼�et
     et.NType=i;
     OrderInsert(ev,et,cmp); // �����뿪�¼�et����������¼���ev��
   }
 }

 void CustomerDeparture()
 { // ����ͻ��뿪�¼�en(en.NType<Qu)
   int i;
   i=en.NType; // ȷ���뿪�¼�en�����Ķ������i
   DeQueue(q[i],customer); // ɾ����i���е���ͷ�ͻ�
   TotalTime+=en.OccurTime-customer.ArrivalTime; // �ͻ�����ʱ��=�뿪�¼�en�ķ���ʱ��-�ÿͻ��ĵ���ʱ��
   if(!QueueEmpty(q[i]))
   { // ɾ����i���е���ͷ�ͻ��󣬵�i�����Բ���
     GetHead(q[i],customer); // ����i�����µ���ͷ�ͻ�����customer
     et.OccurTime=en.OccurTime+customer.Duration; // �趨�뿪�¼�et,����ͷ���뿪ʱ��=ԭ��ͷ���뿪ʱ��+����ͷ����ҵ���ʱ��
     et.NType=i; // ��i�����е��뿪�¼�
     OrderInsert(ev,et,cmp); // �����뿪�¼�et����������¼���ev��
   }
 }

 void main()
 {
 //fq=fopen("a.txt","w"); // ��a.txt�ļ�������д��ͻ�������Ϣ
 //fp=fopen("b.txt","w"); // ��b.txt�ļ�������д�������¼������ʷ��¼
   printf("����������Ӫҵʱ�䳤��(��λ:��): ");
   scanf("%d",&CloseTime);
 //srand(time(0)); // ������������ӣ���ʹÿ�����г���������������ͬ(time(0)�ǳ��������������ʱ���й�)
   Bank_Simulation();
 //fclose(fq); // �ر�a.txt
 //fclose(fp); // �ر�b.txt
 }
