# compiling

gcc -Wall -m32 -I./inc/ ./src/hello.c -o ./build/bin/hello
objdump -Sx ./build/bin/hello
./build/bin/hello


# toolchain workflow

gedit ./src/hello.c ./inc/hello.h&
gcc -E -Wall -m32 -I./inc/ ./src/hello.c > ./build/misc/hello.i
gedit ./build/misc/hello.i&
gcc -S -Wall -m32 ./build/misc/hello.i -o ./build/misc/hello.s
gedit ./build/misc/hello.s&
as --32 ./build/misc/hello.s -o ./build/obj/hello.o
readelf -h ./build/obj/hello.o
objdump -Sx ./build/obj/hello.o > ./build/misc/hello.obj
gedit ./build/misc/hello.obj&
gcc -Wall -m32 ./build/obj/hello.o -o ./build/bin/hello
readelf -h ./build/bin/hello
objdump -Sx ./build/bin/hello > ./build/misc/hello.bin
gedit ./build/misc/hello.bin&
./build/bin/hello


# linking minimal

ls -l build/bin 
gcc -c -Wall -m32 -I./inc/ ./src/hello.c -o ./build/obj/hello.o
as --32 ./build/startup/crt0.s -o ./build/obj/crt0.o
ld -melf_i386 ./build/obj/crt0.o ./build/obj/hello.o -o ./build/bin/hello
readelf -h ./build/bin/hello
objdump -Sx ./build/bin/hello > ./build/misc/hello.bin
gedit ./build/misc/hello.bin&
./build/bin/hello


# linker script minimal

gcc  -m32 -Wl,--verbose
gcc -c -Wall -m32 -I./inc/ ./src/hello.c -o ./build/obj/hello.o
as --32 ./build/startup/crt0.s -o ./build/obj/crt0.o
ld -melf_i386 -T ./build/script/linker_script_default.ld ./build/obj/crt0.o ./build/obj/hello.o -o ./build/bin/hello
ls -l build/bin 
./build/bin/hello

ld -melf_i386 -T ./build/script/linker_script_minimal.ld ./build/obj/crt0.o ./build/obj/hello.o -o ./build/bin/hello
objdump -Sx ./build/bin/hello > ./build/misc/hello.bin
gedit ./build/misc/hello.bin&
ls -l ./build/bin
./build/bin/hello

strip ./build/bin/hello
ls -l ./build/bin
objdump -Sx ./build/bin/hello > ./build/misc/hello.bin
gedit ./build/misc/hello.bin&
./build/bin/hello


# execution

./build/bin/hello


# clean

rm ./build/misc/*.* ./build/obj/*.o ./build/bin/*


