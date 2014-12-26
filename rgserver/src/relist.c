#include "../include/relist.h"
#include <string.h>
#include <stdlib.h>
void createRegistList(struct regist_node** head) {
	*head = malloc(sizeof(struct regist_node));
}
/********************/
void insertRegist(struct regist_node* head, struct meta_msg* v) {
	if (!head) {
		printf("Linklist be not initialized\n");
		exit(-1);
	}
	struct regist_node* p;
	struct regist_node* q;
	p = head;
	while (q = p->next)
		p = p->next;
	struct regist_node* n = (struct regist_node*) malloc(
			sizeof(struct regist_node));
	strcpy(n->value.ipaddr, v->ipaddr);
	n->value.port = v->port;
	n->value.flag = v->flag;
	p->next = n;
	n->prev = p;
}
/*******************
 void getRegistNodeByKey(struct regist_node* head,struct node_value* v){
 if(!head){
 printf("Linklist be not initialized\n");
 exit(-1);
 }
 struct regist_node* curr = head->next;
 while(curr){
 if(!strcmp(curr->value.key,v->key)){
 strcpy(v->value,curr->value.value);
 break;
 }
 curr = curr->next;
 }
 }
 **/
/*****************/
void getRegistNode(struct regist_node* head, unsigned int index,
		struct meta_msg* v) {
	if (!head) {
		printf("Linklist be not initialized\n");
		exit(-1);
	}
	struct regist_node* curr = head->next;
	int i = 0;
	while (curr) {
		if (i++ == index) {
			strcpy(v->ipaddr, curr->value.ipaddr);
			v->port = curr->value.port;
			v->flag = curr->value.flag;
			break;
		}
		curr = curr->next;
	}
}
/**********************/
void destroyRegistList(struct regist_node* head) {
	struct regist_node* curr = head;
	while (curr) {
		struct regist_node* n = curr->next;
		free(curr);
		curr = n;
	}
	printf("destroy the list\n");
}
/************************/
static void travel(struct regist_node* head) {
	struct regist_node* curr = head->next;
	while (curr) {
//printf("key: %s\t%s\n",curr->value.key,curr->value.value);
		curr = curr->next;
	}
}
/**
 int main(int argc,char** argv){
 struct node_value nv[5];
 strcpy(nv[0].key,"ipaddr");
 strcpy(nv[0].value,"127.0.0.1");
 strcpy(nv[1].key,"ipaddr1");
 strcpy(nv[1].value,"127.0.0.2");
 strcpy(nv[2].key,"ipaddr2");
 strcpy(nv[2].value,"127.0.0.3");
 strcpy(nv[3].key,"ipaddr3");
 strcpy(nv[3].value,"127.0.0.4");
 strcpy(nv[4].key,"ipaddr4");
 strcpy(nv[4].value,"127.0.0.5");

 struct regist_node* head;
 createList(&head);
 int i = 0;
 for(;i < 5;i++)
 insert(head,nv[i]);
 //travel(head);
 struct node_value vd;
 strcpy(vd.key,"ipaddr2");
 getNodeByKey(head,&vd);
 printf("value: %s\n",vd.value);
 destroyList(head);
 return 0;
 }
 **/
