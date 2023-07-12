#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int Seqdatatype;

typedef struct Seqlist
{
	Seqdatatype* a;
	int size;
	int capacity;
}Seqlist;

void SeqlistInit(Seqlist* pq);
void SeqlistDestory(Seqlist* pq);

void SeqlistPrint(Seqlist* pq);

void SeqlistPushBack(Seqlist* pq, Seqdatatype x);
void SeqlistPopBack(Seqlist* pq);

void SeqlistPushFront(Seqlist* pq, Seqdatatype x);
void SeqlistPopFront(Seqlist* pq);

int SeqlistFind(Seqlist* pq, Seqdatatype x);

void SeqlistInsert(Seqlist* pq, int pos, Seqdatatype x);
void SeqlistErase(Seqlist* pq, int pos);

void SeqlistModify(Seqlist* pq, int pos, Seqdatatype x);