/*
 * pointer_to_func.h
 *
 *  Created on: Mar 22, 2022
 *      Author: SEkoSh
 */

#include <iostream>

#ifndef POINTER_TO_FUNC_H_
#define POINTER_TO_FUNC_H_

void checkPointerToFunc();

void checkPointersLogic();

void checkConstPointers();

const char* returnPointerToConst();

void checkConstMembers();

class checkConst
{
public:
	checkConst() : m_PrivateVar1(0), m_PrivateVar2(0) {};
	void testConstFunction() const;

	void testNonConstFunction ();
private:
	int m_PrivateVar1;
	mutable int m_PrivateVar2;
};

#endif /* POINTER_TO_FUNC_H_ */
