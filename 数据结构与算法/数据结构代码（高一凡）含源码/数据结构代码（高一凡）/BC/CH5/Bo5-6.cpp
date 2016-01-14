 // bo5-6.cpp ��������չ��������洢(�洢�ṹ��c5-6.h����)�Ļ�������(13��)
 #include"func5-1.cpp" // �㷨5.8

 void InitGList(GList1 &L)
 { // �����յĹ����L
   L=NULL;
 }

 void CreateGList(GList1 &L,SString S) // �㷨5.7��
 { // ������չ��������洢�ṹ���ɹ�������д��ʽ��S���������L����emp="()"
   SString emp,sub,hsub;
   GList1 p;
   StrAssign(emp,"()"); // ��emp="()"
   if(!(L=(GList1)malloc(sizeof(GLNode1)))) // �����㲻�ɹ�
     exit(OVERFLOW);
   if(!StrCompare(S,emp)) // �����ձ�
   {
     L->tag=LIST;
     L->hp=L->tp=NULL;
   }
   else if(StrLength(S)==1) // ������ԭ�ӹ����
   {
     L->tag=ATOM;
     L->atom=S[1];
     L->tp=NULL;
   }
   else // ����һ���
   {
     L->tag=LIST;
     L->tp=NULL;
     SubString(sub,S,2,StrLength(S)-2); // ���������(ȥ����1���ַ������1���ַ�)����sub
     sever(sub,hsub); // ��sub�з������ͷ��hsub
     CreateGList(L->hp,hsub);
     p=L->hp;
     while(!StrEmpty(sub)) // ��β���գ����ظ���n���ӱ�
     {
       sever(sub,hsub); // ��sub�з������ͷ��hsub
       CreateGList(p->tp,hsub);
       p=p->tp;
     };
   }
 }

 void DestroyGList(GList1 &L)
 { // ��ʼ�����������L���ڡ�������������ٹ����L
   GList1 ph,pt;
   if(L) // L��Ϊ�ձ�
   { // ��ph��pt����L������ָ��
     if(L->tag) // ���ӱ�
       ph=L->hp;
     else // ��ԭ��
       ph=NULL;
     pt=L->tp;
     DestroyGList(ph); // �ݹ����ٱ�ph
     DestroyGList(pt); // �ݹ����ٱ�pt
     free(L); // �ͷ�L��ָ���
     L=NULL; // ��LΪ��
   }
 }

 void CopyGList(GList1 &T,GList1 L)
 { // ��ʼ�����������L���ڡ�����������ɹ����L���Ƶõ������T
   T=NULL;
   if(L) // L����
   {
     T=(GList1)malloc(sizeof(GLNode1));
     if(!T)
       exit(OVERFLOW);
     T->tag=L->tag; // ����ö�ٱ���
     if(L->tag==ATOM) // ���ƹ����岿��
       T->atom=L->atom; // ���Ƶ�ԭ��
     else
       CopyGList(T->hp,L->hp); // �����ӱ�
     if(L->tp==NULL) // ����β
       T->tp=L->tp;
     else
       CopyGList(T->tp,L->tp); // �����ӱ�
   }
 }

 int GListLength(GList1 L)
 { // ��ʼ�����������L���ڡ����������������L�ĳ��ȣ���Ԫ�ظ���
   int len=0;
   GList1 p=L->hp; // pָ���1��Ԫ��
   while(p)
   {
     len++;
     p=p->tp;
   };
   return len;
 }

 int GListDepth(GList1 L)
 { // ��ʼ�����������L���ڡ����������������L�����
   int max,dep;
   GList1 pp;
   if(L==NULL||L->tag==LIST&&!L->hp)
     return 1; // �ձ����Ϊ1
   else if(L->tag==ATOM)
     return 0; // ��ԭ�ӱ����Ϊ0��ֻ������ڵݹ������
   else // ��һ�������
     for(max=0,pp=L->hp;pp;pp=pp->tp)
     {
       dep=GListDepth(pp); // ����ppΪͷָ����ӱ����
       if(dep>max)
         max=dep;
     }
   return max+1; // �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
 }

 Status GListEmpty(GList1 L)
 { // ��ʼ�����������L���ڡ�����������ж������L�Ƿ�Ϊ��
   if(!L||L->tag==LIST&&!L->hp)
     return OK;
   else
     return ERROR;
 }

 GList1 GetHead(GList1 L)
 { // ���ɹ����L�ı�ͷԪ�أ�����ָ�����Ԫ�ص�ָ��
   GList1 h,p;
   if(!L||L->tag==LIST&&!L->hp) // �ձ��ޱ�ͷ
     return NULL;
   p=L->hp->tp; // pָ��L�ı�β
   L->hp->tp=NULL; // ��ȥL�ı�β����
   CopyGList(h,L->hp); // ����ͷԪ�ظ��Ƹ�h
   L->hp->tp=p; // �ָ�L�ı�β(����ԭL����)
   return h;
 }

 GList1 GetTail(GList1 L)
 { // �������L�ı�β����Ϊ���������ָ������¹�����ָ��
   GList1 t,p;
   if(!L||L->tag==LIST&&!L->hp) // �ձ��ޱ�β
     return NULL;
   p=L->hp; // pָ���ͷ
   L->hp=p->tp; // ��L��ɾȥ��ͷ
   CopyGList(t,L); // ��L�ı�β����t
   L->hp=p; // �ָ�L�ı�ͷ(����ԭL����)
   return t;
 }

 void InsertFirst_GL(GList1 &L,GList1 e)
 { // ��ʼ�������������ڡ��������������Ԫ��e(Ҳ�������ӱ�)��Ϊ�����L�ĵ�1Ԫ��(��ͷ)
   GList1 p=L->hp;
   L->hp=e;
   e->tp=p;
 }

 void DeleteFirst_GL(GList1 &L,GList1 &e)
 { // ��ʼ�����������L���ڡ����������ɾ�������L�ĵ�һԪ�أ�����e������ֵ
   if(L&&L->hp)
   {
     e=L->hp;
     L->hp=e->tp;
     e->tp=NULL;
   }
   else
     e=L;
 }

 void Traverse_GL(GList1 L,void(*v)(AtomType))
 { // ���õݹ��㷨���������L
   GList1 hp;
   if(L) // L����
   {
     if(L->tag==ATOM) // LΪ��ԭ��
     {
       v(L->atom);
       hp=NULL;
     }
     else // LΪ�ӱ�
       hp=L->hp;
     Traverse_GL(hp,v);
     Traverse_GL(L->tp,v);
   }
 }
