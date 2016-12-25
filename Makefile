all: compile stripcomment

compile:
	gcc -s -O2 \
	-nostdlib \
    -fno-unwind-tables \
    -fno-asynchronous-unwind-tables \
    -fdata-sections \
    -Wl,--gc-sections \
    -Wa,--noexecstack \
    -fno-builtin \
    -fno-stack-protector \
	ls.c ls.S -o ls.exe

stripcomment:
	strip -R .comment ls.exe

clean:
	rm ls.exe
