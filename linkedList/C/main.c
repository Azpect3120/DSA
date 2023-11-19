#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int Val;
    struct ListNode *Next;
    struct ListNode *Prev;
};

struct ListNode* CreateNode (int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node != NULL) {
        node->Val = val;
        node->Next = NULL;
        node->Prev = NULL;
    }
    return node;
}

struct ListNode* Append (struct ListNode *root, int val) {
    struct ListNode *curr = root;
    while (curr != NULL && curr->Next != NULL) {
        curr = curr->Next;
    }
    struct ListNode *new = CreateNode(val);
    new->Prev = curr;
    curr->Next = new;
    return root;
}

struct ListNode* AppendArray (struct ListNode *root, int *arr, int size) {
    struct ListNode *curr = root;
    while (curr != NULL && curr->Next != NULL) {
        curr = curr->Next;
    }
    for (int i = 0; i < size; i++) {
        struct ListNode *new = CreateNode(arr[i]);
        new->Prev = curr;
        curr->Next = new;
        curr = curr->Next;
    }
    return root;
}

struct ListNode* Concat (struct ListNode *a, struct ListNode *b) {
    struct ListNode *curr = a;
    while (curr != NULL && curr->Next != NULL) {
        curr = curr->Next;
    }
    b->Prev = curr;
    curr->Next = b;
    return curr;
}

struct ListNode* FindOne (struct ListNode *root, int target) {
    struct ListNode *curr = root;
    while (curr != NULL) {
        if (curr->Val == target) {
            return curr;
        }
        curr = curr->Next;
    }
    return NULL;
}

struct ListNode* RemoveOne (struct ListNode *root, int target) {
    struct ListNode *curr = root;
    if (curr->Val == target) {
        return curr->Next;
    }
    while (curr != NULL) {
        if (curr->Val == target) {
            curr->Prev->Next = curr->Next;
            if (curr->Next != NULL) {
                curr->Next->Prev = curr->Prev;
            }
            return root;
        }
        curr = curr->Next;
    }
    return root;
}

struct ListNode* RemoveAll (struct ListNode *root, int target) {
    struct ListNode *temp = CreateNode(0);
    temp->Next = root;
    struct ListNode *curr = temp;
    while(curr != NULL && curr->Next != NULL) {
        if (curr->Next->Val == target) {
            struct ListNode* nodeToRemove = curr->Next;
            curr->Next = nodeToRemove->Next;

            if (curr->Next != NULL) {
                curr->Next->Prev = curr;
            }

            free(nodeToRemove);
        } else {
            curr = curr->Next;
        }
    }
    root = temp->Next;
    free(temp);
    return root;
}

void Print (struct ListNode *root) {
    if (root == NULL) {
        printf("NULL");
    }
    struct ListNode *curr = root;
    while (curr != NULL) {
        printf("%d", curr->Val);
        if (curr->Next != NULL) {
            printf(" -> ");
        } else {
            printf("\n");
        }
        curr = curr->Next;
    }
}

void PrintReverse (struct ListNode *root) {
    if (root == NULL) {
        printf("NULL");
    }
    struct ListNode *curr = root;
    while (curr != NULL && curr->Next != NULL) {
        curr = curr->Next;
    }
    while (curr != NULL) {
        printf("%d", curr->Val);
        if (curr->Prev != NULL) {
            printf(" -> ");
        } else {
            printf("\n");
        }
        curr = curr->Prev;
    }
}

void PrintNode (struct ListNode *node) {
    if (node != NULL) {
        if (node->Prev != NULL) {
            printf("%d <- ", node->Prev->Val);
        } else {
            printf("NULL <- ");
        }
        printf("(%d)", node->Val);
        if (node->Next != NULL) {
            printf(" -> %d\n", node->Next->Val);
        } else {
            printf("\n");
        }
    } else {
        printf("(NULL)\n");
    }
}

void PrintNodes (struct ListNode *root) {
    if (root == NULL) {
        printf("(NULL)");
    }
    struct ListNode *curr = root;
    while (curr != NULL) {
        if (curr != NULL && curr->Prev != NULL) {
            printf("%d <- ", curr->Prev->Val);
        } else {
            printf("NULL <- ");
        }
        printf("(%d)", curr->Val);
        if (curr->Next != NULL) {
            printf(" -> %d", curr->Next->Val);
        } else {
            printf(" -> NULL");
        }
        printf("\n");
        curr = curr->Next;
    }
}

int main () {
    struct ListNode *root = CreateNode(10);
    Append(root, 12);
    Append(root, 13);
    Append(root, 14);
    Append(root, 16);
    Append(root, 15);
    Append(root, 19);

    int array[] = {8, 10, 14, 12, 18};
    int size = sizeof(array) / sizeof(array[0]);

    AppendArray(root, array, size);

    struct ListNode *a = CreateNode(1);
    Append(a, 2);
    Append(a, 3);
    Append(a, 4);
    Append(a, 5);
    Append(a, 6);

    Concat(root, a);
    Print(root);

    /* root = RemoveOne(root, 10); */
    /* root = RemoveOne(root, 6); */
    root = RemoveAll(root, 6);
    Print(root);
    root = RemoveAll(root, 10);
    Print(root);
    root = RemoveAll(root, 14);
    Print(root);

    return 0;
}
