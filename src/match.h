#ifndef MATCH_H
#define MATCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "read.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Match{
public:
    Match(Read* r, int pos, int distance, bool reversed = false);
    ~Match();
    void print(int leftlen, int centerlen, int rightlen);
    void printHtmlTD(ofstream& file, int leftlen, int centerlen, int rightlen);
    void printReadsToFile(ofstream& file);
    void setReversed(bool flag);
    void addOriginalRead(Read* r);
    void addOriginalPair(ReadPair* pair);

    inline bool operator <(const Match& other) const 
    {
        return mPos < other.mPos;
    }
    inline bool operator >(const Match& other) const
    {
        return mPos > other.mPos;
    }
    inline static bool less(const Match* m1, const Match* m2)
    {
        return *m1 < *m2;
    }
    inline static bool greater(const Match* m1, const Match* m2)
    {
        return *m1 > *m2;
    }

private:
    Read* mRead;
    vector<Read*> mOriginalReads;
    int mDistance;
    bool mReversed;
    // the start position of the mutation's center
    int mPos;
};


#endif