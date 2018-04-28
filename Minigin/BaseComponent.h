#pragma once
namespace dae
{
	class GameObject;

	class BaseComponent
	{
	public:
		BaseComponent();
		virtual ~BaseComponent();
		

	protected:
		virtual void Update(float elapsedSec) = 0;
		virtual void Render() = 0;
		void SetGameObject(GameObject* pGameObject) { m_pGameObject = pGameObject; }
		GameObject* GetGameObject() { return m_pGameObject; }


		GameObject* m_pGameObject;
		//add transform later


	private:
		friend class GameObject;

	};
}



