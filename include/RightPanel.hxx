#ifndef RIGHTPANEL_HXX
#define RIGHTPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/panel.h>

class RightPanel : public wxPanel
{
public:
    RightPanel(wxPanel *parent);

    void OnSetText(wxCommandEvent & event);

    wxStaticText *m_text;

};

#endif
