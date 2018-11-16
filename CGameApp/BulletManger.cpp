#include "BulletManger.h"


void CBulletManger::AllBulletMove()
{
	auto ite = m_bulletlist.begin();
	while(ite != m_bulletlist.end())
	{
		(*ite)->MoveBullet();
		ite++;
	}	
}
void CBulletManger::AllBulletShow(HDC hMemDC)
{
	auto ite = m_bulletlist.begin();
	while(ite != m_bulletlist.end())
	{
		(*ite)->ShowBullet(hMemDC);
		ite++;
	}	
}
void CBulletManger::IsHitEmeny(CEmenyManger &EmenyManger,CBoomEmenyPlane &BoomEmenyManger)
{
	auto ite_bullet = m_bulletlist.begin();

	while(ite_bullet != m_bulletlist.end())
	{

		bool flag = false;  //标记是否要删除炮弹结点
		auto ite_emeny =  EmenyManger.m_emerylist.begin();
		while(ite_emeny !=  EmenyManger.m_emerylist.end())
		{
			//子弹在飞机矩形框中
			if((*ite_bullet)->m_x >= (*ite_emeny)->m_x &&(*ite_bullet)->m_x <= (*ite_emeny)->m_x+(*ite_emeny)->width 
				&& (*ite_bullet)->m_y >= (*ite_emeny)->m_y && (*ite_bullet)->m_y <= (*ite_emeny)->m_y+(*ite_emeny)->length)
			{	
				flag = true;
				//子弹从链表上删除
				delete *ite_bullet;
				*ite_bullet = NULL;
				ite_bullet = m_bulletlist.erase(ite_bullet); 
				//飞机血量减减
				(*ite_emeny)->blood--;

				//判断是否爆炸
				if((*ite_emeny)->IsExplosion())
				{
					//从存活飞机链表上删除 加到爆炸飞机链表上
					BoomEmenyManger.m_BoomPlanelist.splice(BoomEmenyManger.m_BoomPlanelist.end(),EmenyManger.m_emerylist,ite_emeny);	
				}

				break;
			}

			ite_emeny++;
		}

		if(flag == false)
			ite_bullet++;
		else
		   flag = false;
	}

}


CBulletManger::CBulletManger(void)
{
}


CBulletManger::~CBulletManger(void)
{
	auto ite = m_bulletlist.begin();
	while(ite != m_bulletlist.end())
	{
		delete *ite;
		*ite = NULL;
		ite++;
	}
}
