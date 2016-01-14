// shortestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "shortest.h"
#include "shortestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortestDlg dialog

CShortestDlg::CShortestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShortestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShortestDlg)
	m_Info = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShortestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShortestDlg)
	DDX_Text(pDX, IDC_INFO, m_Info);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShortestDlg, CDialog)
	//{{AFX_MSG_MAP(CShortestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortestDlg message handlers

BOOL CShortestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	int i;
	CreateFUDN(g); // ͨ���ļ�����������g
    for(i=0;i<g.vexnum;i++)
      g.arcs[i][i]=0; // ShortestPath_FLOYD()Ҫ��Խ�Ԫ��ֵΪ0,��Ϊ������ͬ,�����Ϊ0
    ShortestPath_FLOYD(g,p,d); // ��ÿ�Զ��������·��	
	r=14;
	count=0;
	for(i=0;i<2;i++)
	  number[i]=0;
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShortestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShortestDlg::OnPaint() 
{
	int i,j,q;
	CPaintDC dc(this); // device context for painting
	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	    CRect rcClient;
		GetClientRect(&rcClient);
		CFont /*fnBig,*/fnBig2;
		dc.SetTextAlign(TA_CENTER);
		fnBig2.CreatePointFont(120,"����",&dc);
		dc.SetBkMode(TRANSPARENT); // �����ı��ı���Ϊ͸��
		CFont *pFont2=dc.SelectObject(&fnBig2);
		dc.TextOut(280,10,"ȫ����·��ͨʾ��ͼ");
		CFont fnBig;
		fnBig.CreatePointFont(90,"����",&dc);
		CFont *pFont=dc.SelectObject(&fnBig);
		dc.SelectStockObject(NULL_BRUSH); // ����ͼ�����Ϊ͸��
		for(i=0;i<g.vexnum;i++)
		{
			dc.Ellipse(g.vexs[i].x-r,g.vexs[i].y-r,g.vexs[i].x+r,g.vexs[i].y+r);
			if(i>2)
				dc.TextOut(g.vexs[i].x,g.vexs[i].y-r/2,g.vexs[i].a);
		}
		dc.TextOut(70,20,g.vexs[0].a); // ��4���������ı�����
		dc.TextOut(278,60,g.vexs[1].a);
		dc.TextOut(574,20,g.vexs[2].a);
		CString m;
		for(i=0;i<g.vexnum;i++)
		{
			for(j=0;j<i;j++)
				if(g.arcs[i][j]!=INFINITY)
				{
			m.Format("%d",g.arcs[i][j]);
			X=g.vexs[j].x-g.vexs[i].x;
			Y=g.vexs[j].y-g.vexs[i].y;
			R=sqrt(X*X+Y*Y);
		    q=int(atan(-Y/X)*1800/3.14159216);
 		    x=int(r*X/R);
			y=int(r*Y/R);
			dc.MoveTo(g.vexs[i].x+x,g.vexs[i].y+y);
			dc.LineTo(g.vexs[j].x-x,g.vexs[j].y-y);
			CFont fnBig1;
			fnBig1.CreateFont(r,0,q,q,int(q*2),
			FALSE,FALSE,FALSE,ANSI_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,PROOF_QUALITY,
			DEFAULT_PITCH+FF_DONTCARE,"����");
			CFont *pFont1=dc.SelectObject(&fnBig1);
            dc.TextOut(g.vexs[j].x-int(X/2),g.vexs[j].y-int(Y/2)+2,m);
				}
		}
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShortestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int CShortestDlg::LocateVex(MGraph G, VertexType u)
 { // ��ʼ����: ͼG����,u��G�ж�������ͬ����
   // �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1
   int i;
   for(i=0;i<G.vexnum;++i)
     if(strcmp(u,G.vexs[i].a)==0)
       return i;
   return -1;
 }

void CShortestDlg::CreateFUDN(MGraph &G)
 { // ��������(�ڽӾ���)��ʾ��,���ļ�����û�������Ϣ��������G
   int i,j,k,w;
   VertexType va,vb;
   FILE *graphlist;
   graphlist=fopen("mapvc.txt","r"); // �������ļ�,����graphlist��ʾ
   fscanf(graphlist,"%d",&G.vexnum);
   fscanf(graphlist,"%d",&G.arcnum);
   for(i=0;i<G.vexnum;++i) // ���춥������
     fscanf(graphlist,"%s%d%d",G.vexs[i].a,&G.vexs[i].x,&G.vexs[i].y);
   for(i=0;i<G.vexnum;++i) // ��ʼ���ڽӾ���
     for(j=0;j<G.vexnum;++j)
       G.arcs[i][j]=INFINITY; // ��
   for(k=0;k<G.arcnum;++k)
   {
     fscanf(graphlist,"%s%s%d",va,vb,&w);
     i=LocateVex(G,va);
     j=LocateVex(G,vb);
     G.arcs[i][j]=G.arcs[j][i]=w; // ������
   }
   fclose(graphlist); // �ر������ļ�
 }


void CShortestDlg::ShortestPath_FLOYD(MGraph G, PathMatrix P, DistancMatrix D)
 { // ��Floyd�㷨��������G�и��Զ���v��w֮������·��P[v][w]�����Ȩ����D[v][w]��
   // ��P[v][w][u]ΪTRUE,��u�Ǵ�v��w��ǰ������·���ϵĶ��㡣�㷨7.16
   int u,v,w,i;
   for(v=0;v<G.vexnum;v++) // ���Խ��֮���ʼ��֪·��������
     for(w=0;w<G.vexnum;w++)
     {
       D[v][w]=G.arcs[v][w]; // ����v������w��ֱ�Ӿ���
       for(u=0;u<G.vexnum;u++)
	 P[v][w][u]=FALSE; // ·�������ֵ
       if(D[v][w]<INFINITY) // ��v��w��ֱ��·��
	 P[v][w][v]=P[v][w][w]=TRUE; // ��v��w��·������v��w����
     }
   for(u=0;u<G.vexnum;u++)
     for(v=0;v<G.vexnum;v++)
       for(w=0;w<G.vexnum;w++)
	 if(D[v][u]<INFINITY&&D[u][w]<INFINITY&&D[v][u]+D[u][w]<D[v][w])
	 { // ��v��u��w��һ��·������
	   D[v][w]=D[v][u]+D[u][w]; // ������̾���
	   for(i=0;i<G.vexnum;i++)
	     P[v][w][i]=P[v][u][i]||P[u][w][i]; // ��v��w��·��������v��u�ʹ�u��w������·��
	 }
 }

void CShortestDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
  // TODO: Add your message handler code here and/or call default

  CString strMessage,ss;
  CDC* pDC=GetDC();  
  pDC->SelectStockObject(NULL_BRUSH); // ����ͼ�����Ϊ͸��
  CPen pendot(PS_DOT,1,RGB(0,0,0)); // ��ɫ����
  CPen penblack(PS_SOLID,1,RGB(0,0,0)); // ��ɫʵ��
  CPen *pOldPen;
  int i,k;
  count++;
  if(count%2) // ����������������
  {
    if(count>1) // ���ǵ�һ������̾��룬Ҫ�úڱ��ػ�
	{
	  pOldPen=pDC->SelectObject(&penblack); // ���úڱ��ػ� 
      pDC->Ellipse(g.vexs[number[0]].x-r,g.vexs[number[0]].y-r,g.vexs[number[0]].x+r,g.vexs[number[0]].y+r); // ���
      pDC->Ellipse(g.vexs[number[1]].x-r,g.vexs[number[1]].y-r,g.vexs[number[1]].x+r,g.vexs[number[1]].y+r); // �յ�
      k=1;
	  while(pa[k]!=-1)
	  {
	    X=double(g.vexs[pa[k]].x-g.vexs[pa[k-1]].x);
	    Y=double(g.vexs[pa[k]].y-g.vexs[pa[k-1]].y);
	    R=sqrt(X*X+Y*Y);
 	    x=int(r*X/R);
	    y=int(r*Y/R);
	    pDC->MoveTo(g.vexs[pa[k-1]].x+x,g.vexs[pa[k-1]].y+y);
	    pDC->LineTo(g.vexs[pa[k]].x-x,g.vexs[pa[k]].y-y);
	    pDC->Ellipse(g.vexs[pa[k]].x-r,g.vexs[pa[k]].y-r,g.vexs[pa[k]].x+r,g.vexs[pa[k]].y+r);
		k++;
	  };
	}
	pOldPen=pDC->SelectObject(&pendot); // �����߻� 
    for(i=0;i<g.vexnum;i++)
	{
	  X=double(point.x-g.vexs[i].x);
	  Y=double(point.y-g.vexs[i].y);
	  if(int(sqrt(X*X+Y*Y))<=r)
	  {
        pDC->Ellipse(g.vexs[i].x-r,g.vexs[i].y-r,g.vexs[i].x+r,g.vexs[i].y+r); // �ú���ػ��������֮����
	    number[0]=i; // ���¸ö���֮���
		break;
	  }
	}
	m_Info=""; // ��̬�ı���Ϊ��
	UpdateData(FALSE);
  }
  else// ����������ż����
  {
    pOldPen=pDC->SelectObject(&pendot); // �����߻� 
    for(i=0;i<g.vexnum;i++)
	{
	  X=point.x-g.vexs[i].x;
	  Y=point.y-g.vexs[i].y;
	  if(sqrt(X*X+Y*Y)<=r)
	  {
        pDC->Ellipse(g.vexs[i].x-r,g.vexs[i].y-r,g.vexs[i].x+r,g.vexs[i].y+r); // �ú���ػ��������֮����
	    number[1]=i; // ���¸ö���֮���
		break;
	  }
	}
	if(d[number[0]][number[1]]<INFINITY) // ��ͨ·
	{
	  path1(g,p,number[0],number[1],pa); // �����·�����������е��յ������;�������ĳ���
	  strMessage.Format("%s��%s����̾���Ϊ%d\n;��: %s ",g.vexs[number[0]].a,g.vexs[number[1]].a,d[number[0]][number[1]],g.vexs[pa[0]].a);
	  int k=1;
	  while(pa[k]!=-1)
	  {
		X=g.vexs[pa[k]].x-g.vexs[pa[k-1]].x;
		Y=g.vexs[pa[k]].y-g.vexs[pa[k-1]].y;
		R=sqrt(X*X+Y*Y);
 		x=int(r*X/R);
		y=int(r*Y/R);
		pDC->MoveTo(g.vexs[pa[k-1]].x+x,g.vexs[pa[k-1]].y+y);
		pDC->LineTo(g.vexs[pa[k]].x-x,g.vexs[pa[k]].y-y);
		pDC->Ellipse(g.vexs[pa[k]].x-r,g.vexs[pa[k]].y-r,g.vexs[pa[k]].x+r,g.vexs[pa[k]].y+r);
		ss.Format("%s ",g.vexs[pa[k++]].a);
		strMessage+=ss;
	  };
	}
    else
	{
	  strMessage.Format("%s��%sû��·����ͨ\n",g.vexs[number[0]].a,g.vexs[number[1]].a);
	  pa[1]=-1; // �����ߵı�־
	}
	m_Info=strMessage;
	UpdateData(FALSE);
  }
  CDialog::OnLButtonDown(nFlags, point);
}

void CShortestDlg::path1(MGraph G, PathMatrix P, int i, int j, int pa[])
{ // �������Ϊi�������е����Ϊj���յ�������·����;�������ĳ���
  int k,l;
  int m=i; // ��������Ÿ���m
  l=0;
  for(k=0;k<G.vexnum;k++)
    pa[k]=-1; // pa�ĳ�ֵ
  while(m!=j) // û���յ����
  {
    G.arcs[m][m]=INFINITY; // �Խ�Ԫ�ظ�ֵ�����
    for(k=0;k<G.vexnum;k++)
      if(G.arcs[m][k]<INFINITY&&P[m][j][k]) // m��k��ֱ��ͨ·����k��m��j�����·����
      {
	    pa[l++]=m;
		G.arcs[m][k]=G.arcs[k][m]=INFINITY; // ��ֱ��ͨ·��Ϊ��ͨ
		m=k; // �����ĳ�����Ÿ���m����������
		break;
      }
  }
  pa[l]=j; // �յ����
}
