#include <iostream>
#include <vector>

using namespace std;
const int n=10000;
struct Node{
    int id;
    int durability;
    int weight;
    Node *parent=NULL;
    vector<int> children;
    public:
    	Node(int i,int d,int w){id=i;durability=d;weight=w;parent=nullptr;}
    	Node(){id:0;durability:0;weight:0;parent:nullptr;}
};
struct Stack {
    Node *array;
    int top;
    int length;
	Stack(int l) {
        array = new Node[l];
        length = l;
        top = 0;
    }
	Node pop() {
        if (top != 0)
            return array[--top];
        else
         {}   //return nullptr;
    }
	bool push(Node node) {
        if (top != length) {
            array[top++] = node;
            return true;
        } else
            return false;
    }
	Node getTopValue() {
        if (top != 0)
            return array[top - 1];
        else
            {}//return null;
    }
	bool isEmpty() {return top == 0 ? true : false;}
};
bool check(Node root, Node nodeArray[], Stack stack, int childrenWeight[], int number) {
    for (int child : root.children)
        if (child <= number)
            stack.push(nodeArray[child]);
    while (!stack.isEmpty()) {
        Node node = stack.getTopValue();
        int nodeId = node.id;
        if (!node.children.empty() && childrenWeight[nodeId] == -1) {
            for (int child : node.children) {
                if (child <= number)
                    stack.push(nodeArray[child]);
                childrenWeight[nodeId] = 0;
            }
        } else if (node.children.empty()) {
            stack.pop();
            if (nodeArray[nodeId].weight > nodeArray[nodeId].durability)
                return false;
            int parentId = nodeArray[nodeId].parent->id;
            if (parentId != -1)
                childrenWeight[parentId] += nodeArray[nodeId].weight;
        } else if (childrenWeight[nodeId] != -1) {
            stack.pop();
            if (nodeArray[nodeId].weight + childrenWeight[nodeId] > nodeArray[nodeId].durability)
                return false;
            int parentId = nodeArray[nodeId].parent->id;
            if (parentId != -1)
                childrenWeight[parentId] += nodeArray[nodeId].weight + childrenWeight[nodeId];
        }
    }
    return true;
}

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
    int childrenw[N];
    int min=0,max=N-1,result=0;
    while(min<=max){
    	int mid=(min+max)/2;
    	for(int i=0;i<N;i++){childrenw[i]=-1;}
    	Stack stack(N);
            if (check(root, nodes, stack, childrenw, mid)) {
                result = mid + 1;
                min = mid + 1;
            } else
                max = mid - 1;
        }
        return result;
}

