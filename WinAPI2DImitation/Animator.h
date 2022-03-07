#pragma once

class GameObject;
class Animation;
class Texture;

class Animator
{
	friend class GameObject;

private:
	map<wstring, Animation*>	m_mapAni;
	Animation* m_pCurAni;
	GameObject* m_pOwner;

public:
	Animator();
	~Animator();

	GameObject* getObj();

	void update();
	void render(HDC _hDC);

	void createAnimation(const wstring& strName, 
						 Texture* tex,
						 fPoint lt,
						 fPoint slice,
						 fPoint step,
						 float duration,
						 UINT frmCount);
	Animation* findAnimation(const wstring& strName);
	void play(const wstring& strName);
};

