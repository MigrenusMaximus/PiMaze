@echo off
2>NUL del *.o
2>NUL del *.ko
2>NUL del *.obj
2>NUL del *.elf
2>NUL del *.gch
2>NUL del *.pch
2>NUL del *.lib
2>NUL del *.a
2>NUL del *.la
2>NUL del *.lo
rem 2>NUL del *.dll
2>NUL del *.so
2>NUL del *.so.*
2>NUL del *.dylib
rem 2>NUL del *.exe
2>NUL del *.out
2>NUL del *.app
2>NUL del *.i*86
2>NUL del *.x86_64
2>NUL del *.hex
echo "Cleanup complete"