howto:
	@echo "usage: make source_file_basename.bin"

%.bin:%.c
	gcc -Wall -o $@ -lpthread $<

clean:
	@rm -rf *.bin
