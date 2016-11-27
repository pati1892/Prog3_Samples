
# Sample makefile

# uncomment to debug workflow
#!CMDSWITCHES +D

!IFNDEF WINSDK
WINSDK=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include
!ENDIF
INCLUDE=$(INCLUDE);$(WINSDK)
!include <win32.mak>

!IFNDEF SLNDIR
SLNDIR=F:\Projects\DEVCOL_INT\Lecture\CPP\WS2016\Samples
!ENDIF

baseBuildDir=$(SLNDIR)
ProjectDir=$(baseBuildDir)HelloWorldCMakefile
Output=HelloWorldCMakefile.exe
Platform=Win32

!IFDEF NODEBUG
Build=Release
!ELSE
Build=Debug
!ENDIF

baseObjDir=$(ProjectDir)\obj\$(Platform)
objDir = $(baseObjDir)\$(Build)
BuildDir=$(ProjectDir)\$(Build)

Objs="$(objDir)\main.obj"

{$(ProjectDir)\}.c{$(objDir)\}.obj:
#  echo $(objDir) - $(BuildDir)
#  echo $(@D) - $(@F)
  $(cc) $(cdebug) $(cflags) $(cvars) /Fo$*  $<

$(BuildDir)\$(Output): $(Objs)
  $(link) $(ldebug) $(conflags) -out:"$@" $** $(conlibs)

# rules without targets always out of time
.PHONY: clean
.PHONY: all

clean:
	del "$(objDir)\*.obj" 
	del "$(BuildDir)\$(Output)

all: $(BuildDir)\$(Output)
