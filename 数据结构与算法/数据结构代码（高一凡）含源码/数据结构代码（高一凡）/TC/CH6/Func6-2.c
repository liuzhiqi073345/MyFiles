 /* func6-2.c bo6-5.c��algo7-1.c���� */
 void PreOrderTraverse(CSTree T,void(*Visit)(TElemType))
 { /* �ȸ��������ӡ��ֵܶ�������ṹ����T */
   if(T)
   {
     Visit(T->data); /* �ȷ��ʸ���� */
     PreOrderTraverse(T->firstchild,Visit); /* ���ȸ������������� */
     PreOrderTraverse(T->nextsibling,Visit); /* ����ȸ�������һ���ֵ����� */
   }
 }
