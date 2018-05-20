Compile:
gcc filter.c Filter

Run:
./Filter filename.csv


Plot:
gnuplot 'filtered.csv' using 0:1 w linespoints

