#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include <string>
int rec = 0;
//bool valid = false;
#include <assert.h>

class  stacks{   //class for stacks
	struct node{
		string value;
		node *next;
		int index;
	};

	node *top;
	int size;
public:
	bool valid;
	stacks(){
		top = NULL;
		size = 0;
	}
	void push(string dig, int i){  //pushing the brackets

		node *newnode;

		newnode = new node;
		newnode->value = dig.at(i);  //pushing the particular character from the string
		newnode->next = NULL;
		newnode->index = i;

		if (top == NULL){
			top = newnode;
			size++;   //incrementing the size
		}
		else {


			newnode->next = top;   //if not newnode
			top = newnode;
			size++;


		}
	}



	string pop(){

		if (isempty()){ //checking if stack is empty
			string a = "Stack is empty\n";
			return a;
		}
		else{

			node *del;
			del = top;
			string d = del->value;
			top = top->next;
			size--;


			delete(del);   //deleting the top value
			return d;
		}

	}
	bool isempty(){  //checking if the stack is empty or not
		if (size == 0){
			return true;
		}
		else
			return false;
	}
	string peek(){   //function for the top value 
		if (!isempty()){
			string a = top->value;
			return a;
		}
		else{
			return "The stack is empty\n";
		}
	}
	
	void checkexp(string a){
		valid = true;
		int count = 0;
		int b = a.length();
		cout << endl;
		//cout << b;
		istringstream buf(a);
		//int f1 = 0, f2 = 0, f3 = 0;
		for (string word; buf >> word;){
		
			if (word == a){
				valid = false;
				return;
			}
			string equal = "=";
			if (word == equal){
				count++;
				if (count > 1){
				valid = false;
				return;
				}
			}
		}
			
		for (int i = 0; i < a.length(); ++i)
		{

			if (a.at(i) == '(' || a.at(i) == '[' || a.at(i) == '{'){  //pushing the particular bracket
				//string b = a.at(i);
				push(a, i);
				rec++;
			}
			else if (a.at(i) == ')' || a.at(i) == ']' || a.at(i) == '}'){  //closing bracket check
				if (isempty()){
					valid = false;
				}

				else {
					string I = pop();

					if ((a.at(i) == ')' && I.at(0) == '(') || (a.at(i) == '}' && I.at(0) == '{') || (a.at(i) == ']' && I.at(0) == '['))  //if it is same as open bracket
					{
						rec--;

					}
					else if (I.at(0) == '(' && (a.at(i) == '}' || a.at(i) == ']'))// && I.at(0) == '{') || (a.at(i) == ']' && I.at(0) == '[')) //if mismatched
					{
						cout << "Missmatch for the closing bracket " << a[i] << " at position " << i + 1 << endl;
						valid = false;
					}
					else if (I.at(0) == '{' && (a.at(i) == ')' || a.at(i) == ']'))// && I.at(0) == '{') || (a.at(i) == ']' && I.at(0) == '[')) //if mismatched
					{
						cout << "Missmatch for the closing bracket " << a[i] << " at position " << i + 1 << endl;
						valid = false;
					}
					else if (I.at(0) == '[' && (a.at(i) == '}' || a.at(i) == ')'))// && I.at(0) == '{') || (a.at(i) == ']' && I.at(0) == '['))  //if mismatched
					{
						cout << "Missmatch for the closing bracket " << a[i] << " at position " << i + 1 << endl;
						valid = false;
					}

					//valid = false;
				}// end of else
			}



		}

	}



	~stacks(){  //destructor
		node  *newnode = top;
		node *nextNode;
		if (!isempty()){
			while (newnode = NULL)
			{
				nextNode = newnode->next;
				delete newnode;
				newnode = nextNode;
			}
		}
	}
	void checkclear(){  //checking for the mismatched of brackets
		while (size != 0){
			node *temp = top;
			cout << "We have following unresolved bracket at" << temp->value << " at position " << (temp->index) + 1 << endl;
			top = top->next;
			delete temp;
			size--;
		}
	}

	void checkvalid(){  //checking the validity of expression

		if (valid == true && isempty() && rec == 0){
			cout << "The expression is valid" << endl;
		}
		else{
			cout << "The expression is not valid" << endl;
		}
	}


	void splitstring(string a, int arr[4]){
		int i = 0;
		istringstream buf(a);
		int f1 = 0, f2 = 0, f3 = 0;
		for (string word; buf >> word;){
			//cout << word << endl;
			if (std::stringstream(word) >> f1)
			{
				std::cout << f1 << std::endl;
				
				arr[i] = f1;
				if (i == 4){
					arr[3] = arr[3] - f1;
				}
				arr[i] = f1;
				i++;
			}

		}
	}

	//source : http://www.cplusplus.com/forum/beginner/81057/

	void calculatecuberoot(int arr[4]){

		double a, b, c, d, value;
		double f, g, h;
		double i, j, k, l, m, n, p, po;
		double r, s, t, u;
		double x1, x2, x2re, x2im, x3re, x3im, x3;

		{

			a = arr[0];
			b = arr[1];
			c = arr[2];
			d = arr[3];
			cout << "CUBIC EQUATION : " << a << " x^3 + " << b << " x^2 + " << c << " x + " << d << " = 0" << endl;

			f = ((3 * c / a) - ((b*b) / (a*a))) / 3;
			g = ((2 * (b*b*b) / (a*a*a)) - (9 * b*c / (a*a)) + (27 * d / a)) / 27;
			h = ((g*g) / 4) + ((f*f*f) / 27);

			if (f == 0 && g == 0 && h == 0){     // all roots are real and equal
				x1 = pow((d / a), 0.33333333333333333333333333333333);
				x2 = pow((d / a), 0.33333333333333333333333333333333);
				x3 = pow((d / a), 0.33333333333333333333333333333333);
				cout << "x = " << x1 << endl;
				cout << "x = " << x2 << endl;
				cout << "x = " << x3 << endl;
			}
			else if (h <= 0){         // all 3 roots are real
				i = pow((((g*g) / 4) - h), 0.5);
				j = pow(i, 0.33333333333333333333333333333333);
				k = acos((g / (2 * i))*-1);
				l = j * -1;
				m = cos(k / 3);
				n = sqrt(3) * sin(k / 3);
				p = (b / (3 * a))*-1;
				x1 = (2 * j)*m - (b / (3 * a));
				cout << "x = " << x1 << endl;
				x2 = l * (m + n) + p;
				cout << "x = " << x2 << endl;
				x3 = l * (m - n) + p;
				cout << "x = " << x3 << endl;
			}
			else if (h>0){        // only 1 root is real
				r = ((g / 2)*-1) + pow(h, 0.5);
				s = pow(r, 0.33333333333333333333333333333333);
				t = ((g / 2)*-1) - pow(h, 0.5);
				u = pow((t), 0.33333333333333333333333333333333);
				x1 = (s + u) - (b / (3 * a));
				cout << "x = " << x1 << endl;
				x2re = (((s + u)*-1) / 2) - (b / (3 * a));
				x2im = -(s - u)*pow(3, 0.5) / 2;
				cout << "x = (" << x2re << "," << x2im << ")" << endl;
				x3re = (((s + u)*-1) / 2) - (b / (3 * a));
				x3im = (s - u)*pow(3, 0.5) / 2;
				cout << "x = (" << x3re << "," << x3im << ")" << endl;
			}
		}

	}

	void calculateroot(int arr[4]){
		int check = 0;
		int b = arr[2];
		int a = arr[1];
		int c = arr[3];
		cout << "QUADRATIC EQUATION : " << a<< " x^2 + " << b << " x + " << c << " = 0" << endl;
		int determinant = b*b - 4 * a*c;
		float x1, x2, x3;
		if (determinant > 0){

			x1 = (-b + sqrt(determinant)) / (2 * a);
			x2 = (-b - sqrt(determinant)) / (2 * a);
			cout << "Roots are real and different." << endl;
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
		else if (determinant == 0){
			cout << "Roots are real and same." << endl;
			x1 = (-b + sqrt(determinant)) / (2 * a);
			cout << "x1 = x2 =" << x1 << endl;
		}
		else{
			cout << "Roots are complex and different" << endl;
		}
			
	}

	void sort(string a,int arr[4]){
		int check = 0;
		int i = 0;
		int x1=0,x2=0,x3 = 0,x4=0;
		int f1;
		istringstream buf(a);
		for (string word; buf >> word;){
			if ((word.find("x3") != std::string::npos) || (word.find("X3") != std::string::npos)) {
				if (std::stringstream(word) >> f1)
				{

					arr[0] = f1;
					x1 = 1;
					continue;
				}
				

			}
			else if (x1 == 0){
				arr[0] = 0;
			}
			if ((word.find("x2") != std::string::npos) || (word.find("X2") != std::string::npos)) {
				if (std::stringstream(word) >> f1)
				{

					arr[1] = f1;
				}

				x2 = 1;
				continue;
			}
			else if (x2 == 0){
				arr[1] = 0;
			}
			if ((word.find("x") != std::string::npos) || (word.find("X") != std::string::npos)) {
				if (std::stringstream(word) >> f1)
				{

					arr[2] = f1;
					x3 = 1;
				}

				continue;
			}
			else if (x3==0){
				arr[2] = 0;
			}

			if (bool has_only_digits = (word.find_first_not_of("0123456789") == string::npos)){
				std::stringstream(word) >> f1;
				
				if (check == 1){
					arr[3] = arr[3] - f1;
					continue;
				}
				arr[3] = f1;
				i++;
				x4 = 1;
				continue;
			}
			else if (x4==0){
				arr[3] = 0;
				//x4 = 1;
			}
			string equal = "=";
			if (word == equal){
				check = 1;
			}

		}
	}

	bool isvalid(){
		if (valid == true && isempty() && rec == 0){
			return true;
		}
		else{
			return false;
		}
	}
};

class Test{


	void checkvalid(){
		string c = "(5x2 + 6x + 4 == 32";

		stacks s3;
		s3.checkexp(c);
		assert(false == s3.isvalid());

	}


};
int main(){

	string a;  //creating an object of the class
	//cout << "Enter an expression:" << endl;
	//getline(cin, a);
	a = "3x3 + 5x2 + 6x + 4 = 2";

	stacks s1;
	s1.checkexp(a);


	s1.checkclear();
	s1.checkvalid();
	int arr[4] = { 0, 0, 0 ,0};
	
	s1.sort(a,arr);
	if (s1.isvalid()){
		if (arr[0] != 0){
			s1.calculatecuberoot(arr);
		}
		else{
			s1.calculateroot(arr);
		}
	}
	

	string b;  //creating an object of the class
	//cout << "Enter an expression:" << endl;
	//getline(cin, a);
	b = "5x2 + 6x + 4 = 32";

	stacks s2;
	s2.checkexp(b);


	s2.checkclear();
	s2.checkvalid();
	int arr1[4] = { 0, 0, 0, 0 };

	s2.sort(b, arr1);
	if (s2.isvalid()){
		if (arr1[0] != 0){
			s2.calculatecuberoot(arr1);
		}
		else{
			s2.calculateroot(arr1);
		}
	}

	string c = "(5x2 + 6x + 4 == 32";

	stacks s3;
	s3.checkexp(c);


	s3.checkclear();
	s3.checkvalid();
	int arr2[4] = { 0, 0, 0, 0 };

	s3.sort(c, arr1);
	if (s3.isvalid()){
		if (arr1[0] != 0){
			s3.calculatecuberoot(arr2);
		}
		else{
			s3.calculateroot(arr2);
		}
	}



}
