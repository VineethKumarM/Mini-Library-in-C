#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char name[15];
    int id;
//    int rent;
};
struct member {
    char name[25];
    int age;
    // string email;
//    string school;
};

struct issues {
    char stdn[25]; //student name
    char bk_issued[15];   //book name
//    struct date issued; //date issued on
//    struct date due_on;     //date due on
	int a;
	int b;

};

int main()
{
    FILE *q,*m,*l;
    int i;
    q=fopen("libbooks.txt","a+");
    m=fopen("stu.txt","a+");
    l=fopen("issues.txt","a+");
    fclose(q);
    while(1){
        printf("\n");
        printf("===============================================================\n");
        printf("                       Library Management\n");
        printf("===============================================================\n");
        printf("[1] Press 1 to Add Book\n");
        printf("[2] Press 2 to Take Student Membership\n");
        printf("[3] Press 3 to Return back a Book\n");
        printf("[4] Press 4 to Check Issues\n");
        printf("[5] Press 5 to Display Books\n");
        printf("[6] Press 6 to Display students with membership\n");
        printf("[0] Press 0 to EXIT\n");
        printf("===============================================================\n");
        printf("Please Enter Your Input : ");
        int input,n;
        fflush(stdin);
        scanf("%d",&input);
        system("cls");
    switch(input){
        case 0:
            printf("===============================================================\n");
            printf("  You have successfully exited the Library Management Program\n");
            printf("===============================================================\n");
            return 0;
        case 1:
            printf("===============================================================\n");
            printf("                           Add Book\n");
            printf("===============================================================\n");
            FILE *fp1;
            fp1=fopen("libbooks.txt","a+");
			struct book lib;
            printf("Enter Book Name : ");
//                fflush(stdin);
            scanf("%s",&lib.name);
            printf("\nEnter ID Number : ");
//                fflush(stdin);
			scanf("%d",&lib.id);
			fprintf(fp1,"%s\t%d\n",&lib.name,&lib.id);
            fclose(fp1);
            printf("===============================================================\n");
            printf("                   Added Successfully\n");
            printf("===============================================================\n");
            break;
            
            case 2:
            printf("===============================================================\n");
            printf("                           Take Student Membership\n");
            printf("===============================================================\n");
            FILE *fp2;
            FILE *k2;
            FILE *pf5;
            pf5=fopen("libbooks.txt","r");
            char line5[250];
            char ch5,l5;
            fp2=fopen("stu.txt","a+");
            k2=fopen("issues.txt","a+");
            	struct member stu;
            	struct issues any;
            printf("Enter Name : ");
//                fflush(stdin);
            scanf("%s",&stu.name);
            printf("Enter Mobile Number : ");
            scanf("%d",&stu.age);
            
            printf("A book will be issued to you please select the number from the below list: ");
            printf("===============================================================\n");

            while(1){
            	int a=0;
                ch5=fgetc(pf5);
                
                if(feof(pf5))    break;
                if(ch5=='\t')    printf("\t");
                else if(ch5=='\n' && l5!='\n'){
                    a++;
					printf("\n--------------\n %d",a);
				}   
                else
                    printf("%c",ch5);
                l5=ch5;
            }
            printf("Enter one book you want to borrow: ");
//                char t[15];
            scanf("%s",&any.bk_issued);
            printf("today date: ");
            scanf("%d",&any.a);
            any.b=any.a+15;
            fclose(pf5);
			fprintf(fp2,"%s\t%d\n",&stu.name,&stu.age);
            fprintf(k2,"%s\t%s\t%d\n",&any.stdn,&any.bk_issued,&any.a);
            fclose(fp2);
            fclose(k2);
            
            printf("Please submit the book within 2 weeks");
            printf("===============================================================\n");
            printf("                   Updated Successfully\n");
            printf("===============================================================\n");
            break;
            
    	case 3:
        	printf("===============================================================\n");
			FILE *a1;
        	a1=fopen("issues.txt","r");
			char o[50],o1[100];
			int o2=0;
			printf(" 				 Enter the details: \n");
        	fflush(stdin);
        	gets(o);
        	int o3=strlen(o);
        	printf("--\n");
        	printf(" deatails in our records: \n");
        	while (1) {
        		int j;
        		char m[3]={0};
        		fgets(o1,100,a1);
        		if(feof(a1))	break;
        		if(strncmp(o,o1,o3)==0) {
        			for (i=0,j=0;i<strlen(o1);i++) {
        				if(o1[i]=='\t') {
        					printf("\n");
        					j++;
						}
						else {
							if(j>1){
								m[j-2]=o1[i];
							}
							printf("%c",o1[i]);
						}
					}
					o2++;
				}
			}
			if(o2==0) printf("Incorrect details");
			printf("Enter todays date: ");
			int d;
			scanf("%d",&d);
			int d1=m[0];
			d1+=10*m[1];
			d1+=m[2];
			int x=d-d1;
			int y=100*m[0]+10*m[1]+m[2]+15;
			if(x>15)
				printf("You made late submision, please pay the fine: ");
			else printf("Thanks for submission on time.");
			fclose(a1);
			break; 

            case 5:
                printf("===============================================================\n");
                printf("                         Display Books\n");
                printf("===============================================================\n");
                FILE *pf51;
                pf51=fopen("libbooks.txt","r");
                char line51[250];
                char ch51,l51;
                while(1){
                    ch51=fgetc(pf51);
                    if(feof(pf51))    break;
                    if(ch51=='\t')    printf("\n");
                    else if(ch51=='\n' && l51!='\n')
                        printf("\n===============================================================\n");
                    else
                        printf("%c",ch51);
                    l51=ch51;
                }
                fclose(pf51);
                break;
        
        
		case 6:
            printf("===============================================================\n");
            printf("                         Display students with membership \n");
            printf("===============================================================\n");
            FILE *pf7;
            pf7=fopen("stu.txt","r");
            char ine6[250];
            char ch6,l6;
            while(1){
                ch6=fgetc(pf7);
                if(feof(pf7))    break;
                if(ch6=='\t')    printf("\n");
                else if(ch6=='\n' && l6!='\n')
                    printf("\n===============================================================\n");
                else
                    printf("%c",ch6);
                l6=ch6;
            }
            fclose(pf7);
            break;
				
				
    }
    printf("Press any number to go back : ");
    fflush(stdin);
    scanf("%d",&n);
    system("cls");
    }
}
