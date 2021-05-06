#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

	struct CUSTOMER {
	int  customerNo;
    char name[20];
	char surname[20];
    char customerType[20];
	char birthPlace[20];
	struct ACCOUNT *pac;

   };
   
   	struct ACCOUNT {
		char accountName[20];	
		struct ACNO *pacno;	
	};
	
	
	struct ACNO {
			char accountNo[20];
			double balance;
		}; 
		


void Add_Customer();
void List_Customer();
void Search_Customer();
void Deposite_Money();
void Money_Transfer();
void Withdraw_Money();
void Delete_Account();

int main()

{ 
    printf("\n                                                     BANK MANAGEMENT SYSTEM\n");
	char enterType = 'r';
     
     printf("\n >>Add Customer (1)<< || >>Search Customer (2)<< || >>Deposit Money (3)<<  ||   >>Money Transfer(4)<<  ||  >>Withdraw Money(5)<<  ||  >>Delete Account(6)<<  ||  >>Exit(E)<< \n");
     
     enterType = getche();
     
     while(enterType != 'E' || enterType != 'e') {
          switch(enterType)
          {
                        case '1': {Add_Customer();List_Customer();break;}
                        case '2': {Search_Customer();break;}
                        case '3': {Deposite_Money();List_Customer();break;}
                        case '4': {Money_Transfer();List_Customer();break;}
                        case '5': {Withdraw_Money();List_Customer();break;}
                        case '6': {Delete_Account();List_Customer();break;}
          }
          printf("Do you want to do another action? (Y/N)?\n");
          enterType = getche();
          if(enterType == 'N' || enterType == 'n') {
                    break;
          }
     }



    return  0;

}

    void Add_Customer()
    {
	
		FILE *CustomerDB;
		FILE *CommercialDB;	
		CUSTOMER *pmus;
    	pmus = (CUSTOMER*) malloc(sizeof(CUSTOMER)); 	
    	pmus->pac = (ACCOUNT*) malloc(sizeof(ACCOUNT));
    	pmus->pac->pacno = (ACNO*) malloc(sizeof(ACNO));
		
		srand(time(0));			
		pmus->customerNo=rand();
		
		
		
		printf("---Customer Information ---  \n\n");
		printf("Customer No : %d\n",pmus->customerNo);
		  	   	   	     
	     printf("enter the customer's name  : \n");
	     scanf("%s",pmus->name);
	     printf("enter the customer's surname  : \n");
	     scanf("%s",pmus->surname);
	     printf("enter the customer's type (individual or or commercial)  : (i/c)\n");
	     scanf("%s",pmus->customerType);
	     printf("enter the customer's birthplace  : \n");
	     scanf("%s",pmus->birthPlace);
	     	 
	     	 
	    printf("---Account Information---  \n\n"); 	 
	    
	    printf("enter account name  : \n");
	    scanf("%s",pmus->pac->accountName);

	    
	    printf("enter account no : \n");
	    scanf("%s",pmus->pac->pacno->accountNo);
	    
	    printf("enter balance : \n");
	    scanf("%lf",&pmus->pac->pacno->balance);
	    
	    	     	
	    CustomerDB = fopen("Customer.txt","a");
	    CommercialDB = fopen("Commercial.txt","a");
	    
	    if(strcmp(pmus->customerType,"i")==0 ){
	    	
	    	fprintf(CustomerDB, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
	    	
		}
	 	 else if(strcmp(pmus->customerType,"c")==0 ){
			
			fprintf(CommercialDB, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}
	    
	    
		
	   
	    fclose(CustomerDB);
	     fclose(CommercialDB);
	    
	    printf("---Customer List ---  \n\n");
	    
	    free(pmus);
				   
		}
    
    
void List_Customer()
{
     FILE *CustomerDB;
      FILE *CommercialDB;
     CUSTOMER *pmus;
     pmus = (CUSTOMER*) malloc(sizeof(CUSTOMER));
     pmus->pac = (ACCOUNT*) malloc(sizeof(ACCOUNT));
     pmus->pac->pacno = (ACNO*) malloc(sizeof(ACNO));
     
     CustomerDB = fopen("Customer.txt","r");
     CommercialDB = fopen("Commercial.txt","r");
     printf("individual\n");
     printf("-----no\tN\tS\tCT\tBP\tAN\tAN\tBL\n");
     
    while( fscanf(CustomerDB, "%d %s %s %s %s %s %s %lf \n", &pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,&pmus->pac->pacno->balance) != EOF )
    {
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%lf\n", pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
    }
     printf("commercial\n");
     printf("-----no\tN\tS\tCT\tBP\tAN\tAN\tBL\n");
    
     while( fscanf(CommercialDB, "%d %s %s %s %s %s %s %lf \n", &pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,&pmus->pac->pacno->balance) != EOF )
    {
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%lf\n", pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
    }
        
     
     fclose(CustomerDB);
      fclose(CommercialDB);
     free(pmus);
     
}


void Search_Customer()
{
     FILE *CustomerDB;
     FILE *CommercialDB;
     CUSTOMER *pmus;
     pmus = (CUSTOMER*) malloc(sizeof(CUSTOMER));
     pmus->pac = (ACCOUNT*) malloc(sizeof(ACCOUNT));
     pmus->pac->pacno = (ACNO*) malloc(sizeof(ACNO));
     
     char srcName[20];
     
     CustomerDB = fopen("Customer.txt","r");
     CommercialDB = fopen("Commercial.txt","r");
     
     printf("Enter customer name.\n");
     scanf("%s",srcName);
     
    
      printf("-no\tN\tS\tCT\tBP\tAN\tAN\tBL\n");
      
    while( fscanf(CustomerDB, "%d %s %s %s %s %s %s %lf \n", &pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,&pmus->pac->pacno->balance) != EOF )
    {
    	if(strcmp(pmus->name,srcName)==0){
    		   		
    		 printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%lf\n", pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}
    	
       
    }
    
    while( fscanf(CommercialDB, "%d %s %s %s %s %s %s %lf \n", &pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,&pmus->pac->pacno->balance) != EOF )
    {
    	if(strcmp(pmus->name,srcName)==0){
    		   		
    		 printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%lf\n", pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}
    	
       
    }
        
     
     fclose(CustomerDB);
     fclose(CommercialDB);
     free(pmus);
     
}

    
void Deposite_Money()
{
     FILE *CustomerDB;
     FILE *CustomerDBTEMP;
     CUSTOMER *pmus;
     pmus = (CUSTOMER*) malloc(sizeof(CUSTOMER));
     pmus->pac = (ACCOUNT*) malloc(sizeof(ACCOUNT));
     pmus->pac->pacno = (ACNO*) malloc(sizeof(ACNO));
     
     char srcName[20];
     char accNo[20];
     int balanceG;
     
     CustomerDB = fopen("Customer.txt","r");
     
     
     printf("Enter customer name.\n");
     scanf("%s",srcName);
      printf("Enter account no.\n");
     scanf("%s",accNo);
     printf("How much money do you want to deposit? .\n");
     scanf("%d",&balanceG);
     
     CustomerDBTEMP = fopen("CustomerTEMP.txt","a");
     
    while( fscanf(CustomerDB, "%d %s %s %s %s %s %s %lf \n", &pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,&pmus->pac->pacno->balance) != EOF )
    {
				
    	if(strcmp(pmus->name,srcName)==0 && strcmp(pmus->pac->pacno->accountNo,accNo)==0){
    		
    		 pmus->pac->pacno->balance=pmus->pac->pacno->balance+balanceG;
    		 
    		fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}else{
			fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}
    	
       
    }
        
     
         
     fclose(CustomerDB);
     fclose(CustomerDBTEMP);
     free(pmus);
     
    remove("Customer.txt");
    rename("CustomerTEMP.txt","Customer.txt");
    
    
     
}

void Money_Transfer()
{
   	 
	 FILE *CustomerDB;
	 FILE *CommercialDB;
     FILE *CustomerDBTEMP;
     FILE *CommercialDBTEMP;
     
    
     CUSTOMER *pmus;
     pmus = (CUSTOMER*) malloc(sizeof(CUSTOMER));
     pmus->pac = (ACCOUNT*) malloc(sizeof(ACCOUNT));
     pmus->pac->pacno = (ACNO*) malloc(sizeof(ACNO));
     
     CUSTOMER *pmus1;
     pmus1 = (CUSTOMER*) malloc(sizeof(CUSTOMER));
     pmus1->pac = (ACCOUNT*) malloc(sizeof(ACCOUNT));
     pmus1->pac->pacno = (ACNO*) malloc(sizeof(ACNO));
     
	int cNO;
    double balanceA;
    int cNO2;
     
     CustomerDB = fopen("Customer.txt","r");
    CommercialDB = fopen("Commercial.txt","r");

     printf("Enter the CustomerNo to which the money will be withdrawn .\n");
     scanf("%d",&cNO);
      
     printf("Enter the amount of money to be transferred.\n");
     scanf("%lf",&balanceA);
     
     printf("Enter the number of the customer to whom the money will be deposited .\n");
     scanf("%d",&cNO2);
         
     CustomerDBTEMP = fopen("CustomerTEMP.txt","a");
    CommercialDBTEMP = fopen("CommercialTEMP.txt","a");
     
    while(fscanf(CustomerDB, "%d %s %s %s %s %s %s %lf \n", &pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,&pmus->pac->pacno->balance) != EOF )
    {
    
    	if(pmus->customerNo==cNO){
    		
    		
    		
    		 pmus->pac->pacno->balance=pmus->pac->pacno->balance-(balanceA+(balanceA*2/100));
    		 
    		fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}
    	else if(pmus->customerNo==cNO2){
    		
    		pmus->pac->pacno->balance=pmus->pac->pacno->balance+balanceA;
    		fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}
		else{
			fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}
		
		
		
    	
	}
	
	
	 while(fscanf(CommercialDB, "%d %s %s %s %s %s %s %lf \n", &pmus1->customerNo, pmus1->name, pmus1->surname,pmus1->customerType,pmus1->birthPlace,pmus1->pac->accountName,pmus1->pac->pacno->accountNo,&pmus1->pac->pacno->balance) != EOF )
    {
    
    	if(pmus1->customerNo==cNO){
    		
    		 pmus1->pac->pacno->balance=pmus1->pac->pacno->balance-balanceA;
    		 
    		fprintf(CommercialDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus1->customerNo, pmus1->name, pmus1->surname, pmus1->customerType,pmus1->birthPlace,pmus1->pac->accountName,pmus1->pac->pacno->accountNo,pmus1->pac->pacno->balance);
		}
    	else if(pmus1->customerNo==cNO2){
    		
    			
    		
    		pmus1->pac->pacno->balance=pmus1->pac->pacno->balance+balanceA;
    		fprintf(CommercialDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus1->customerNo, pmus1->name, pmus1->surname, pmus1->customerType,pmus1->birthPlace,pmus1->pac->accountName,pmus1->pac->pacno->accountNo,pmus1->pac->pacno->balance);
		}
		else{
			fprintf(CommercialDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus1->customerNo, pmus1->name, pmus1->surname, pmus1->customerType,pmus1->birthPlace,pmus1->pac->accountName,pmus1->pac->pacno->accountNo,pmus1->pac->pacno->balance);
		}
		
		
		
    	
	}
    	
       
        
     fclose(CustomerDB);
     fclose(CommercialDB);
     fclose(CustomerDBTEMP);
     fclose(CommercialDBTEMP);
    
	 free(pmus);
     free(pmus1);
     
     
    remove("Customer.txt");
    rename("CustomerTEMP.txt","Customer.txt");
    remove("Commercial.txt");
    rename("CommercialTEMP.txt","Commercial.txt");
    
     
}

void Withdraw_Money()
{
     FILE *CustomerDB;
     FILE *CustomerDBTEMP;
     CUSTOMER *pmus;
     pmus = (CUSTOMER*) malloc(sizeof(CUSTOMER));
     pmus->pac = (ACCOUNT*) malloc(sizeof(ACCOUNT));
     pmus->pac->pacno = (ACNO*) malloc(sizeof(ACNO));
     
     char srcName[20];
     char accNo[20];
     double balanceG;
     
     CustomerDB = fopen("Customer.txt","r");
     
     
     printf("Enter customer name .\n");
     scanf("%s",srcName);
      printf("enter account number .\n");
     scanf("%s",accNo);
     printf("How much money do you want to withdraw?.\n");
     scanf("%lf",&balanceG);
     
     CustomerDBTEMP = fopen("CustomerTEMP.txt","a");
     
    while( fscanf(CustomerDB, "%d %s %s %s %s %s %s %lf \n", &pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,&pmus->pac->pacno->balance) != EOF )
    {
				
    	if(strcmp(pmus->name,srcName)==0 && strcmp(pmus->pac->pacno->accountNo,accNo)==0){
    		
    		 pmus->pac->pacno->balance=pmus->pac->pacno->balance-balanceG;
    		 
    		fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}else{
			fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}
    	
       
    }
        
     
         
     fclose(CustomerDB);
     fclose(CustomerDBTEMP);
     free(pmus);
     
    remove("Customer.txt");
    rename("CustomerTEMP.txt","Customer.txt");
    
    
     
}

void Delete_Account()
{
	 FILE *CustomerDB;
     FILE *CustomerDBTEMP;
     CUSTOMER *pmus;
     pmus = (CUSTOMER*) malloc(sizeof(CUSTOMER));
     pmus->pac = (ACCOUNT*) malloc(sizeof(ACCOUNT));
     pmus->pac->pacno = (ACNO*) malloc(sizeof(ACNO));
     
     char srcName[20];
     char accNo[20];
     int balanceG;
     
     CustomerDB = fopen("Customer.txt","r");
     
     
     printf("Enter customer name.\n");
     scanf("%s",srcName);
      printf("enter account number .\n");
     scanf("%s",accNo);
     
     
    CustomerDBTEMP = fopen("CustomerTEMP.txt","a");
     
    while( fscanf(CustomerDB, "%d %s %s %s %s %s %s %lf \n", &pmus->customerNo, pmus->name, pmus->surname,pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,&pmus->pac->pacno->balance) != EOF )
    {
				
    	if(strcmp(pmus->name,srcName)==0 && strcmp(pmus->pac->pacno->accountNo,accNo )==0 && pmus->pac->pacno->balance==0){
    		
    		remove("Customer.txt");
    		fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
		}else {
			
			fprintf(CustomerDBTEMP, "%d %s %s %s %s %s %s %lf \n",pmus->customerNo, pmus->name, pmus->surname, pmus->customerType,pmus->birthPlace,pmus->pac->accountName,pmus->pac->pacno->accountNo,pmus->pac->pacno->balance);
			
		}
    	
       
    }
        
     remove("Customer.txt");
    rename("CustomerTEMP.txt","Customer.txt");
         
     fclose(CustomerDB);
     fclose(CustomerDBTEMP);
     free(pmus);
     
  
	
	
	
	
}
