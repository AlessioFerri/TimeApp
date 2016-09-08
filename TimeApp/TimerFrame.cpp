/*
 * Timer.cpp
 *
 *  Created on: 24 lug 2016
 *      Author: alessio
 */

#include "TimerFrame.h"
#include <wx/wx.h>

TimerFrame::TimerFrame(Timer* t,wxWindow* parent, wxWindowID id, const wxString& title,
		const wxPoint& pos, const wxSize& size, long style) :
		wxFrame(parent, id, title, pos, size, style), subject(t) {


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

	Hours = new wxStaticText(this, wxID_ANY, wxT(" 0"), wxDefaultPosition,
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

	Minutes = new wxStaticText(this, wxID_ANY, wxT(" 0"), wxDefaultPosition,
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

	Seconds = new wxStaticText(this, wxID_ANY, wxT(" 0"), wxDefaultPosition,
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



	TimerFrame::~TimerFrame()
	{
		detach();
		InitBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
				wxCommandEventHandler(TimerFrame::OnInitTimer), NULL, this);
		StartBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
				wxCommandEventHandler(TimerFrame::StartTimer), NULL, this);
		StopBtn->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
				wxCommandEventHandler(TimerFrame::StopTimer), NULL, this);
	}

void TimerFrame::StopTimer(wxCommandEvent& event) {

	subject->stop();

}

void TimerFrame::StartTimer(wxCommandEvent& event) {
	subject->start();
}

void TimerFrame::OnInitTimer(wxCommandEvent& event) {

	subject->init(HoursCtrl->GetValue(),MinsCtrl->GetValue(),SecCtrl->GetValue());

}

void TimerFrame::OnZeroTimer(wxCommandEvent& event) {
	subject->zero();
}

void TimerFrame::attach() {
	subject->subscribe(this);
}

void TimerFrame::detach() {
	subject->unsubscribe(this);
}

void TimerFrame::updateTime(unsigned int h,unsigned int m,unsigned int s) {

	Seconds->SetLabel(wxString::Format(wxT("%i"), s));
	Minutes->SetLabel(wxString::Format(wxT("%i"), m));
	Hours->SetLabel(wxString::Format(wxT("%i"), h));
}

void TimerFrame::updateInit(unsigned int h,unsigned int m,unsigned int s) {
	Hours->SetLabel(wxString::Format(wxT("%i"), h));
	Minutes->SetLabel(wxString::Format(wxT("%i"), m));
	Seconds->SetLabel(wxString::Format(wxT("%i"), s));



}

