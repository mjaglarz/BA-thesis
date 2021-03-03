Overview of tools to improve the performance of Python programs
================================
## Abstract:
The main purpose of this bachelor's thesis is to check whether Python - in relation to selected languages - will achieve worse results in performance tests. For this purpose, tests have been written for the algorithms for calculating the nth number of the Fibonacci sequence, quick sort and matrix multiplication, as well as for basic operations, which are representative examples of mechanisms on which more advanced algorithms are based. The thesis consists of the presentation of selected languages, research on the obtained times and an overview with the use of tools for increasing productivity.

## Key words:
Python, benchmark, micro-benchmark, C, Julia, Fibonacci, quick sort, matrix multiplication

---

Przegląd narzędzi do zwiększenia wydajności programów w języku Python
================================
## Streszczenie:
Głównym celem pracy licencjackiej jest sprawdzenie tezy, czy Python – w stosunku do wybranych języków – uzyska gorsze rezultaty w próbach wydajnościowych. W tym celu napisano testy dla algorytmów obliczania n-tej liczby ciągu Fibonacciego, sortowania szybkiego oraz mnożenia macierzy, a także dla podstawowych operacji, będących reprezentatywnymi przykładami mechanizmów, na których bazują bardziej zaawansowane algorytmy. Praca składa się z przedstawiania wybranych języków, badań nad uzyskanymi czasami oraz przeglądu z zastosowaniem narzędzi do zwiększania wydajności.

## Słowa kluczowe:
Python, test wydajnościowy, micro-benchmark, C, Julia, Fibonacci, sortowanie szybkie, mnożenie macierzy

## Opis zawartości pracy:
Praca składa się odpowiednio z katalogów:
* benchmarks
* results
* utils

W pierwszy katalogu, **benchmarks**, znajduje się kod źródłowy testów wydajnościowych dla C, Pythona, Julii oraz implementacji w Pythonie, z zastosowaniem narzędzi do zwiększenia wydajności (katalog **Python++**). W tym katalogu znajdują się kolejne podkatalogi: 
* Caching
* Cython
* Numba
* NumPy
* staticCython

Dla każdego narzędzia, jak i języka stworzono plik _Makefile_, ułatwiający uruchamianie programów.

W katalogu **results** znajdują się wyniki w postaci plików tekstowych dla poszczególnych algorytmów oraz podstawowych operacji.

W ostatnim katalogu, **utils**, znajdują się pomocnicze programy, między innymi do testowania podstawowych operacji (_basic_operations.*_), szukania najlepszych czasów dla danego pliku z wynikami (_find_best_time.py_), uzyskiwania informacji o liczbie wykonywanych operacji dla algorytmów (_benchmark_operations.py_) oraz generowania danych (_data_generator.py_), przechowywanych w podkatalogu **data**.
