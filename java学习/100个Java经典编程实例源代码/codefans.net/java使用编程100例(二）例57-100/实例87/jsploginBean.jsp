<%@ page contentType="text/html; charset=GB2312"%>
<jsp:useBean id="myBean" scope="page" class="com.bean.myBean" />
<jsp:setProperty name="myBean" property="*" />
<%
int iResult = myBean.check();
if(iResult==1){ 
%>
��¼�ɹ��� ��ӭ<%=myBean.getNAME()%>����Java���硣
<%
}
if(iResult==0){
%>
��¼ʧ�ܣ�<%=myBean.getNAME()%>û�������ɫ�� ���<a href="javascript:history.back(-1);">����</a>���µ�¼�� 
<%
}
if(iResult==-1){
%>
��¼ʧ�ܣ�<%=myBean.getNAME()%>�����벻��ȷ�����<a href="javascript:history.back(-1);">����</a>���µ�¼�� 
<%
}
if(iResult==-2){
%>
��¼ʧ�ܣ�û��<%=myBean.getNAME()%>�û������<a href="javascript:history.back(-1);">����</a>���µ�¼�� 
<%
}
%>