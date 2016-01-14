 // algo4-4.cpp ����algo4-3.cpp�������ļ�,������ѯͼ��
 #include"c1.h"
 typedef int ElemType;
 #include"c2-5.h"
 #include"bo2-6.cpp"
 #include"c4-2.h"
 #include"bo4-2.cpp"

 #define MaxBookNum 10 // ����ֻ��10��������������
 #define MaxKeyNum 25 // ��������������(�ؼ��ʵ������Ŀ)
 #define MaxLineLen 46 // ��������󳤶�

 struct IdxTermType // ����������
 {
   HString key; // �ؼ���(�ѷ������ͣ�c4-2.h)
   LinkList bnolist; // ����������������(c2-5.h)
 };

 struct IdxListType // ����������(�����)
 {
   IdxTermType item[MaxKeyNum+1]; // ��������������
   int last; // �ؼ��ʵĸ���
 };

 struct BookTermType // ��Ŀ������
 {
   char bookname[MaxLineLen+1]; // ������(����'\0')
   int bookno; // ���
 };

 struct BookListType // ��Ŀ������(�����)
 {
   BookTermType item[MaxBookNum]; // ��Ŀ����������
   int last; // ��Ŀ������
 };

 void main()
 {
   FILE *f; // �κ�ʱ������һ���ļ�
   IdxListType idxlist; // ������
   BookListType booklist; // ��Ŀ��
   char buf[MaxLineLen+5]; // ��ǰ��Ŀ��(������ź�'\0')
   HString ch; // �����ַ���
   int BookNo; // ���
   Link p; // ����ָ��
   int i,j,k,flag=1; // flag�Ǽ�����ѯ�ı�־
   InitString(ch); // ��ʼ��HString���͵ı���
   if(!(f=fopen("BookIdx.txt","r"))) // �������ؼ����������ļ�
     exit(OVERFLOW);
   fscanf(f,"%d",&idxlist.last); // �����ؼ��ʸ���
   for(k=0;k<idxlist.last;k++) // �ѹؼ����ļ������ݿ���idxlist��
   {
     fscanf(f,"%s",buf);
     i=0;
     while(buf[i])
       buf[i++]=tolower(buf[i]); // ��ĸתΪСд
     InitString(idxlist.item[k].key);
     StrAssign(idxlist.item[k].key,buf);
     InitList(idxlist.item[k].bnolist); // ��ʼ���������bo2-6.cpp
     fscanf(f,"%d",&i);
     for(j=0;j<i;j++)
     {
       fscanf(f,"%d",&BookNo);
       MakeNode(p,BookNo); // �����µ���Ž�㣬bo2-6.cpp
       p->next=NULL; // ����Ž���ָ����ֵ
       Append(idxlist.item[k].bnolist,p); // �ڱ�β�����µ���Ž�㣬bo2-6.cpp
     }
   }
   fclose(f);
   if(!(f=fopen("BookInfo.txt","r"))) // ����Ŀ�ļ�
     exit(FALSE);
   i=0;
   while(fgets(buf,MaxLineLen,f))
   { // ����Ŀ�ļ������ݿ���booklist��
     booklist.item[i].bookno=atoi(buf); // ǰ��λ����Ϊ���
     strcpy(booklist.item[i++].bookname,&buf[4]); // ��buf��������ʼ���ַ���������booklist��
   }
   booklist.last=i;
   while(flag)
   {
     printf("��������Ŀ�Ĺؼ���(һ��)��");
     scanf("%s",buf);
     i=0;
     while(buf[i])
       buf[i++]=tolower(buf[i]); // ��ĸתΪСд
     StrAssign(ch,buf);
     i=0;
     do
     {
       k=StrCompare(ch,idxlist.item[i++].key); // bo4-2.cpp
     }while(k&&i<=idxlist.last);
     if(!k) // ���������д˹ؼ���
     {
       p=idxlist.item[--i].bnolist.head->next; // pָ���������д˹ؼ�����Ӧ�������Ԫ���
       while(p)
       {
         j=0;
         while(j<booklist.last&&p->data!=booklist.item[j].bookno) // ��booklist������Ӧ�����
           j++;
         if(j<booklist.last)
           printf("%3d %s",booklist.item[j].bookno,booklist.item[j].bookname);
         p=p->next; // ���������
       }
     }
     else
       printf("û�ҵ�\n");
     printf("��������������1���˳�����������0��");
     scanf("%d",&flag);
   }
 }
