#pragma once
class Frame ;

class Widget
{
	Widget *m_pParent{} ;
protected:
	bool m_IsVisible{true} ;
public:
	void SetParent(Widget *p) {
		m_pParent = p ;
	}
	virtual void AddChild(Widget *pWidget) = 0 ;
	virtual void RemoveChild(Widget *pWidget) = 0 ;
	virtual void Paint() = 0 ;
	virtual void SetVisibility(bool visibility) = 0 ;
	virtual ~Widget()=default ;
	virtual Frame* GetFrame() {return nullptr ;} ;
	Widget * GetParent(){return m_pParent ;}
	bool HasParent()const{return m_pParent !=nullptr ;}
};

