<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" %>
<%@ page import="javax.naming.*" %>
<%@ page import ="javax.sql.DataSource" %>
<%
/**
�˳���ʵ��ʹ���������ӳز�ѯ���ݿ⣬��ʵ�ַ�ҳ��ʾ��<br>
��Ȩ���У� �Ž� ;<br>
**/
%>
<%
//��������Դ��¼��Ϣ
Hashtable ht = new Hashtable();
String dbPoolName = "myPool";
String user = "system";  //����ĵ�¼�������û���
String password = "weblogic";  //��¼����������
//���ý�������
ht.put(Context.INITIAL_CONTEXT_FACTORY,"weblogic.jndi.WLInitialContextFactory");
ht.put(Context.PROVIDER_URL,"t3://localhost:7001");
Context ctx = new InitialContext(ht);
//��ȡ����Դ
DataSource ds = (DataSource)ctx.lookup(dbPoolName);
//������������
Connection conn = ds.getConnection(user,password);//�˴���WebLogic7��¼�û��������� 
Statement stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_READ_ONLY);
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
      window.location.href="jspJDBCPool.jsp?pageNo="+num;
   }
</script>
</head>

<body>
<table width="70%"  border="0" align="center" bgcolor="#99CC99">
   <tr>
     <th colspan="3" bgcolor="#99CC99" scope="col"><span class="style3">�û���¼����</span>����������ʾ</th>
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
conn.close();
%>

