#include <iostream>
#include <vector>

using namespace std;
const int n=10000;
struct Node{
    int id;
    int dur;
    int weight;
    Node *parent;
    vector<int> children=new vector<int>(n);
};
int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int N=A.size();
    if(N==0) return 0;
    Node nodes[]=new Node[N];
    Node root=new Node(-1,0,0);
    int i=0;
    for(i=0;i<N;i++){
        Node node=new Node(i,A[i],B[i]);
        if(C[i]==-1){
            node.parent=root;
        }else{
            node.parent=nodes[C[i]];
        }
        node.parent.children.push_back(i);
        nodes[i]=node;        
    }
}
