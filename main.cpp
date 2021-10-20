#include <iostream>
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<ctime>
#include "sdk.h"
#define MAX 9
using namespace std;
int main()
{
    sdk sudoku;
    sudoku.commencer_jouer();
    sudoku.jouer_maintenant();
    return 0;
}
