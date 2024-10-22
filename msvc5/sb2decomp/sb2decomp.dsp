# Microsoft Developer Studio Project File - Name="sb2decomp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=sb2decomp - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "sb2decomp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sb2decomp.mak" CFG="sb2decomp - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sb2decomp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "sb2decomp - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sb2decomp - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /Gi /GX /O2 /I "..\..\dxsdk3\sdk\inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_X86_" /D WINVER=0x0400 /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ddraw.lib dsound.lib dplayx.lib dxguid.lib /nologo /subsystem:windows /machine:I386 /libpath:"..\..\dxsdk3\sdk\lib" /FORCE:MULTIPLE
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "sb2decomp - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /Gm /Gi /GX /Zi /Od /I "..\..\dxsdk3\sdk\inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_X86_" /D WINVER=0x0400 /FR /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ddraw.lib dsound.lib dplayx.lib dxguid.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"..\..\dxsdk3\sdk\lib" /FORCE:MULTIPLE
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "sb2decomp - Win32 Release"
# Name "sb2decomp - Win32 Debug"
# Begin Source File

SOURCE=..\..\src\blupi.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\button.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\button.h
# End Source File
# Begin Source File

SOURCE=..\..\src\ddutil.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\ddutil.h
# End Source File
# Begin Source File

SOURCE=..\..\src\decblock.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\decblupi.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\decdesign.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\decio.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\decmove.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\decnet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\decor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\decor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\dectables.h
# End Source File
# Begin Source File

SOURCE=..\..\src\def.h
# End Source File
# Begin Source File

SOURCE=..\..\src\event.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\event.h
# End Source File
# Begin Source File

SOURCE=..\..\src\jauge.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\jauge.h
# End Source File
# Begin Source File

SOURCE=..\..\src\menu.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\menu.h
# End Source File
# Begin Source File

SOURCE=..\..\src\misc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\misc.h
# End Source File
# Begin Source File

SOURCE=..\..\src\movie.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\movie.h
# End Source File
# Begin Source File

SOURCE=..\..\src\network.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\network.h
# End Source File
# Begin Source File

SOURCE=..\..\src\obstacle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\pixmap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\pixmap.h
# End Source File
# Begin Source File

SOURCE=..\..\src\pixtables.h
# End Source File
# Begin Source File

SOURCE=..\..\src\resource.h
# End Source File
# Begin Source File

SOURCE=..\..\src\resource1.h
# End Source File
# Begin Source File

SOURCE=..\..\src\sound.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\sound.h
# End Source File
# Begin Source File

SOURCE=..\..\src\text.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\text.h
# End Source File
# Begin Source File

SOURCE=..\..\src\texttables.h
# End Source File
# Begin Source File

SOURCE=..\..\src\wave.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\wave.h
# End Source File
# End Target
# End Project
