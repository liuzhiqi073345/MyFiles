<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" %>
<%
/**
�˳���ʵ�����ݿ��ѯ����ʵ�ַ�ҳ��ʾ��<br>
��Ȩ���У� �Ž� ;<br>
**/
%>
<%
//�������ݿ�������Ϣ
String MM_conn_DRIVER = "oracle.jdbc.driver.OracleDriver";
String MM_conn_USERNAME = "test";
String MM_conn_PASSWORD = "test";
String MM_conn_STRING = "jdbc:oracle:thin:@127.0.0.1:1521:ORCL";
//��ȡ���ݿ����Ӻͽ����
Driver DriverRecordset1 = (Driver)Class.forName(MM_conn_DRIVER).newInstance();
Connection ConnRecordset1 = DriverManager.getConnection(MM_conn_STRING,MM_conn_USERNAME,MM_conn_PASSWORD);
Statement stmt = ConnRecordset1.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_READ_ONLY);
ResultSet rs = stmt.executeQuery("SELECT * FROM TEST.TBL_USER ORDER BY ID ASC");

//ҳ���ʼ��
String pageStr=(String)request.getParameter("pageNo");
int pageSize = 10;
if(pageStr==null || pageStr.equals(""))	pageStr="1";
int pageNo = java.lang.Integer.parseInt(pageStr);
if (pageNo==0) pageNo=1;

//��ȡ��¼����
rs.last();  
int intRowCount = rs.getRow(); 
//������ҳ��  
int intPageCount = (intRowCount+pageSize-1) / pageSize;
//��������ʾ��ҳ��  
if(pageNo>intPageCount) pageNo = intPageCount; 

//����¼ָ�붨λ������ʾҳ�ĵ�һ����¼��  
rs.absolute((pageNo-1) * pageSize + 1); 
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�û���¼����</title>
<style type="text/css">
<!--
.style3 {font-size: large}
-->
</style>
<script language='javascript'>
   function toUrl(num){
      window.location.href="jspJDBC.jsp?pageNo="+num;
   }
</script>
</head>

<body>
<table width="70%"  border="0" align="center" bgcolor="#00CC99">
   <tr>
     <th colspan="3" bgcolor="#00CCCC" scope="col"><span class="style3">�û���¼����</span>����������ʾ</th>
   </tr>
   <tr bgcolor="#FFFFFF">
    <th scope="col"><kbd>ID</kbd></th>
    <th scope="col"><kbd>�û���</kbd></th>
    <th scope="col"><kbd>����</kbd></th>
  </tr>
 <%
 int i = 0;
 while(i<pageSize && !rs.isAfterLast())
 {
  %>
  <tr bgcolor="#FFFFFF">
    <th width="28%" scope="col"><%=rs.getObject("ID")%></th>
    <th width="27%" scope="col"><%=rs.getObject("NAME")%></th>
    <th width="45%" scope="col"><%=rs.getObject("PASSWORD")%></th>
  </tr>
<%
 rs.next();
 i++;
 }
%>
<tr>
    <th colspan="3" scope="row">
<%if (pageNo==1){
    out.print("��ҳ ��һҳ"); 
    }else{
%>
<a href="javascript:toUrl('1');">��ҳ</a>  <a href="javascript:toUrl('<%=pageNo-1%>');">��һҳ</a> 
<% } %>
<% if (pageNo+1>intPageCount){
     out.print ("��һҳ βҳ");
   }else{
%>
<a href="javascript:toUrl('<%=pageNo+1%>');">��һҳ</a> <a href="javascript:toUrl('<%=intPageCount%>');">βҳ</a>
<% } %>
    </th>
  </tr>
</table>
</body>
</html>
<%
//�ر����ݿ����ӣ��ͷ���Դ��
rs.close();
stmt.close();
ConnRecordset1.close();
%>

