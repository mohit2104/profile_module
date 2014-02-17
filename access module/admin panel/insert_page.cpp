# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>

struct node1 {
       char admin_name[100];
       struct node1 *next_admin;
       };
       
        
struct node {
       char file_name[100];
       struct node *same_folder;
       struct node *in_folder;
       struct node1* admin;
       };
       
       
       
       
       
       
struct node * insert(struct node *root,char path[],char current_folder[])
{

     struct node *tmp=root,*temp;
     int i=0,path_end=0,path_length=strlen(path),x;
     char ch,str[100];
if(root==NULL)
{

              temp=(struct node *)malloc(sizeof(struct node));
                                                                      temp->admin=NULL;
                                                                      temp->in_folder=NULL;
                                                                      temp->same_folder=NULL;
                                                                      strcpy(temp->file_name,current_folder);
              return temp;
              }
              
              
   while(path_end==0)
   {
                     x=0;
                     ch=path[i++];
                     while(ch!='/' && ch!='\0')
                     {
                                   str[x++]=ch;
                                   ch=path[i++];
                                   }
                                   str[x]='\0';
                                   if(i>=path_length)
                                   path_end=1;
                          //      printf("%s\n",str);
     while(tmp!=NULL)
     {
                      if(strcmp(tmp->file_name,str)==0)
                      {
                                                     //  flag=1;
                                                     if(path_end==1)
                                                     {
                                                      temp=(struct node *)malloc(sizeof(struct node));
                                                                      temp->admin=NULL;
                                                                      temp->in_folder=NULL;
                                                                      temp->same_folder=NULL;
                                                                      strcpy(temp->file_name,current_folder);
                                                                      if(tmp->in_folder==NULL)
                                                                    {  tmp->in_folder=temp; return root; }
                                                       tmp=tmp->in_folder;
                                                       while(tmp->same_folder!=NULL)
                                                       tmp=tmp->same_folder;
                                                       tmp->same_folder=temp;
                                                       return root;
                                                      }
                                                      tmp=tmp->in_folder;
                                                      break;
                                                       }
                                                       tmp=tmp->same_folder;
                                                       }
                                                      // if(flag==1)
                                                      // continue;
                                                       //else
                                                       //{
                                                         //  printf("NO SUCH PATH FOUND\n");
                                                        //   break;
                                                         //  }
                                                           
                                                           }
                                                           }
                                                           
                      
void display(struct node *root)
{
    struct node1 *admin;
     if(root==NULL)
     return;
     while(root!=NULL)
     {
                      printf("%s ",root->file_name);
                     admin=root->admin;
                     while(admin!=NULL)
                     { printf("%s ",admin->admin_name);admin=admin->next_admin;}
                      printf("\n");
                      display(root->in_folder);
                      root=root->same_folder;
                      }
}


     struct node1 * add_admin_name(struct node1 *tmp,char admin_name[])
     {
          struct node1 * temp=(struct node1 *)malloc(sizeof(struct node)),*star;
          strcpy(temp->admin_name,admin_name);
          temp->next_admin=NULL;
          if(tmp==NULL)
          return temp;
          star=tmp;
          while(star->next_admin!=NULL)
          star=star->next_admin;
          star->next_admin=temp;
          return tmp;
          }
    
     
     
 void add_previleges(struct node *root,char admin_name[],int x)
{

     if(root==NULL)
     return;
     while(root!=NULL)
     {
                      root->admin=add_admin_name(root->admin,admin_name);
                     // printf("adding %s\n",root->file_name);
                      add_previleges(root->in_folder,admin_name,1);
                      if(x!=0)
                      root=root->same_folder;
                      else
                      root=NULL;
                      }
}    
     
     

void check_admin(struct node1* tmp,char admin[])
{
     while(tmp!=NULL)
     {
                     if(strcmp(tmp->admin_name,admin)==0)
                     { printf("you can access the page\n"); return; }
                     tmp=tmp->next_admin;
                     }
                     printf("you are not authorized to access this page. ACCESS DINIED!\n");
                     return;
                     }





void add_admin(struct node *root,char path[],char admin_name[])
{
     int path_end=0,x,i=0,path_length=strlen(path);
     char ch,str[100];
     struct node *tmp=root;
     while(path_end==0)
   {
                     x=0;
                     ch=path[i++];
                     while(ch!='/' && ch!='\0')
                     {
                                   str[x++]=ch;
                                   ch=path[i++];
                                   }
                                   str[x]='\0';
                                   if(i>=path_length)
                                   path_end=1;
                          //      printf("%s\n",str);
     while(tmp!=NULL)
     {
                      if(strcmp(tmp->file_name,str)==0)
                      {
                                                     //  flag=1;
                                                     if(path_end==1)
                                                                        {
                                                                    add_previleges(tmp,admin_name,0);
                                                      return;
                                                      }
                                                      tmp=tmp->in_folder;
                                                      break;
                                                       }
                                                       tmp=tmp->same_folder;
                                                       }
                                                           
                                                           }
                                                           }
           
     
     
     void access_page(struct node *root,char path[],char admin_name[])
{
     int path_end=0,x,i=0,path_length=strlen(path);
     char ch,str[100];
     struct node *tmp=root;
     while(path_end==0)
   {
                     x=0;
                     ch=path[i++];
                     while(ch!='/' && ch!='\0')
                     {
                                   str[x++]=ch;
                                   ch=path[i++];
                                   }
                                   str[x]='\0';
                                   if(i>=path_length)
                                   path_end=1;
                          //      printf("%s\n",str);
     while(tmp!=NULL)
     {
                      if(strcmp(tmp->file_name,str)==0)
                      {
                                                     //  flag=1;
                                                     if(path_end==1)
                                                     {
                                                                    check_admin(tmp->admin,admin_name);
                                                      return;
                                                      }
                                                      tmp=tmp->in_folder;
                                                      break;
                                                       }
                                                       tmp=tmp->same_folder;
                                                       }
                                                           
                                                           }
                                                           }
     
     
int main()
{
    char path[100],admin[100],sas[100],was[100];  int t;
    struct node *root=NULL;
    FILE *page=fopen("page_tree.txt","r");
    FILE *ad=fopen("admin.txt","r");
    while(!feof(page))
    
    {
                     fscanf(page,"%s%s",sas,was);
                   //  printf("%s %s\n",sas,was);
    root=insert(root,sas,was);
}
while(!feof(ad))
{
             fscanf(ad,"%s%s",sas,was);
             add_admin(root,sas,was);
             }
    
    while(1)
    {
            printf("\npress 1 to add admin \t 2 to display\t 3 to access page\n");
            scanf("%d",&t);
                    if(t==2)
                    display(root);
                    else
                    {
                        scanf("%s%s",path,admin);
                    access_page(root,path,admin);
                    }
                    }
    getch();
    return 0;
}

