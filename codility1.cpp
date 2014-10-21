#include <iostream>
#include <vector>

using namespace std;
const int n=10000;
struct Node{
    int id;
    int dur;
    int weight;
    Node *parent=NULL;
    vector<int> children;
    
    public:
    	Node(int i,int d,int w){
    		id=i;dur=d;weight=w;parent=nullptr;
    	}
    	Node(){
    		id:0;
    		dur:0;
    		weight:0;
    		parent:nullptr;
    	}
};
int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int N=A.size();
    if(N==0) return 0;
    Node nodes[N];
    Node root={-1,0,0};
    int i=0;
    for(i=0;i<N;i++){
        Node node(i,A[i],B[i]);
        if(C[i]==-1){
            node.parent=&root;
        }else{
            node.parent=&nodes[C[i]];
        }
        node.parent->children.push_back(i);
        nodes[i]=node;        
    }
    
    return 0;
}
