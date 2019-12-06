#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <cfloat>
#include <set>
using namespace std;


#define X_MAX 40
#define Y_MAX 30
#define Z_MAX 10

         int world[1200] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct position {
  int xy;
};

struct Node {

  position pos;
  int parentXY;
  float gCost; //from starting node
  float hCost; //heuristics - to destination
  float fCost; //g+h

};


inline bool operator < (const Node& lhs, const Node& rhs)
{
    if(lhs.fCost == rhs.fCost){
        return lhs.pos.xy < rhs.pos.xy;
    }
    return lhs.fCost < rhs.fCost;
}


bool isValid(int xy) {
  int x = xy % X_MAX;
  int y = xy / X_MAX;
  if (world[xy] == 1) {
    if (x < 0 || y < 0 || x >= X_MAX || y >= Y_MAX) {
      return false;
    }
    return true;
  }
  return false;
}

bool isDestination(int xy, int dest) {
        if (xy==dest) {
            return true;
        }
        return false;
    }

double calculateH(int xy, int dest) {
  int x = xy % X_MAX;
  int y = xy / X_MAX;
  double H = (sqrt((x - dest % X_MAX) * (x - dest % X_MAX) +
    (y - dest / X_MAX) * (y - dest / X_MAX)));
  return H;
}

vector<Node> TracePath(vector<Node> nodes, int dest){

stack<Node> path;
vector<Node> usablePath;

int xy = dest;
while(nodes[xy].parentXY != xy){ //&& nodes[xy].pos!=-1){ ???
    path.push(nodes[xy]);
    int txy = nodes[xy].parentXY;
    xy = txy;
}

path.push(nodes[xy]);//push starting node

while(!path.empty()){   //reverso
    Node top = path.top();
    path.pop();
    usablePath.emplace_back(top);
}

return usablePath;
}

void PrintMap(vector<Node> nodes){

for(int i=0;i<Y_MAX;i++){
    for(int j=0;j<X_MAX;j++){
            if(nodes[j+i*X_MAX].gCost==FLT_MAX){
                cout<<0<<" ";
            }else{
        cout<<nodes[j+i*X_MAX].gCost<<" ";
        }
    }cout<<endl;
}

cout<<endl;
}

void PrintBools(bool closedMap[]){

for(int i=0;i<Y_MAX;i++){
    for(int j=0;j<X_MAX;j++){

        cout<<closedMap[j+i*X_MAX]<<" ";

    }cout<<endl;
}

cout<<endl;
}

vector < Node > Astar(int start, int dest) {

  vector < Node > empty;
  int Mx = X_MAX * Y_MAX;
  if (!isValid(dest)) {
    cout << "Destination is occupied" << endl;
    return empty;
  }

  if (isDestination(start,dest)) {
    cout << "You are the destination" << endl;
    return empty;
  }

  vector < Node > allNodes;
  bool closedList[Mx];

  for (int xy = 0; xy < Mx; xy++) {

    Node t;
    t.pos.xy = xy;
    t.fCost = FLT_MAX;
    t.gCost = FLT_MAX;
    t.hCost = FLT_MAX;
    t.parentXY = -1;

    allNodes.push_back(t);
    closedList[xy]=false;
  }


  allNodes[start].fCost = 0.;
  allNodes[start].gCost = 0.;
  allNodes[start].hCost = 0.;
  allNodes[start].parentXY=start;

    set < Node > openList;  //sorted stack

  openList.emplace(allNodes[start]);    //construct element from arguments in allNodes[start]
  bool destinationReached = false;

  while (!openList.empty() && openList.size()<Mx) {//if not empty and larger than max size

    Node currentNode;

   do{ currentNode = *openList.begin();    //get first sorted element
    openList.erase(openList.begin());
    }while(!isValid(currentNode.pos.xy));    //get first valid element


    closedList[currentNode.pos.xy]=true;


      for (int xt = -1; xt < 2; xt++) {
            for (int yt = -1; yt < 2; yt++) {

                if(abs(xt)==abs(yt))continue;

                double child_g, child_h, child_f;
                int x = currentNode.pos.xy % X_MAX + xt;
                int y = currentNode.pos.xy / X_MAX + yt;

                int child_xy = x + y * X_MAX;

                if(isDestination(child_xy,dest)){   //destination found, construct path

                    allNodes[child_xy].parentXY=currentNode.pos.xy;
                    destinationReached = true;

                    return TracePath(allNodes,dest);
                }
                else if(closedList[child_xy]==false){

                    child_g = currentNode.gCost+1.0;
                    child_h = calculateH(child_xy,dest);
                    child_f = child_g+child_h;

                    if(allNodes[child_xy].fCost==FLT_MAX||allNodes[child_xy].fCost>child_f){    //if cost to node is lower than present update it
                        allNodes[child_xy].gCost = child_g;
                        allNodes[child_xy].hCost = child_h;
                        allNodes[child_xy].fCost = child_f;
                        allNodes[child_xy].parentXY = currentNode.pos.xy;
                        openList.insert(allNodes[child_xy]);

                    }

                }
        }
      }
    }

    if(destinationReached==false){
        cout<<"destination not found"<<endl;
    }

  return empty;
}

int main() {


    pair<int,int> start = {2,2};
    pair<int,int> finish = {39,29};

  /*  cout<<start.first-1<<" "<<(start.second-1)*X_MAX<<endl;
    cout<<(start.second-1)*X_MAX+start.first-1<<endl;
    cout<<endl;

     cout<<finish.first-1<<" "<<(finish.second-1)*X_MAX<<endl;
    cout<<(finish.second-1)*X_MAX+finish.first-1<<endl;
    cout<<endl;
*/

  vector < Node > way = Astar(start.first-1+(start.second-1)*X_MAX, finish.first-1+(finish.second-1)*X_MAX);

    for(Node &n : way){
            world[n.pos.xy] = 8;
       // cout<<n.pos.xy<<endl;
    }
    for(int i=0;i<Y_MAX;i++){
    for(int j=0;j<X_MAX;j++){

        cout<<world[j+i*X_MAX]<<" ";
    }cout<<endl;
    }


  return 0;
}
