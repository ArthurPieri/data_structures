typedef struct linkedList List;

List* createList();
List* insertElement(List* list, int value);
void printList(List* list);
bool isListEmpty(List* list);
List* searchElement(List* list, int value);
List* deleteElement(List* list, int value);
void freeList(List* list);