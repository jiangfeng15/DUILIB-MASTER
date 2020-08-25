#include "StdAfx.h"
#include "UIChartCtrl.h"

#include <atlconv.h>
namespace DuiLib
{

	CChartCtrlUI::CChartCtrlUI() : m_gdiplusToken(0),
		m_EnableEffect(false),
		m_stPointXy(NULL),
		m_bDataAdd(false),
		m_bFirstUpdate(false),
		m_bGetRectChart(false)
	{
		m_nCurPointCount = 0;

		m_rectChart.left = 0;
		m_rectChart.top = 0;
		m_rectChart.right = 0;
		m_rectChart.bottom = 0;

		GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL);
	}

	CChartCtrlUI::~CChartCtrlUI()
	{
		try
		{
			GdiplusShutdown(m_gdiplusToken);
			if (m_stPointXy != NULL)
			{
				delete m_stPointXy;
				m_stPointXy = NULL;
			}
		}
		catch (...)
		{
			throw "CChartCtrlUI::~CChartCtrlUI";
		}
	}

	LPCTSTR CChartCtrlUI::GetClass() const
	{
		return DUI_CTR_CHART_CONTROL;
	}

	LPVOID CChartCtrlUI::GetInterface(LPCTSTR pstrName)
	{
		if (_tcscmp(pstrName, DUI_CTR_CHART_CONTROL) == 0) return static_cast<CChartCtrlUI*>(this);
		return CControlUI::GetInterface(pstrName);
	}
	CDuiString CChartCtrlUI::GetText() const
	{
		try
		{
			if (!m_EnableEffect)
				return CControlUI::GetText();
			return m_TextValue;
		}
		catch (...)
		{
			throw "CChartCtrlUI::GetText";
		}
	}
	void CChartCtrlUI::SetText(LPCTSTR pstrText)
	{
		try
		{
			if (!GetEnabledEffect())
				return CControlUI::SetText(pstrText);

			m_TextValue = pstrText;
		}
		catch (...)
		{
			throw "CChartCtrlUI::SetText";
		}
	}

	void CChartCtrlUI::SetEnabledEffect(bool _EnabledEffect)
	{
		try
		{
			m_EnableEffect = _EnabledEffect;
		}
		catch (...)
		{
			throw "CLabelUI::SetEnabledEffect";
		}
	}


	bool CChartCtrlUI::GetEnabledEffect()
	{
		try
		{
			return m_EnableEffect;
		}
		catch (...)
		{
			throw "CLabelUI::GetEnabledEffect";
		}
	}
	void CChartCtrlUI::DoEvent(TEventUI& event)
	{

		CControlUI::DoEvent(event);
	}
	void CChartCtrlUI::SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue)
	{
		LPTSTR pstr = NULL;
		if (_tcscmp(pstrName, _T("curvpen")) == 0) {
			if (*pstrValue == _T('#')) pstrValue = ::CharNext(pstrValue);
			LPTSTR pstr = NULL;
			DWORD clrColor = _tcstoul(pstrValue, &pstr, 16);
			SetCurvPenColor(clrColor);
		}
		else if (_tcscmp(pstrName, _T("width")) == 0)
		{
			DWORD dwWidth = _tcstoul(pstrValue, &pstr, 10);
			m_dwWidth = dwWidth;
			ASSERT(m_dwWidth > 0);
			//初始化数据，分配数据空间
			m_stPointXy = new PointF[m_dwWidth];
			ASSERT(m_stPointXy != NULL);
			CControlUI::SetAttribute(pstrName, pstrValue);
		}
		else if (_tcscmp(pstrName, _T("height")) == 0)
		{
			DWORD dwHeight = _tcstoul(pstrValue, &pstr, 10);
			m_dwHeight = dwHeight;
			ASSERT(m_dwHeight > 0);
			CControlUI::SetAttribute(pstrName, pstrValue);
		}
		else
			CControlUI::SetAttribute(pstrName, pstrValue);
	}
	void CChartCtrlUI::SetCurvPenColor(DWORD dwColor)
	{
		m_curvPenColor = dwColor;
	}
	int CChartCtrlUI::GetPointCount()
	{
		return m_nCurPointCount;
	}

	void CChartCtrlUI::AddPointXy(PointF clsPointF)
	{
		POINTF tempPf;

		if (m_nCurPointCount > m_dwWidth)
			return;
		if (!m_bGetRectChart) //没有获取到矩形区域
			return;
		if (m_nCurPointCount == m_dwWidth)
		{
			for (int i = 0; i < m_nCurPointCount-1; i++)
			{
				m_stPointXy[i].Y = m_stPointXy[i+1].Y;
				//X值保持不变
			}
			m_stPointXy[m_nCurPointCount-1] = clsPointF;
		}
		else
		{
			m_stPointXy[m_nCurPointCount].X = clsPointF.X;
			m_stPointXy[m_nCurPointCount].Y = clsPointF.Y;
			m_nCurPointCount++;
		}
		m_bDataAdd = true;
	}
	PointF CChartCtrlUI::valueToPointF(float value)
	{
		PointF clsRes;
		clsRes.X = 0.0; 
		clsRes.Y = 0.0;
		if (m_bGetRectChart) //正确获取控件矩形区域
		{
			clsRes.Y = (REAL)m_rectChart.top + ((REAL)m_dwHeight - value / 100.0 * (REAL)m_dwHeight);
			if (m_nCurPointCount < m_dwWidth)
				clsRes.X = m_nCurPointCount + 1 + m_rectChart.left;
			else
				clsRes.X = m_nCurPointCount + m_rectChart.left;
		}

		return clsRes;
	}
	void CChartCtrlUI::DoPaint(HDC hDC, const RECT& rcPaint)
	{
		CControlUI::DoPaint(hDC, rcPaint);
		if (!m_bGetRectChart)
		{
			m_rectChart = this->GetPos();
			if (m_rectChart.left > 0 && m_rectChart.right > 0 && m_rectChart.top > 0 && m_rectChart.bottom > 0)
				m_bGetRectChart = true;
		}

		//重绘制曲线图
		//if (m_bDataAdd) //有数据加入
		{
			Pen      pen(m_curvPenColor);
			Graphics graphics(hDC);
			graphics.SetSmoothingMode(SmoothingModeAntiAlias);

			Status restatus = graphics.DrawCurve(&pen, (const PointF*)m_stPointXy, m_nCurPointCount);
			m_bDataAdd = false;
		}

	}
}