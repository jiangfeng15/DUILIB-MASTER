#ifndef UI_CHART_CTRL_H
#define UI_CHART_CTRL_H
#pragma once

#include <GdiPlus.h>
#pragma comment( lib, "GdiPlus.lib" )
using namespace Gdiplus;
class UILIB_API Gdiplus::RectF;
struct UILIB_API Gdiplus::GdiplusStartupInput;

namespace DuiLib
{
	class UILIB_API CChartCtrlUI : public CControlUI
	{
	public:
		CChartCtrlUI();
		~CChartCtrlUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void		SetEnabledEffect(bool _EnabledEffect);
		bool		GetEnabledEffect();
		void SetText(LPCTSTR pstrText);
		CDuiString	GetText() const;
		void DoEvent(TEventUI& event);
		void DoPaint(HDC hDC, const RECT& rcPaint);
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void SetCurvPenColor(DWORD dwColor);


		int GetPointCount();
		void AddPointXy(PointF clsPointF);
		PointF valueToPointF(float value);

	private:
		DWORD					m_dwWidth; //�ؼ����
		DWORD					m_dwHeight;  //�ؼ��߶�
		DWORD					m_curvPenColor; //�������߻���
		PointF                  * m_stPointXy;//��ʾ100��ֵ�������ͺ���
		int					    m_nCurPointCount;
		bool					m_EnableEffect;
		CDuiString				m_TextValue;
		ULONG_PTR				m_gdiplusToken;
		GdiplusStartupInput		m_gdiplusStartupInput;
		bool                    m_bDataAdd; //�Ƿ������ݼ��룬�������ػ�
		bool                    m_bFirstUpdate;  //�Ƿ�������һ��
		RECT					m_rectChart;  //��������ڿͻ���������
		bool                    m_bGetRectChart; //�ж��Ƿ��ȡ����������
	};
}
#endif