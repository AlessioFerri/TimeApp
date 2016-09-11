/*
 * Timer.cpp
 *
 *  Created on: 07 set 2016
 *      Author: alessio
 */

#include "Timer.h"

void Timer::start(){
	timer->Start(1000);
}

void Timer::stop(){
	timer->Stop();
}

void Timer::zero(){
	if (timer->IsRunning() == true)
			timer->Stop();

		seconds = 0;
		minutes = 0;
		hours = 0;
		initialized = false;
		notify();
}

void Timer::init(unsigned int h,unsigned int m,unsigned int s){
	initialized = true;
	seconds = s;
	minutes = m;
	hours = h;
	notify();
}


void Timer::subscribe(Observer*o){
	observers.push_back(o);
}

void Timer::unsubscribe(Observer*o){
	observers.remove(o);
}

void Timer::OnTimer(wxTimerEvent& event){

	if (initialized == false) {
			timer->Stop();
			wxMessageDialog *dial = new wxMessageDialog(NULL,
					wxT("Timer has not been initialized!"), wxT("Error"),
					wxOK | wxICON_ERROR);
			dial->ShowModal();

		}

		else {

			if (seconds == 0 && minutes == 0 && hours == 0) {
				timer->Stop();
				initialized = false;
				seconds = 0;
				notify();
				wxMessageDialog *dial = new wxMessageDialog(NULL,
						wxT("Time is out!"), wxT("Info"), wxOK);
				dial->ShowModal();
			}
			else {

				if (seconds == 0) {

					if (minutes != 0) {
						minutes--;
						notify();
					}

					else if (hours != 0) {
						hours--;
						notify();
						minutes = 59;
						notify();
					}
					seconds = 59;
					notify();
				}
				seconds--;
				notify();

			}
		}

}

void Timer::notify(){
	for(auto itr = observers.begin(); itr != observers.end();itr++)
		(*itr)->update(hours,minutes,seconds);
}






BEGIN_EVENT_TABLE(Timer,wxFrame)
EVT_TIMER(-1,Timer::OnTimer)
END_EVENT_TABLE()
