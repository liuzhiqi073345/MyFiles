 /* bo9-2.c ��̬���ұ�(����������)�Ļ�������(8��)�������㷨9.5(b)���㷨9.6��9.8 */
 typedef ElemType TElemType;
 #include"c6-2.h" /* �������Ĵ洢�ṹ */
 #include"func9-1.c"

 Status SearchBST1(BiTree *T,KeyType key,BiTree f,BiTree *p) /* �㷨9.5(b) */
 { /* �ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ������� */
   /* �ɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE������ָ��pָ�����·���� */
   /* ���ʵ����һ����㲢����FALSE��ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
   if(!*T) /* ���Ҳ��ɹ� */
   {
     *p=f;
     return FALSE;
   }
   else if EQ(key,(*T)->data.key) /*  ���ҳɹ� */
   {
     *p=*T;
     return TRUE;
   }
   else if LT(key,(*T)->data.key)
     return SearchBST1(&(*T)->lchild,key,*T,p); /* ���������м������� */
   else
     return SearchBST1(&(*T)->rchild,key,*T,p); /*  ���������м������� */
 }

 Status InsertBST(BiTree *T, ElemType e)
 { /* ������������T�в����ڹؼ��ֵ���e.key������Ԫ��ʱ������e������TRUE�����򷵻�FALSE���㷨9.6 */
   BiTree p,s;
   if(!SearchBST1(T,e.key,NULL,&p)) /* ���Ҳ��ɹ� */
   {
     s=(BiTree)malloc(sizeof(BiTNode));
     s->data=e;
     s->lchild=s->rchild=NULL;
     if(!p)
       *T=s; /* ������*sΪ�µĸ���� */
     else if LT(e.key,p->data.key)
       p->lchild=s; /* ������*sΪ���� */
     else
       p->rchild=s; /* ������*sΪ�Һ��� */
     return TRUE;
   }
   else
     return FALSE; /* �������йؼ�����ͬ�Ľ�㣬���ٲ��� */
 }

 void Delete(BiTree *p)
 { /* �Ӷ�����������ɾ�����p�����ؽ�����������������㷨9.8 */
   BiTree q,s;
   if(!(*p)->rchild) /* p������������ֻ���ؽ�����������(��ɾ�����Ҷ��Ҳ�ߴ˷�֧) */
   {
     q=*p;
     *p=(*p)->lchild;
     free(q);
   }
   else if(!(*p)->lchild) /* p���������գ�ֻ���ؽ����������� */
   {
     q=*p;
     *p=(*p)->rchild;
     free(q);
   }
   else /* p���������������� */
   {
     q=*p;
     s=(*p)->lchild;
     while(s->rchild) /* ת��Ȼ�����ҵ���ͷ(�Ҵ�ɾ����ǰ��) */
     {
       q=s;
       s=s->rchild;
     }
     (*p)->data=s->data; /* sָ��ɾ���ģ�ǰ����(����ɾ���ǰ����ֵȡ����ɾ����ֵ) */
     if(q!=*p) /* ���1 */
       q->rchild=s->lchild; /* �ؽ�*q�������� */
     else /* ���2 */
       q->lchild=s->lchild; /* �ؽ�*q�������� */
     free(s);
   }
 }

 Status DeleteBST(BiTree *T,KeyType key)
 { /* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ�㣬 */
   /* ������TRUE�����򷵻�FALSE���㷨9.7 */
   if(!*T) /* �����ڹؼ��ֵ���key������Ԫ�� */
     return FALSE;
   else
   {
     if EQ(key,(*T)->data.key) /* �ҵ��ؼ��ֵ���key������Ԫ�� */
       Delete(T);
     else if LT(key,(*T)->data.key)
       DeleteBST(&(*T)->lchild,key);
     else
       DeleteBST(&(*T)->rchild,key);
     return TRUE;
   }
 }
