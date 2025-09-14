#include "AccelAdapter.h"

bool AccelAdapter::Up() {
	return m_Accel.GetVerticalAxis() > 0 ;
}

bool AccelAdapter::Down() {
	return m_Accel.GetVerticalAxis() < 0 ;
}

bool AccelAdapter::Left() {
	return m_Accel.GetHorizontalAxis() < 0 ;
}

bool AccelAdapter::Right() {
	return m_Accel.GetHorizontalAxis() > 0 ;
}
