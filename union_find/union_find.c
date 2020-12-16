#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SET_SIZE 10

size_t Find(size_t x, size_t (*parent)[2]){
    return parent[x][1];
}

void FindReplace(size_t x, size_t new_par, size_t new_root, size_t (*parent)[2]){
    size_t next;
    size_t prev_root = Find(x, parent);

    while(parent[x][0] != new_par){
	next = parent[x][0];
	parent[x][0] = new_par;
	parent[x][1] = new_root;
	x = next;
    }

    for(size_t i=0; i < SET_SIZE; i++){
	if(Find(i, parent) == prev_root){
	    parent[i][1] = new_root;
	}
    }

    return;
}

void FindCompress(size_t root, size_t (*parent)[2]){
    for(size_t i=0; i < SET_SIZE; i++){
	if(Find(i, parent) == root){
	    FindReplace(i, root, root, parent);
	}
    }

    return;
}

void Union(size_t x, size_t y, size_t (*parent)[2]){
    size_t root = Find(x, parent);
    FindReplace(y, root, root, parent);
    FindCompress(root, parent);

    return;
}

int main(){
    // node: parent|root
    size_t parent[SET_SIZE][2];

    for(size_t i = 0; i < SET_SIZE; i++){
	parent[i][0] = i;
	parent[i][1] = i;
    }

    Union(3, 4, parent);
    Union(7, 6, parent);
    Union(3, 5, parent);
    Union(4, 6, parent);
    Union(1, 3, parent);

    for(size_t i = 0; i < SET_SIZE; i++){
	printf("i: %zu, parent: %zu, root: %zu\n", i, parent[i][0], parent[i][1]);
    }

    return 0;
}
