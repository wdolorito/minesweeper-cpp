#ifndef BUTTONPANEL_HXX
#define BUTTONPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/wx.h>

class ButtonPanel : public wxFrame
{
public:
    ButtonPanel(const wxString& title);

    void OnQuit(wxCommandEvent & event);
};

#endif
