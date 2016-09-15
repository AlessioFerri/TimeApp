/*
 * TestApp.h
 *
 *  Created on: 28 lug 2016
 *      Author: alessio
 */

#ifndef TESTAPP_H_
#define TESTAPP_H_
#include <wx/wx.h>
#include "Clock.h"

class TestApp : public wxApp{
public:
	Clock*frame;

	virtual bool OnInit(){
		frame = new Clock(NULL);
		frame->Show(true);
		return true;
	}
};



#endif /* TESTAPP_H_ */
