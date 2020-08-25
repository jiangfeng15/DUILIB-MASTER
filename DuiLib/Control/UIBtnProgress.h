#ifndef UI_BTN_PROGRESS_H
#define UI_BTN_PROGRESS_H
#pragma once

#include <GdiPlus.h>
#pragma comment( lib, "GdiPlus.lib" )
using namespace Gdiplus;
class UILIB_API Gdiplus::RectF;
struct UILIB_API Gdiplus::GdiplusStartupInput;

#define PI  3.1415926

namespace DuiLib
{
	class UILIB_API CBtnProgressUI : public CControlUI
	{
	public:
		CBtnProgressUI();
		~CBtnProgressUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		void		SetEnabledEffect(bool _EnabledEffect);
		bool		GetEnabledEffect();
		void DoEvent(TEventUI& event);
		void DoPaint(HDC hDC, const RECT& rcPaint);
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		//���ý�������ɫ
		void SetProgressColor(DWORD dwColor);
		//���ð�ť�ⲿԲ������ɫ
		void SetOutBtnBkColor(DWORD dwColor);
		//���ð�ť������ɫ
		void SetBtnBkColor(DWORD dwColor);
		//���ð�ť���������ɫ
		void SetBtnHotColor(DWORD dwColor);
		//���ð�ť����״̬��ɫ
		void SetBtnPushColor(DWORD dwColor);
		//���ý��������
		void SetProgressWidth(DWORD dwWidth);
		//���ý������뾶
		void SetProgressRadius(DWORD dwRadius);
		//���ð�ť�뾶
		void SetBtnRadius(DWORD dwRadius);
		//���ð�ť����������
		void SetBtnSpace(DWORD dwSpace);
		//���ý�����ֵ
		void SetScoreValue(DWORD dwValue);
		//���ð�ť�ı�
		void SetBtnTextValue(LPCTSTR pstrText);
		//���ð�ť�ı���ɫ
		void SetBtnTextColor(DWORD dwValue);
		//��ȡ��ť�ı�
		CDuiString GetBtnText() const;
		//���ý������ı���ʾ�߾�
		void SetValueTextPadding(RECT rc);
		//���ð�ť�ı���ʾ�߾�
		void SetBtnTextPadding(RECT rc);
		//���ý���������
		void SetValueFont(int index);
		//���ð�ť�ı�����
		void SetBtnTextFont(int index);
		//��ȡ����������
		int GetValueFont() const;
		//��ȡ��ť�ı�����
		int GetBtnTextFont() const;
		//��ť��������հ״������������
		void SetBtnSpacePadding(DWORD dwValue);
		//����Բ�ΰ�ť����ʱ������ɫ
		void EnableBtnStatus(bool bEnable);
		//�ж��������ťλ���Ƿ���Բ�ΰ�ť��
		bool IsPointInBtn(POINT pMouse);
		void		SetEnabledValueStroke(bool _EnabledStroke);
		bool		GetEnabledValueStroke();
		void		SetEnabledValueShadow(bool _EnabledShadowe);
		bool		GetEnabledValueShadow();

		void		SetEnabledBtnTextStroke(bool _EnabledStroke);
		bool		GetEnabledBtnTextStroke();
		void		SetEnabledBtnTextShadow(bool _EnabledShadowe);
		bool		GetEnabledBtnTextShadow();

		void		SetStrokeValueColor(DWORD _StrokeColor);
		DWORD		GetStrokeValueColor();

		void		SetStrokeBtnTextColor(DWORD _StrokeColor);
		DWORD		GetStrokeBtnTextColor();

		//���ƽ�������ť�ؼ�
		void DoDrawProgress(HDC hdc, RECT CtrlRect);

		//���ƽ�������ֵ
		void DoDrawScoreValue(HDC hdc);
		//����Բ�οؼ��ı�
		void DoDrawBtnText(HDC hdc);

	private:
		ULONG_PTR				m_gdiplusToken;
		GdiplusStartupInput		m_gdiplusStartupInput;


		//��Բ������Բ������
		PointF					m_pfCircularCenter;
		PointF					m_pfBtnCenter;

		//��������ɫ
		DWORD					m_dwProgressBkColor;
		//��ť�⻷��ɫ
		DWORD					m_dwOutBtnBkColor;
		//��ť������ɫ
		DWORD					m_dwBtnBkColor;
		//��ťhot״̬��ɫ
		DWORD					m_dwBtnHotColor;
		//��ťPush״̬��ɫ
		DWORD					m_dwBtnPushColor;
		//���������
		DWORD					m_dwProgressWidth;
		//������Բ�뾶
		DWORD					m_dwProgressRadius;
		//��ť�뾶
		DWORD					m_dwBtnRadius;
		//��ť����������
		DWORD					m_dwBtnSpace;
		//��ť�ؼ��ľ������������ж�������¼�
		RECT					m_rcButton;

		bool					m_bFocused;	
		//��������ʾ��ֵ
		DWORD					m_dwProgressValue;
		//�ı���ʾ��ʽ
		UINT					m_uValueStyle;
		//�ı���ʾλ��
		RECT					m_rcValueTextPadding;
		//��������ֵ��ɫ
		DWORD					m_dwVauleColor;
		//��������ֵ������ɫ
		DWORD					m_dwDisabledVauleColor;
		//��ť��ʾ�ı�
		CDuiString				m_csBtnText;
		//�ı���ʾ��ʽ
		UINT					m_uTextStyle;
		//�ı���ʾλ��
		RECT					m_rcBtnTextPadding;
		//��ť�ı���ɫ
		DWORD					m_dwBtnTextColor;
		//��ť�����ı���ɫ
		DWORD					m_dwDisabledBtnTextColor;
		//��ť��������հ״������������
		DWORD					m_dwBtnSpacePadding;

		int						m_hAlign;
		int						m_vAlign;

		int						m_iScoreFont;  //��������
		int						m_iBtnTextFont; //��ť�ı�����
		bool					m_EnableEffect;

		RectF					m_ShadowValueOffset;
		RectF					m_ShadowBtnTextOffset;

		bool					m_EnabledValueStroke;
		bool					m_EnabledValueShadow;

		bool					m_EnabledBtnTextStroke;
		bool					m_EnabledBtnTextShadow;

		DWORD					m_dwStrokeValueColor;
		DWORD					m_dwStrokeBtnTextColor;
	};
}
#endif