#include<wx/wxprec.h>
#include<wx/wx.h>
#include<wx/colour.h>

class MyApp: public wxApp{
public:
    virtual bool OnInit();


} ;

class MyFrame : public wxFrame{
public:
     MyFrame(const wxString& title,const wxPoint& pos);//,const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnChangC(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnBC(wxCommandEvent& event);
    void act(wxActivateEvent& event);
   // wxDECLARE_EVENT_TABLE();
 wxButton* button;
  wxTextCtrl  *textctrl;
  wxCheckBox *cb;
   int r=25;
    int g=50;
    int b=0;
};



enum
{
    ID_Hello = 1,ID_ChangC=2
};
/*wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(ID_ChangC,   MyFrame::OnChangC)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_BUTTON(wxID_OK, MyFrame::OnBC)
wxEND_EVENT_TABLE()*/
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Hello World", wxPoint(50, 50));//, wxSize(m_maxWidth,m_maxHeight) );
    frame->Show( true );
   // frame->
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos)//, const wxSize& size)
        :wxFrame(NULL, wxID_ANY, title, pos)//, size)
        {


            this->SetMaxSize(this->GetMaxSize() );
             wxPanel *panel = new wxPanel(this, -1);
             wxBoxSizer *vbox=new wxBoxSizer(wxVERTICAL);
                   wxColor bc(255,0,0);
            SetBackgroundColour(bc);
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(ID_ChangC,"Change_Color");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );


  textctrl = new wxTextCtrl(panel, -1, wxT("welcome"), wxPoint(-1, -1),wxSize(250, 150));
   button = new wxButton(panel, wxID_OK, wxT("Show"));
   cb=new wxCheckBox(panel,-1,"Male");

   vbox->Add(textctrl,0,wxEXPAND|wxALIGN_LEFT | wxLeft | wxBOTTOM,10);
   vbox->Add(button,0,wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);
   vbox->Add(cb,0,wxALIGN_LEFT | wxRIGHT | wxBOTTOM, 10);

  panel->SetSizer(vbox);
 this->Maximize(true);
   /*
    Connect(ID_Hello,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MyFrame::OnHello));
    Connect(ID_ChangC,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MyFrame::OnChangC));
    Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,  wxCommandEventHandler(MyFrame::OnExit));
    Connect(wxID_ABOUT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MyFrame::OnAbout));
    Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnBC));
*/
Bind(wxEVT_COMMAND_MENU_SELECTED,&MyFrame::OnHello,this,ID_Hello);
Bind(wxEVT_COMMAND_MENU_SELECTED,&MyFrame::OnChangC,this,ID_ChangC);
Bind(wxEVT_COMMAND_MENU_SELECTED,&MyFrame::OnExit,this,wxID_EXIT);
Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnBC,this,wxID_OK);
Bind(wxEVT_COMMAND_MENU_SELECTED,&MyFrame::OnAbout,this,wxID_ABOUT);
Bind(wxEVT_ACTIVATE,&MyFrame::act,this);
//Centre();
     //wxString v= textctrl->GetValue();
}

void MyFrame::OnChangC(wxCommandEvent& event)
{
    wxColor bc1(r,g,b);
    SetBackgroundColour(bc1);
    r+=25;g+=20;b+=20;
   //RefreshRect(wxRect(50, 50,450, 340),true);
Refresh(true,NULL);

}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    //wxLogMessage("Hello world from wxWidgets!");
    wxMessageDialog *Md=new wxMessageDialog(this,wxT("Hello World"),wxT("look at me"),wxOK|wxCANCEL|wxICON_INFORMATION);
int r=Md->ShowModal();
if(r==wxID_OK){wxMessageBox("OK click","ok",wxOK);}
if(r==wxID_CANCEL){wxMessageBox("cancel click","cancel",wxOK);}

}
void MyFrame::OnBC(wxCommandEvent& event)
{//cb->Toggle();




}

void MyFrame::act(wxActivateEvent& event){
    //   textctrl->SetValue("active");

}
