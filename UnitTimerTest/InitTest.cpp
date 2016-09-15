/*
 * InitTest.cpp
 *
 *  Created on: 14 set 2016
 *      Author: alessio
 */
#include <gtest/gtest.h>
#include "TimerApp.h"
#include <wx/wx.h>
#include <wx/uiaction.h>


 class GuiTest : public ::testing::Test{
 protected:
 TimerApp*app;

 virtual void SetUp(){
 char appname[] = "ClockTest.o";
 int argc = 1;
 char *argv[1] = {appname};
 app = new TimerApp();
 wxApp::SetInstance(app);
 wxEntryStart(argc,argv);
 app->OnInit();
 }

 virtual void TearDown()
 {
 app->OnExit();
 wxEntryCleanup();
 }
 };



TEST_F(GuiTest,Test) {

	wxUIActionSimulator act;

	app->frame->HoursCtrl->SetFocus();
	wxYield();
	act.Text("10");
	wxYield();
	app->frame->InitBtn->SetFocus();
	wxYield();
	act.Char(WXK_RETURN);
	wxYield();
	ASSERT_EQ(app->frame->Hours->GetLabel(), wxT("10"));
	ASSERT_TRUE(app->frame->subject->isInitialized());			//per bottone inizializzazione


	app->frame->StartBtn->SetFocus();
	wxYield();
	act.Char(WXK_RETURN);
	wxYield();
	ASSERT_TRUE(app->frame->timer->IsRunning());  //per bottone start


	app->frame->StopBtn->SetFocus();
	wxYield();
	act.Char(WXK_RETURN);
	wxYield();
	ASSERT_FALSE(app->frame->timer->IsRunning()); // per bottone stop

	app->frame->ZeroBtn->SetFocus();
	wxYield();
	act.Char(WXK_RETURN);
	wxYield();
	ASSERT_FALSE(app->frame->subject->isInitialized());
	ASSERT_EQ(app->frame->Hours->GetLabel(), wxT("0")); //per bottone azzera

}


