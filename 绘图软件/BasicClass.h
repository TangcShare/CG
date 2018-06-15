#ifndef BasicClass_
#define BasicClass_
class CDraw{
	public:
	CDraw(){};//构造函数
	COLORREF m_colorPen;//颜色
	COLORREF m_colorBrush;//填充颜色
	int m_lineWide;//线宽
	int m_lineType;//线型：实线，虚线，点划线，双点划线

};
//直线
class CLine:CDraw{
public:
	CLine& operator =(const CLine& ln){//重载=等号操作符,实现直线赋值
			this->pt1=ln.pt1;
			this->pt2=ln.pt2;
			return *this;	};
		bool operator==(const CLine& ln){//重载==双等号操作符,判断两直线是否相同
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
	int flag;///是否有裁剪窗口,0没有,1有
};
#endif