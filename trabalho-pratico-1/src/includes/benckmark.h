/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lucas Takeshi Moreira Chang
  3889 - Igor de Melo Alves

*/

#ifndef __BENCHMARK_H__
#define __BENCHMARK_H__

#include <time.h>

typedef struct benchmark  Benchmark;

struct benchmark {
 clock_t timeI,timeF;
 double timeT;
 int comparations;
 int memory;
 int compPat;
 int compTST;
};

void benchmarkInit(Benchmark *bench);
void benchmarkInitcompPat(Benchmark *bench);
void benchmarkInitcompTST(Benchmark *bench);

void benchmarkStartTimer(Benchmark *bench);
void benchmarkStopTimer(Benchmark *bench);
void benchmarkSumComparations(Benchmark *bench, int comparations);
void benchmarkSumMemory(Benchmark *bench, int bytes);
void benchmarkSetComparations(Benchmark *bench, int val);
void benchmarkSumComparationsPat(Benchmark *bench, int comparations);
void benchmarkSumComparationsTST(Benchmark *bench, int comparations);

double  benchmarkGetTime(Benchmark bench);
int  benchmarkGetComparations(Benchmark bench);
int  benchmarkGetMemory(Benchmark bench);

#endif
