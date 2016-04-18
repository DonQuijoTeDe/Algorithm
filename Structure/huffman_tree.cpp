#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int size = 6;
string encryption[size];

//the structure of each node
struct Node{
    Node* left;
    Node* right;
    int data;
    char letter;
};
// if a->data < b->data return true
//otherwise return false
bool compare (Node* a,Node* b){
    return a->data < b->data;
}
//the encryption of the huffman tree
void traversal (Node* root,string temp){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        encryption[(root->letter)-'A'] = temp;
    }
    traversal(root->left,temp+'0');
    traversal(root->right,temp+'1');
}

main(){
    //declare the input letter and initialize its frequency
    char input[] = {'A','B','C','D','E','F'};
    int frequency = 0;
    vector<Node*> forest;
    for(int i=0;i<size;i++){
        cout << input[i] << ": ";
        cin >> frequency;
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = frequency;
        temp->letter = input[i];
        temp->left = NULL;
        temp->right = NULL;
        forest.push_back(temp);
    }
    //complete the huffman tree
    for(int i=0;i<size-1;i++){
        sort(forest.begin(),forest.end(),compare); //do the sort if the compare function return false
        Node* temp = (Node*)malloc(sizeof(Node));
        int key = forest[0]->data + forest[1]->data;
        temp->data = key;
        temp->letter = '\0';
        temp->left = forest[0];
        temp->right = forest[1];
        forest.erase(forest.begin()); //erase the first two object of the vector
        forest.erase(forest.begin());//because we already choose the smallest two object to combination
        forest.push_back(temp);
    }

    traversal(forest[0],"");

    cout << "---------Huffman Code---------\n";
    for(int i=0;i<size;i++){
        cout << input[i] << ": " << encryption[i] << "\n";
    }
    return 0;
}
