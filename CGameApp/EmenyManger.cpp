#include "EmenyManger.h"



void CEmenyManger::ALLSurviveEmenyMove()
{
	auto ite = m_emerylist.begin();
	while(ite != m_emerylist.end()){
		
		//如果飞机超过边界  就删除
		if((*ite)->m_y > 550)
		{
			delete *ite;
			*ite = NULL;
			ite = m_emerylist.erase(ite);
		}
		(*ite)->MoveEmenyPlane();
		ite++;
	}

}
void CEmenyManger::ALLSurviveEmenyShow(HDC hMemDC)
{
   	auto ite = m_emerylist.begin();
	while(ite != m_emerylist.end()){
		
		(*ite)->ShowEmenyPlane(hMemDC);
		ite++;
	}

}


CEmenyManger::CEmenyManger(void)
{
}


CEmenyManger::~CEmenyManger(void)
{
	auto ite = m_emerylist.begin();
	while(ite != m_emerylist.end()){

		delete *ite;
		*ite = NULL;

		ite++;
	}
}
