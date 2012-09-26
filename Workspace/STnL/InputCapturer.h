/********************************************************************
	created:	2012/09/18
	created:	18:9:2012   10:15
	filename: 	e:\GitHub\STnL\Workspace\STnL\InputCapturer.h
	file path:	e:\GitHub\STnL\Workspace\STnL
	file base:	InputCapturer
	file ext:	h
	author:		Rainsing
	
	purpose:	��������������
*********************************************************************/
#ifndef InputCapturer_h__
#define InputCapturer_h__

enum KeyCode
{
	KC_LEFT_ARROW,
	KC_RIGHT_ARROW,
	KC_UP_ARROW,
	KC_DOWN_ARROW,
	KC_A,
	KC_S,
	KC_D,
	KC_W,
	KC_Q,
	KC_E,
	KC_R,
};

class InputCapturer
{
public:
	bool IsKeyDown(KeyCode keyCode);
	bool IsKeyPressed(KeyCode keyCode);
};

#endif // InputCapturer_h__
