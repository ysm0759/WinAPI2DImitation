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
		//충돌체 Right Collider Component 가 없는 경우 무시
		if (nullptr == vecLeft[i]->getCollider())
			continue;

		for (int j = 0; j < vecRight.size(); j++)
		{
			// 자기 자신과의 충돌은 무시;
			if (vecLeft[i] == vecRight[j])
				continue;

			//  충돌체 Right Collider Component 가 없는 경우 무시
			if (nullptr == vecRight[j]->getCollider())
				continue;

			// 두 충돌체 ID를 이용해서 유일한 키 생성

			ColliderID id;

			id.leftID = vecLeft[i]->getCollider()->getID();
			id.rightID = vecRight[j]->getCollider()->getID();

			map<ULONGLONG, bool>::iterator iter = m_mapCollInfo.find(id.ID);

			// 충돌 정보가 없는 경우, 충돌하지 않은 상태를 넣어줌

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
					// 아무것도 하지 않음
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


	// 		 ㅡㅡㅡㅡㅡㅡㅡ		 ㅡㅡㅡㅡㅡㅡㅡ									 ㅡㅡㅡㅡㅡㅡㅡ 
	//		|			 |		|			 |									|			 | 
	// 		|			 |		|			 |									|			 |
	//		|	  o   	 |		|	  o 	 |									|	  o 	 | |
	//		|			 |		|			 |									|			 | |
	//		|			 |		|			 |									|			 | |
	//       ㅡㅡㅡㅡㅡㅡㅡ       ㅡㅡㅡㅡㅡㅡㅡ									 ㅡㅡㅡㅡㅡㅡㅡ |
	//             ㅡㅡㅡㅡ      ㅡㅡㅡㅡ 둘이 절때 닿을 수 없음						둘이 절때 닿을 수 없음
	//																			 ㅡㅡㅡㅡㅡㅡㅡ  |
	//			거리가 같아져야 닿을 수 있음										|			 |	|
	//																			|			 |	|
	//																			|	  o 	 |	|
	//																			|			 |
	//																			|			 |
	//																			 ㅡㅡㅡㅡㅡㅡㅡ
	//
	//
	//		//그걸 계산한 결과 서로의 상단 거리 왼쪽 오른쪽 거리를 구한후 그 값이 크기보다 둘다 작으면 닿은거임
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
				// 충돌을 검사해야하는 두 그룹
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow, (GROUP_GAMEOBJ)iCol);
			}
		}
	}
}

void CollisionManager::CheckGroup(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight)
{
	// [행][렬]
	UINT iRow;	// 렬
	UINT iCol;	// 행

	// 더 작은 수를 행으로 둠
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
	//비트연산자로 값 변경
	m_arrCheck[iRow] |= (1 << iCol);
}

void CollisionManager::UnCheckGroup(GROUP_GAMEOBJ _objLeft, GROUP_GAMEOBJ _objRight)
{
	// [행][렬]
	UINT iRow;	// 렬
	UINT iCol;	// 행

	// 더 작은 수를 행으로 둠
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
	// 비트연산자로 해제
	m_arrCheck[iRow] &= ~(1 << iCol);
}

void CollisionManager::Reset()
{
	// memset(시작 주소, 설정할 데이터, 설정할 크기);
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_GAMEOBJ::SIZE);

}
