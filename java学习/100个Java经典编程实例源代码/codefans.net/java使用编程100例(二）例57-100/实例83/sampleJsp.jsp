<%-- ָ���ļ����� --%>
<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<%-- ���������� --%>
<%@ page import="java.util.Date" %>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>ʹ��JSP�ļ�ʵ��</title>
<style type="text/css">
<!--
.style1 {
	font-size: 16px;
	font-weight: bold;
}
-->
</style>
</head>
<%
String message = "��ã���ʱJSP��̬�����ҳ����ʾ��";
%>
<body>
<p align="center" class="style1">��ӭ�Ķ���Javaʵ��һ������</p>
<p align="center">��ã���ʱHTML��������ľ�̬��ʾ��</p>
<p align="center"><%= message %> </p>
<p align="center">����ʱ�䣺<%= new Date() %> </p>
</body>
</html>
