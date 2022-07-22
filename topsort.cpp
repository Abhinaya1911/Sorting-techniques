#include <iostream>
using namespace std;
struct snode{
	string vname;
	snode *link;
};
class SLL{
	snode *first;
  public:
	SLL():first(NULL){
	}
	void insert_at_beg(string s){
		snode *t = new snode();
		t->vname = s;
		t->link = first;
		first = t;
	}
	
	void display(){
		snode *temp = first;
		while (temp != NULL){
			cout << temp->vname<< ", ";
		    temp = temp->link;
		}
		cout << endl;
	}
};
struct adjnode{
	int v_idx;
	adjnode *link;
};
struct vertex{
	string vname;
	char color;
	int s;
	int f;
	int p;
	adjnode *adjver;
};
class DAG{
	vertex v[20];
	int n;
	int count;
	SLL toporder;
	public:
		void createGraph(){
			int m;
			cout << "Enter the number of vertices: ";
			cin >> n;
			for (int i=0; i<n; i++){
				cout << "Enter the name of the vertex: ";
				cin >> v[i].vname;
				cout << "Enter number of adjacent vertices for " << v[i].vname<<": ";
				cin >> m;
				v[i].adjver = NULL;
				for (int j=0; j<m; j++){
					adjnode *nn = new adjnode();
					cout << "Enter index of adjacent vertex: ";
					cin >> nn->v_idx;
					nn->link = v[i].adjver;
					v[i].adjver = nn;
				}
			}
		}
		void topsort(){
			DFS();
			toporder.display();
		}
		void DFS(){
			count = 0;
			for (int i=0; i<n; i++){
				v[i].color = 'W';
				v[i].p = -1;
			}
			for (int i=0; i<n; i++)
			   if (v[i].color == 'W')
			       DFS_Visit(i);
		}
		void DFS_Visit(int u){
			v[u].s = ++count;
			v[u].color = 'G';
			adjnode *t = v[u].adjver;
			while (t != NULL){
				if (v[t->v_idx].color == 'W'){
					v[t->v_idx].p = u;
					DFS_Visit(t->v_idx);
				}
				t = t->link;
			}
			v[u].f = ++count;
			v[u].color = 'B';
			toporder.insert_at_beg(v[u].vname);
		}
};
int main(){
	DAG g;
	g.createGraph();
	g.topsort();
	return 0;
}
