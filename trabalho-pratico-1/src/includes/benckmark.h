#ifndef __BENCHMARK_H__
#define __BENCHMARK_H__

typedef struct benchmark * Benchmark;

void benchmarkInit(Benchmark *bench);
void benchmarkDelete(Benchmark *bench);

void benchmarkStartTimer(Benchmark *bench);
void benchmarkStopTimer(Benchmark *bench);
void benchmarkSumComparations(Benchmark *bench, int comparations);
void benchmarkSumMemory(Benchmark *bench, int bytes);

int  benchmarkGetTime(Benchmark bench);
int  benchmarkGetComparations(Benchmark bench);
int  benchmarkGetMemory(Benchmark bench);

#endif
