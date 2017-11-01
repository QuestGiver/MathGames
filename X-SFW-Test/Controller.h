#pragma once
//controller -> rigidbody -> transform
#include "Transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

//Poll for input and apply changes to the rigidbody

class Controller
{
public:
	void poll(Rigidbody &rb, const transform &t)
	{
		//controlls
	}
};