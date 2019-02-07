#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<stdint.h>
#include<math.h>
#include<string.h>

//a stack implementation using linked lists

// linked list
struct Node {

int data;
struct Node* next;

};

// stack implementation

// first stack
int top1 = -1;
struct Node* head1;
// second stack
int top2 = -1;
struct Node* head2;

int Top1(){ // it returns the last element in the linked lists === tail

int position = 0;
struct Node* temp;
temp = head1;


while((temp->next != NULL) && position < top1) {
position++;
temp = temp->next;
}

return temp->data;

}

void push1(int data) {

// inserting an element at the back of a linked list

struct Node* temp = head1;
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

new_node->next = NULL;
new_node->data = data;

if(temp != NULL){

while(temp->next != NULL){
temp = temp->next;

}

temp->next = new_node;
top1 = top1 + 1;

}else{

head1 = new_node;
top1 = top1 + 1;

}

return;

}

int isEmpty1(){
if(top1 == -1){
return 1;
}else{
return 0;
}
}

void pop1(){

top1 = top1 - 1;

}

int Top2(){ // it returns the last element in the linked lists === tail

int position = 0;
struct Node* temp;
temp = head2;


while((temp->next != NULL) && position < top2) {
position++;
temp = temp->next;
}

return temp->data;

}

void push2(int data) {

// inserting an element at the back of a linked list

struct Node* temp = head2;
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

new_node->next = NULL;
new_node->data = data;

if(temp != NULL){

while(temp->next != NULL){
temp = temp->next;

}

temp->next = new_node;
top2 = top2 + 1;

}else{

head2 = new_node;
top2 = top2 + 1;

}

return;

}

int isEmpty2(){
if(top2 == -1){
return 1;
}else{
return 0;
}
}

void pop2(){

top2 = top2 - 1;

}


int main() {
int x;
int sum = 0;
int count = 0;
int target = 0;
int length;
int data;

// red color
printf("\033[1;31m])");

printf("[+] before we start the game please enter the maximal sum : ");
scanf("%d", &x);

printf("[+] how many elements you want in stack 1 ? : ");
scanf("%d", &length);

printf("\n");

for(int i = 0; i < length; i++){

printf("--> insert a value : ");
scanf("%d", &data);

push1(data);

}

printf("\n");
printf("[+] how many elements you want in stack 2 ? : ");
scanf("%d", &length);

printf("\n");

for(int i = 0; i < length; i++){

printf("--> insert a value : ");
scanf("%d", &data);

push2(data);

}

while(sum < x){

sum = sum + Top1();
target = Top1();
pop1();
count = count + 1;
}

sum = sum - target;
count = count - 1;
target = 0;

while(sum < x){

sum = sum + Top2();
target = Top2();
pop2();
count = count + 1;
}

count = count - 1;

printf("\n");
printf("[*] hey there, the maximum number of elements removable from both stacks is %d \n", count); 

}
