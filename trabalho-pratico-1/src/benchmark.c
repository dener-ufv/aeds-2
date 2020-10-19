  #include "includes/benckmark.h"

   struct benchmark {
    clock_t timeI,timeF;
    double timeT;
    int comparations;
    int memory;
  };

  void benchmarkInit(Benchmark *bench) {
    bench->timeI=0;
    bench->timeF=0;
    bench->timeT=0;
    bench->comparations=0;
    bench->memory=0;
  }

  void benchmarkDelete(Benchmark *bench) {
      // to be implemented
  }

  void benchmarkStartTimer(Benchmark *bench) {
      bench->timeI = clock();
  }

  void benchmarkStopTimer(Benchmark *bench) {
      bench->timeF = clock();
      bench->timeT = ((double) ((bench->timeF) - (bench->timeI))) / CLOCKS_PER_SEC ;
  }

  void benchmarkSumComparations(Benchmark *bench, int comparations) {
    bench->comparations+=comparations;
  }

  void benchmarkSumMemory(Benchmark *bench, int bytes) {
      bench->memory += bytes;
  }

  double  benchmarkGetTime(Benchmark bench) {
      return bench.timeT;
  }

  int  benchmarkGetComparations(Benchmark bench) {
      return bench.comparations;
  }

  int  benchmarkGetMemory(Benchmark bench) {
    return bench.memory;
  }
