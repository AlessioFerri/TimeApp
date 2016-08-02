/*
 * Clock.cpp
 *
 *  Created on: 26 lug 2016
 *      Author: alessio
 */

#include "Clock.h"

Clock::Clock(wxWindow* parent, wxWindowID id, const wxString& title,
		const wxPoint& pos, const wxSize& size, long style) :
		wxFrame(parent, id, title, pos, size, style) {
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxStaticBoxSizer* ChooseSzr;
	ChooseSzr = new wxStaticBoxSizer(
			new wxStaticBox(this, wxID_ANY,
					wxT("Scegliere il formato desiderato:")), wxVERTICAL);

	wxString m_choice1Choices[] = { wxT("-"), wxT("Time Only"), wxT(
			"Date only"), wxT("Date and Time"), wxT("Time and Date") };
	int m_choice1NChoices = sizeof(m_choice1Choices) / sizeof(wxString);
	m_choice1 = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
			m_choice1NChoices, m_choice1Choices, 0);
	m_choice1->SetSelection(0);
	ChooseSzr->Add(m_choice1, 0, wxALL | wxEXPAND, 5);

	amPm = new wxCheckBox(this, wxID_ANY, wxT("AM/PM"), wxDefaultPosition,
			wxDefaultSize, 0);
	ChooseSzr->Add(amPm, 0, wxALL, 5);

	DateCheck = new wxCheckBox(this, wxID_ANY, wxT("MM/GG/AA"),
			wxDefaultPosition, wxDefaultSize, 0);
	ChooseSzr->Add(DateCheck, 0, wxALL, 5);

	ChooseSzr->Add(0, 0, 1, wxEXPAND, 5);

	Slot1 = new wxStaticText(this, wxID_ANY, wxT("-"), wxDefaultPosition,
			wxDefaultSize, 0);
	Slot1->Wrap(-1);
	Slot1->SetFont(wxFont(40, 76, 90, 90, false, wxT("Monospace")));

	ChooseSzr->Add(Slot1, 0, wxALL, 5);

	Slot2 = new wxStaticText(this, wxID_ANY, wxT("-"), wxDefaultPosition,
			wxDefaultSize, 0);
	Slot2->Wrap(-1);
	Slot2->SetFont(wxFont(20, 76, 90, 90, false, wxT("Monospace")));

	ChooseSzr->Add(Slot2, 0, wxALL, 5);

	ChooseSzr->Add(0, 0, 1, wxEXPAND, 5);

	this->SetSizer(ChooseSzr);
	this->Layout();

	now = wxDateTime::Now();

	m_choice1->Connect(wxEVT_COMMAND_CHOICE_SELECTED,
			wxCommandEventHandler(Clock::SetStrings), NULL, this);

	amPm->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED,
			wxCommandEventHandler(Clock::SetHour), NULL, this);

	DateCheck->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED,
			wxCommandEventHandler(Clock::SetDate), NULL, this);

}

Clock::~Clock() {
	m_choice1->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED,
			wxCommandEventHandler(Clock::SetStrings), NULL, this);

	amPm->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED,
			wxCommandEventHandler(Clock::SetHour), NULL, this);

	DateCheck->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED,
			wxCommandEventHandler(Clock::SetDate), NULL, this);

}

void Clock::SetStrings(wxCommandEvent& event) {

	if (m_choice1->GetCurrentSelection() == 1) {
		time = now.Format(wxT("%H:%M"));
		Slot1->SetLabel(time);
		Slot2->SetLabel(wxT(""));
	}

	if (m_choice1->GetCurrentSelection() == 2) {

		date = now.Format(wxT("%a %d %b %Y"));
		Slot1->SetLabel(date);
		Slot2->SetLabel(wxT(""));
	}

	if (m_choice1->GetCurrentSelection() == 3) {

		time = now.Format(wxT("%H:%M"));
		date = now.Format(wxT("%a %d %b %Y"));
		Slot1->SetLabel(date);
		Slot2->SetLabel(time);
	}

	if (m_choice1->GetCurrentSelection() == 4) {

		time = now.Format(wxT("%H:%M"));
		date = now.Format(wxT("%a %d %b %Y"));
		Slot2->SetLabel(date);
		Slot1->SetLabel(time);
	}
}

void Clock::SetHour(wxCommandEvent& event) {

	if (amPm->IsChecked()) {
		if (m_choice1->GetCurrentSelection() == 1) {

			if (now.GetHour() > 12) {
				time = now.Format(wxT("%I:%M PM"));
				Slot1->SetLabel(time);
			} else
				time = now.Format(wxT("%I:%M AM"));
			Slot1->SetLabel(time);
		}

		if (m_choice1->GetCurrentSelection() == 3) {

			if (now.GetHour() > 12) {
				time = now.Format(wxT("%I:%M PM"));
				Slot2->SetLabel(time);
			} else
				time = now.Format(wxT("%I:%M AM"));
			Slot2->SetLabel(time);
		}

		if (m_choice1->GetCurrentSelection() == 4) {

			if (now.GetHour() > 12) {
				time = now.Format(wxT("%I:%M PM"));
				Slot1->SetLabel(time);
			} else
				time = now.Format(wxT("%I:%M AM"));
			Slot1->SetLabel(time);
		}
	} else {

		if (m_choice1->GetCurrentSelection() == 1) {

			time = now.Format(wxT("%H:%M"));
			Slot1->SetLabel(time);
		}

		if (m_choice1->GetCurrentSelection() == 3) {

			time = now.Format(wxT("%H:%M"));
			Slot2->SetLabel(time);
		}

		if (m_choice1->GetCurrentSelection() == 4) {

			time = now.Format(wxT("%H:%M"));
			Slot1->SetLabel(time);

		}

	}
}

void Clock::SetDate(wxCommandEvent& event) {

	if (DateCheck->IsChecked()) {

		if (m_choice1->GetCurrentSelection() == 2) {
			date = now.Format(wxT("%x"));
			Slot1->SetLabel(date);
		}

		if (m_choice1->GetCurrentSelection() == 3) {

			date = now.Format(wxT("%x"));
			Slot1->SetLabel(date);
		}

		if (m_choice1->GetCurrentSelection() == 4) {
			date = now.Format(wxT("%x"));
			Slot2->SetLabel(date);
		}

	}

	else {

		if (m_choice1->GetCurrentSelection() == 2) {
			date = now.Format(wxT("%a %d %b %Y"));
			Slot1->SetLabel(date);
		}

		if (m_choice1->GetCurrentSelection() == 3) {

			date = now.Format(wxT("%a %d %b %Y"));
			Slot1->SetLabel(date);
		}

		if (m_choice1->GetCurrentSelection() == 4) {
			date = now.Format(wxT("%a %d %b %Y"));
			Slot2->SetLabel(date);
		}
	}

}
