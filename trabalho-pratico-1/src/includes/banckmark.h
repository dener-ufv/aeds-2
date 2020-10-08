#ifndef __BANCHMARK_H__
#define __BANCHMARK_H__

typedef struct banchmark * Banchmark;

void banchmarkInit(Banchmark *banch);
void banchmarkDelete(Banchmark *banch);

void banchmarkStartTimer(Banchmark *banch);
void banchmarkStopTimer(Banchmark *banch);
void banchmarkSetComparations(Banchmark *banch, int comparations);
void banchmarkSumMemory(Banchmark *banch, int bytes);

int  banchmarkGetTime(Banchmark banch);
int  banchmarkGetComparations(Banchmark bench);
int  banchmarkGetMemory(Banchmark bench);

#endif
