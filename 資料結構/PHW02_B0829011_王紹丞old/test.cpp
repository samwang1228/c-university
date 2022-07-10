#include <iostream>

#ifndef _Circular_Queue_
#define _Circular_Queue_
#include "PHW02_B0829011.cpp"
#endif

using namespace std;

class ListObject{
    public:
        int node;
        ListObject* NextObject;

        ListObject(){}
        ListObject(int n){
            NextObject = 0;
            node = n;
        }
        void set_edge(int target){
            if(NextObject!=0){
                NextObject -> set_edge(target);
            }else{
                NextObject = new ListObject(target);
            }
        }
};

class UndirectedLinkedList{
    private:
        int node_count;
        ListObject** NodeList;
    public:
        UndirectedLinkedList(){}
        UndirectedLinkedList(int n,int e){
            node_count = n;
            NodeList = new ListObject*[n];
            for(int i=0;i<n;i++){
                NodeList[i] = new ListObject(i);
            }            
        }

        void set_edge(int n1,int n2){
            NodeList[n1]->set_edge(n2);
            NodeList[n2]->set_edge(n1);
        }

        void output(){
            cout << "----------------"<<endl;
            for(int i=0;i<node_count;i++){
                cout << i << " -> ";
                ListObject* Next = NodeList[i];
                while(Next->NextObject!=0){
                    Next = Next->NextObject;
                    cout << Next->node << " ";
                }
                cout << endl;
            }   
            cout << "----------------"<<endl;         
        }

        void dfs_visit(int* node_color, int node){
            cout << node << " ";
            node_color[node] = 1;
            ListObject* Next = NodeList[node];
            while(Next->NextObject!=0){
                Next = Next->NextObject;
                if(node_color[Next->node]==0){
                    dfs_visit(node_color,Next->node);
                }
            }
            node_color[node] = 2;
        }

        void dfs(){
            int* node_color = new int[node_count];
            // 0=white, 1=gray, 2=black
            for(int i=0;i<node_count;i++){
                node_color[i] = 0;
            }
            for(int i=0;i<node_count;i++){
                if(node_color[i] == 0){
                    dfs_visit(node_color,i);
                }        
            }
            cout << endl;
        }

        void bfs(){
           Queue* queue = new Queue(node_count);
            int* node_color = new int[node_count];
            // 0=white, 1=gray, 2=black
            for(int i=0;i<node_count;i++){
                node_color[i] = 0;
            }
            for(int i=0;i<node_count;i++){
                if(node_color[i] == 0){
                    queue->push(i);
                    node_color[i] = 1;
                    while(!(queue->empty())){
                        int node = queue->pop();
                        cout << node << " ";
                        node_color[node] = 2;

                        ListObject* Next = NodeList[node];
                        while(Next->NextObject!=0){
                            Next = Next->NextObject;
                            if(node_color[Next->node]==0){
                                queue->push(Next->node);
                                node_color[Next->node] = 1;
                            }
                        }
                    }
                }        
            }
            cout << endl;
        }
};