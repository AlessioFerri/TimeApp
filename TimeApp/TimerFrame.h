/*
 * Timer.h
 *
 *  Created on: 24 lug 2016
 *      Author: alessio
 */

#ifndef TIMERFRAME_H_
#define TIMERFRAME_H_
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "Observer.h"
#include "Timer.h"

class TimerFrame: public Observer,public wxFrame  {

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

	Timer* subject;

	virtual void StopTimer(wxCommandEvent& event);
	virtual void StartTimer(wxCommandEvent& event);
	virtual void OnInitTimer(wxCommandEvent& event);
	virtual void OnZeroTimer(wxCommandEvent& event);

public:

	TimerFrame(Timer*t,wxWindow* parent, wxWindowID id = wxID_ANY,
			const wxString& title = wxT("Timer"), const wxPoint& pos =
					wxDefaultPosition, const wxSize& size = wxSize(627, 481),
			long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	virtual ~TimerFrame();

	virtual void attach() override;
	virtual void detach() override;
	virtual void update(unsigned int h, unsigned int m, unsigned int s) override;

};

#endif /* TIMERFRAME_H_ */
