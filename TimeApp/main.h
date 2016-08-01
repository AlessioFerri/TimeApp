/*
 * main.h
 *
 *  Created on: 27 lug 2016
 *      Author: alessio
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <wx/wx.h>

class TimeApp : public wxApp{
public:
	virtual ~TimeApp(){}
	virtual bool OnInit();
};


#endif /* MAIN_H_ */
