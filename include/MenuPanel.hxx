/* MenuPanel.hxx */
#ifndef MENUPANEL_HXX
#define MENUPANEL_HXX

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/panel.h>
#include "MainFrame.hxx"
#include "MinePanel.hxx"

class MainFrame;
class MinePanel;

class MenuPanel : public wxPanel {
    private:
        int padding;
        wxArrayString *gameDiff;
        wxBoxSizer *hSizer;
        wxBoxSizer *vSizer;
        MainFrame *topLevel;
        MinePanel *minePanel;
        wxComboBox *diff;
        wxStaticText *minesRem;
        wxStaticText *timer;
        wxTimer *gameTimer;

        void doSetup();
        void setupComboBox();
        void setupStaticText();
        void setupPanel();
        void restartGame(std::string difficulty);
        void handleTimer(wxTimerEvent& event);
        void handleComboBox(wxCommandEvent& event);

    public:
        MenuPanel(wxPanel *parent);
        void setMinePanel(MinePanel *minePanel);
        void setMainFrame(MainFrame *mainFrame);
        void setMinesRem(int i);
        int getTime();
        void resetTimer();
        void startTimer();
        void stopTimer();
};

#endif /* MENUPANEL_HXX */
