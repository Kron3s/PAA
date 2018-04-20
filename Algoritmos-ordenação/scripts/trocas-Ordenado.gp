set title "Algoritmos Ordenado Trocas " textcolor "red"
set xlabel "Tamanho"
set ylabel "Trocas"


plot 'resultado/desordenado/BubbleSortTrocasComparacao.txt'  using 1:3 with linespoints  title 'Bubble', 'resultado/desordenado/InsertSortTrocasComparacao.txt'  using 1:3 with linespoints  title'Insertion'linecolor 'red', 'resultado/desordenado/MergeSortTrocasComparacao.txt' using 1:3 with linespoints   title 'Merge', 'resultado/desordenado/QuickSortTrocasComparacao.txt' using 1:3 with linespoints   title 'Quick', 'resultado/desordenado/SelectSortTrocasComparacao.txt'using 1:3 with linespoints ls 2 pt 10 title 'Selection'


set terminal png             #(will produce .png output)
set output "resultado/graficos/trocas_ordenado.png" #(output to any filename.png you want)
replot
set term x11