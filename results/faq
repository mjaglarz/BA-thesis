# BA-thesis
BA thesis: "Przegląd narzędzi do zwiększenia wydajności programów w języku Python"


## Pytanie 1 ok
Jaka funkcja do mierzenia czasu? Generalnie jest ich sporo w C więc pytanie, którą wybra, aby nikt się nie przyczepił że mogłem lepszą? wybrac?
https://stackoverflow.com/questions/12392278/measure-time-in-linux-time-vs-clock-vs-getrusage-vs-clock-gettime-vs-gettimeof
Początkowo miałem clock:
It depends what you want: \b{time} measures the real time while \b{clock} measures the processing time taken by the current process. If your process sleeps for any appreciable amount of time, or the system is busy with other processes, the two will be very different.
W teście używane jest gettimeofday ale zgodnie z POSIX 2008 jest to już przestarzałe: 
http://man7.org/linux/man-pages/man2/gettimeofday.2.html
Koniec końców wybrałem clock_gettime. -> chociaż też pytanie bo może to byc CLOCK_MONOTONIC jako stały odmierzacz czasu, ale może też by konkretnie dla procesu/wątku 

## Pytanie 2 ok
ternary operator czy zwykły if-else -> ternary operator jest szybszy Ternary Operator is a programming statement. “If-Else” is a programming block. The statement is, of course, faster than Block:
https://www.yawintutor.com/ternary-operator-vs-if-else/

## pytanie3 ok
quicksort - wzięta implementacja z benchmarku dla intów nie double'ów, czy to robi jakąkolwiek różnicę i czy to jest problem, że nie jest to najpopularniejsza implementacja, a dowolna w sumie

## pytanie 4 not ok
wykorzystanie zewnętrznych bilbiotek 
https://github.com/MersenneTwister-Lab/SFMT/blob/master/SFMT.c - to było go generowania liczb losowych
http://octave.org/doxygen/4.0/dd/dd0/randmtzig_8c.html - to nie wiem ale było includowane
https://software.intel.com/en-us/mkl-tutorial-c-multiplying-matrices-using-dgemm - używane do mnożenia macierzy, pobrałem sobie ale czy tego używac???