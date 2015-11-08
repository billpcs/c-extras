#define TYPE_ int
typedef struct listcreator NODE;
int new_list(NODE **Head);
int del_list(NODE **Head);
int fill_list(int len, TYPE_ value, NODE **Head);
int append_list(TYPE_ elem, NODE **Head);
int set_list(TYPE_ arr[], NODE **Head);
int insert_list(TYPE_ elem, int index, NODE **Head);
int length_list(NODE **Head);
double sum_list(NODE **Head);
int getitem_list(int index, NODE **Head);
int pop_list(NODE **Head);
int count_list(TYPE_ key, NODE **Head);
int removeitem_list(TYPE_ key, NODE **Head);
int index_list(TYPE_ key, NODE **Head);
void reverse_list(NODE **Head);
void print_list(NODE **Start);
