#ifndef BasicClass_
#define BasicClass_
class CDraw{
	public:
	CDraw(){};//���캯��
	COLORREF m_colorPen;//��ɫ
	COLORREF m_colorBrush;//�����ɫ
	int m_lineWide;//�߿�
	int m_lineType;//���ͣ�ʵ�ߣ����ߣ��㻮�ߣ�˫�㻮��

};
//ֱ��
class CLine:CDraw{
public:
	CLine& operator =(const CLine& ln){//����=�ȺŲ�����,ʵ��ֱ�߸�ֵ
			this->pt1=ln.pt1;
			this->pt2=ln.pt2;
			return *this;	};
		bool operator==(const CLine& ln){//����==˫�ȺŲ�����,�ж���ֱ���Ƿ���ͬ
			if(this->pt1==ln.pt1&&this->pt2==ln.pt2)
				return true;
			else
				return false;	}
		CPoint pt1;
		CPoint pt2;
};


class CCutRect:CDraw{
public:
	CCutRect(){
		flag=0;
		xL=0;
		xR=0;
		yT=0;
		yB=0;	}
	int xL,xR,yT,yB;
	int flag;///�Ƿ��вü�����,0û��,1��
};
#endif