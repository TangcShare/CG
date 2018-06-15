; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCMDlg5
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CGDraw.h"
LastPage=0

ClassCount=12
Class1=CCGDrawApp
Class2=CCGDrawDoc
Class3=CCGDrawView
Class4=CMainFrame

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDD_MDLG
Class5=CAboutDlg
Resource3=IDD_MDLG5
Class6=CCMDlg
Resource4=IDR_MAINFRAME
Class7=CCMDlg1
Resource5=IDD_MDLG4
Class8=CCMDlg2
Resource6=IDD_MDLG3
Class9=CCMDlg3
Resource7=IDD_MDLG2
Class10=CCMDlg4
Resource8=IDD_MDLG1
Class11=CCMDlg5
Resource9=IDR_DRAW
Class12=CCMDlg6
Resource10=IDD_MDLG6

[CLS:CCGDrawApp]
Type=0
HeaderFile=CGDraw.h
ImplementationFile=CGDraw.cpp
Filter=N

[CLS:CCGDrawDoc]
Type=0
HeaderFile=CGDrawDoc.h
ImplementationFile=CGDrawDoc.cpp
Filter=N

[CLS:CCGDrawView]
Type=0
HeaderFile=CGDrawView.h
ImplementationFile=CGDrawView.cpp
Filter=C
LastObject=CCGDrawView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=CGDraw.cpp
ImplementationFile=CGDraw.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_DRAW]
Type=1
Class=?
Command1=ID_DRAWPOINT
Command2=ID_DRAWLINE
Command3=ID_DRAWPOL
Command4=ID_FILL
Command5=ID_CLEAR
Command6=ID_CUT
Command7=ID_DRAWREC
Command8=ID_ZOOM
Command9=ID_MIRROR
Command10=ID_ROTATE
Command11=ID_3D
Command12=ID_DRAWPOL1
Command13=ID_MOVE
Command14=ID_DEL
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_MDLG]
Type=1
Class=CCMDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CCMDlg]
Type=0
HeaderFile=CMDlg.h
ImplementationFile=CMDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_MDLG1]
Type=1
Class=CCMDlg1
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDITX1,edit,1350631552
Control6=IDC_EDITY1,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDITK1,edit,1350631552
Control9=IDC_SPIN4,msctls_updown32,1342177312

[CLS:CCMDlg1]
Type=0
HeaderFile=CMDlg1.h
ImplementationFile=CMDlg1.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SPIN4
VirtualFilter=dWC

[DLG:IDD_MDLG2]
Type=1
Class=CCMDlg2
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDITX2,edit,1350631552
Control6=IDC_EDITY2,edit,1350631552
Control7=IDC_SPIN1,msctls_updown32,1342177312
Control8=IDC_EDITROT,edit,1350631552
Control9=IDC_STATIC,static,1342308352

[CLS:CCMDlg2]
Type=0
HeaderFile=CMDlg2.h
ImplementationFile=CMDlg2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SPIN1
VirtualFilter=dWC

[DLG:IDD_MDLG3]
Type=1
Class=CCMDlg3
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_mir1,button,1342242816
Control4=IDC_mir2,button,1342242816

[CLS:CCMDlg3]
Type=0
HeaderFile=CMDlg3.h
ImplementationFile=CMDlg3.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_mir1
VirtualFilter=dWC

[DLG:IDD_MDLG4]
Type=1
Class=CCMDlg4
ControlCount=21
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_EDITlashen,edit,1350631552
Control6=IDC_SPIN1,msctls_updown32,1342177312
Control7=IDC_EDITxuanzhuan,edit,1350631552
Control8=IDC_SPIN2,msctls_updown32,1342177312
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO2,combobox,1344340226
Control14=IDC_STATIC,static,1342308352
Control15=IDC_SPIN3,msctls_updown32,1342177312
Control16=IDC_EDITsuofang,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_mir3,button,1342242816
Control19=IDC_mir6,button,1342242816
Control20=IDC_mir4,button,1342242816
Control21=IDC_mir5,button,1342242816

[CLS:CCMDlg4]
Type=0
HeaderFile=CMDlg4.h
ImplementationFile=CMDlg4.cpp
BaseClass=CDialog
Filter=D
LastObject=CCMDlg4
VirtualFilter=dWC

[DLG:IDD_MDLG5]
Type=1
Class=CCMDlg5
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_BUTTON4,button,1342242816

[CLS:CCMDlg5]
Type=0
HeaderFile=CMDlg5.h
ImplementationFile=CMDlg5.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON2
VirtualFilter=dWC

[DLG:IDD_MDLG6]
Type=1
Class=CCMDlg6
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1342177289

[CLS:CCMDlg6]
Type=0
HeaderFile=CMDlg6.h
ImplementationFile=CMDlg6.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_DEL
VirtualFilter=dWC

