/*
 * Timer.cpp
 *
 *  Created on: 24 lug 2016
 *      Author: alessio
 */

#include "Timer.h"

enum {
	TIMER_ID = 10
};

Timer::Timer(wxWindow* parent, wxWindowID id, const wxString& title,
		const wxPoint& pos, const wxSize& size, long style) :
		wxFrame(parent, id, title, pos, size, style), initialized(false) {

	timer = new wxTimer(this, TIMER_ID);

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxStaticBoxSizer* SetupSzr;
	SetupSzr = new wxStaticBoxSizer(
			new wxStaticBox(this, wxID_ANY, wxT("Setup:")), wxVERTICAL);

	HoursLabel = new wxStaticText(this, wxID_ANY, wxT("Hours"),
			wxDefaultPosition, wxDefaultSize, 0);
	HoursLabel->Wrap(-1);
	SetupSzr->Add(HoursLabel, 0, wxALL, 5);

	HoursCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
			wxDefaultSize, wxSP_ARROW_KEYS, 0, 24, 0);
	SetupSzr->Add(HoursCtrl, 0, wxALL | wxEXPAND, 5);

	MinsLabel = new wxStaticText(this, wxID_ANY, wxT("Minutes:"),
			wxDefaultPosition, wxDefaultSize, 0);
	MinsLabel->Wrap(-1);
	SetupSzr->Add(MinsLabel, 0, wxALL, 5);

	MinsCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
			wxDefaultSize, wxSP_ARROW_KEYS, 0, 59, 0);
	SetupSzr->Add(MinsCtrl, 0, wxALL | wxEXPAND, 5);

	SecLabel = new wxStaticText(this, wxID_ANY, wxT("Seconds:"),
			wxDefaultPosition, wxDefaultSize, 0);
	SecLabel->Wrap(-1);
	SetupSzr->Add(SecLabel, 0, wxALL, 5);

	SecCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
			wxDefaultSize, wxSP_ARROW_KEYS, 0, 59, 0);
	SetupSzr->Add(SecCtrl, 0, wxALL | wxEXPAND, 5);

	InitBtn = new wxButton(this, wxID_ANY, wxT("Initialize!"),
			wxDefaultPosition, wxDefaultSize, 0);
	SetupSzr->Add(InitBtn, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer(
			new wxStaticBox(this, wxID_ANY, wxT("Count:")), wxHORIZONTAL);

	Hours = new wxStaticText(this, wxID_ANY, wxT("00"), wxDefaultPosition,
			wxDefaultSize, 0);
	Hours->Wrap(-1);
	Hours->SetFont(wxFont(40, 76, 90, 90, false, wxT("Monospace")));

	sbSizer9->Add(Hours, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	sbSizer9->Add(0, 0, 1, wxEXPAND, 5);

	m_staticText22 = new wxStaticText(this, wxID_ANY, wxT(":"),
			wxDefaultPosition, wxDefaultSize, 0);
	m_staticText22->Wrap(-1);
	m_staticText22->SetFont(wxFont(40, 74, 90, 90, false, wxT("Sans")));

	sbSizer9->Add(m_staticText22, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	sbSizer9->Add(0, 0, 1, wxEXPAND, 5);

	Minutes = new wxStaticText(this, wxID_ANY, wxT("00"), wxDefaultPosition,
			wxDefaultSize, 0);
	Minutes->Wrap(-1);
	Minutes->SetFont(wxFont(40, 76, 90, 90, false, wxT("Monospace")));

	sbSizer9->Add(Minutes, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	sbSizer9->Add(0, 0, 1, wxEXPAND, 5);

	m_staticText23 = new wxStaticText(this, wxID_ANY, wxT(":"),
			wxDefaultPosition, wxDefaultSize, 0);
	m_staticText23->Wrap(-1);
	m_staticText23->SetFont(wxFont(40, 74, 90, 90, false, wxT("Sans")));

	sbSizer9->Add(m_staticText23, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	sbSizer9->Add(0, 0, 1, wxEXPAND, 5);

	Seconds = new wxStaticText(this, wxID_ANY, wxT("00"), wxDefaultPosition,
			wxDefaultSize, 0);
	Seconds->Wrap(-1);
	Seconds->SetFont(wxFont(40, 76, 90, 90, false, wxT("Monospace")));

	sbSizer9->Add(Seconds, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	SetupSzr->Add(sbSizer9, 1, wxEXPAND, 5);

	StartBtn = new wxButton(this, wxID_ANY, wxT("Start!"), wxDefaultPosition,
			wxDefaultSize, 0);
	SetupSzr->Add(StartBtn, 0, wxALL | wxEXPAND, 5);

	StopBtn = new wxButton(this, wxID_ANY, wxT("Stop"), wxDefaultPosition,
			wxDefaultSize, 0);
	SetupSzr->Add(StopBtn, 0, wxALL | wxEXPAND, 5);

	ZeroBtn = new wxButton(this, wxID_ANY, wxT("Set to zero"),
			wxDefaultPosition, wxDefaultSize, 0);
	SetupSzr->Add(ZeroBtn, 0, wxALL | wxEXPAND, 5);

	this->SetSizer(SetupSzr);
	this->Layout();

	InitBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Timer::OnInitTimer), NULL, this);

	StartBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Timer::StartTimer), NULL, this);
	StopBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Timer::StopTimer), NULL, this);

	ZeroBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Timer::OnZeroTimer), NULL, this);

}

Timer::~Timer() {
	InitBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Timer::OnInitTimer), NULL, this);
	StartBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Timer::StartTimer), NULL, this);
	StopBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(Timer::StopTimer), NULL, this);
}

void Timer::StopTimer(wxCommandEvent& event) {

	timer->Stop();

}

void Timer::OnTimer(wxTimerEvent& event) {

	if (initialized == false) {
		timer->Stop();
		wxMessageDialog *dial = new wxMessageDialog(NULL,
				wxT("Timer has not been initialized!"), wxT("Error"),
				wxOK | wxICON_ERROR);
		dial->ShowModal();

	}

	else {

		if (seconds == 0) {

			if (minutes != 0) {
				minutes--;
				Minutes->SetLabel(wxString::Format(wxT("%i"), minutes));
			}

			else if (hours != 0) {
				hours--;
				Hours->SetLabel(wxString::Format(wxT("%i"), hours));
				minutes = 59;
				Minutes->SetLabel(wxString::Format(wxT("%i"), minutes));
			}
			seconds = 59;
			Seconds->SetLabel(wxString::Format(wxT("%i"), seconds));
		}
		seconds--;
		Seconds->SetLabel(wxString::Format(wxT("%i"), seconds));

		if (seconds == 0 && minutes == 0 && hours == 0) {
			timer->Stop();
			initialized = false;
			seconds = 0;
			Seconds->SetLabel(wxString::Format(wxT("%i"), seconds));
			wxMessageDialog *dial = new wxMessageDialog(NULL,
					wxT("Time is out!"), wxT("Info"), wxOK);
			dial->ShowModal();
		}
	}
}

void Timer::StartTimer(wxCommandEvent& event) {
	timer->Start(1000);
}

void Timer::OnInitTimer(wxCommandEvent& event) {
	initialized = true;
	seconds = SecCtrl->GetValue();
	Seconds->SetLabel(wxString::Format(wxT("%i"), seconds));
	minutes = MinsCtrl->GetValue();
	Minutes->SetLabel(wxString::Format(wxT("%i"), minutes));
	hours = HoursCtrl->GetValue();
	Hours->SetLabel(wxString::Format(wxT("%i"), hours));

}

void Timer::OnZeroTimer(wxCommandEvent& event) {

	if (timer->IsRunning() == true)
		timer->Stop();

	seconds = 0;
	Seconds->SetLabel(wxString::Format(wxT("%i"), seconds));
	minutes = 0;
	Minutes->SetLabel(wxString::Format(wxT("%i"), minutes));
	hours = 0;
	Hours->SetLabel(wxString::Format(wxT("%i"), hours));
	initialized = false;
}

BEGIN_EVENT_TABLE(Timer,wxFrame)
EVT_TIMER(TIMER_ID,Timer::OnTimer)
END_EVENT_TABLE()
