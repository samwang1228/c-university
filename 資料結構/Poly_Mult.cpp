#include <iostream>
#include <cstdlib>
#include <ctime>

# define test 5

using namespace std;

class Node {
		friend class Poly;
		private:
			int coef=0,exp=0 ; 
			Node *next = NULL ;
	}; 

class Poly{
	public:
		Node* get_Head();
		Node* Add(Node* p1,Node* p2);
		void Mult(Node* p1,Node* p2);
		void Cin_data(int x);
		void print();
	private:
		Node *Head;
};


int main(){
	int m,n;
	double start_time,end_time;
	Poly a,b,c;
	cout << "Two polynomiala's terms you want ";
	cin >> m >>n;
	a.Cin_data(m);
	a.print();
	b.Cin_data(n);
	b.print();
	start_time = clock();
	c.Mult(a.get_Head(),b.get_Head());
	end_time = clock();
	cout << "ans is as follow "<<endl;
	c.print();
	cout <<"Total time is "<<(end_time-start_time)/CLOCKS_PER_SEC;
	
} 
Node* Poly::get_Head()
{
	return Head;
}

void Poly::Cin_data(int x)
{
	int p_exp,p_coef,y=x;
	Node *p_node = new Node; 
	Head = p_node;
	
	if(x<test){
		for(int i=0;i<x;i++){
			cout << "input data "<<endl;
			cin >> p_coef >> p_exp;
			p_node -> coef = p_coef;
			p_node -> exp = p_exp;
			p_node -> next = new Node;
			p_node = p_node -> next; 
		}
	}
	else{
		for(int i=0 ; i<x; i++){
			p_node -> coef = rand()%10+1;
			p_node -> exp = y;
			p_node -> next = new Node;
			p_node = p_node -> next;
			y--;
		}
	}
}

void Poly::print()
{	
	cout<< "your Polynomial is : ";
	int count = 0; 
	Node *p_node = new Node;
	p_node = Head;
	while(p_node->next!= NULL){
		if (count!=0){
			cout <<"+"<< p_node->coef <<"x^"<<p_node->exp;
		}
		else{
			cout << p_node->coef <<"x^"<<p_node->exp;
		}
		count++;
		p_node = p_node->next;
	}
	cout << endl;
}

Node* Poly::Add(Node *p1,Node *p2)
{
	Node *ans = new Node, *header,*head;
	//Node *p1_head = p1;
	//Node *p2_head = p2;
	head = ans;
	header = ans; 
    while(p1->next != NULL || p2->next != NULL){
    	/*while(p1_head->next!= NULL){
			cout << p1_head->coef <<" "<<p1_head->exp<<endl;
			p1_head = p1_head->next; 
		}
		while(p2_head->next!= NULL){
			cout << p2_head->coef <<" "<<p2_head->exp<<endl;
			p2_head = p2_head->next; 
		}   */    
		if (p1 -> exp == p2 -> exp ){
            ans->exp = p1->exp;
            ans->coef = p1->coef + p2->coef;
            ans->next = new Node;
            p1=p1 -> next;
            p2=p2 ->next;
        }
        else if (p1 -> exp > p2 -> exp){
            ans -> exp = p1 -> exp;
            ans -> coef = p1 -> coef;
            ans -> next = new Node;
            p1=p1 -> next;
        }
        else if (p1->exp < p2 -> exp){
            ans->exp = p2->exp;
            ans->coef = p2->coef;
            ans->next = new Node;
            p2=p2 -> next;
        }
        ans = ans->next;
    }
    /*while(head->next!= NULL){
			cout << head->coef <<" "<<head->exp<<endl;
			head = head->next; 
		}*/ 
    return header;
}

void Poly::Mult(Node *p1,Node *p2)
{
	//Node* p1_head = p1;
	Node* p2_head = p2;
	Node* mult_ans = new Node;
	Node* add_ans = new Node;
	//Node* add_head = add_ans;
	Node* mult_head = mult_ans,*mult_end;
	while(p1->next != NULL){
		while(p2->next != NULL){
			mult_ans->coef = p1->coef*p2->coef;
            mult_ans->exp = p1->exp + p2->exp;
            p2 = p2->next;
            mult_ans->next = new Node;
           	mult_ans = mult_ans->next;
		}
		mult_end = mult_ans;				// 	嚙踝蕭嚙踝蕭嚙踝蕭嚙誹，嚙磊嚙踝蕭嚙踝蕭嚙踝蕭嚙踝蕭嚙羯嚙踝蕭 
		mult_ans = mult_head;				//  嚙踝蕭嚙糊嚙踝蕭嚙瘦嚙踝蕭嚙編嚙踝蕭嚙稷嚙篁嚙諒前嚙璀嚙踝蕭嚙稼嚙糊 
		add_ans = Add(mult_ans,add_ans);	// 	嚙稷嚙褒加嚙糊嚙踝蕭嚙諛加嚙踝蕭嚙瘦  
		mult_ans = mult_end;				//	嚙磊嚙踝蕭嚙踝蕭嚙糊嚙罷嚙締嚙踝蕭嚙踝蕭m 
		mult_head = mult_end;				//	嚙磊嚙踝蕭嚙踝蕭嚙糊嚙豎要嚙踝蕭嚙諒前嚙踝蕭嚙練 
		p1 = p1->next;						// 郭我我我我ˇ我我我我我我我我我我我我我 我我我我ˇ我我我我我我我我我我我我我
		p2 = p2_head;						// 我我我我ˇ我我我我我我我我我我我我我我我我我ˇ我我我我我我我我我我我我我
	}
	Head = add_ans;
}
