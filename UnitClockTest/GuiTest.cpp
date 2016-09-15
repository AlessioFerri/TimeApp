/*
 * GuiTest.cpp
 *
 *  Created on: 15 set 2016
 *      Author: alessio
 */
#include "TestApp.h"
#include <gtest/gtest.h>
#include <wx/uiaction.h>

class GuiTest: public testing::Test {
protected:
	TestApp*app;

	virtual void SetUp() {
		char appname[] = "ClockTest.o";
		int argc = 1;
		char *argv[1] = { appname };
		app = new TestApp();
		wxApp::SetInstance(app);
		wxEntryStart(argc, argv);
		app->OnInit();
	}

	virtual void TearDown() {
		app->OnExit();
		wxEntryCleanup();
	}
};

TEST_F(GuiTest,ClockTest) {

	wxDateTime d = wxDateTime::Now();
	wxUIActionSimulator act;

	app->frame->m_choice1->SetFocus();
	wxYield();
	act.Select(app->frame->m_choice1->GetString(1));
	wxYield();
	ASSERT_EQ(app->frame->Slot1->GetLabel(), d.Format(wxT("%H:%M"))); // Time Only

	app->frame->m_choice1->SetFocus();
	wxYield();
	act.Select(app->frame->m_choice1->GetString(2));
	wxYield();
	ASSERT_EQ(app->frame->Slot1->GetLabel(), d.Format(wxT("%a %d %b %Y"))); // date only

	app->frame->m_choice1->SetFocus();
	wxYield();
	act.Select(app->frame->m_choice1->GetString(3));
	wxYield();
	ASSERT_EQ(app->frame->Slot1->GetLabel(), d.Format(wxT("%a %d %b %Y")));
	ASSERT_EQ(app->frame->Slot2->GetLabel(), d.Format(wxT("%H:%M"))); // date and time

	app->frame->m_choice1->SetFocus();
	wxYield();
	act.Select(app->frame->m_choice1->GetString(4));
	wxYield();
	ASSERT_EQ(app->frame->Slot1->GetLabel(), d.Format(wxT("%H:%M")));
	ASSERT_EQ(app->frame->Slot2->GetLabel(), d.Format(wxT("%a %d %b %Y"))); // time and date

	app->frame->amPm->SetFocus();
	wxYield();
	act.Char(WXK_SPACE);
	wxYield();

	if (d.GetHour() > 12)
		ASSERT_EQ(app->frame->Slot1->GetLabel(), d.Format(wxT("%I:%M PM")));

	else{
		ASSERT_EQ(app->frame->Slot1->GetLabel(), d.Format(wxT("%I:%M AM")));
	}																		 // per AM/PM

	app->frame->DateCheck->SetFocus();
	wxYield();
	act.Char(WXK_SPACE);
	wxYield();
	ASSERT_EQ(app->frame->Slot2->GetLabel(),d.Format(wxT("%x"))); // per date chackbox





}

