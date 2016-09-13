/*
 * MainFrame.cpp
 *
 *  Created on: 27 lug 2016
 *      Author: alessio
 */

#include "MainFrame.h"
#include "Clock.h"
#include "Timer.h"
#include "TimerFrame.h"
#include "MyWxTimer.h"

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title,
		const wxPoint& pos, const wxSize& size, long style) :
		wxFrame(parent, id, title, pos, size, style) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer(
			new wxStaticBox(this, wxID_ANY, wxT("Time App:")), wxVERTICAL);

	ClockBtn = new wxButton(this, wxID_ANY, wxT("Clock"), wxDefaultPosition,
			wxDefaultSize, 0);
	sbSizer2->Add(ClockBtn, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	TimerBtn = new wxButton(this, wxID_ANY, wxT("Timer"), wxDefaultPosition,
			wxDefaultSize, 0);
	sbSizer2->Add(TimerBtn, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	this->SetSizer(sbSizer2);
	this->Layout();

	ClockBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::OpenClock), NULL, this);

	TimerBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::OpenTimer), NULL, this);
}

MainFrame::~MainFrame() {
	ClockBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::OpenClock), NULL, this);

	TimerBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(MainFrame::OpenTimer), NULL, this);
}

void MainFrame::OpenClock(wxCommandEvent& event) {

	Clock* c = new Clock(this);
	c->Show(true);
}

void MainFrame::OpenTimer(wxCommandEvent& event) {
	Timer* timer = new Timer();
	MyWxTimer*tmr = new MyWxTimer(timer);
	TimerFrame*t = new TimerFrame(tmr, timer, this);
	t->Show(true);
}
