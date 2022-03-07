#pragma once

class Animator;
class Texture;

struct AniFrm
{
	fPoint fptLT;
	fPoint fptSlice;
	fPoint fptOffset;
	float fDuration;
};

class Animation
{
	friend class Animator;


private:
	wstring			m_strName;			  //애니메이션 이름
	Animator*		m_pAnimator;		  //애니메이터
	Texture*		m_pTex;				  //애니메이션 이미지
	vector<AniFrm>	m_vecFrm;			  //모든 프레임의 자르기 영역 및 유지시간
	int				m_iCurFrm;			  //현재 프레임의 index
	float			m_fAccTime;			  //다음 프레임까지 축적시간

public:
	Animation();
	~Animation();

	void setName(const wstring& _strName);
	const wstring& getName();

	void setFrame(int _frmIndex);
	AniFrm& getFrame(int _frmIndex);

	void update();
	void render(HDC hDC);

	void create(Texture* tex, fPoint lt, fPoint slice, fPoint step, float duration, UINT frmCount);	// 애니메이션 생성

};

