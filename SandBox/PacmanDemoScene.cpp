#include "stdafx.h"
#include "PacmanDemoScene.h"
#include "FpsCounterPrefab.h"
#include "PacmanPrefab.h"
#include "LevelLoader.h"
#include "InputManager.h"
#include <SDL.h>
#include <iostream>


PacmanDemoScene::PacmanDemoScene() :
Scene("Pacman demo scene")
{
	
	dae::LevelLoader::LoadLevel("level01", this);

	m_pPacman = new PacmanPrefab();
	m_pPacman->Translate(10, 100,1);
	AddChild(m_pPacman);
	
	auto fpsCounter = new FpsCounterPrefab();
	//fpsCounter->Translate(10, 10, 1);
	AddChild(fpsCounter);

}


PacmanDemoScene::~PacmanDemoScene()
{
	
}

void PacmanDemoScene::Update(float elapsedSec)
{
	(elapsedSec);

	//destroy & distable/enable test
	if(dae::InputManager::GetInstance().IsKeyPressed((SDLK_SPACE)))
	{
		if (m_pPacman)
		{
			m_pPacman->Destroy();
		}
	}

	if(dae::InputManager::GetInstance().IsKeyPressed(SDLK_o))
	{
		m_pPacman->SetEnabled(true);
	}

	if (dae::InputManager::GetInstance().IsKeyPressed(SDLK_p))
	{
		m_pPacman->SetEnabled(false);
	}
}

void PacmanDemoScene::Render()
{
}
