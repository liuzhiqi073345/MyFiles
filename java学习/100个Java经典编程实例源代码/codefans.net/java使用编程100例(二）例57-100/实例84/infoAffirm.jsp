<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%
//��ȡ�ͻ��ύ��Ϣ
String name = (String)request.getParameter("username");
String nick = (String)request.getParameter("nickname");
String sex = (String)request.getParameter("sex");
String educate = (String)request.getParameter("educate");
String birthday = (String)request.getParameter("birthday");
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�û���Ϣȷ��</title>
</head>

<body>
<table width="70%"  border="0" align="center" bgcolor="#00CC33">
<tr><td >
<table width="100%"  border="0" align="center">
  <tr>
    <th colspan="2" scope="col">�û���Ϣ��д</th>
  </tr>
  <tr bgcolor="#FFFFFF">
    <th width="27%" scope="row"><div align="right">�û�����</div></th>
    <td width="73%"><%=name%></td>
  </tr>
  <tr bgcolor="#FFFFFF">
    <th scope="row"><div align="right">�ǳƣ�</div></th>
    <td><%=nick%></td>
  </tr>
  <tr bgcolor="#FFFFFF">
    <th scope="row"><div align="right">�Ա�</div></th>
    <td><% if(sex.equals("1")) out.print("��"); else out.print("Ů");%></td>
  </tr>
  <tr bgcolor="#FFFFFF">
    <th scope="row"><div align="right">ѧ����</div></th>
    <td><%
	int ii = Integer.parseInt(educate);
	switch (ii){
	   case 1 :
	     out.print("Сѧ");
	     break;
	  case 2 :
	     out.print("����");
	     break;
	  case 3 :
	     out.print("����");
	     break;
	case 4 :
	     out.print("��ѧ");
	     break;
	}
	%></td>
  </tr>
  <tr bgcolor="#FFFFFF">
    <th scope="row"><div align="right">������</div></th>
    <td><%=birthday%></td>
  </tr>
  <tr bgcolor="#FFFFFF">
    <th scope="row"><div align="right"></div></th>
    <td>&nbsp;</td>
  </tr>
  <tr bgcolor="#FFFFFF">
    <th scope="row"><div align="right"></div></th>
    <td><input type="submit" name="Submit" value="ȷ��">
            </td>
  </tr>
</table>
</td></tr>
</table>
</body>
</html>
