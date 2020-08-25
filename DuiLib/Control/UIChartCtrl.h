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
		DWORD					m_dwWidth; //控件宽度
		DWORD					m_dwHeight;  //控件高度
		DWORD					m_curvPenColor; //绘制曲线画笔
		PointF                  * m_stPointXy;//显示100个值，超过就后移
		int					    m_nCurPointCount;
		bool					m_EnableEffect;
		CDuiString				m_TextValue;
		ULONG_PTR				m_gdiplusToken;
		GdiplusStartupInput		m_gdiplusStartupInput;
		bool                    m_bDataAdd; //是否有数据加入，加入则重绘
		bool                    m_bFirstUpdate;  //是否界面更新一次
		RECT					m_rectChart;  //窗口相对于客户区的坐标
		bool                    m_bGetRectChart; //判断是否获取到矩形坐标
	};
}
#endif