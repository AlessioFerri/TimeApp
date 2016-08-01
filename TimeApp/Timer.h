/*
 * Timer.h
 *
 *  Created on: 24 lug 2016
 *      Author: alessio
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <wx/wx.h>
#include <wx/spinctrl.h>




class Timer : public wxFrame
{

	protected:
		wxStaticText* HoursLabel;
		wxSpinCtrl* HoursCtrl;
		wxStaticText* MinsLabel;
		wxSpinCtrl* MinsCtrl;
		wxStaticText* SecLabel;
		wxSpinCtrl* SecCtrl;

		wxStaticText* Hours;
		wxStaticText* m_staticText22;
		wxStaticText* Minutes;
		wxStaticText* m_staticText23;
		wxStaticText* Seconds;
		wxButton* InitBtn;

		wxButton* StartBtn;
		wxButton* StopBtn;
		wxButton* ZeroBtn;

		wxTimer* timer;
		bool initialized;

		unsigned int seconds,minutes,hours;

		virtual void StopTimer( wxCommandEvent& event );
		virtual void StartTimer( wxCommandEvent& event);
		virtual void OnTimer(wxTimerEvent& event);
		virtual void OnInitTimer(wxCommandEvent& event);
		virtual void OnZeroTimer(wxCommandEvent& event);



	public:

		Timer( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Timer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 627,481 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		virtual ~Timer();
		DECLARE_EVENT_TABLE()

};

#endif /* TIMER_H_ */
