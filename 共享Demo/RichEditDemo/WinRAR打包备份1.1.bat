@rem -------------------------------
@rem WinRAR�������.bat v1.1
@rem zhupf.m2s.venustech 
@rem 2008-9-25 ������ ���� 1:36
@rem -------------------------------

@rem �õ���ǰĿ¼
@for %%p in ("%cd%") do @set myapp=%%~nxp

@rem ������е�bin�ļ���
@rd /S/Q bin >nul 2>nul

@rem ����bin bin\Debug bin\Release �ļ���
@md bin >nul 2>nul
@md bin\Debug >nul 2>nul
@md bin\Release >nul 2>nul

@rem �������ɵ��ļ���bin�ļ���
@copy /Y Debug\%myapp%.exe bin\Debug\ >nul 2>nul
@copy /Y Release\%myapp%.exe bin\Release\ >nul 2>nul
@copy /Y Debug\%myapp%.dll bin\Debug\ >nul 2>nul
@copy /Y Release\%myapp%.dll bin\Release\ >nul 2>nul
@copy /Y Debug\%myapp%.lib bin\Debug\ >nul 2>nul
@copy /Y Release\%myapp%.lib bin\Release\ >nul 2>nul
@copy /Y Debug\%myapp%.ocx bin\Debug\ >nul 2>nul
@copy /Y Release\%myapp%.ocx bin\Release\ >nul 2>nul

@rem ɾ��Debug��Release�ļ���
@rd /S/Q Debug >nul 2>nul
@rd /S/Q Release >nul 2>nul

@rem ����SRCBAK�ļ���
@md SRCBAK >nul 2>nul

@rem �ڳ���λ�ò���WinRAR
@FOR %%M IN (C D E F G H I J K L M N O P Q R S T U V W X Y Z) DO (
@set myrar="%%M:\Program Files\WinRAR\rar"
@if exist "%%M:\Program Files\WinRAR\rar.exe" goto findrar)
@echo �Ҳ���WinRAR��װλ��,���޸ı�������ָ��
@echo �밴������˳�...
@pause >nul 2>nul
@goto Exit
:findrar
@echo �ҵ���WinRAR��װλ��: %myrar%

@rem ��rarѹ����Ҫ���ݵĴ�����ļ���SRCBAK�ļ�����
::rar
@%myrar% a -r -y -x*.rar -x*\cvs -x*\cvs\* -x*\SRCBAK -x*\SRCBAK\* -x*\ref -x*\ref\* -x.cvsignore -x*.log -x*.WW -x*.aps -x*.exp -x*.idb -x*.ilk -x*.ncb -x*.obj -x*.opt -x*.pch -x*.pdb -x*.plg -x*.positions -x*.res -x*.sbr -x*.tlb -x*.tli -x*.tlh -xver.dat -xReadMe.txt -x*.bak -x*.tmp -x*.temp -xThumbs.db -x*.GID  -agMM{��}DD{��}HH{��}MM{��} .\SRCBAK\%myapp%_ >nul 2>nul
::-x*.log -x*.bat
::@rd /S/Q bin >nul 2>nul
@rem pause
:Exit