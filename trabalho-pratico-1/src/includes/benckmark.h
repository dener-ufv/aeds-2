#ifndef __BENCHMARK_H__
#define __BENCHMARK_H__

#include <time.h>

typedef struct benchmark  Benchmark;

struct benchmark {
 clock_t timeI,timeF;
 double timeT;
 int comparations;
 int memory;
};

void benchmarkInit(Benchmark *bench);
void benchmarkDelete(Benchmark *bench);

void benchmarkStartTimer(Benchmark *bench);
void benchmarkStopTimer(Benchmark *bench);
void benchmarkSumComparations(Benchmark *bench, int comparations);
void benchmarkSumMemory(Benchmark *bench, int bytes);

double  benchmarkGetTime(Benchmark bench);
int  benchmarkGetComparations(Benchmark bench);
int  benchmarkGetMemory(Benchmark bench);

#endif
