<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" %>
<%@ page import="com.bean.Browser"%>
<%
Browser BR = new Browser(request, session);
%>
<html>
<head>
<title>Javaʵ��100��</title>
</head>
<body>
<p>
���������<%=BR.getName()%><br>
������汾��<%=BR.getVersion()%><br>
�����ʹ�����ԣ�<%=BR.getLanguage()%><br>
��������汾�ţ�<%=BR.getMainVersion()%><br>
�����С�汾�ţ�<%=BR.getMinorVersion()%><br>
�������Ʒ��˾��<%=BR.getCompany()%><br>
</p>
<p>
�ͻ�����ʱ����<%=BR.getLocale()%><br>
ʹ�õĲ���ϵͳ��<%=BR.getOs()%><br>
</p>
</body>
</html>
