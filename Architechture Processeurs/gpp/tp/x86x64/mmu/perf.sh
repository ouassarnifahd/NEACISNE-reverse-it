#!/bin/bash
# hardware events capture
# command line : bash perf.sh [fileName_currentDir] [repeat_cmd]

red='\e[0;31m'
nc='\e[0m' # no color

echo -e "${red}------------ hardware events${nc}"
perf stat -B -r $2 -e cpu-cycles,instructions,cache-references,cache-misses,branch-instructions,branch-misses,bus-cycles,ref-cycles,cpu-clock,page-faults,alignment-faults ./$1 

echo -e "${red}------------ hardware events - L1 caches${nc}" 
perf stat -B -r $2 -e L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses ./$1

echo -e "${red}------------ hardware events - LLC caches${nc}" 
perf stat -B -r $2 -e LLC-loads,LLC-stores,LLC-stores,LLC-prefetches ./$1

echo -e "${red}------------ hardware events - TLB caches${nc}" 
perf stat -B -r $2 -e dTLB-loads,dTLB-load-misses,dTLB-stores,dTLB-store-misses,iTLB-loads,iTLB-load-misses ./$1

echo -e "${red}------------ hardware events - branch prediction${nc}" 
perf stat -B -r $2 -e branch-loads,branch-load-misses ./$1

exit 0
