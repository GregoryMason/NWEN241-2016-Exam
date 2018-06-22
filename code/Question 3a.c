#include <stdio.h>
#include <stdlib.h>

#define node_size sizeof(charNode)
typedef struct charNode charNode;
typedef charNode *ptr_charNode;

struct charNode {
	char data;
	ptr_charNode next;
};

ptr_charNode charList(char *str) {
	if (str[0] == '\0') return NULL;

	ptr_charNode head = malloc(node_size);

	ptr_charNode tail = head;
	tail->data = str[0];

	int i = 1;
	while (str[i] != '\0') {
		tail->next = malloc(node_size);
		tail = tail->next;
		tail->data = str[i];
		i++;
	}
	tail->next = NULL;

	return head;
}


//Add main function to run and check the code
int main(void) {
	ptr_charNode a = charList("Edit this string to print something else!");

	if (a == NULL) return 0;
	
	while(a->next) {
		printf("%c", a->data);
		a = a->next;
	}
	printf("%c\n", a->data);
	return 0;
}