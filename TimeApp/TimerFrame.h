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
#include "MyWxTimer.h"

class TimerFrame: public Observer, public wxFrame  {

protected:
	wxStaticText* HoursLabel;
	wxSpinCtrl* HoursCtrl;
	wxStaticText* MinsLabel;
	wxSpinCtrl* MinsCtrl;
	wxStaticText* SecLabel;
	wxSpinCtrl* SecCtrl;
	wxButton* InitBtn;
	wxStaticText* Hours;
	wxStaticText* m_staticText20;
	wxStaticText* Minutes;
	wxStaticText* m_staticText22;
	wxStaticText* Seconds;

	wxButton* StartBtn;

	wxButton* StopBtn;

	wxButton* ZeroBtn;

	Timer* subject;
	MyWxTimer* timer;

	virtual void StopTimer(wxCommandEvent& event);
	virtual void StartTimer(wxCommandEvent& event);
	virtual void OnInitTimer(wxCommandEvent& event);
	virtual void OnZeroTimer(wxCommandEvent& event);

public:

	TimerFrame(MyWxTimer*tmr, Timer*t, wxWindow* parent = nullptr, wxWindowID id =
			wxID_ANY, const wxString& title = wxT("Timer"),
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxSize(571, 517),
			long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	virtual ~TimerFrame();

	virtual void attach() override;
	virtual void detach() override;
	virtual void update(unsigned int h, unsigned int m, unsigned int s)
			override;
	virtual void updateFinish() override;

};

#endif /* TIMERFRAME_H_ */
