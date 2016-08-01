/*
 * main.cpp
 *
 *  Created on: 27 lug 2016
 *      Author: alessio
 */

#include "main.h"
#include "MainFrame.h"

IMPLEMENT_APP(TimeApp)

bool TimeApp::OnInit(){

	MainFrame* m = new MainFrame(NULL);
	m->Show(true);

	return true;
}
