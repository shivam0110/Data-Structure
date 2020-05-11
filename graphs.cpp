#include<bits/stdc++.h>
using namespace std;

int A[20][20];

// A function to print the incidence matrix.
void incidence_mat(int v , int count,int dir){
	int i, j,x,y;

    //input
    int ed_no = 0;
	for(i = 0; i < count; i++){
            cout<<"Enter edge ";
            cin>>x>>y;
            A[x-1][ed_no] = 1;
            A[y-1][ed_no] = 1;
            ed_no++;
    }


    //display
    for(i = 0; i < count; i++)
		cout<<setw(6)<<"E("<<i+1<<")";
	cout<<endl;
    for(i = 0; i < v; i++) {
        cout<<setw(6)<<"V("<<i+1<<")";
        for(j = 0; j < count; j++) {
            cout << A[i][j] << " ";
        }
      cout << endl;
   }
}

// A function to print the adjacency matrix.
void adjacency_mat(int v , int count,int dir){
	int i, j, x, y;

    if(dir==1){
	    for(i = 0; i < count; i++){
            cout<<"Enter edge ";
            cin>>x>>y;
            A[x-1][y-1]=1;
        }
    }
    if(dir==2){
        for(i = 0; i < count; i++){
            cout<<"Enter edge ";
            cin>>x>>y;
            A[x-1][y-1]=1;
            A[y-1][x-1]=1;
        }
    }
    
    //display
	cout<<"\n\n"<<setw(4)<<"";
	for(i = 0; i < v; i++)
		cout<<setw(3)<<"("<<i+1<<")";
	cout<<"\n\n";
 
 	for(i = 0; i < v; i++)
	{
		cout<<setw(3)<<"("<<i+1<<")";
		for(j = 0; j < v; j++)
		{
			cout<<setw(4)<<A[i][j];
		}
		cout<<"\n\n";
	}
}

void displayAdjList(list<int> adj_list[], int v){
  for(int i = 0; i<v; i++) {
     cout << i << "--->";
     list<int> :: iterator it;
     for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
        cout << *it << " ";
     }
     cout << endl;
   }
}

void add_edge(list<int> adj_list[], int edge, int dir) { 
    int i,x,y;
    if(dir==1){
	    for(i = 0; i < edge; i++){
            cout<<"Enter edge ";
            cin>>x>>y;
            adj_list[x].push_back(y);
        }
    }
    if(dir==2){
        for(i = 0; i < edge; i++){
            cout<<"Enter edge ";
            cin>>x>>y;
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        }
    }
}

void initialize(){
    for(int i = 0;i < 20;++i)
        for(int j = 0;j < 20;++j)          
            A[i][j] = 0;
}

int main(){
    int x, y, vertex, edge, dir,type;
    initialize();       
    

    while(1){
        cout<<"-------------------------------------\n";
        cout<<"1.Directed graph\n2.indirected graph\n3.Exit\nEnter Choice: ";
        cin>>dir;

        if(dir==3)
            exit(0);

        cout<<"\t1.incidence matrix\n\t2.adjacency matrix\n\t3.adjacency list\n\tEnter graph representation: ";
        cin>>type;
        cout<<endl;

        switch(type){
            case 1: cout<<"Enter number of vertices: ";
                    cin>>vertex;
                    cout<<"Enter number of edge: ";
                    cin>>edge;
                    incidence_mat(vertex,edge,dir);
                    break;

            case 2: cout<<"Enter number of vertices: ";
                    cin>>vertex;
                    cout<<"Enter number of edge: ";
                    cin>>edge;
                    adjacency_mat(vertex,edge,dir);
                    break;

            case 3: cout<<"Enter number of vertices: ";
                    cin>>vertex;
                    cout<<"Enter number of edge: ";
                    cin>>edge;
                    list<int> adj_list[vertex];
                    add_edge(adj_list, edge, dir);
                    displayAdjList(adj_list, vertex);
                    break;
        }

        
    }

    return 0;
}