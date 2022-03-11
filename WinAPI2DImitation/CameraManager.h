#pragma once

class GameObject;

class CameraManager
{
	SINGLETON(CameraManager);


private:
	fPoint m_fptLookAt;			// ���� �ִ� ��ġ
	fPoint m_fptCurLookAt;		// ī�޶� ���� ���� ��ġ
	fPoint m_fptPrevLookAt;		// ī�޶� ������ ���� ��ġ
	GameObject* m_pTargetObj;	// Ʈ��ŷ �� ������Ʈ

	fPoint m_fptDiff;			// �ػ� �߽ɰ� ī�޶� LookAt ������ ����

	float m_fTime = 2;			// Ÿ���� ���󰡴� �ѽð�
	float m_fAccTime;			// Ÿ���� ���� �ҿ�ð�
	float m_fSpeed;				// Ÿ���� ���󰡴� �ӵ�
	float m_fPreSpeed;			// Ÿ���� ���󰡴� �ӵ�
	float m_fAccel;				// Ÿ���� ���󰡴� ��ӵ�
	float m_fAccDir = 1.f;		// ��ӵ��� ����


	void CalDiff();


public:
	void update();

	void setLookAt(fPoint _lookAt);
	void setTargetObj(GameObject* _target);

	fPoint getLookAt();			// ���� ī�޶� ��ġ ��ȯ
	fPoint getRenderPos(fPoint _objPos);
	fPoint getRealPos(fPoint _renderPos);

};

