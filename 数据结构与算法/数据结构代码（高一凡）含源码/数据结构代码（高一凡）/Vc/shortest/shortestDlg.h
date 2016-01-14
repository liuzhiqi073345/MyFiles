// shortestDlg.h : header file
//

#if !defined(AFX_SHORTESTDLG_H__09351F68_AD8D_11D8_BBBC_00D00916554C__INCLUDED_)
#define AFX_SHORTESTDLG_H__09351F68_AD8D_11D8_BBBC_00D00916554C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
 #include<math.h> // EOF(=^Z��F6),NULL
 #define TRUE 1
 #define FALSE 0
 #define INFINITY INT_MAX // ���������ֵ�����
 #define MAX_VERTEX_NUM 26 // ��󶥵����
 #define MAX_NAME 9
 typedef char VertexType[MAX_NAME];
 typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 3ά����
 typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 2ά����
 struct bb
 {
   VertexType a;
   int x;
   int y;
 };
 struct MGraph
 {
   bb vexs[MAX_VERTEX_NUM]; // ��������
   int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // �ڽӾ���
   int vexnum,arcnum; // ͼ�ĵ�ǰ�������ͻ���
 };
 /////////////////////////////////////////////////////////////////////////////
// CShortestDlg dialog

class CShortestDlg : public CDialog
{
// Construction
public:
	void path1(MGraph G,PathMatrix P, int i, int j, int pa[]);
	void ShortestPath_FLOYD(MGraph G,PathMatrix P,DistancMatrix D);
	void CreateFUDN(MGraph &G);
	int LocateVex(MGraph G,VertexType u);
	MGraph g;
    int r,x,y,count,number[2]; // r�ǰ뾶
   PathMatrix p; // 3ά����
   DistancMatrix d; // 2ά����
  int pa[MAX_VERTEX_NUM];
  double R,X,Y;
	CShortestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShortestDlg)
	enum { IDD = IDD_SHORTEST_DIALOG };
	CString	m_Info;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShortestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShortestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORTESTDLG_H__09351F68_AD8D_11D8_BBBC_00D00916554C__INCLUDED_)
