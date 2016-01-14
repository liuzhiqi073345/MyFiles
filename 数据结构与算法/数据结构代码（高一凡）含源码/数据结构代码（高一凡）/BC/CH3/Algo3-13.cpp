 // algo3-13.cpp ʹ���Ŷӻ�������ҵ��ģ��
 #define Qu 4 // ������
 #define Khjg 5 // �����ڵ���Ŀͻ���ʱ�������ֵ
 #define Blsj 30 // ÿ���ͻ�����ҵ���ʱ�����ֵ
 #include"func3-3.cpp" // ����algo3-12.cpp��algo3-13.cpp��ͬ�õ��ĺ����ͱ�����

 LinkQueue q; // �Ŷӻ�����q
 QElemType customer[Qu]; // Qu���ͻ�����Ԫ��, ������ڴ��ڰ���ҵ��Ŀͻ�����Ϣ
 //FILE *fq; // �ļ���ָ�룬����ָ��c.txt�ļ�
 //int j=0; // ������������c.txt�ļ��õ�
 Boolean chk[Qu]; // ����״̬��1Ϊ�У�0Ϊæ

 void OpenForDay()
 { // ��ʼ���¼�����ev�Ҳ����1�������¼�����ʼ���Ŷӻ�q����ʼ��Qu������Ϊ1(����)
   int i;
   InitList(ev); // ��ʼ���¼�����evΪ��
   en.OccurTime=0; // �趨��1λ�ͻ�����ʱ��Ϊ0(����һ���ţ����пͻ���)
   en.NType=Qu; // ����
   OrderInsert(ev,en,cmp); // ����1�������¼�en��������¼���ev�У���bo2-6.cpp��
   InitQueue(q); // ��ʼ���Ŷӻ�����q
   for(i=0;i<Qu;i++)
     chk[i]=1; // ��ʼ��Qu������Ϊ1(����)
 }

 int ChuangKou()
 { // ���ؿ��д��ڵ����(0��Qu-1)�����ж�����ڿ��У����������С�ġ����޿��д��ڣ�����Qu
   int i;
   for(i=0;i<Qu;i++)
     if(chk[i])
       return i;
   return i;
 }

 void CustomerArrived()
 { // ����ͻ������¼�en(en.NType=Qu)����algo3-12.cpp��ͬ
   QElemType f;
   int durtime,intertime,i;
   ++CustomerNum; // �ͻ�����1
   Random(durtime,intertime); // ���ɵ�ǰ�ͻ�����ҵ���ʱ�����һ���ͻ������ʱ����2�������
   et.OccurTime=en.OccurTime+intertime; // ��һ�ͻ�et����ʱ��=��ǰ�ͻ�en�ĵ���ʱ��+ʱ����
   et.NType=Qu; // ��һ�ͻ������¼�
   if(et.OccurTime<CloseTime) // ��һ�ͻ�����ʱ������δ����
     OrderInsert(ev,et,cmp); // ��������һ�ͻ������¼�et�����¼���ev�У���bo2-6.cpp��
   f.ArrivalTime=en.OccurTime; // ����ǰ�ͻ������¼�en��������Ԫ��f
   f.Duration=durtime;
   EnQueue(q,f); // ����ǰ�ͻ�f��ӵ��Ŷӻ�
   i=ChuangKou(); // ����д��ڵ����
   if(i<Qu) // �п��д���
   {
     DeQueue(q,customer[i]); // ɾȥ�Ŷӻ�����ͷ�ͻ�(Ҳ���Ǹ���ӵ�f���Ŷӻ���i�Ŵ���)
 //  if(j++<20) // ���ǰ20���ͻ�������Ϣ������ҵ�񴰿���Ϣ���ļ�c.txt��
 //    fprintf(fq,"�ͻ�����ʱ��=%3d,����ҵ���ʱ��=%2d,���ڴ���=%d\n",customer[i].ArrivalTime,customer[i].Duration,i);
     et.OccurTime=en.OccurTime+customer[i].Duration; // �趨һ��i�Ŵ��ڵ��뿪�¼�et
     et.NType=i; // ��i�Ŵ��ڵ��뿪�¼�
     OrderInsert(ev,et,cmp); // �����뿪�¼�et����������¼���ev��
     chk[i]=0; // i�Ŵ���״̬��æ
   }
 }

 void CustomerDeparture()
 { // ����ͻ��뿪�¼�en(en.NType<Qu)����algo3-12.cpp��ͬ
   int i;
   i=en.NType; // ȷ���뿪�¼�en�����Ĵ������i
   chk[i]=1; // i�Ŵ���״̬����
   TotalTime+=en.OccurTime-customer[i].ArrivalTime; // �ͻ�����ʱ��=�뿪�¼�en�ķ���ʱ��-�ÿͻ��ĵ���ʱ��
   if(!QueueEmpty(q))
   { // ��i���ڵĿͻ��뿪���Ŷӻ��Բ���
     DeQueue(q,customer[i]); // ɾȥ�Ŷӻ�����ͷ�ͻ������丳��customer[i](�Ŷӻ�����ͷ�ͻ�ȥi���ڰ���ҵ��)
 //  if(j++<20) // ���ǰ20���ͻ�������Ϣ������ҵ�񴰿���Ϣ���ļ�c.txt��
 //    fprintf(fq,"�ͻ�����ʱ��=%3d,����ҵ���ʱ��=%2d,���ڴ���=%d\n",customer[i].ArrivalTime,customer[i].Duration,i);
     chk[i]=0; // i�Ŵ���״̬��æ
     et.OccurTime=en.OccurTime+customer[i].Duration; // �趨customer[i]���뿪�¼�et,�ͻ����뿪ʱ��=ԭ�ͻ����뿪ʱ��+��ǰ�ͻ�����ҵ���ʱ��
     et.NType=i; // ��i�Ŵ��ڵ��뿪�¼�
     OrderInsert(ev,et,cmp); // �����뿪�¼�et����������¼���ev��
   }
 }

 void main()
 {
 //fq=fopen("c.txt","w"); // ��c.txt�ļ�������д��ͻ�������Ϣ
 //fp=fopen("d.txt","w"); // ��d.txt�ļ�������д�������¼������ʷ��¼
   printf("����������Ӫҵʱ�䳤��(��λ:��): ");
   scanf("%d",&CloseTime);
 //srand(time(0)); // �������������,��ʹÿ�����г���������������ͬ(time(0)�ǳ�������,�����ʱ���й�)
   Bank_Simulation();
 //fclose(fq); // �ر�c.txt
 //fclose(fp); // �ر�d.txt
 }
