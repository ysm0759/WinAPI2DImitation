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
	wstring			m_strName;			  //�ִϸ��̼� �̸�
	Animator*		m_pAnimator;		  //�ִϸ�����
	Texture*		m_pTex;				  //�ִϸ��̼� �̹���
	vector<AniFrm>	m_vecFrm;			  //��� �������� �ڸ��� ���� �� �����ð�
	int				m_iCurFrm;			  //���� �������� index
	float			m_fAccTime;			  //���� �����ӱ��� �����ð�

public:
	Animation();
	~Animation();

	void setName(const wstring& _strName);
	const wstring& getName();

	void setFrame(int _frmIndex);
	AniFrm& getFrame(int _frmIndex);

	void update();
	void render(HDC hDC);

	void create(Texture* tex, fPoint lt, fPoint slice, fPoint step, float duration, UINT frmCount);	// �ִϸ��̼� ����

};

