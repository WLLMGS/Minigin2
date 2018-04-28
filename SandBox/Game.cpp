#include "stdafx.h"
#include "Game.h"
#include "SceneManager.h"
#include "EngineTestScene.h"
#include "PacmanDemoScene.h"
#include "InputManager.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::LoadGameData()
{
	dae::SceneManager::GetInstance().AddScene(new PacmanDemoScene());
	dae::SceneManager::GetInstance().AddScene(new PacmanDemoScene());
}

void Game::Update(float elapsedSec)
{
	
}
