#include "MiniginPCH.h"
#include "PacmanPrefab.h"
#include "SpriteComponent.h"
#include "TextComponent.h"
#include "ColliderComponent.h"
#include "InputManager.h"


PacmanPrefab::PacmanPrefab()
{
	auto sprite = new dae::SpriteComponent(dae::TextureName::PACMAN);
	sprite->SetAnimated(true);
	sprite->SetAnimationParameters(3, 9, 10.0f, 9.0f);

	AddComponent(sprite);
	AddComponent(new ColliderComponent());
}

void PacmanPrefab::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);

	auto command = dae::InputManager::GetInstance().HandleInput();

	if (command) command->Execute(this);


	float horz{ 0.0f};
	float vert{0.0f};

	switch (m_Direction)
	{
	case Right:
		horz = m_Speed;
		break;

	case Left:
		horz = -m_Speed;
		break;

	case Up:
		vert = -m_Speed;
		break;

	case Down:
		vert = m_Speed;
		break;
	}

	Transform()->Translate(horz * elapsedSec, vert * elapsedSec, 0.0f);
}



