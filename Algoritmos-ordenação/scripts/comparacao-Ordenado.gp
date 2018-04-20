set title "Algoritmos Ordenado Comparações " textcolor "red"
set xlabel "Tamanho"
set ylabel "Comparações"

plot 'resultado/desordenado/BubbleSortTrocasComparacao.txt'  using 1:2 with linespoints  title 'Bubble', 'resultado/desordenado/InsertSortTrocasComparacao.txt'  using 1:2 with linespoints  title'Insertion'linecolor 'red', 'resultado/desordenado/MergeSortTrocasComparacao.txt' using 1:2 with linespoints   title 'Merge', 'resultado/desordenado/QuickSortTrocasComparacao.txt' using 1:2 with linespoints   title 'Quick', 'resultado/desordenado/SelectSortTrocasComparacao.txt'using 1:2 with linespoints  ls 2 pt 10 title 'Selection'

set terminal png             #(will produce .png output)
set output "resultado/graficos/comparacao_ordenado.png" #(output to any filename.png you want)
replot
set term x11