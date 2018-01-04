#include<stdio.h>
#include<stdlib.h>
#include<string.h>


  struct node{
   char name[100];
    int num;
    int year;
   struct node* next;
  };

    FILE *f;

void sorter(struct node* start, int size);

void sorter(struct node* start, int size){ 
   if (size==0){
    return;
  }

   if (size==1){
     printf("%s %d\n", start->name, start->num);
     return;
   }

  struct node *p;
  struct node *q;
  
  p=start;
  q=start->next;
  int tempyear;
  int tempnum;
  char tempname[100];

  for (int i=size; i>1; i--){
    for (int j=i; j>1; j--){
      if (p->year>q->year){
	tempyear=p->year;
	strcpy(tempname, p->name);
	tempnum=p->num;
	
	p->year=q->year;
       	strcpy(p->name, q->name);
	p->num=q->num;
	
	q->year = tempyear;
	strcpy(q->name, tempname);
	q->num = tempnum;
	
      }else if (p->year==q->year){
	if (strcmp(p->name, q->name)>0){
	tempyear=p->year;
	strcpy(tempname, p->name);
	tempnum=p->num;
	
	p->year=q->year;
       	strcpy(p->name, q->name);
	p->num=q->num;
	
	q->year = tempyear;
	strcpy(q->name, tempname);
	q->num = tempnum;
	}
      }
      p=p->next;
      q=q->next;
    }
    p=start;
    q=start->next;
  }
  
  p=start;
  
  while (p!=NULL){
     printf("%s %d\n",p->name, p->num);
     p=p->next;
  }
}


int main(int argc, char *argv[]){
  int size = 0;
  struct node *head, *ptr;
  head=(struct node*)malloc(sizeof(struct node));
  ptr=head;
  ptr->next=NULL;
  char line[100];
  char done[]="DONE\n";
  char* filename=argv[argc-1];

  f=fopen(filename, "rt");
  fgets(line, 100, f);

   while (strcmp(line, done)!=0){ 
    sscanf(line, "%s\n", ptr->name);
    fgets(line, 100, f);
    sscanf(line, "%d\n", &ptr->num);

    fgets(line, 100, f);
    sscanf(line, "%d\n", &ptr->year);
    
    size++;
    fgets(line, 100, f);
    

    if (strcmp(line,done)==0){
      ptr->next=NULL;
      break;
    }

    ptr->next=(struct node*)malloc(sizeof(struct node));
    ptr=ptr->next;
   

  }
   
  fclose(f);

  sorter(head, size);

  struct node *next_ptr;
  
  ptr=head;
   while (ptr!=NULL){
     next_ptr=ptr->next;
     free(ptr);
     ptr=next_ptr;
   } 
}

