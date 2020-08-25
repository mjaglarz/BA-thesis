README.md

# Przegląd narzędzi do zwiększenia wydajności programów w języku Python

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