#include "framework.h"
#include "CollisionManager.h"
#include "Scene.h"
#include "Collider.h"



CollisionManager::CollisionManager()
{
	m_arrCheck[0] = 0;
}

CollisionManager::~CollisionManager()
{
	
}

void CollisionManager::CollisionGroupUpdate(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight)
{
	Scene* pCurScene = CURSCENE;

	const vector<GameObject*>& vecLeft = pCurScene->getGroupObject(_objLeft);
	const vector<GameObject*>& vecRight = pCurScene->getGroupObject(_objRight);


	for (int i = 0; i < vecLeft.size(); i++)
	{
		//�浹ü Right Collider Component �� ���� ��� ����
		if (nullptr == vecLeft[i]->getCollider())
			continue;

		for (int j = 0; j < vecRight.size(); j++)
		{
			// �ڱ� �ڽŰ��� �浹�� ����;
			if (vecLeft[i] == vecRight[j])
				continue;

			//  �浹ü Right Collider Component �� ���� ��� ����
			if (nullptr == vecRight[j]->getCollider())
				continue;

			// �� �浹ü ID�� �̿��ؼ� ������ Ű ����

			ColliderID id;

			id.leftID = vecLeft[i]->getCollider()->getID();
			id.rightID = vecRight[j]->getCollider()->getID();

			map<ULONGLONG, bool>::iterator iter = m_mapCollInfo.find(id.ID);

			// �浹 ������ ���� ���, �浹���� ���� ���¸� �־���

 			if (m_mapCollInfo.end() == iter)
			{
				m_mapCollInfo.insert(make_pair(id.ID, false));
				iter = m_mapCollInfo.find(id.ID);
			}

			if (IsCollision(vecLeft[i]->getCollider(), vecRight[j]->getCollider()))
			{
				//prev O , cur O
				if (iter->second)
				{
					vecLeft[i]->getCollider()->onCollision(vecRight[j]->getCollider());
					vecRight[j]->getCollider()->onCollision(vecLeft[i]->getCollider());
				}	
				else
				{
					vecLeft[i]->getCollider()->onCollisionEnter(vecRight[j]->getCollider());
					vecRight[j]->getCollider()->onCollisionEnter(vecLeft[i]->getCollider());
					iter->second = true;
				}
			}		
			else
			{
				// Prev O, Cur X
				if (iter->second)
				{
					vecLeft[i]->getCollider()->onCollisionExit(vecRight[j]->getCollider());
					vecRight[j]->getCollider()->onCollisionExit(vecLeft[i]->getCollider());
					iter->second = false;
				}
				// Prev X, Cur X
				else
				{
					// �ƹ��͵� ���� ����
				}
			}
		}
	}

}

bool CollisionManager::IsCollision(Collider* _pLeftCollider, Collider* _pRightCollider)
{
	fPoint fptLeftPos = _pLeftCollider->getFinalPos();
	fPoint fptLeftScale = _pLeftCollider->getScale();

	fPoint fptRightPos = _pRightCollider->getFinalPos();
	fPoint fptRightScale = _pRightCollider->getScale();


	// 		 �ѤѤѤѤѤѤ�		 �ѤѤѤѤѤѤ�									 �ѤѤѤѤѤѤ� 
	//		|			 |		|			 |									|			 | 
	// 		|			 |		|			 |									|			 |
	//		|	  o   	 |		|	  o 	 |									|	  o 	 | |
	//		|			 |		|			 |									|			 | |
	//		|			 |		|			 |									|			 | |
	//       �ѤѤѤѤѤѤ�       �ѤѤѤѤѤѤ�									 �ѤѤѤѤѤѤ� |
	//             �ѤѤѤ�      �ѤѤѤ� ���� ���� ���� �� ����						���� ���� ���� �� ����
	//																			 �ѤѤѤѤѤѤ�  |
	//			�Ÿ��� �������� ���� �� ����										|			 |	|
	//																			|			 |	|
	//																			|	  o 	 |	|
	//																			|			 |
	//																			|			 |
	//																			 �ѤѤѤѤѤѤ�
	//
	//
	//		//�װ� ����� ��� ������ ��� �Ÿ� ���� ������ �Ÿ��� ������ �� ���� ũ�⺸�� �Ѵ� ������ ��������
	if (abs(fptLeftPos.x - fptRightPos.x) < (fptLeftScale.x + fptRightScale.x) / 2.f
		&& abs(fptLeftPos.y - fptRightPos.y) < (fptLeftScale.y + fptRightScale.y) / 2.f)
	{
		return true;
	}

	return false;
}

void CollisionManager::init()
{

}

void CollisionManager::update()
{
	for (UINT iRow = 0; iRow < (UINT)GROUP_GAMEOBJ::SIZE; iRow++)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_GAMEOBJ::SIZE; iCol++)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				// �浹�� �˻��ؾ��ϴ� �� �׷�
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow, (GROUP_GAMEOBJ)iCol);
			}
		}
	}
}

void CollisionManager::CheckGroup(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight)
{
	// [��][��]
	UINT iRow;	// ��
	UINT iCol;	// ��

	// �� ���� ���� ������ ��
	if ((UINT)_objLeft < (UINT)_objRight)
	{
		iRow = (UINT)_objLeft;
		iCol = (UINT)_objRight;
	}
	else
	{
		iRow = (UINT)_objRight;
		iCol = (UINT)_objLeft;
	}
	//��Ʈ�����ڷ� �� ����
	m_arrCheck[iRow] |= (1 << iCol);
}

void CollisionManager::UnCheckGroup(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight)
{
	// [��][��]
	UINT iRow;	// ��
	UINT iCol;	// ��

	// �� ���� ���� ������ ��
	if ((UINT)_objLeft > (UINT)_objRight)
	{
		iRow = (UINT)_objLeft;
		iCol = (UINT)_objRight;
	}
	else
	{
		iRow = (UINT)_objRight;
		iCol = (UINT)_objLeft;
	}
	// ��Ʈ�����ڷ� ����
	m_arrCheck[iRow] &= ~(1 << iCol);
}

void CollisionManager::Reset()
{
	// memset(���� �ּ�, ������ ������, ������ ũ��);
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_GAMEOBJ::SIZE);

}
