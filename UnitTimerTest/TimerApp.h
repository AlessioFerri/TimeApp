/*
 * TimerApp.h
 *
 *  Created on: 14 set 2016
 *      Author: alessio
 */

#ifndef TIMERAPP_H_
#define TIMERAPP_H_
#include <wx/wx.h>
#include "TimerFrame.h"
#include "MyWxTimer.h"
#include "Timer.h"

class TimerApp : public wxApp{
public:
	TimerFrame* frame;

	virtual ~TimerApp(){}

	virtual bool OnInit(){
		Timer* timer = new Timer();
		MyWxTimer* tmr = new MyWxTimer(timer);
		frame = new TimerFrame(tmr,timer,nullptr);
		frame->Show(true);
		return true;

	}
};



#endif /* TIMERAPP_H_ */
