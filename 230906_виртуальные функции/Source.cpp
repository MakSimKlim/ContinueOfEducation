class Weapon
{
public:
	virtual void MainFire() {};
	virtual void SecondaryFire() {};

};

class Pistol : public Weapon
{};

class Knife :public Weapon
{};

bool PressedMouseButton()
{
	return true;
}

void test()
{
	Weapon* PlayerArsenal[10];//������ ����������
	Pistol pistol;
	Knife knife;
	PlayerArsenal[0] = &knife;// ������ ������ ����� �������� � ������������ (�������� ������������)
	PlayerArsenal[1] = &pistol;// ������ ������ ����� �������� � ������������ (�������� ������������)

	int currentWeapon = 0;
	enum MouseButtons {Left, Right};

	if (PressedMouseButton())
	{
		MouseButtons pressedButton = Left;
		switch (pressedButton)
		{
		case Left:
			PlayerArsenal[currentWeapon]->MainFire();
			break;
		case Right:
			PlayerArsenal[currentWeapon]->SecondaryFire();
			break;
		}

	}
	

}