char copy(char name);
int getdata(char *user, char *line);
char *strstr(char*, char*);

typedef struct treenode {
  char *name;
  char *password;
  struct treenode *left;
  struct treenode *right;
} node;

node* insert(char *name, char *password, node* pos);
void show(node* position);

void alpha(node* position) {

  if (position != NULL) {
    alpha(position->left);
        if (position->password!=NULL){
            printf(" (%s)\n ", position->name);
        }
    alpha(position->right);
  }
}
