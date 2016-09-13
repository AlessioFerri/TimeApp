/*
 * Timer.cpp
 *
 *  Created on: 24 lug 2016
 *      Author: alessio
 */

#include "TimerFrame.h"
#include <wx/wx.h>

TimerFrame::TimerFrame(MyWxTimer*tmr, Timer* t, wxWindow* parent, wxWindowID id,
		const wxString& title, const wxPoint& pos, const wxSize& size,
		long style) :
		wxFrame(parent, id, title, pos, size, style), subject(t), timer(tmr) {

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer(
			new wxStaticBox(this, wxID_ANY, wxT("Setup:")), wxVERTICAL);

	HoursLabel = new wxStaticText(this, wxID_ANY, wxT("Hours:"),
			wxDefaultPosition, wxDefaultSize, 0);
	HoursLabel->Wrap(-1);
	sbSizer3->Add(HoursLabel, 0, wxALL, 5);

	HoursCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
			wxDefaultSize, wxSP_ARROW_KEYS, 0, 24, 0);
	sbSizer3->Add(HoursCtrl, 0, wxALL | wxEXPAND, 5);

	MinsLabel = new wxStaticText(this, wxID_ANY, wxT("Minutes:"),
			wxDefaultPosition, wxDefaultSize, 0);
	MinsLabel->Wrap(-1);
	sbSizer3->Add(MinsLabel, 0, wxALL, 5);

	MinsCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
			wxDefaultSize, wxSP_ARROW_KEYS, 0, 59, 0);
	sbSizer3->Add(MinsCtrl, 0, wxALL | wxEXPAND, 5);

	SecLabel = new wxStaticText(this, wxID_ANY, wxT("Seconds:"),
			wxDefaultPosition, wxDefaultSize, 0);
	SecLabel->Wrap(-1);
	sbSizer3->Add(SecLabel, 0, wxALL, 5);

	SecCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
			wxDefaultSize, wxSP_ARROW_KEYS, 0, 59, 0);
	sbSizer3->Add(SecCtrl, 0, wxALL | wxEXPAND, 5);

	InitBtn = new wxButton(this, wxID_ANY, wxT("Initialize!"),
			wxDefaultPosition, wxDefaultSize, 0);
	sbSizer3->Add(InitBtn, 0, wxALL | wxEXPAND, 5);

	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer(
			new wxStaticBox(this, wxID_ANY, wxT("Count")), wxHORIZONTAL);

	Hours = new wxStaticText(this, wxID_ANY, wxT("00"), wxDefaultPosition,
			wxDefaultSize, 0);
	Hours->Wrap(-1);
	Hours->SetFont(wxFont(48, 74, 90, 90, false, wxT("Sans")));

	sbSizer31->Add(Hours, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_staticText20 = new wxStaticText(this, wxID_ANY, wxT(":"),
			wxDefaultPosition, wxDefaultSize, 0);
	m_staticText20->Wrap(-1);
	m_staticText20->SetFont(wxFont(48, 74, 90, 90, false, wxT("Sans")));

	sbSizer31->Add(m_staticText20, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	Minutes = new wxStaticText(this, wxID_ANY, wxT("00"), wxDefaultPosition,
			wxDefaultSize, 0);
	Minutes->Wrap(-1);
	Minutes->SetFont(wxFont(48, 74, 90, 90, false, wxT("Sans")));

	sbSizer31->Add(Minutes, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_staticText22 = new wxStaticText(this, wxID_ANY, wxT(":"),
			wxDefaultPosition, wxDefaultSize, 0);
	m_staticText22->Wrap(-1);
	m_staticText22->SetFont(wxFont(48, 74, 90, 90, false, wxT("Sans")));

	sbSizer31->Add(m_staticText22, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	Seconds = new wxStaticText(this, wxID_ANY, wxT("00"), wxDefaultPosition,
			wxDefaultSize, 0);
	Seconds->Wrap(-1);
	Seconds->SetFont(wxFont(48, 74, 90, 90, false, wxT("Sans")));

	sbSizer31->Add(Seconds, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	sbSizer31->Add(0, 0, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	StartBtn = new wxButton(this, wxID_ANY, wxT("Start!"), wxDefaultPosition,
			wxDefaultSize, 0);
	bSizer4->Add(StartBtn, 0, wxALL | wxEXPAND, 5);

	bSizer4->Add(0, 0, 1, wxEXPAND, 5);

	StopBtn = new wxButton(this, wxID_ANY, wxT("Stop"), wxDefaultPosition,
			wxDefaultSize, 0);
	bSizer4->Add(StopBtn, 0, wxALL | wxEXPAND, 5);

	bSizer4->Add(0, 0, 1, wxEXPAND, 5);

	ZeroBtn = new wxButton(this, wxID_ANY, wxT("Set to zero"),
			wxDefaultPosition, wxDefaultSize, 0);
	bSizer4->Add(ZeroBtn, 0, wxALL | wxEXPAND, 5);

	sbSizer31->Add(bSizer4, 1, wxEXPAND, 5);

	sbSizer3->Add(sbSizer31, 1, wxEXPAND, 5);

	this->SetSizer(sbSizer3);
	this->Layout();

	attach();

	InitBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(TimerFrame::OnInitTimer), NULL, this);

	StartBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(TimerFrame::StartTimer), NULL, this);
	StopBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(TimerFrame::StopTimer), NULL, this);

	ZeroBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(TimerFrame::OnZeroTimer), NULL, this);

}

TimerFrame::~TimerFrame() {
	detach();
	InitBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(TimerFrame::OnInitTimer), NULL, this);
	StartBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(TimerFrame::StartTimer), NULL, this);
	StopBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(TimerFrame::StopTimer), NULL, this);
	delete subject;

}

void TimerFrame::StopTimer(wxCommandEvent& event) {

	timer->Stop();

}

void TimerFrame::StartTimer(wxCommandEvent& event) {
	if (subject->isInitialized() == false) {

		wxMessageDialog *dial = new wxMessageDialog(NULL,
				wxT("Timer has not been initialized!"), wxT("Error"),
				wxOK | wxICON_ERROR);
		dial->ShowModal();

	}

	else

		timer->Start(1000);
}

void TimerFrame::OnInitTimer(wxCommandEvent& event) {

	subject->init(HoursCtrl->GetValue(), MinsCtrl->GetValue(),
			SecCtrl->GetValue());

}

void TimerFrame::OnZeroTimer(wxCommandEvent& event) {

	if (timer->IsRunning())
		timer->Stop();

	subject->zero();
}

void TimerFrame::attach() {
	subject->subscribe(this);
}

void TimerFrame::detach() {
	subject->unsubscribe(this);
}

void TimerFrame::update(unsigned int h, unsigned int m, unsigned int s) {

	Seconds->SetLabel(wxString::Format(wxT("%i"), s));
	Minutes->SetLabel(wxString::Format(wxT("%i"), m));
	Hours->SetLabel(wxString::Format(wxT("%i"), h));
}

void TimerFrame::updateFinish() {
	timer->Stop();
	subject->setInitialized(false);
	Seconds->SetLabel(wxString::Format(wxT("%i"), 0));

	wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Time is out!"),
			wxT("Info"), wxOK);
	dial->ShowModal();
}

