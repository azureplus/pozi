#include "../include/dirlist.h"
#include <string.h>
#include <stdlib.h>
//static int size = 0;
void createDirList(struct dir_list_node** head) {
	*head = malloc(sizeof(struct dir_list_node));
}
/************************/
void insertDir(struct dir_list_node* head, const char* filename) {
	if (!head) {
		printf("Linklist be not initialized\n");
		exit(-1);
	}
	struct dir_list_node* p;
	struct dir_list_node* q;
	p = head;
	int index = 0;
	while ((q = p->next) && (index++ < size)) {
		p = p->next;
	}
	struct dir_list_node* n = (struct dir_list_node*) malloc(
			sizeof(struct dir_list_node));
	strcpy(n->value.filename, filename);
	++size;
//printf("create a filename node\n");
	p->next = n;
	n->prev = p;
}
/********************/
void insertNodeDir(struct dir_list_node* head, struct dir_node_value* v) {
	if (!head) {
		printf("Linklist be not initialized\n");
		exit(-1);
	}
	struct dir_list_node* p;
	struct dir_list_node* q;
	p = head;
	while (q = p->next)
		p = p->next;
	struct dir_list_node* n = (struct dir_list_node*) malloc(
			sizeof(struct dir_list_node));
	strcpy(n->value.filename, v->filename);
	p->next = n;
	n->prev = p;
}
/*****************/
void getDirNode(struct dir_list_node* head, unsigned int index,
		struct dir_node_value* v) {
	if (!head) {
		printf("Linklist be not initialized\n");
		exit(-1);
	}
	struct dir_list_node* curr = head->next;
	int i = 0;
	while (curr) {
		if (i++ == index) {
			strcpy(v->filename, curr->value.filename);
			break;
		}
		curr = curr->next;
	}
}
/**********************/
void destroyDirList(struct dir_list_node* head) {
	struct dir_list_node* curr = head;
	int index = 0;
	while (curr && index++ < size) {
		struct dir_list_node* n = curr->next;
		free(curr);
		curr = n;
	}
	printf("destroy the list\n");
}
/************************/
static void travel(struct dir_list_node* head) {
	struct dir_list_node* curr = head->next;
	int index = 0;
	while (curr && index++ < size) {
		printf("key: %s\n", curr->value.filename);
		curr = curr->next;
	}
}
int dirsize() {
	return size;
}
/**

 **/
