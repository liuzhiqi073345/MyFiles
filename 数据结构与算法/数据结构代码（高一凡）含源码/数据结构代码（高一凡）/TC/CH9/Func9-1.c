 /* func9-1.c �����㷨9.5(a)��func6-3.c,bo9-2.c��bo9-3.c���� */
 #include"func6-3.c" /* ����InitBiTree()��DestroyBiTree()��PreOrderTraverse()��InOrderTraverse()4���� */
 #define InitDSTable InitBiTree /* ���ʼ���������Ĳ���ͬ */
 #define DestroyDSTable DestroyBiTree /* �����ٶ������Ĳ���ͬ */
 #define TraverseDSTable InOrderTraverse /* ����������������Ĳ���ͬ */

 BiTree SearchBST(BiTree T,KeyType key)
 { /* �ڸ�ָ��T��ָ�����������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ�أ� */
   /* �����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ�롣�㷨9.5(a) */
   if(!T||EQ(key,T->data.key))
     return T; /* ���ҽ��� */
   else if LT(key,T->data.key) /* ���������м������� */
     return SearchBST(T->lchild,key);
   else
     return SearchBST(T->rchild,key); /* ���������м������� */
 }