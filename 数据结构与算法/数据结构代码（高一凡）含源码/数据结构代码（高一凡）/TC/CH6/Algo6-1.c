 /* algo6-1.c ��շ������롣ʵ���㷨6.12�ĳ��� */
 #include"c1.h"
 #include"c6-7.h"
 #include"func6-1.c"

 void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n) /* �㷨6.12 */
 { /* w���n���ַ���Ȩֵ(��>0)������շ�����HT�������n���ַ��ĺշ�������HC */
   int m,i,s1,s2,start;
   unsigned c,f;
   HuffmanTree p;
   char *cd;
   if(n<=1)
     return;
   m=2*n-1;
   *HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); /* 0�ŵ�Ԫδ�� */
   for(p=*HT+1,i=1;i<=n;++i,++p,++w)
   {
     (*p).weight=*w;
     (*p).parent=0;
     (*p).lchild=0;
     (*p).rchild=0;
   }
   for(;i<=m;++i,++p)
     (*p).parent=0;
   for(i=n+1;i<=m;++i) /* ���շ����� */
   { /* ��HT[1��i-1]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2 */
     select(*HT,i-1,&s1,&s2);
     (*HT)[s1].parent=(*HT)[s2].parent=i;
     (*HT)[i].lchild=s1;
     (*HT)[i].rchild=s2;
     (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
   }
   /* ��Ҷ�ӵ���������ÿ���ַ��ĺշ������� */
   *HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
   /* ����n���ַ������ͷָ������([0]����) */
   cd=(char*)malloc(n*sizeof(char)); /* ���������Ĺ����ռ� */
   cd[n-1]='\0'; /* ��������� */
   for(i=1;i<=n;i++)
   { /* ����ַ���շ������� */
     start=n-1; /* ���������λ�� */
     for(c=i,f=(*HT)[i].parent;f!=0;c=f,f=(*HT)[f].parent)
     /* ��Ҷ�ӵ������������ */
       if((*HT)[f].lchild==c)
         cd[--start]='0';
       else
         cd[--start]='1';
     (*HC)[i]=(char*)malloc((n-start)*sizeof(char));
     /* Ϊ��i���ַ��������ռ� */
     strcpy((*HC)[i],&cd[start]); /* ��cd���Ʊ���(��)��HC */
   }
   free(cd); /* �ͷŹ����ռ� */
 }

 void main()
 {
   HuffmanTree HT;
   HuffmanCode HC;
   int *w,n,i;
   printf("������Ȩֵ�ĸ���(>1): ");
   scanf("%d",&n);
   w=(int*)malloc(n*sizeof(int));
   printf("����������%d��Ȩֵ(����):\n",n);
   for(i=0;i<=n-1;i++)
     scanf("%d",w+i);
   HuffmanCoding(&HT,&HC,w,n);
   for(i=1;i<=n;i++)
     puts(HC[i]);
 }
