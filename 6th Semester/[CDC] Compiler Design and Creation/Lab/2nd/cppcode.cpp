// from Ashish Shrestha

#include<iostream>
#include<string.h>
#include<string>

using namespace std;

char stack[20];
int top = -1;
void push(char x){
    stack[++top] = x;
}
 
char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '.' || x == '*')
        return 1;
}

struct Node{
    int left, right;
    char value;
    bool nullable;
    int firstpos[20], lastpos[20], followpos[20], position; 
};

void calculateNullable(struct Node *node, int expLength){
    for(int i = 0; i < expLength; i++){
        if(node[i].value == '-'){
            node[i].nullable = NULL;
        }
        else if(node[i].value == ' ' || node[i].value == '*'){
            node[i].nullable = true;
            
        } 
        else if(isalpha(node[i].value) && node[i].position == i + 1){
            node[i].nullable = false;
        }
        else if(node[i].value == '+'){
            node[i].nullable = node[node[i].left].nullable || node[node[i].right].nullable;
        }
        else if(node[i].value == '.'){
            node[i].nullable = node[node[i].left].nullable && node[node[i].right].nullable;
        }
        else{
            node[i].nullable = false;
        }
    }
}

void calculatePos(struct Node *node, int expLength){
    for(int i = 0; i < expLength; i++){
        if(isalpha(node[i].value) || node[i].value == '#'){
            int j = 0;
            node[i].firstpos[j]='\0';
            node[i].lastpos[j]='\0';
            node[i].firstpos[j] = node[i].position;
            node[i].lastpos[j] = node[i].position; 
            node[i].firstpos[j+1] = '\0';
            node[i].lastpos[j+1] = '\0';
        }
        else if(node[i].value == '*'){
            int j = 0, k = 0;
            for(j = 0; node[node[i].left].firstpos[j] != '\0'; j++){
                node[i].firstpos[j] = node[node[i].left].firstpos[j];
            }
            node[i].firstpos[j] = '\0';
            for(k = 0; node[node[i].left].lastpos[k] != '\0'; k++){
                node[i].lastpos[k] = node[node[i].left].lastpos[k];
            }
            // node[i].firstpos[j] = '\0';
            node[i].lastpos[k] = '\0';
        }
        else if(node[i].value == '+'){
            int countFirst = 0, countLast = 0;
            for(int j = 0; node[node[i].left].firstpos[j] != '\0'; j++){
                node[i].firstpos[j] = node[node[i].left].firstpos[j];
                countFirst = j;
            }
            for(int j = 0; node[node[i].left].lastpos[j] != '\0'; j++){
                node[i].lastpos[j] = node[node[i].left].lastpos[j];
                countLast = j;
            }
            node[i].firstpos[countFirst+1] = '\0';
            node[i].lastpos[countLast+1] = '\0';
            for(int j = 0; node[node[i].right].firstpos[j] != '\0'; j++){
                for(int k = 0; node[i].firstpos[k]!= '\0'; k++){
                    if(node[i].firstpos[k] == node[node[i].right].firstpos[j]){
                        break;
                    }
                    else{
                        node[i].firstpos[countFirst+1] = node[node[i].right].firstpos[j];
                        countFirst++;
                    }
                }
            }
            for(int j = 0; node[node[i].right].lastpos[j] != '\0'; j++){
                for(int k = 0; node[i].lastpos[k]!= '\0'; k++){
                    if(node[i].lastpos[k] == node[node[i].right].lastpos[j]){
                        break;
                    }
                    else{
                        node[i].lastpos[countLast+1] = node[node[i].right].lastpos[j];
                        countLast++;
                    }
                }
            }
            node[i].firstpos[countFirst+1] = '\0';
            node[i].firstpos[countLast+1] = '\0';
        }
        else if(node[i].value == '.'){
            if(node[node[i].left].nullable){
                int countFirst = 0;
                for(int j = 0; node[node[i].left].firstpos[j] != '\0'; j++){
                    node[i].firstpos[j] = node[node[i].left].firstpos[j];
                    countFirst = j;
                }
                node[i].firstpos[countFirst+1] = '\0';
                for(int j = 0; node[node[i].right].firstpos[j] != '\0'; j++){
                    for(int k = 0; node[i].firstpos[k]!= '\0'; k++){
                        if(node[i].firstpos[k] == node[node[i].right].firstpos[j]){
                            break;
                        }
                        else{
                            node[i].firstpos[countFirst+1] = node[node[i].right].firstpos[j];
                            countFirst++;
                        }
                    }
                }
                node[i].firstpos[countFirst] = '\0';
            }
            if(!(node[node[i].left].nullable)){
                int j = 0;
                for(j = 0; node[node[i].left].firstpos[j] != '\0'; j++){
                    node[i].firstpos[j] = node[node[i].left].firstpos[j];
                }
                node[i].firstpos[j] = '\0';
            }
            if(node[node[i].right].nullable){
                int countLast = 0;
                for(int j = 0; node[node[i].left].lastpos[j] != '\0'; j++){
                    node[i].lastpos[j] = node[node[i].left].lastpos[j];
                    countLast = j;
                }
                node[i].lastpos[countLast+1] = '\0';
                for(int j = 0; node[node[i].right].lastpos[j] != '\0'; j++){
                    for(int k = 0; node[i].lastpos[k]!= '\0'; k++){
                        if(node[i].lastpos[k] == node[node[i].right].lastpos[j]){
                            break;
                        }
                        else{
                            node[i].lastpos[countLast+1] = node[node[i].right].lastpos[j];
                            countLast++;
                        }
                    }
                }
                node[i].firstpos[countLast] = '\0';
            }
            if(!(node[node[i].right].nullable)){
                int k = 0;
                for(k = 0; node[node[i].right].lastpos[k] != '\0'; k++){
                    node[i].lastpos[k] = node[node[i].right].lastpos[k];
                }
                node[i].lastpos[k] = '\0';
            }
        }
        else{
            node[i].firstpos[0] = '\0';
            node[i].lastpos[0] = '\0';
        }
    }
}


void calculateFollow(struct Node *node, int expLength){
    for(int i = 0; i < expLength; i++){
        if(node[i].value == '*'){
            for(int j = 0; node[i].lastpos[j] != '\0'; j++){
                for(int  k = 0; k < expLength; k++){
                    if(node[k].position > 0){
                        if(node[k].position == node[i].lastpos[j]){
                            for(int l = 0; node[i].firstpos[l] != '\0'; l++){
                                node[k].followpos[l] = node[i].firstpos[l];
                                node[k].followpos[l+1] = '\0';
                            }
                        }
                    }
                }
            }
        }
        else if(node[i].value == '.'){
            int count = 0;
            for(int j = 0; node[node[i].left].lastpos[j] != '\0'; j++){
                for(int  k = 0; k < expLength; k++){
                    if(node[k].position > 0){
                        if(node[k].position == node[node[i].left].lastpos[j]){
                            for(int l = 0; node[node[i].right].firstpos[l-count] != '\0'; l++){
                                while(node[k].followpos[l] != '\0'){
                                    count++;
                                    l++;
                                }
                                node[k].followpos[l] = node[node[i].right].firstpos[l-count];
                                node[k].followpos[l+1] = '\0';
                            }
                            count = 0;
                        }
                    }
                }
            }
        }
    }
}


string topostfix(char* e){
    char x;
    // char tempArray[100];
    string postfix= "";
    while(*e != '\0')
    {
        if(isalnum(*e) || *e == '#' || *e == '-')
            postfix += *e;
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '('){
                postfix += x;
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(*e)){
                postfix += pop();
            }
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        postfix += pop();
    }


    return postfix;
}

string separate(string exp){
    int i,j=0;
    char temp[100];
    string tempStr;
    for(i=0; i < 10; i++){
        if(i==0){
            temp[j]=exp[i];
            j++;
        }
        else if(exp[i]== '*'){
            temp[j] = exp[i];
            temp[j+1] = '-';
            j+=2;
        }
        else if((isalpha(exp[i]) && isalpha(exp[i-1])) || (isalpha(exp[i]) && exp[i-1]=='*') || (exp[i]=='#' && (isalpha(exp[i-1]) || exp[i-1]=='*'))){
            temp[j]='.';
            temp[j+1]=exp[i];
            j+=2;
        }
        else{
            temp[j]=exp[i];
            j++;
        }
    }
    tempStr = temp;
    return tempStr;
}

int main(){  
    char exp[100];
    string postfix;
    int pos[20] ,i=0, j=1; 
    cout<<"Enter the expresssion:";
    cin>>exp;
    strcat(exp,"#");
    postfix = exp;
    postfix = separate(postfix);
    for(int i=0; i< postfix.length();i++){
        exp[i]= postfix[i];
    }
    postfix = topostfix(exp);
    for(int i=0; i<postfix.length(); i++){
        if(isalpha(postfix[i]) || postfix[i] == '#'){
            pos[i] = j;
            j++;
        }
        else
            pos[i] = 0;
    }
    cout<<endl;
    struct Node arrNode[postfix.length()];
    for(int i=0; i<postfix.length(); i++){
        arrNode[i].value = postfix[i];
        arrNode[i].position = pos[i];
    }
    for(int i = 0; i < postfix.length(); i++){
        if(arrNode[i].value == '*' || arrNode[i].value == '.' || arrNode[i].value == '+'){
            arrNode[i].left = i-2;
            arrNode[i].right = i-1;
        }
        else{
            arrNode[i].left = 0;
            arrNode[i].right = 0;    
        }
    }
    calculateNullable(arrNode, postfix.length());
    calculatePos(arrNode, postfix.length());
    for(int i = 0; i < postfix.length(); i++){
        arrNode[i].followpos[0] = '\0';
    }
    calculateFollow(arrNode, postfix.length());
    cout<<"node\tposition\tnullable\tfirstpos\tlastpos\t\tfollowpos\n";
    for(int i = 0; i < postfix.length(); i++){
        if(arrNode[i].value == '-'){
            continue;
        }
        cout<<arrNode[i].value<<"\t"<<arrNode[i].position<<"\t";
        if(arrNode[i].nullable){
            cout<<"\ttrue";
        }
        else{
            cout<<"\tfalse";
        }
        cout<<"\t\t";
        for(int j = 0; arrNode[i].firstpos[j] != '\0'; j++)
            cout<<arrNode[i].firstpos[j]<<",";
        cout<<"\t\t";
        for(int j = 0; arrNode[i].lastpos[j] != '\0'; j++)
            cout<<arrNode[i].lastpos[j]<<",";
        cout<<"\t\t";
        for(int j = 0; arrNode[i].followpos[j] != '\0'; j++)
            cout<<arrNode[i].followpos[j]<<",";    
        cout<<endl;
    }
}  