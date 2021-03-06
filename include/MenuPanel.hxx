/* MenuPanel.hxx */
#ifndef MENUPANEL_HXX
#define MENUPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "MainFrame.hxx"

class MenuPanel : public wxPanel {
    private:
        static const int padding;

        wxArrayString *gameDiff;
        wxBoxSizer *hSizer;
        wxBoxSizer *vSizer;
        wxChoice *diff;
        wxStaticText *minesRem;
        wxStaticText *timer;
        wxTimer *gameTimer;

        void doSetup();
        void setupChoice();
        void setupStaticText();
        void setupPanel();

        void handleChoice(wxCommandEvent& event);
        void handleTimer(wxTimerEvent& event);

    public:
        MenuPanel(wxFrame *parent);
        void restartGame(wxString difficulty);
        int getMinesRem();
        void setMinesRem(int i);
        void setDiff(wxString difficulty);
        int getTime();
        void resetTimer();
        void startTimer();
        void stopTimer();
};

#endif /* MENUPANEL_HXX */
