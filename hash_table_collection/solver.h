struct dataitem;

struct dataitem** make_table();
void insert_to_table(int key, int value, struct dataitem** table);
void free_table(struct dataitem** table);
int* get_from_table(int key, struct dataitem** table);
