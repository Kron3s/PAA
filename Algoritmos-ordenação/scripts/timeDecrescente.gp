set title "Algoritmos Decrescente " textcolor "red"
set xlabel "Tamanho"
set ylabel "Cpu-time"

plot 'resultado/decrescente/BubbleSortTime.dat'with lines title 'Bubble', 'resultado/decrescente/InsertSortTime.txt' with lines title'Insertion'linecolor 'red', 'resultado/decrescente/MergeSortTime.txt' with lines title 'Merge', 'resultado/decrescente/QuickSortTime.txt' with lines title 'Quick', 'resultado/decrescente/SelectSortTime.txt' with lines title 'Select'

 set terminal png             #(will produce .png output)
 set output "resultado/graficos/tempo_decrescente.png" #(output to any filename.png you want)
 replot
 set term x11

