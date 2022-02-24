#pragma once

class GameObject;

class Scene
{

private:
	vector<GameObject*> m_arrObj[(int)GAMEOBJ_GROUP::SIZE]; // 상속받은 씬이 가지고 있어야할 오브젝트들
	wstring m_sceneName; // 씬 이름

public:
	Scene();
	virtual ~Scene();

	virtual void update();			// 가지고 있는 오브젝트들을 모두 갱신 해주는 함수
	virtual void render(HDC _hDC);	// 가지고 있는 오브젝트들을 모드 그려주는 함수

	virtual void enter() = 0;		// 각 씬들이 시작할 떄 넣야하는 object를 넣어줘야하는 함수
	virtual void exit() = 0;		// 끝날때 모든 생성된 오브젝트들을 지워주는 함수


	void setName(const wstring& _sceneName);
	wstring getName();

	void AddObject(GameObject* _pObj, GAMEOBJ_GROUP _type); // 씬에 오브젝트들을 type별로 넣어주는 함수 


};

