#ifndef COMMUNICATE_HXX
#define COMMUNICATE_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "LeftPanel.hxx"
#include "RightPanel.hxx"

class Communicate : public wxFrame
{
public:
    Communicate(const wxString& title);


    LeftPanel *m_lp;
    RightPanel *m_rp;
    wxPanel *m_parent;

};

#endif
