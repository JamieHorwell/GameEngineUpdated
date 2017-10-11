#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "MyKeyMapper.h"
#include "Controls.h"
#include <iostream>

MyKeyMapper::MyKeyMapper()
{
}


MyKeyMapper::~MyKeyMapper()
{
}

//which action for which key pressed? 
int MyKeyMapper::getAction(int key) const
{
	switch (key) {
	case	MOVECAMERAUP:
		return 0x57;
	case	MOVECAMERADOWN:
		return 0x53;
	case	MOVECAMERALEFT:
		return 0x41;
	case	MOVECAMERARIGHT:
		return 0x44;
	case	LFTMOUSECLICK:
		return VK_LBUTTON;
	 case	RGHTMOUSCLICK:
		 return VK_RBUTTON;
	 case	BUILDUNIT1:
		 return 0x42;
	 case	BUILDUNIT2:
		 return 0x43;
	}
	return -1;
}


