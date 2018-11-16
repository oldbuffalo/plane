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

		bool flag = false;  //����Ƿ�Ҫɾ���ڵ����
		auto ite_emeny =  EmenyManger.m_emerylist.begin();
		while(ite_emeny !=  EmenyManger.m_emerylist.end())
		{
			//�ӵ��ڷɻ����ο���
			if((*ite_bullet)->m_x >= (*ite_emeny)->m_x &&(*ite_bullet)->m_x <= (*ite_emeny)->m_x+(*ite_emeny)->width 
				&& (*ite_bullet)->m_y >= (*ite_emeny)->m_y && (*ite_bullet)->m_y <= (*ite_emeny)->m_y+(*ite_emeny)->length)
			{	
				flag = true;
				//�ӵ���������ɾ��
				delete *ite_bullet;
				*ite_bullet = NULL;
				ite_bullet = m_bulletlist.erase(ite_bullet); 
				//�ɻ�Ѫ������
				(*ite_emeny)->blood--;

				//�ж��Ƿ�ը
				if((*ite_emeny)->IsExplosion())
				{
					//�Ӵ��ɻ�������ɾ�� �ӵ���ը�ɻ�������
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
