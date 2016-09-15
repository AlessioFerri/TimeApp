/*
 * Clock.h
 *
 *  Created on: 26 lug 2016
 *      Author: alessio
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/datetime.h>
#include <wx/checkbox.h>

class Clock: public wxFrame {

public:
	wxChoice* m_choice1;
	wxCheckBox* amPm;
	wxCheckBox* DateCheck;


	wxStaticText* Slot1;
	wxStaticText* Slot2;
	wxDateTime now;
	wxString time;
	wxString date;

	virtual void SetStrings(wxCommandEvent& event);
	virtual void SetHour( wxCommandEvent& event );
	virtual void SetDate( wxCommandEvent& event );



	Clock(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title =
			wxT("Clock"), const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxSize(649, 332),
			long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	virtual  ~Clock();

};
#endif /* CLOCK_H_ */
