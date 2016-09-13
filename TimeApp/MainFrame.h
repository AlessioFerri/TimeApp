/*
 * MainFrame.h
 *
 *  Created on: 27 lug 2016
 *      Author: alessio
 */

#ifndef MAINFRAME_H_
#define MAINFRAME_H_
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/frame.h>

class MainFrame: public wxFrame {
private:

protected:
	wxButton* ClockBtn;
	wxButton* TimerBtn;

	virtual void OpenClock(wxCommandEvent& event);
	virtual void OpenTimer(wxCommandEvent& event);

public:

	MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY,
			const wxString& title = wxT("TimeApp"), const wxPoint& pos =
					wxDefaultPosition, const wxSize& size = wxSize(249, 134),
			long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	virtual ~MainFrame();

};

#endif /* MAINFRAME_H_ */
