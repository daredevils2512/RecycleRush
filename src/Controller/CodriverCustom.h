/*
 * CodriverCustom.h
 *
 *  Created on: Jan 26, 2015
 *      Author: Craig
 */

#ifndef SRC_CONTROLLER_CODRIVERCUSTOM_H_
#define SRC_CONTROLLER_CODRIVERCUSTOM_H_

#include "CodriverBase.h"

class CodriverCustom: public CodriverBase {
public:
	CodriverCustom(Joystick* stick);
	virtual ~CodriverCustom();
};

#endif /* SRC_CONTROLLER_CODRIVERCUSTOM_H_ */
