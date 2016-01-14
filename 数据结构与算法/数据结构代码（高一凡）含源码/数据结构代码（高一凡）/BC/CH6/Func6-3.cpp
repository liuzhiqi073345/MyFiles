 // func6-3.cpp bo6-2.cpp��func9-1.cpp����
 void InitBiTree(BiTree &T)
 { // �������������ն�����T
   T=NULL;
 }

 void DestroyBiTree(BiTree &T)
 { // ��ʼ������������T���ڡ�������������ٶ�����T
   if(T) // �ǿ���
   {
     if(T->lchild) // ������
       DestroyBiTree(T->lchild); // ������������
     if(T->rchild) // ���Һ���
       DestroyBiTree(T->rchild); // �����Һ�������
     free(T); // �ͷŸ����
     T=NULL; // ��ָ�븳0
   }
 }

 void PreOrderTraverse(BiTree T,void(*Visit)(TElemType))
 { // ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú������㷨6.1���иĶ�
   // �������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
   if(T) // T����
   {
     Visit(T->data); // �ȷ��ʸ����
     PreOrderTraverse(T->lchild,Visit); // ���������������
     PreOrderTraverse(T->rchild,Visit); // ����������������
   }
 }

 void InOrderTraverse(BiTree T,void(*Visit)(TElemType))
 { // ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
   // �������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
   if(T)
   {
     InOrderTraverse(T->lchild,Visit); // ���������������
     Visit(T->data); // �ٷ��ʸ����
     InOrderTraverse(T->rchild,Visit); // ����������������
   }
 }