 // algo3-9.cpp �õݹ麯������Թ�����(������н�)
 #include"c1.h" // ���ݡ�PASCAL������ơ�(֣��������)�еĳ���ı�
 #include"func3-1.cpp" // ����ǽԪ��ֵΪ0����ͨ��·��Ϊ-1��ͨ��·��Ϊ�㼣

 void Try(PosType cur,int curstep)
 { // �ɵ�ǰλ��cur����ǰ����curstep��̽��һ��
   int i;
   PosType next; // ��һ��λ��
   PosType direc[4]={{0,1},{1,0},{0,-1},{-1,0}}; // {������,������},�ƶ�����,����Ϊ��������
   for(i=0;i<=3;i++) // ������̽���������ĸ�����
   {
     next.x=cur.x+direc[i].x; // �����ƶ����򣬸���һλ�ø�ֵ
     next.y=cur.y+direc[i].y;
     if(m[next.x][next.y]==-1) // ��һ��λ����ͨ·
     {
       m[next.x][next.y]=++curstep; // ����һ��λ����Ϊ�㼣
       if(next.x!=end.x||next.y!=end.y) // û���յ�
         Try(next,curstep); // ����һ��λ�ü�����̽(���׵ݹ���ã����յ����)
       else // ���յ�
       {
         Print(); // ������(���ڣ����ٵݹ����)
         printf("\n");
       }
       m[next.x][next.y]=-1; // �ָ�Ϊͨ·���Ա�����һ��������̽��һ��·
       curstep--; // �㼣Ҳ��1
     }
   }
 }

 void main()
 {
   Init(-1); // ��ʼ���Թ���ͨ��ֵΪ-1
   printf("���Թ�����ڵ����ڵ�·������:\n");
   m[begin.x][begin.y]=1; // ��ڵ��㼣Ϊ1
   Try(begin,1); // �ɵ�1�������̽��
 }
