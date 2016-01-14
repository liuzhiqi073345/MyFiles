 /* bo2-9.c ����ͷ���ĵ�����(�洢�ṹ��c2-2.h����)�Ĳ��ֻ�������(2��) */
 Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����*/
   /*           ����OK���������ʧ�ܣ�pre_e�޶��壬����INFEASIBLE */
   LinkList q,p=L; /* pָ���һ����� */
   while(p->next) /* p��ָ����к�� */
   {
     q=p->next; /* qΪp�ĺ�� */
     if(q->data==cur_e)
     {
       *pre_e=p->data;
       return OK;
     }
     p=q; /* p����� */
   }
   return INFEASIBLE;
 }

 Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�*/
   /*           ����OK���������ʧ�ܣ�next_e�޶��壬����INFEASIBLE */
   LinkList p=L; /* pָ���һ����� */
   while(p->next) /* p��ָ����к�� */
   {
     if(p->data==cur_e)
     {
       *next_e=p->next->data;
       return OK;
     }
     p=p->next;
   }
   return INFEASIBLE;
 }