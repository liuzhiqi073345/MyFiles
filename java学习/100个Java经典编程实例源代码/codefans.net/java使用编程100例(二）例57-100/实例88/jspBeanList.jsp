<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" %>
<%
/**
���ļ���ʾʹ��Bean�������ݿ⣬����ѯTBL_USER����������ݼ�¼<br>
��Ȩ���У� �Ž� ;<br>
**/
%>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<jsp:useBean id="conn" scope="page" class="com.bean.JDBCConn" />

<html> 
<head> 
<title>Javaʵ��100��</title> 
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<script language='javascript'>
   function toUrl(num){
      window.location.href="jspBeanList.jsp?pageNo="+num;
   }
</script>
<style type="text/css">
<!--
.style3 {font-size: large}
-->
</style>
</head> 

<%
String pageStr=(String)request.getParameter("pageNo");
int pageSize = 10;
if(pageStr==null || pageStr.equals(""))	pageStr="1";
int pageNo = java.lang.Integer.parseInt(pageStr);
if (pageNo==0) pageNo=1;

//���ò���
String sql="SELECT * FROM TEST.TBL_USER ORDER BY ID ASC";


//�õ������
Vector vResult=new Vector();
vResult=conn.query(sql,pageNo,pageSize);
System.out.println("&&&&&"+vResult);

//���㷭ҳ����
int count=Integer.parseInt((String)vResult.elementAt(0));
int pageCount=(int)((count-1)/pageSize + 1);
%>
<body topmargin="40" leftmargin="0" bgcolor="#FFFFFF" text="#000000"> 

<table width="75%" border="0" align="center" bgcolor="#CCCCFF">
<tr ><td align="center"><span class="style3">�û���¼����</span>����������ʾ
</td>
</tr>
<tr ><td >
 <table width="100%" border="0" cellpadding="0">
   <tr bgcolor="#FFFFFF">
    <th scope="col"><kbd>ID</kbd></th>
    <th scope="col"><kbd>�û���</kbd></th>
    <th scope="col"><kbd>����</kbd></th>
  </tr>
<%
for (int i=1;i<vResult.size();i++) {
  Vector vResultRow=new Vector();
  System.out.println("1111"+vResultRow);
  vResultRow=(Vector)vResult.elementAt(i);
   String str_ID=(String)vResultRow.elementAt(0);
   String str_Name=(String)vResultRow.elementAt(1);
   String str_PWD=(String)vResultRow.elementAt(2);

%>
 <tr bgcolor="#FFFFFF">
<td ><%=str_ID%></td>
<td ><%=str_Name%></td>
<td ><%=str_PWD%></td>
</tr>
<%} %>

</table>
<tr>
  <td colspan="2" align="right">
  <%if (pageNo==1){
    out.print("��ҳ ��һҳ"); 
    }else{
%>
<a href="javascript:toUrl('1');">��ҳ</a>  <a href="javascript:toUrl('<%=pageNo-1%>');">��һҳ</a> 
<% } %>
<% if (pageNo+1>pageCount){
     out.print ("��һҳ βҳ");
   }else{
%>
<a href="javascript:toUrl('<%=pageNo+1%>');">��һҳ</a> <a href="javascript:toUrl('<%=pageCount%>');">βҳ</a>
<% } %>
  </td>
  </tr>
  </td></tr>
  
</table>
</body> 
</html> 



