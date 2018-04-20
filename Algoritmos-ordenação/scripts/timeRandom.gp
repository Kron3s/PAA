set title "Algoritmos Desordenados " textcolor "red"
set xlabel "Tamanho"
set ylabel "Cpu-time"

plot 'resultado/desordenado/BubbleSortTime.dat' with lines title 'Bubble', 'resultado/desordenado/InsertSortTime.txt' with lines title'Insertion'linecolor 'red', 'resultado/desordenado/MergeSortTime.txt' with lines title 'Merge', 'resultado/desordenado/QuickSortTime.txt' with lines title 'Quick', 'resultado/desordenado/SelectSortTime.txt' with lines title 'Select'

set terminal png             #(will produce .png output)
set output "resultado/graficos/tempo_desordenado.png" #(output to any filename.png you want)
 replot
set term x11
