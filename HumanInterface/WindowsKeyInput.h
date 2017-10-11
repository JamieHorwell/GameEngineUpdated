#pragma once
class AbstractKeyMapper;

class WindowsKeyInput
{

	
public:
	WindowsKeyInput();
	~WindowsKeyInput();
	
	bool initialize(AbstractKeyMapper* keyMapper, int maxActionValue);
	void update();
	inline int getActionsThisFrame() const { return actionsThisFrame; };


	bool actionsActive(int actions) const;
	bool actionsHeld(int actions) const;
	bool firstInstanceAction(int actions) const;
	//needs implementing
	bool actionsLetGo(int actions) const;

private:
	int maxActionValue;
	int actionsThisFrame;
	int actionsLastFrame;
	AbstractKeyMapper* keyMapper;

};

