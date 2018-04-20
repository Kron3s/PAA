set title "Algoritmos Desordenados Comparações " textcolor "red"
set xlabel "Tamanho"
set ylabel "Comparações"

plot 'resultado/desordenado/BubbleSortTrocasComparacao.txt' using 1:2 with linespoints   title 'Bubble', 'resultado/desordenado/InsertSortTrocasComparacao.txt' using 1:2 with linespoints  title 'Insertion' linecolor 'red', 'resultado/desordenado/MergeSortTrocasComparacao.txt' using 1:2  with linespoints  ls 13 pt 13  title 'Merge', 'resultado/desordenado/QuickSortTrocasComparacao.txt'  using 1:2 with linespoints  title 'Quick', 'resultado/desordenado/SelectSortTrocasComparacao.txt' using 1:2 with linespoints  ls 2 pt 10 title 'Selection'

set terminal pngcairo size 720,540  enhanced font 'Verdana,10'      #(will produce .png output)
set output "resultado/graficos/comparacao_desordenado.png" #(output to any filename.png you want)
 replot
set term x11
