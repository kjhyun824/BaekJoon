/*
 * =====================================================================================
 *
 *       Filename:  breakWall.cpp
 *
 *    Description:  Break wall to find out shortest path form source
 *
 *        Version:  1.0
 *        Created:  04/15/18 00:12:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Junghyun Kim
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
using namespace std;

int R, C, K;

struct mapElem {
  int rN;
  int cN;
  int frN;
  int fcN;
  unsigned int dist;
  bool isWall;
  int restBomb;
  bool operator<(const mapElem& rhs) const {
    return dist < rhs.dist;
  }
};

mapElem mapArr[1000][1000];
priority_queue<mapElem> priQueue;

void checkPath(int fromR, int fromC, int row, int col) {
  if(fromR == mapArr[row][col].frN && fromC == mapArr[row][col].fcN) return;

  if(mapArr[fromR][fromC].dist + 1 < mapArr[row][col].dist) {
    if(mapArr[row][col].isWall && mapArr[fromR][fromC].restBomb > 0) {
      mapArr[row][col].dist = mapArr[fromR][fromC].dist + 1;
      mapArr[row][col].restBomb = mapArr[fromR][fromC].restBomb - 1;
      mapArr[row][col].frN = fromR;
      mapArr[row][col].fcN = fromC;
      priQueue.push(mapArr[row][col]);
    }
    else if(!mapArr[row][col].isWall) {
      mapArr[row][col].dist = mapArr[fromR][fromC].dist + 1;
      mapArr[row][col].restBomb = mapArr[fromR][fromC].restBomb;
      mapArr[row][col].frN = fromR;
      mapArr[row][col].fcN = fromC;
      priQueue.push(mapArr[row][col]);
    }
  }
}

void findPath() {
  mapElem frontElem = priQueue.top();
  priQueue.pop();

  int row = frontElem.rN, col = frontElem.cN;

  if(row + 1 < R) {
    checkPath(row,col,row+1,col);
  }

  if(row - 1 >= 0) {
    checkPath(row,col,row-1,col);
  }

  if(col + 1 < C) {
    checkPath(row,col,row,col+1);
  }

  if(col - 1 >= 0) {
    checkPath(row,col,row,col-1);
  }
}

int main() {
  cin >> R >> C >> K;
  for(int i = 0; i < R; i++) {
    string line;
    cin >> line;
    for(int j = 0; j < C; j++) {
      mapArr[i][j].rN = i;
      mapArr[i][j].cN = j;
      mapArr[i][j].frN = -1;
      mapArr[i][j].fcN = -1;
      mapArr[i][j].dist = ~0;
      mapArr[i][j].restBomb = -1;
      if(line[j] == '0') {
        mapArr[i][j].isWall = false;
      } else {
        mapArr[i][j].isWall = true;
      }
    }
  }

  mapArr[0][0].dist = 1;
  mapArr[0][0].restBomb = K;

  priQueue.push(mapArr[0][0]);

  while(!priQueue.empty())
    findPath();

  if(mapArr[R-1][C-1].dist == ~0) 
    cout << -1 << endl;
  else
    cout << mapArr[R-1][C-1].dist << endl;

  return 0;
}
