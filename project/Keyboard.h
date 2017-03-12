#ifndef KEYBOARD_DEF
#define KEYBOARD_DEF

#define KEYINPUT(input) (Keyboard::GetInstance()->GetKeyInput(input))

class Keyboard {
private:
	int key[256];
	Keyboard(){};

public :
	void Update();
	int GetKeyInput(int keyCode);

	static Keyboard* GetInstance() {
		static Keyboard instance;
		return &instance;
	}
};

#endif