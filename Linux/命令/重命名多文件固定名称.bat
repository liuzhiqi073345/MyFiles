@Echo off
setlocal enabledelayedexpansion
for /f "delims=" %%a in ('dir /s /b /a-d') do (
 if "%%~sa" neq "%~s0" (
  set "xz=%%~nxa"
  set xz=!xz:[�����]=!

echo xz:[�����]
  attrib -s -h -r %%~sa 2>nul &&ren %%~sa "!xz!" 2>nul
))
pause 

����ΪBAT�ļ�������Ƶ�����ļ������� 
Ҫ��VISTA��WIN7ϵͳ���Ҽ����Թ���Ա������С�BAT�ļ�