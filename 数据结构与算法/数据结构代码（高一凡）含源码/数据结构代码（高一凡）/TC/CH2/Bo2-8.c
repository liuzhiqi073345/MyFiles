 /* bo2-8.c ����ͷ���ĵ�����(�洢�ṹ��c2-2.h����)�Ĳ��ֻ�������(9��) */
 #define DestroyList ClearList /* DestroyList()��ClearList()�Ĳ�����һ���� */
 void InitList(LinkList *L)
 { /* �������������һ���յ����Ա�L */
   *L=NULL; /* ָ��Ϊ�� */
 }

 void ClearList(LinkList *L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
   LinkList p;
   while(*L) /* L���� */
   {
     p=*L; /* pָ����Ԫ��� */
     *L=(*L)->next; /* Lָ���2�����(����Ԫ���) */
     free(p); /* �ͷ���Ԫ��� */
   }
 }

 Status ListEmpty(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
   if(L)
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   int i=0;
   LinkList p=L;
   while(p) /* pָ����(û����β) */
   {
     p=p->next; /* pָ����һ����� */
     i++;
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType *e)
 { /* LΪ����ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR */
   int j=1;
   LinkList p=L;
   if(i<1) /* iֵ���Ϸ� */
     return ERROR;
   while(j<i&&p) /* û����i��Ԫ�أ�Ҳû����β */
   {
     j++;
     p=p->next;
   }
   if(j==i) /* ���ڵ�i��Ԫ�� */
   {
     *e=p->data;
     return OK;
   }
   else
     return ERROR;
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { /* ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0) */
   /* �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
   /*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
   int i=0;
   LinkList p=L;
   while(p)
   {
     i++;
     if(compare(p->data,e)) /* �ҵ�����������Ԫ�� */
       return i;
     p=p->next;
   }
   return 0;
 }

 Status ListInsert(LinkList *L,int i,ElemType e)
 { /* �ڲ���ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e */
   int j=1;
   LinkList p=*L,s;
   if(i<1) /* iֵ���Ϸ� */
     return ERROR;
   s=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
   s->data=e; /* ��s��data��ֵ */
   if(i==1) /* ���ڱ�ͷ */
   {
     s->next=*L;
     *L=s; /* �ı�L */
   }
   else
   { /* ���ڱ�����ദ */
     while(p&&j<i-1) /* Ѱ�ҵ�i-1����� */
     {
       p=p->next;
       j++;
     }
     if(!p) /* i���ڱ�+1 */
       return ERROR;
     s->next=p->next;
     p->next=s;
   }
   return OK;
 }

 Status ListDelete(LinkList *L,int i,ElemType *e)
 { /* �ڲ���ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ */
   int j=1;
   LinkList p=*L,q;
   if(i==1) /* ɾ����1����� */
   {
     *L=p->next; /* L�ɵ�2����㿪ʼ */
     *e=p->data;
     free(p); /* ɾ�����ͷŵ�1����� */
   }
   else
   {
     while(p->next&&j<i-1) /* Ѱ�ҵ�i����㣬����pָ����ǰ�� */
     {
       p=p->next;
       j++;
     }
     if(!p->next||j>i-1) /* ɾ��λ�ò����� */
       return ERROR;
     q=p->next; /* ɾ�����ͷŽ�� */
     p->next=q->next;
     *e=q->data;
     free(q);
   }
   return OK;
 }

 void ListTraverse(LinkList L,void(*vi)(ElemType))
 { /* ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi() */
   LinkList p=L;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
 }
