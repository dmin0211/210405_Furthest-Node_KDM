#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> edge_array(20005);
int length_node[20005];

void dijkstra(int start){
  length_node[start]=0;
  queue<pair<int,int>> next;
  next.push({0,start});
  while(!next.empty()){
    int current=next.front().second;
    int distance=next.front().first;
    next.pop();
    if(distance>length_node[current]) continue;
    for(int i=0;i<edge_array[current].size();i++){
      int next_node=edge_array[current][i];
      int next_distance=distance+1;
      if(next_distance<length_node[next_node]){
        length_node[next_node]=next_distance;
        next.push({next_distance,next_node});
      }
    }
  }
}

int solution(int n, vector<vector<int>> edge) {
  int answer = 0;
  for (int i = 0; i < edge.size(); ++i) {
    edge_array[edge[i][0]].push_back(edge[i][1]);
    edge_array[edge[i][1]].push_back(edge[i][0]);
  }

  fill(&length_node[0],&length_node[20004]+1,1000001);
  dijkstra(1);
  int max_length=0;
  for(int i=2;i<=20000;i++){
    if(length_node[i]!=1000001){
      max_length=max(max_length,length_node[i]);
    }
  }
  for (int i = 2; i <=20000; ++i) {
    if(length_node[i]==max_length) answer++;
  }
//  cout<<answer<<endl;
  return answer;
}

int main(){
  int n=6;
  vector<vector<int>> test={{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}};
  solution(n,test);
}