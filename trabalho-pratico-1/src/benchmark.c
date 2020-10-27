/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lucas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/

  #include "includes/benckmark.h"


  void benchmarkInit(Benchmark *bench) {
    bench->timeI=0;
    bench->timeF=0;
    bench->timeT=0;
    bench->comparations=0;
    bench->memory=0;
    bench->compPat=0;
    bench->compTST=0;


  }
  void benchmarkInitcompPat(Benchmark *bench){
    bench->compPat=0;
  }
  void benchmarkInitcompTST(Benchmark *bench){
    bench->compTST=0;
  }

  void benchmarkStartTimer(Benchmark *bench) {
      bench->timeI = clock();
  }

  void benchmarkStopTimer(Benchmark *bench) {
      bench->timeF = clock();
      bench->timeT = ((double) ((bench->timeF) - (bench->timeI))) / CLOCKS_PER_SEC ;
  }

  void benchmarkSumComparations(Benchmark *bench, int comparations) {
    bench->comparations += comparations;
  }
  void benchmarkSumComparationsPat(Benchmark *bench, int comparations) {
    bench->compPat += comparations;
  }
  void benchmarkSumComparationsTST(Benchmark *bench, int comparations) {
    bench->compTST += comparations;
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
