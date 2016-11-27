#rem path
BASETOOLDIR=$(VS140COMNTOOLS)../..
TOOLPATH=$(BASETOOLDIR)/vc/bin/
INC1=$(BASETOOLDIR)/vc/include
INC2=C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt
LIB1=$(BASETOOLDIR)/vc/lib
LIB2=C:\Program Files (x86)\Windows Kits\10\lib\10.0.10240.0\ucrt\x86
PATH=$(PATH);$(TOOLPATH)
!IFNDEF SDK
SDK=X:\
!ENDIF

# rem compiler
CC=cl
CFLAGS=/c /I "$(INC1)" /I "$(INC2)"

#rem linker
LD=link
LDFLAGS=/SUBSYSTEM:CONSOLE /LIBPATH:"$(LIB1)" /LIBPATH:"$(LIB2)" /LIBPATH:"$(SDK)"

all: main.exe	
	@echo build "main.exe" done

main.exe: main.obj
	$(LD) main.obj $(LDFLAGS)

main.obj: main.c
	$(CC) $(CFLAGS) main.c

clean:
	del main.exe
	del main.obj


