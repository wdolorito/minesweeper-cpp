#include "ButtonPanel.hxx"

ButtonPanel::ButtonPanel(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 150))
{
  wxPanel *panel = new wxPanel(this, wxID_ANY);

  wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"), 
      wxPoint(20, 20));
  Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(ButtonPanel::OnQuit));
  button->SetFocus();
  Centre();
}

void ButtonPanel::OnQuit(wxCommandEvent & WXUNUSED(event))
{
    Close(true);
}
