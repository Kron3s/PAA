set title "Algoritmos Ordenado " textcolor "red"
set xlabel "Tamanho"
set ylabel "Cpu-time"

plot 'resultado/ordenado/BubbleSortTime.dat' with lines title 'Bubble', 'resultado/ordenado/InsertSortTime.txt' with lines title'Insertion'linecolor 'red', 'resultado/ordenado/MergeSortTime.txt' with lines title 'Merge', 'resultado/ordenado/QuickSortTime.txt' with lines title 'Quick', 'resultado/ordenado/SelectSortTime.txt' with lines title 'Select'

set terminal pngcairo size 720,540  enhanced font 'Verdana,10'      #(will produce .png output)
set output "resultado/graficos/tempo_ordenado.png" #(output to any filename.png you want)
 replot
set term x11

