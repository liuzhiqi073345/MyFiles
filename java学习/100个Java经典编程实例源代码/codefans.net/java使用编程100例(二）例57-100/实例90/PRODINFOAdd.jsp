<%@ page contentType="text/html; charset=GB2312"%>
<jsp:useBean id="fileBean" scope="page" class="com.bean.MoqUploadBean" />
<html> 
<head>
<title></title>
</head>
<body bgcolor="#FFFFFF" text="#000000">
<div align="center">�����Ʒ���</div><br><br>
<%
//�����ϴ�·��
fileBean.getUpLoadPath();
//�����ϴ��ߴ�
fileBean.setSize(10000*1024);
//�����ϴ��ļ�����
fileBean.setSuffix(".gif.jpg.html.htm.txt.swf");
//��ȡ����
fileBean.setSourceFile(request);
String [] saSourceFile = fileBean.getSourceFile();
String [] saObjectFile = fileBean.getObjectFileName();
String [] saDescription = fileBean.getDescription();
int iCount = fileBean.getCount();
String sObjectPath = fileBean.getObjectPath();
/**
for(int i=0;i<iCount;i++) {
  out.println("<br>Դʼ�ļ�:");
  out.println(saSourceFile[i]);
  out.println("<br>Ŀ���ļ�:");
  out.println(sObjectPath+saObjectFile[i]);
  out.println("<br>�ϴ�����:");
  out.println(saDescription[i]);
  out.println("<br>");
}
**/
%>
<table width="100%" border="0">
<%
String CLASSID = fileBean.getFieldValue("CLASSID");
String PNAME = fileBean.getFieldValue("PNAME");
String PDESC = fileBean.getFieldValue("PDESC");
String PUSE = fileBean.getFieldValue("PUSE");
String PREPRICE = fileBean.getFieldValue("PREPRICE");
String CURRPRICE = fileBean.getFieldValue("CURRPRICE");
String AMOUNT = fileBean.getFieldValue("AMOUNT");
String STATUS = fileBean.getFieldValue("STATUS");
String MODEL = fileBean.getFieldValue("MODEL");
String BRANDNAME = fileBean.getFieldValue("BRANDNAME");

String POSTFEE = fileBean.getFieldValue("POSTFEE");
String UNIT = fileBean.getFieldValue("UNIT");
String ATTACHMENT = fileBean.getFieldValue("ATTACHMENT");
String ONLINEDATE = fileBean.getFieldValue("ONLINEDATE");

%>

<tr>
  <td width="23%" align="right"><img src="upload/<%=saObjectFile[1]%>"></td>
  <td width="77%">
  <img src="upload/<%=saObjectFile[0]%>" width="200" higth="200">
  </td>
</tr>
<tr>
  <td width="23%" align="right">��Ʒ����:</td>
  <td width="77%">
  <%=PNAME%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">��Ʒ����:</td>
  <td width="77%">
  <%=PDESC%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">��Ʒ��;:</td>
  <td width="77%">
  <%=PUSE%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">��Ʒԭ�۸�:</td>
  <td width="77%">
  <%=PREPRICE%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">��Ʒ���ڼ۸�:</td>
  <td width="77%">
  <%=CURRPRICE%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">�����:</td>
  <td width="77%">
  <%=AMOUNT%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">�Ƿ��ϼ�:</td>
  <td width="77%">
  <%if(STATUS==null) out.print("���ϼ�"); else out.print("�ϼ�");%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">��Ʒ�ͺ�:</td>
  <td width="77%">
  <%=MODEL%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">�̱�:</td>
  <td width="77%">
  <%=BRANDNAME%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">��λ:</td>
  <td width="77%">
  <%=UNIT%>
  </td>
</tr>
<tr>
  <td width="23%" align="right">����˵��:</td>
  <td width="77%">
  <%=ATTACHMENT%>
  </td>
</tr>

</table>

</body>
</html>