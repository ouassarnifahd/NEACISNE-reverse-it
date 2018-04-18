*** manual building commands lines :

# gcc -Wall -march=native -std=c99 -I./test/h -I./firlib/h -o3 ./test/src/firtest_main.c ./test/src/firtest_sys.c ./firlib/src/fir_sp.c ./firlib/src/fir_sp_r4.c ./firlib/src/fir_sp_sse_r4.c -o ./build/bin/firtest -lm

# ./build/bin/firtest

*** automatic building (Makefile call) commands lines :

# make

# ./build/bin/firtest

