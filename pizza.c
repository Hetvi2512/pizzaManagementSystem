#include<stdio.h>
#include<conio.h>
struct pizza{
    int id;
    char name[20];
    int price;
    char size;
}pizza;
void add();
void del();
void show();

void main()
{
    char choice;
    int n,it,i;
    printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_  THE PIZZA CENTER *_*_*_*_*_*_*_*_*_*_*_*_*_*_*");
    printf("\nenter 1 if you are Owner \n enter 2 if you are Customer\n");
    scanf("%c",&choice);
switch (choice)
{
    case '1' :
        printf("welcome Owner");
        printf("\n enter '3' to add pizza \n enter '4' to delete the pizza");
        scanf("%d",&n);
           switch(n)
           {
                case 3:
                printf("\nAdd the pizza:");
                printf("how many items you want to add");
                scanf("%d",&it);
                for(i=0;i<it;i++)
                    add();
                break;
                case 4:
                printf("\n Delete the pizza :");
                show();
                del();
                break;
           }
        break;
    case '2' :
        printf("Welcome User:");
        show();
        break;

}
}
void add()
{
    FILE *fp;
    fp=fopen("pizza.txt","a");
    printf("Enter ID of Pizza :");
    scanf("%d",&pizza.id);
    printf("Enter Name of Pizza :");
    scanf("%s",&pizza.name);
    printf("Enter price of Pizza :");
    scanf("%d",&pizza.price);
    fwrite(&pizza,sizeof(pizza),1,fp);
    fclose(fp);
}
void show()
{
    FILE *fp1;
    fp1=fopen("pizza.txt","r");
    while(fread(&pizza,sizeof(pizza),1,fp1)){
        printf("\n%d",pizza.id);
        printf("\t%s",pizza.name);
        printf("\t%d",pizza.price);
    }
    fclose(fp1);
}
void del()
{
    FILE *fp2 = fopen("pizza.txt","r");
    FILE *ftp ;
    int nm;
    printf("enter id of pizza:");
    scanf("%d",&nm);
    if(check(nm)==0){
        printf("there are no number like you enter:");
    }
    else{
        ftp = fopen("tmp.txt","w");
        while(fread(&pizza,sizeof(pizza),1,fp2)){
            if(pizza.id!=nm)
                fwrite(&pizza,sizeof(pizza),1,ftp);
        }
        fclose(fp2);
        fclose(ftp);
        fp2 = fopen("pizza.txt","w");
        ftp = fopen("tmp.txt","r");
        while(fread(&pizza,sizeof(pizza),1,ftp))
            {
                fwrite(&pizza,sizeof(pizza),1,fp2);
        }
        fclose(fp2);
        fclose(ftp);
    }
}
int check(int nm){
    FILE *fp3 = fopen("pizza.txt","r");
    while(fread(&pizza,sizeof(pizza),1,fp3)){
        if(pizza.id==nm){
            return 1;
        }
    }
    fclose(fp3);
    return 0;
}
