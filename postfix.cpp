/*
postfix calculator using stack
what we learn here, 
first character is not int to conver it using c - '0'
second when using stack to calculate, remember to create a stack<ints>

*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

int perform(char c, int op1, int op2){
	if(c == '+')
		return op1+op2;
	if(c == '-')
		return op1-op2;
	if(c == '*')
		return op1*op2;
	if(c == '/')	
		return op1/op2;
}

int EvaluatePostfix(char *c, int len){
	stack<int> s;
	int op1, op2, answer, result;
	int temp; //convert char to int

	for(int i =0;i<len;i++){
		if(c[i] != '+' && c[i] != '-' && c[i] != '*' && c[i] != '/'){
			temp = c[i] - '0'; //convert character to int 0-9 range
			if(temp<10)
				s.push(temp);
			else{
				printf("Error, invalid string....\n");	
				return false;
			}		
		}
		else if(c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/'){
			if(s.empty()){
				printf("Error, invalid string....\n");
				return false;
			}
				
			op2 = s.top();
			s.pop();

			//becasue we need two operands and one operator to do so
			if(s.empty()){
				printf("Error, invalid string....\n");
				return false;
			}	
			op1 = s.top();
			s.pop();
			result = perform(c[i], op1, op2);
			s.push(result);
		}
	}
	answer = s.top();
	return answer;
}

int main(){
	char c[50];
	int x;
	printf("Enter a string: ");
	gets(c);

	x = EvaluatePostfix(c, strlen(c));
	printf("The answer is: %d \n", x);

}