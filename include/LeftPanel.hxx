#ifndef LEFTPANEL_HXX
#define LEFTPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/panel.h>

class LeftPanel : public wxPanel
{
public:
    LeftPanel(wxPanel *parent);

    void OnPlus(wxCommandEvent & event);
    void OnMinus(wxCommandEvent & event);

    wxButton *m_plus;
    wxButton *m_minus;
    wxPanel *m_parent;
    int count;

};

const int ID_PLUS = 101;
const int ID_MINUS = 102;

#endif
