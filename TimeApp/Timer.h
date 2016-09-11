/*
 * Timer.h
 *
 *  Created on: 07 set 2016
 *      Author: alessio
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <wx/wx.h>
#include "Subject.h"
#include <list>

class Timer : public Subject, public wxFrame {
public:
	Timer(){
		initialized = false;
		timer = new wxTimer(this);
		seconds = 0;
		minutes = 0;
		hours = 0;

	}

	virtual ~Timer(){
		delete timer;
	}

	virtual void start();
	virtual void stop();
	virtual void zero();
	virtual void init(unsigned int h,unsigned int m,unsigned int s);

	virtual void subscribe(Observer*o) override;
	virtual void unsubscribe(Observer*o) override;
	virtual void notify() override;

	void OnTimer(wxTimerEvent& event);

protected:
	std::list<Observer*> observers;
	wxTimer* timer;
	bool initialized;
	unsigned int hours,minutes,seconds;
	DECLARE_EVENT_TABLE()
};

#endif /* TIMER_H_ */
