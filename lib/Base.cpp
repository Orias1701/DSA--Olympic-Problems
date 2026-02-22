#include <stdio.h>
#include <stdlib.h>
typedef int item;

typedef struct Node {
    item data;
    Node *next;
} Node;

typedef Node* Position;
typedef Node* List;

void Makenull(List &l) {
    l = NULL;
}

bool Empty(List l) {
    return (l == NULL);
}

Position First(List l) {
    return l;
}

Position End(List l) {
    return NULL;
}

Position Pos(int x, List l) {
    if (l == NULL || x < 0) return NULL;
    Position q = First(l);
    int i = 0;
    while (i < x) {
        if (q == NULL || q->next == NULL) return NULL;
        q = q->next;
        i++;
    }
    return q;
}

Position Next(Position p) {
    return (p != NULL) ? p->next : NULL;
}

Position Previous(Position p, List l) {
    if (l == NULL || p == NULL || p == l) return NULL;
    Position q = l;
    while (q->next != NULL) {
        if (q->next == p) return q;
        q = q->next;
    }
    return NULL;
}

Position Locate(item x, List l) {
    Position p = First(l);
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

int Retrieve(Position p, List l) {
    return (p != NULL) ? p->data : -1;
}

void Insert(item x, Position p, List &l) {
    if (Empty(l)) {
        l = (Node*)malloc(sizeof(Node));
        l->data = x;
        l->next = NULL;
    } else if (p == NULL) {
        Position q = l;
        while (q->next != NULL) q = q->next;
        q->next = (Node*)malloc(sizeof(Node));
        q->next->data = x;
        q->next->next = NULL;
    } else {
        Position q = (Node*)malloc(sizeof(Node));
        q->data = p->data;
        p->data = x;
        q->next = p->next;
        p->next = q;
    }
}

void Delete(Position p, List &l) {
    if (p != NULL && p->next != NULL) {
        Position q = p->next;
        p->data = q->data;
        p->next = q->next;
        free(q);
    }
}

void Printlist(List l) {
    while (l != NULL) {
        printf("%4d", l->data);
        l = l->next;
    }
    printf("\n");
}

int main() {
    List l;
    Makenull(l);
    Insert(0, End(l), l);
    Insert(1, End(l), l);
    Insert(5, End(l), l);
    Insert(2, End(l), l);
    Insert(3, End(l), l);
    Insert(4, End(l), l);
    Insert(5, End(l), l);
    Printlist(l);
    printf("\n");
    Delete(Locate(5, l), l);
    Printlist(l);
    printf("%4d", Retrieve(Pos(2, l), l));  
    Position next = Next(Pos(5, l));
    if (next != NULL) {
        printf("%4d", next->data);
    }
    Position prev = Previous(Pos(2, l), l);
    if (prev != NULL) {
        printf("%4d", prev->data);
    }
    return 0;
}
