����Դ�ļ���

MyClass.cpp

MyStruct.cpp

ʹ��Դ�ļ���

g++ test.cpp MyClass.cpp MyStruct.cpp -o test1.exe

����Ŀ���ļ���

g++ -c MyClass.cpp -o MyClass.o

g++ -c MyStruct.cpp -o MyStruct.o

ʹ��Ŀ���ļ���

g++ test.cpp MyClass.o MyStruct.o -o test2.exe

�������ļ���

ar -crv MyLib.a MyClass.o MyStruct.o

ar -t MyLib.a

ʹ�ÿ��ļ���

g++ test.cpp MyLib.a -o test3.exe

������libMy.a

g++ test.cpp -L. -lMy -o test4.exe

�ƶ�����Ŀ¼��mingw\lib

g++ test.cpp -lMy -o test5.exe

