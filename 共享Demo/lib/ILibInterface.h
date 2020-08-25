#ifndef __ILibInterface_H
#define __ILibInterface_H

/** ��lib�ļ��ĸ��º���ӹ���

*   FileName  : ILibInterface.h

*   Author    : Double Sword

*   date      : 2011-8-16

*   Copyright : Copyright belong to Author and ZhiZunNet.CO.

*   RefDoc    : --

*/

/** ��zip�ļ�
*   @Author : Double sword
*   @Params : sourcrZipPath-zip�ļ�ȫ·��,password-����	
*   @Return : ���ظ�zip�ļ���id,�ر�ʱ��Ҫ���������,0ʧ��
*   @Date   : 2011-8-16
*/
extern int OpenZip(LPCSTR sourcrZipPath,LPCSTR password);

/** �ر�zip�ļ�
*   @Author : Double sword
*   @Params : fileId-��openzip���,bHasUpdateOpt�Ƿ����UpdateZipFile
*   @Return : ��
*   @Date   : 2011-8-16
*/
extern void CloseZip(int nZip,bool bHasUpdateOpt = true);

/** �Ա��ļ�crc
*   @Author : Double sword
*   @Params : nZip-OpenZip����,filename-��Ҫ�Աȵ��ļ���(zip�ڵ��ļ������Դ�Ŀ¼1/1.txt)��ulCrc-�ļ���crc		
*   @Return : true��ʾ��Ҫ���£�false����Ҫ
*   @Date   : 2011-8-16
*/
extern bool CompareCrc(int nZip,LPCSTR filename,unsigned long ulCrc);

/** �����Ҫ���µ��ļ�����
*   @Author : Double sword
*   @Params : nZip-OpenZip����,filename-�ļ���(zip�ڵ��ļ������Դ�Ŀ¼1/1.txt),pBuf-�ڴ���,nLen-����		
*   @Return : 
*   @Date   : 2011-8-16
*/
extern bool AddUpdateFile(int nZip,LPCSTR filename,char* pBuf,int nLen);

/** ��������е��ļ����ôκ������и���zip�ļ�
*   @Author : Double sword
*   @Params : nZip-OpenZip����,		
*   @Return : true�ɹ�,falseʧ��
*   @Date   : 2011-8-16
*/
extern bool UpdateZipFile(int nZip);

/** ��ȡ�ļ��б�
*   @FuncName : GetZipFileList
*   @Author   : Double sword
*   @Params   : pszList \0�ָ��� \0\0��ʾ����	
*   @Return   :	void			
*   @Date     :	2012-10-31
*/
extern void GetZipFileList(int nZip,char* pszList);


/** ��ȡzip�ļ���ѹ��Ĵ�С
*   @FuncName : 
*   @Author   : Double sword
*   @Params   : 	
*   @Return   :					
*   @Date     :	2012-10-31
*/
extern int GetZipFileSize(int nZip,char* pszFileName);


/** ��ȡzip�ļ��ֽ���
*   @FuncName : ReadZipFile
*   @Author   : Double sword
*   @Params   : nZip,pszFileName,pPwd����Ҫ����ʱ��NULL,pBuf ,lenth of pBuf

*   @Return   :	�ļ��Ĵ�С

*   @Date     :	2012-10-31
*/
extern int ReadZipFile(int nZip,char* pszFileName,char* pPwd,void* pBuf,int nBufLen);








/************************************************************************/
/* �����                                                               */
/************************************************************************/
#if defined(_MT) && defined(_DLL)	//[MD]
#	ifdef _DEBUG			//MDD
#		ifdef _UNICODE 
#			pragma comment(lib,"ZipLibud.lib")
#		else
#			pragma comment(lib,"ZipLibd.lib")
#		endif
#	else					//MD
#		ifdef _UNICODE 
#			pragma comment(lib,"ZipLibu.lib")
#		else
#			pragma comment(lib,"ZipLib.lib")
#		endif
#	endif
#elif defined(_MT) && !defined(_DLL) //[MT]
#	ifdef _DEBUG			//MTD
#		ifdef _UNICODE 
#			pragma comment(lib,"ZipLibumtd.lib")
#		else
#			pragma comment(lib,"ZipLibmtd.lib")
#		endif
#	else					//MT
#		ifdef _UNICODE 
#			pragma comment(lib,"ZipLibumt.lib")
#		else
#			pragma comment(lib,"ZipLibmt.lib")
#		endif
#	endif
#endif




//sample
//
//int main()
//{
//
//#define __WINDOWS__
//#if defined(__WINDOWS__)
//	_CrtSetDbgFlag(_CrtSetDbgFlag(0) | _CRTDBG_LEAK_CHECK_DF);
//#endif
//
//	int nZip = OpenZip( TEXT("texture.paq"),TEXT("123456") );
//	if (nZip)
//	{
//		char* pBuf = NULL;
//		int nSize = 0;
//		FILE* f = fopen("bk31.ani","rb");
//		if (f)
//		{
//			fseek(f,0,SEEK_END);
//			nSize = ftell(f);
//			fseek(f,0,SEEK_SET);
//			pBuf = new char[nSize];
//			fread(pBuf,1,nSize,f);
//
//		}
//		if( CompareCrc(nZip,"texture/bk31.ani",0) )
//		{
//			AddUpdateFile( nZip,"texture/bk31.ani",pBuf,nSize );
//		}
//
//		UpdateZipFile(nZip);
//
//		CloseZip(nZip);
//
//		if(pBuf)
//			delete[] pBuf;
//	}
//
//	return 0;
//}

#endif //__ILibInterface_H