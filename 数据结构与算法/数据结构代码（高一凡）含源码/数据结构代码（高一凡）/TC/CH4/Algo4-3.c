 /* algo4-3.c ������Ŀ�ļ�bookinfo.txt���������ؼ��������ļ�bookidx.txt��*/
 /* Ϊ����algo4-4.c��׼�����㷨4.9��4.14 */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-5.h"
 #include"bo2-6.c"
 #include"c4-2.h"
 #include"bo4-2.c"

 #define MaxKeyNum 25 /* ��������������(�ؼ��ʵ������Ŀ) */
 #define MaxLineLen 52 /* ��Ŀ��(��Ŀ�ļ���1��)buf����󳤶� */
 #define MaxNoIdx 10 /* ��������(Ҳ��һ����Ŀ�йؼ���)�������Ŀ */

 typedef struct
 {
   char *item[MaxNoIdx]; /* �ʱ�(�ַ���)ָ������ */
   int last; /* �ʵ����� */
 }WordListType; /* һ����Ŀ�Ĵʱ�(˳���)�ͷ������ʱ�(�����)�������� */

 typedef struct
 {
   HString key; /* �ؼ���(�ѷ������ͣ�c4-2.h) */
   LinkList bnolist; /* ����������������(c2-5.h) */
 }IdxTermType; /* ���������� */

 typedef struct
 {
   IdxTermType item[MaxKeyNum+1]; /* �������������� */
   int last; /* �ؼ��ʵĸ��� */
 }IdxListType; /* ����������(�����) */

 /* ȫ�ֱ��� */
 char buf[MaxLineLen+1]; /* ��ǰ��Ŀ��(����'\0') */
 WordListType wdlist,noidx; /* �ݴ�һ����Ĵʱ��������ʱ� */

 void InitIdxList(IdxListType *idxlist)
 { /* ��ʼ����������������idxlistΪ�ձ�����idxlist.item[0]��һ�մ� */
   (*idxlist).last=0;
   InitString(&(*idxlist).item[0].key); /* ��ʼ��[0]��Ԫ��������bo4-2.c�� */
   InitList(&(*idxlist).item[0].bnolist); /* ��ʼ��[0]��Ԫ��������bo2-6.c�� */
 }

 void ExtractKeyWord(int *BookNo)
 { /* ��buf����ȡ�����ؼ��ʵ��ʱ�wdlist����Ŵ���BookNo */
   int i,l,f=1; /* f���ַ���buf������־ 0������ 1��δ���� */
   char *s1,*s2;
   for(i=1;i<=wdlist.last;i++)
   { /* �ͷ���һ����Ŀ�ڴʱ�wdlist�Ĵ洢�ռ� */
     free(wdlist.item[i]);
     wdlist.item[i]=NULL;
   }
   wdlist.last=0; /* ��ʼ���ʱ�wdlist�Ĵ����� */
   *BookNo=atoi(buf); /* ��ǰ��λ����ת��Ϊ�������������BookNo */
   s1=&buf[4]; /* s1ָ�����������ַ� */
   while(f)
   { /* ��ȡ�����ؼ��ʵ��ʱ�wdlist */
     s2=strchr(s1,' '); /* s2ָ��s1��ĵ�һ���ո���û�У�����NULL */
     if(!s2) /* ����β(û�ո�) */
     {
       s2=strchr(s1,'\12'); /* s2ָ��buf�����һ���ַ�(�س���10) */
       f=0;
     }
     l=s2-s1; /* ���ʳ��� */
     if(s1[0]>='A'&&s1[0]<='Z') /* ��������ĸΪ��д */
     { /* д��ʱ� */
       wdlist.item[wdlist.last]=(char *)malloc((l+1)*sizeof(char)); /* ���ɴ��ռ�(����'\0') */
       for(i=0;i<l;i++)
         wdlist.item[wdlist.last][i]=s1[i]; /* д��ʱ� */
       wdlist.item[wdlist.last][l]=0; /* �������� */
       for(i=0;i<noidx.last&&(l=strcmp(wdlist.item[wdlist.last],noidx.item[i]))>0;i++);
       /* �����Ƿ�Ϊ�������� */
       if(!l) /* �Ƿ������� */
       {
         free(wdlist.item[wdlist.last]); /* �Ӵʱ���ɾ���ô� */
         wdlist.item[wdlist.last]=NULL;
       }
       else
         wdlist.last++; /* �ʱ���+1 */
     }
     s1=s2+1; /* s1�ƶ�����һ�����ʵ����ַ��� */
   };
 }

 void GetWord(int i,HString *wd)
 { /* ��wd���شʱ�wdlist�е�i���ؼ��ʣ��㷨4.11 */
   StrAssign(wd,wdlist.item[i]); /* ���ɹؼ����ַ��� bo4-2.c */
 }

 int Locate(IdxListType *idxlist,HString wd,Status *b)
 { /* ��������idxlist�в�ѯ�Ƿ������wd��ȵĹؼ��ʡ������ڣ��򷵻��� */
   /* ���������е�λ�ã���bȡֵTRUE�����򷵻ز���λ�ã���bȡֵFALSE���㷨4.12 */
   int i,m;
   for(i=(*idxlist).last;(m=StrCompare((*idxlist).item[i].key,wd))>0;--i); /* bo4-2.c */
   if(m==0) /* �ҵ� */
   {
     *b=TRUE;
     return i;
   }
   else
   {
     *b=FALSE;
     return i+1;
   }
 }

 void InsertNewKey(IdxListType *idxlist,int i,HString wd)
 { /* ��������idxlist�ĵ�i���ϲ����¹ؼ���wd������ʼ���������������Ϊ�ձ��㷨4.13 */
   int j;
   for(j=(*idxlist).last;j>=i;--j) /* ���������� */
     (*idxlist).item[j+1]=(*idxlist).item[j];
   InitString(&(*idxlist).item[i].key); /* bo4-2.c */
   StrCopy(&(*idxlist).item[i].key,wd); /* �����������µ������� bo4-2.c */
   InitList(&(*idxlist).item[i].bnolist); /* ��ʼ�����������Ϊ�ձ� bo2-6.c */
   (*idxlist).last++;
 }

 void InsertBook(IdxListType *idxlist,int i,int bno)
 { /* ��������idxlist�ĵ�i���в������Ϊbno���������㷨4.14 */
   Link p;
   MakeNode(&p,bno); /* ������ bo2-6.c */
   p->next=NULL;
   Append(&(*idxlist).item[i].bnolist,p); /* �����µ�������� bo2-6.c */
 }

 void InsIdxList(IdxListType *idxlist,int bno)
 { /* �����Ϊbno�Ĺؼ��ʲ����������㷨4.10 */
   int i,j;
   Status b;
   HString wd;
   InitString(&wd); /* bo4-2.c */
   for(i=0;i<wdlist.last;i++)
   {
     GetWord(i,&wd);
     j=Locate(idxlist,wd,&b); /* �ؼ��ʵ�λ�û�������λ��(���������в����ڸô�) */
     if(!b) /* �������в����ڹؼ���wd */
       InsertNewKey(idxlist,j,wd); /* ���������в����µ������� */
     InsertBook(idxlist,j,bno); /* ����������� */
   }
 }

 void PutText(FILE *f,IdxListType idxlist)
 { /* �����ɵ�������idxlist������ļ�f */
   int i,j;
   Link p;
   fprintf(f,"%d\n",idxlist.last);
   for(i=1;i<=idxlist.last;i++)
   {
     for(j=0;j<idxlist.item[i].key.length;j++)
       fprintf(f,"%c",idxlist.item[i].key.ch[j]); /* HString���ʹ�βû��\0��ֻ������ַ���� */
     fprintf(f,"\n%d\n",idxlist.item[i].bnolist.len);
     p=idxlist.item[i].bnolist.head;
     for(j=1;j<=idxlist.item[i].bnolist.len;j++)
     {
       p=p->next;
       fprintf(f,"%d ",p->data);
     }
     fprintf(f,"\n");
   }
 }

 void main()
 { /* �㷨4.9 */
   FILE *f; /* �κ�ʱ������һ���ļ� */
   IdxListType idxlist; /* ������ */
   int BookNo; /* ��ű��� */
   int k;
   f=fopen("NoIdx.txt","r"); /* �򿪷��������ļ� */
   if(!f)
     exit(OVERFLOW);
   fscanf(f,"%d",&noidx.last); /* ��ȡ�������ʸ��� */
   for(k=0;k<noidx.last;k++) /* �ѷ��������ļ����������ο���noidx�� */
   {
     fscanf(f,"%s",buf);
     noidx.item[k]=(char*)malloc((strlen(buf)+1)*sizeof(char));
     strcpy(noidx.item[k],buf);
   }
   fclose(f); /* �رշ��������ļ� */
   f=fopen("BookInfo.txt","r"); /* ����Ŀ�ļ� */
   if(!f)
     exit(FALSE);
   InitIdxList(&idxlist); /* ��������idxlistΪ�գ�����ʼ��[0]��Ԫ */
   while(fgets(buf,MaxLineLen,f)) /* ����Ŀ�ļ���ȡ1����Ϣ��buf�ɹ� */
   {
     ExtractKeyWord(&BookNo);/*��buf�е���Ŵ���BookNo,�ؼ�����ȡ���ʱ�(��ǰ��Ŀ�Ĺؼ��ʱ�)�� */
     InsIdxList(&idxlist,BookNo); /* �����ΪBookNo�Ĺؼ��ʼ���Ų���������idxlist�� */
   }
   fclose(f); /* �ر���Ŀ�ļ� */
   f=fopen("BookIdx.txt","w"); /* �������ؼ��������ļ� */
   if(!f)
     exit(INFEASIBLE);
   PutText(f,idxlist); /* �����ɵ�������idxlist����������ؼ��������ļ� */
   fclose(f); /* �ر������ؼ��������ļ� */
 }
