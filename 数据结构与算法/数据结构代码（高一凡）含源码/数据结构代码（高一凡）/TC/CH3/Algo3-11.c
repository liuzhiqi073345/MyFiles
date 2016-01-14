 /* algo3-11.c ���÷�ѭ��˳����в��ù������������Թ�����(һ��·��) */
 #include"c1.h"
 #include"func3-1.c"
 #define D 8 /* �ƶ���������ֻ��ȡ4��8��(8������б�У�4����ֻ��ֱ��) */

 typedef struct /* �������Ԫ�غ�ջԪ��Ϊͬ���͵Ľṹ�� */
 {
   PosType seat; /* ��ǰ�����ֵ����ֵ */
   int pre; /* ǰһ���ڶ����е���� */
 }QElemType,SElemType; /* ջԪ�غͶ���Ԫ�� */
 #include"c3-1.h" /* ջ�Ĵ洢�ṹ */
 #include"bo3-1.c" /* ջ�Ļ������� */
 #include"c3-4.h" /* ���еĴ洢�ṹ */
 #include"bo3-4.c" /* ��ѭ��˳����еĻ�������(1) */
 #include"bo3-9.c" /* ��ѭ��˳����еĻ�������(2) */

 struct /* �ƶ����飬�ƶ�������������˳ʱ��ת */
 {
   int x,y;
 }move[D]={
 #if D==8
	   {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
 #endif
 #if D==4
	   {0,1},{1,0},{0,-1},{-1,0}};
 #endif

 void Path()
 { /* �����������һ���Թ�·�� */
   SqQueue2 q; /* ���÷�ѭ��˳����� */
   QElemType qf,qt; /* ��ǰ�����һ�� */
   SqStack s; /* ����˳��ջ */
   int i,flag=1; /* ���ҵ����ڣ�flag=0 */
   qf.seat.x=begin.x; /* �������Ϊ��ǰ�� */
   qf.seat.y=begin.y;
   qf.pre=-1; /* �����(��һ��)����һ������=-1 */
   m[qf.seat.x][qf.seat.y]=-1; /* ��ʼ����Ϊ-1(����ѷ��ʹ�) */
   InitQueue(&q);
   EnQueue(&q,qf); /* ������ */
   while(!QueueEmpty(q)&&flag)
   { /* �����л���û������������ĵ��һ�û�ҵ����� */
     DeQueue(&q,&qf); /* ����qfΪ��ǰ�� */
     for(i=0;i<D;i++) /* ����������� */
     {
       qt.seat.x=qf.seat.x+move[i].x; /* ��һ������� */
       qt.seat.y=qf.seat.y+move[i].y;
       if(m[qt.seat.x][qt.seat.y]==1)
       { /* �˵���ͨ���Ҳ��������ʹ� */
         m[qt.seat.x][qt.seat.y]=-1; /* ����ѷ��ʹ� */
         qt.pre=q.front-1; /* qt��ǰһ�㴦�ڶ������ֶ�ͷ��1��λ��(ûɾ��) */
	 EnQueue(&q,qt); /* ���qt */
         if(qt.seat.x==end.x&&qt.seat.y==end.y) /* �����յ� */
         {
           flag=0;
           break;
         }
       }
     }
   }
   if(flag) /* �������������л�û�����յ� */
     printf("û��·���ɵ����յ㣡\n");
   else /* �����յ� */
   {
     InitStack(&s); /* ��ʼ��sջ */
     i=q.rear-1; /* iΪ����ջԪ���ڶ����е�λ�� */
     while(i>=0) /* û����� */
     {
       Push(&s,q.base[i]); /* �������е�·����ջ(ջ��Ϊ���ڣ�ջ��Ϊ���) */
       i=q.base[i].pre; /* iΪǰһԪ���ڶ����е�λ�� */
     }
     i=0; /* iΪ�߳��Թ����㼣 */
     while(!StackEmpty(s))
     {
       Pop(&s,&qf); /* ��������ڵ����ڵ�˳�򵯳�·�� */
       i++;
       m[qf.seat.x][qf.seat.y]=i; /* ���·��Ϊ�㼣(���ǰ��ֵΪ-1) */
     }
     printf("�߳��Թ���һ��������\n");
     Print(); /* ���m���� */
   }
 }

 void main()
 {
   Init(1); /* ��ʼ���Թ���ͨ��ֵΪ1 */
   Path(); /* ��һ���Թ�·�� */
 }
