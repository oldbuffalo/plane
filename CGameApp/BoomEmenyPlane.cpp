#include "BoomEmenyPlane.h"


void CBoomEmenyPlane::ShowAlBoomPlane(HDC hMemDC)
{
 	auto ite = m_BoomPlanelist.begin();
	while(ite != m_BoomPlanelist.end())
	{
		(*ite)->ShowEmenyPlane(hMemDC);
		ite++;
	}
}
void CBoomEmenyPlane::ChangeShowId()
{
	auto ite = m_BoomPlanelist.begin();
	while(ite != m_BoomPlanelist.end())
	{
		if((*ite)->nShowID == 0)
		{
			delete *ite;
			*ite = NULL;
			ite =  m_BoomPlanelist.erase(ite);
			break;
		}
		else
		   (*ite)->nShowID--;
		ite++;
	}
}


CBoomEmenyPlane::CBoomEmenyPlane(void)
{
}


CBoomEmenyPlane::~CBoomEmenyPlane(void)
{
	auto ite = m_BoomPlanelist.begin();
	while(ite != m_BoomPlanelist.end())
	{
		delete *ite;
		*ite = NULL;
		ite++;
	}
}
