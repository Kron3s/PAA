set title "Algoritmos Decrescente Trocas " textcolor "red"
set xlabel "Trocas"
set ylabel "Comparaçoes"

plot 'resultado/decrescente/BubbleSortTrocasComparacao.txt'using 1:3 with linespoints   title 'Bubble', 'resultado/decrescente/InsertSortTrocasComparacao.txt' using 1:3 with linespoints  title'Insertion'linecolor 'red', 'resultado/decrescente/MergeSortTrocasComparacao.txt' using 1:3 with linespoints   title 'Merge', 'resultado/decrescente/QuickSortTrocasComparacao.txt' using 1:3 with linespoints   title 'Quick', 'resultado/decrescente/SelectSortTrocasComparacao.txt'  using 1:3 with linespoints  ls 2 pt 10 title 'Selection'

 set terminal png             #(will produce .png output)
 set output "resultado/graficos/trocas_decrescente.png" #(output to any filename.png you want)
 replot
 set term x11