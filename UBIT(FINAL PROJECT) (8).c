#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Accounts_Information{
	int account_number_r;
	char NIC_r[14];
	char name_r[30];
	int age_r;
	int PIN_r;
	float balance_r;
}Accounts;

typedef struct Transactions_Information{
	int sender_account_number;
    float amount;
    int reciever_account_number;
}Transactions;

void create_account(Accounts* ,int );
int Number_Of_Accounts();
Accounts* Accounts_Reader(int );
void balance_inquiry(Accounts* ,int );
void account_details(Accounts* ,int );
void delete_account(Accounts* ,int );
void update_account(Accounts* ,int );
void withdraw_amount(Accounts* ,int );
void transaction(Accounts* ,int );
int Number_Of_Transactions();
Transactions* Transactions_Reader(int );
void transaction_history(Accounts* ,int ,Transactions* ,int );

int main()
{
	int i,j;
	int choice;
	int num_of_1,num_of_2;
	Accounts* Manipulator_1;
	Transactions* Manipulator_2;
	printf("\t\t\t      ---WELCOME TO OUR BANK---\n");
	for(i=0; ;i++){
	    printf("\nEnter '1' to CREATE ACCOUNT!\n");
	    printf("Enter '2' to DISPLAY ACCOUNT DETAILS!\n");
	    printf("Enter '3' to INQUIRE ABOUT BALANCE!\n");
	    printf("Enter '4' to UPDATE ACCOUNT!\n");
	    printf("Enter '5' to WITHDRAW AMOUNT!\n");
	    printf("Enter '6' to DELETE ACCOUNT!\n");
	    printf("Enter '7' to MAKE A TRANSACTION!\n");
	    printf("Enter '8' to DISPLAY TRANSACTION HSTORY!\n");
	    printf("Enter '9' to EXIT!\n");
	    printf("\nEnter : ");
	    for(j=0;j<3;j++){
	    scanf("%d",&choice);
	    switch(choice){
	    	case 1 : free(Manipulator_1);
			        num_of_1=Number_Of_Accounts();
	    	        Manipulator_1=Accounts_Reader(num_of_1);
	    	        create_account(Manipulator_1,num_of_1);
	    	        break;
	    	case 2 : free(Manipulator_1);
			        num_of_1=Number_Of_Accounts();
	    	        Manipulator_1=Accounts_Reader(num_of_1);
	    	        account_details(Manipulator_1,num_of_1);
	    	        break;
	    	case 3 : free(Manipulator_1);
			        num_of_1=Number_Of_Accounts();
	    	        Manipulator_1=Accounts_Reader(num_of_1);
	    	        balance_inquiry(Manipulator_1,num_of_1);
	    	        break;
	    	case 4 : free(Manipulator_1);
			        num_of_1=Number_Of_Accounts();
	    	        Manipulator_1=Accounts_Reader(num_of_1);
	    	        update_account(Manipulator_1,num_of_1);
	    	        break;
	    	case 5 : free(Manipulator_1);
			        num_of_1=Number_Of_Accounts();
	    	        Manipulator_1=Accounts_Reader(num_of_1);
	    	        withdraw_amount(Manipulator_1,num_of_1);
	    	        break;
	        case 6 : free(Manipulator_1);
			        num_of_1=Number_Of_Accounts();
	    	        Manipulator_1=Accounts_Reader(num_of_1);
	    	        delete_account(Manipulator_1,num_of_1);
	    	        break;
	    	case 7 : free(Manipulator_1);
			        num_of_1=Number_Of_Accounts();
	    	        Manipulator_1=Accounts_Reader(num_of_1);
	    	        transaction(Manipulator_1,num_of_1);
	    	        break;
	    	case 8 : free(Manipulator_1);
	    	        free(Manipulator_2);
			        num_of_1=Number_Of_Accounts();
	    	        Manipulator_1=Accounts_Reader(num_of_1);
	    	        num_of_2=Number_Of_Transactions();
	    	        Manipulator_2=Transactions_Reader(num_of_2);
	    	        transaction_history(Manipulator_1,num_of_1,Manipulator_2,num_of_2);
	    	        break;
	    	case 9 : free(Manipulator_1);
	    	         free(Manipulator_2);
			        exit(0);
			        break;
			default : printf("\n\t\t\t---Invalid Input---\n"); 
		}
		if(choice>0 && choice<=9){
			break;
		}else if((choice<=0 || choice>9) && j<2){
			printf("\nEnter again :  ");
		}
		if(j==2){
			exit(0);
		}
	}
	printf("-------------------------------------------------------------------------------\n");
}
	return 0;
}

void create_account(Accounts* account_creation,int num_of){
	int account_number;
	char NIC[14];
	char name[30];
	int age;
	int PIN;
	float balance;
	int i;
//---------------------------------------------------------//
    printf("\nEnter Name : ");
    scanf("\n%s",name);
    printf("\nEnter NIC : ");
    for(i=0;i<14;i++){
    	scanf("\n%c",&NIC[i]);
	}
    printf("\nEnter Age : ");
    for(i=0;i<3;i++){
        scanf("\n%d",&age);
        if(age>=18){
        	break;
		}else if((age>0 && age<18) && i<2){
        	printf("\nAge must be 18!\n");
        	printf("\nEnter again : ");
		}else if(age<=0 && i<2){
			printf("\n\t\t\t---Invalid Input---\n");
			printf("\nEnter again : ");
		}
		if(i==2){
			printf("\n\t\t\t---Invalid Input---\n");
			exit(0);
		}
    }
    printf("\nEnter PIN : ");
    for(i=0;i<3;i++){
        scanf("\n%d",&PIN);
        if(PIN>=1111 && PIN<=9999){
        	break;
		}else if(PIN<0){
			printf("\n\t\t\t---Invalid Input---\n");
			printf("\nEnter again : ");
		}else if(PIN>9999){
			printf("\nPIN has exceeded the limit (i.e. 4 digits)!\n");
		}else if(i==2){
			printf("\n\t\t\t---Invalid Input---\n");
			exit(0);
		}
    }
    printf("\nEnter Balance : ");
    for(i=0;i<3;i++){
        scanf("\n%f",&balance);
        if(balance<0 && i<2){
        	printf("\n\t\t\t---Invalid Input---\n");
        	printf("\nEnter again : ");
		}else{
			break;
		}
		if(i==2){
			printf("\n\t\t\t---Invalid Input---\n");
			exit(0);
		}
    }
    if(num_of>0){
    account_number=account_creation[num_of-1].account_number_r+1;
    }else if(num_of==0){
    	account_number=1;
	}
    FILE* ptr;
    ptr=fopen("Bank Accounts.txt","a");
//-----------------------------------------------------//
    fprintf(ptr,"Account Number : %d\t",account_number);
    fprintf(ptr,"NIC : ");
    for(i=0;i<14;i++){
    	fprintf(ptr,"%c",NIC[i]);
	}
	fprintf(ptr,"\tName : %s\tAge : %d\tPIN : %d\tBalance : %f\n",name,age,PIN,balance);
//-----------------------------------------------------//
    fclose(ptr);
    printf("\nDear Customer, Your Account has been created!\n");
    printf("\n---Details of the Account---\n");
    printf("\nAccount Number : %d\n",account_number);
    printf("NIC : ");
    for(i=0;i<14;i++){
    	printf("%c",NIC[i]);
	}
	printf("\n");
    printf("Name : %s\n",name);
    printf("Age : %d\n",age);
    printf("PIN : %d\n",PIN);
    printf("Balance : %.2f Rs\n",balance);
//---------------------------------------------------------//
}

int Number_Of_Accounts(){
	int count=0;
	char ch;
	FILE* number_of_accounts;
	number_of_accounts=fopen("Bank Accounts.txt","r");
	while(ch!=EOF){
		ch=fgetc(number_of_accounts);
		if(ch=='\n'){
			count++;
		}
	}
	fclose(number_of_accounts);
	return count;
}

Accounts* Accounts_Reader(int num_of){
	Accounts* Information;
	Information=(Accounts*)malloc(num_of*sizeof(Accounts));
	FILE* Read;
	Read=fopen("Bank Accounts.txt","r");
	int i,j;
	for(i=0;i<num_of;i++){
	    fscanf(Read,"Account Number : %d\tNIC : %s\tName : %s\tAge : %d\tPIN : %d\tBalance : %f\n",&(Information+i)->account_number_r,(Information+i)->NIC_r,(Information+i)->name_r,&(Information+i)->age_r,&(Information+i)->PIN_r
		,&(Information+i)->balance_r);
    }
    fclose(Read);
//    for(i=0;i<num_of;i++){
//    	printf("Account Number : %d\n",(Information+i)->account_number_r);
//    	printf("NIC : ");
//    	for(j=0;j<14;j++){
//    	    printf("%c",(Information+i)->NIC_r[j]);
//        }
//        printf("\n");
//    	printf("Name : %s\n",(Information+i)->name_r);
//    	printf("Age : %d\n",(Information+i)->age_r);
//    	printf("PIN : %d\n",(Information+i)->PIN_r);
//    	printf("Balance : %.2f Rs\n",(Information+i)->balance_r);
//	}
    return Information;
}
void balance_inquiry(Accounts* accounts_balance,int num_of){
	char NIC[14];
	int account_number;
	int PIN;
	int i,j,k,l;
	int check1,check2,check3;
	int checks[14];
	printf("\nEnter NIC : ");
	for(i=0;i<3;i++){
		for(j=0;j<14;j++){
			scanf("\n%c",&NIC[j]);
		}
		for(j=0;j<num_of;j++){
			for(k=0;k<14;k++){
				if(NIC[k]==accounts_balance[j].NIC_r[k]){
					//printf("Correct\n");
					checks[k]=1;
				}
			}
		    if(checks[0]==1&&checks[1]==1&&checks[2]==1&&checks[3]==1&&checks[4]==1&&checks[5]==1&&checks[6]==1&&checks[7]==1&&checks[8]==1&&checks[9]==1&&checks[10]==1&&checks[11]==1&&checks[12]==1&&checks[13]==1){
		    	check1=1;
		    	printf("\n\t\t\t---CORRECT NIC---\n");
		    	printf("\nEnter Account Number : ");
		    	for(k=0;k<3;k++){
		    		scanf("%d",&account_number);
		    		if(account_number==accounts_balance[j].account_number_r){
		    			check2=2;
		    			printf("\n\t\t\t---CORRECT ACCOUNT NUMBER---\n");
		    			printf("\nEnter PIN : ");
		    			for(l=0;l<3;l++){
		    			    scanf("%d",&PIN);
		    			    if(PIN==accounts_balance[j].PIN_r){
		    			    	check3=3;
		    			    	printf("\n\t\t\t---CORRECT PIN---\n");
		    			    	printf("\nBalance : %.2fRs\n",accounts_balance[j].balance_r);
		    			    	break;
							}
							if(check3==3){
						        break;
					        }else if(check3!=3 && l<2){
					           	printf("\n\t\t\t---INCORRECT PIN---\n");
				        		printf("\nEnter again : ");
					        }
							if(l==2){
						        printf("\n\t\t\t---INCORRECT PIN---\n");
						        exit(0);
					        }
		    		    }
		    		    break;
					}
					if(check2==2){
						break;
					}else if(check2!=2 && k<2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						printf("\nEnter again : ");
					}
					if(k==2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						exit(0);
					}
				}
				break;
			}
	    }
	    if(check1==1){
	    	break;
		}else if(check1!=1 && i<2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			printf("\nEnter again : ");
		}
		if(i==2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			exit(0);
		}
	}
}
void account_details(Accounts* account_detail,int num_of){
	char NIC[14];
	int account_number;
	int PIN;
	int i,j,k,l,b;
	int check1,check2,check3;
	int checks[14];
	printf("\nEnter NIC : ");
	for(i=0;i<3;i++){
		for(j=0;j<14;j++){
			scanf("\n%c",&NIC[j]);
		}
		for(j=0;j<num_of;j++){
			for(k=0;k<14;k++){
				if(NIC[k]==account_detail[j].NIC_r[k]){
					//printf("Correct\n");
					checks[k]=1;
				}
			}
		    if(checks[0]==1&&checks[1]==1&&checks[2]==1&&checks[3]==1&&checks[4]==1&&checks[5]==1&&checks[6]==1&&checks[7]==1&&checks[8]==1&&checks[9]==1&&checks[10]==1&&checks[11]==1&&checks[12]==1&&checks[13]==1){
		    	check1=1;
		    	printf("\n\t\t\t---CORRECT NIC---\n");
		    	printf("\nEnter Account Number : ");
		    	for(k=0;k<3;k++){
		    		scanf("%d",&account_number);
		    		if(account_number==account_detail[j].account_number_r){
		    			check2=2;
		    			printf("\n\t\t\t---CORRECT ACCOUNT NUMBER---\n");
		    			printf("\nEnter PIN : ");
		    			for(l=0;l<3;l++){
		    			    scanf("%d",&PIN);
		    			    if(PIN==account_detail[j].PIN_r){
		    			    	check3=3;
		    			    	printf("\n\t\t\t---CORRECT PIN---\n");
		    			    	printf("\nAccount Details!\n");
		    			    	printf("\nAccount Number : %d\n",(account_detail+j)->account_number_r);
    	                        printf("NIC : ");
     	                        for(b=0;b<14;b++){
    	                            printf("%c",(account_detail+j)->NIC_r[b]);
                                }
                                printf("\n");
    	                        printf("Name : %s\n",(account_detail+j)->name_r);
    	                        printf("Age : %d\n",(account_detail+j)->age_r);
    	                        printf("PIN : %d\n",(account_detail+j)->PIN_r);
		    			    	printf("Balance : %.2f Rs\n",account_detail[j].balance_r);
		    			    	break;
							}
							if(check3==3){
						        break;
					        }else if(check3!=3 && l<2){
					           	printf("\n\t\t\t---INCORRECT PIN---\n");
				        		printf("\nEnter again : ");
					        }
							if(l==2){
						        printf("\n\t\t\t---INCORRECT PIN---\n");
						        exit(0);
					        }
		    		    }
		    		    break;
					}
					if(check2==2){
						break;
					}else if(check2!=2 && k<2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						printf("\nEnter again : ");
					}
					if(k==2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						exit(0);
					}
				}
				break;
			}
	    }
	    if(check1==1){
	    	break;
		}else if(check1!=1 && i<2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			printf("\nEnter again : ");
		}
		if(i==2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			exit(0);
		}
	}
}
void delete_account(Accounts* account_deletion,int num_of){
	char NIC[14];
	int account_number;
	int PIN;
	int i,j,k,l,d,loop;
	int check1,check2,check3;
	int checks[14];
	printf("\nEnter NIC : ");
	for(i=0;i<3;i++){
		for(j=0;j<14;j++){
			scanf("\n%c",&NIC[j]);
		}
//		printf("\n");
//		for(j=0;j<14;j++){
//			printf("%c",NIC[j]);
//		}
//		printf("\n");
		for(j=0;j<num_of;j++){
			for(k=0;k<14;k++){
				if(NIC[k]==account_deletion[j].NIC_r[k]){
					//printf("Correct\n");
					checks[k]=1;
				}
			}
		    if(checks[0]==1&&checks[1]==1&&checks[2]==1&&checks[3]==1&&checks[4]==1&&checks[5]==1&&checks[6]==1&&checks[7]==1&&checks[8]==1&&checks[9]==1&&checks[10]==1&&checks[11]==1&&checks[12]==1&&checks[13]==1){
		    	check1=1;
		    	printf("\n\t\t\t---CORRECT NIC---\n");
		    	printf("\nEnter Account Number : ");
		    	for(k=0;k<3;k++){
		    		scanf("%d",&account_number);
		    		if(account_number==account_deletion[j].account_number_r){
		    			check2=2;
		    			printf("\n\t\t\t---CORRECT ACCOUNT NUMBER---\n");
		    			printf("\nEnter PIN : ");
		    			for(l=0;l<3;l++){
		    			    scanf("%d",&PIN);
		    			    if(PIN==account_deletion[j].PIN_r){
		    			    	check3=3;
		    			    	printf("\n\t\t\t---CORRECT PIN---\n");
		    			    	FILE* deletion;
		    			    	deletion=fopen("Bank Accounts.txt","w");
		    			    		for(d=0;d<num_of;d++){
		    			    			if(d==j){
		    			    				continue;
										}
									//-----------------------------------------------------//
										fprintf(deletion,"Account Number : %d\t",account_deletion[d].account_number_r);
										fprintf(deletion,"NIC : ");
										for(loop=0;loop<14;loop++){
										    fprintf(deletion,"%c",account_deletion[d].NIC_r[loop]);
									    }
										fprintf(deletion,"\tName : %s\tAge : %d\tPIN : %d\tBalance : %f\n",account_deletion[d].name_r,account_deletion[d].age_r,account_deletion[d].PIN_r,account_deletion[d].balance_r);
									//-----------------------------------------------------//
									}
								fclose(deletion);
								printf("\nDear customer, Your Account has been deleted!\n");
								printf("\nDetails of the deleted Account!\n");
		    			    	printf("\nAccount Number : %d\n",(account_deletion+j)->account_number_r);
    	                        printf("NIC : ");
     	                        for(d=0;d<14;d++){
    	                            printf("%c",(account_deletion+j)->NIC_r[d]);
                                }
                                printf("\n");
    	                        printf("Name : %s\n",(account_deletion+j)->name_r);
    	                        printf("Age : %d\n",(account_deletion+j)->age_r);
    	                        printf("PIN : %d\n",(account_deletion+j)->PIN_r);
		    			    	printf("Balance : %.2f Rs\n",account_deletion[j].balance_r);
		    			    	break;
							}
							if(check3==3){
						        break;
					        }else if(check3!=3 && l<2){
					           	printf("\n\t\t\t---INCORRECT PIN---\n");
				        		printf("\nEnter again : ");
					        }
							if(l==2){
						        printf("\n\t\t\t---INCORRECT PIN---\n");
						        exit(0);
					        }
		    		    }
		    		    break;
					}
					if(check2==2){
						break;
					}else if(check2!=2 && k<2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						printf("\nEnter again : ");
					}
					if(k==2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						exit(0);
					}
				}
				break;
			}
	    }
	    if(check1==1){
	    	break;
		}else if(check1!=1 && i<2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			printf("\nEnter again : ");
		}
		if(i==2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			exit(0);
		}
	}
}
void withdraw_amount(Accounts* withdraw,int num_of){
	char NIC[14];
	int account_number;
	int PIN;
//---------------------//
	float amount;
	float temporary;
//---------------------//
	int i,j,k,l,m;
	int w,loop;
	int check1,check2,check3;
	int checks[14];
	printf("\nEnter NIC : ");
	for(i=0;i<3;i++){
		for(j=0;j<14;j++){
			scanf("\n%c",&NIC[j]);
		}
		for(j=0;j<num_of;j++){
			for(k=0;k<14;k++){
				if(NIC[k]==withdraw[j].NIC_r[k]){
					//printf("Correct\n");
					checks[k]=1;
				}
			}
		    if(checks[0]==1&&checks[1]==1&&checks[2]==1&&checks[3]==1&&checks[4]==1&&checks[5]==1&&checks[6]==1&&checks[7]==1&&checks[8]==1&&checks[9]==1&&checks[10]==1&&checks[11]==1&&checks[12]==1&&checks[13]==1){
		    	check1=1;
		    	printf("\n\t\t\t---CORRECT NIC---\n");
		    	printf("\nEnter Account Number : ");
		    	for(k=0;k<3;k++){
		    		scanf("%d",&account_number);
		    		if(account_number==withdraw[j].account_number_r){
		    			check2=2;
		    			printf("\n\t\t\t---CORRECT ACCOUNT NUMBER---\n");
		    			printf("\nEnter PIN : ");
		    			for(l=0;l<3;l++){
		    			    scanf("%d",&PIN);
		    			    if(PIN==withdraw[j].PIN_r){
		    			    	check3=3;
		    			    	printf("\n\t\t\t---CORRECT PIN---\n");
		    			    	printf("\nEnter Amount : ");
		    			    	for(m=0;m<3;m++){
		    			    	scanf("%f",&amount);
		    			    	if(amount>0 && amount<=withdraw[j].balance_r){
		    			    		//-------------------------------------------------//
		    			    		temporary=withdraw[j].balance_r;
		    			    		withdraw[j].balance_r=withdraw[j].balance_r-amount;
		    			    		//-------------------------------------------------//
		    			    		FILE* Amount_Withdraw;
		    			    		Amount_Withdraw=fopen("Bank Accounts.txt","w");
		    			    		for(w=0;w<num_of;w++){
		    			    		//-----------------------------------------------------//
										fprintf(Amount_Withdraw,"Account Number : %d\t",withdraw[w].account_number_r);
										fprintf(Amount_Withdraw,"NIC : ");
										for(loop=0;loop<14;loop++){
										    fprintf(Amount_Withdraw,"%c",withdraw[w].NIC_r[loop]);
									    }
										fprintf(Amount_Withdraw,"\tName : %s\tAge : %d\tPIN : %d\tBalance : %f\n",withdraw[w].name_r,withdraw[w].age_r,withdraw[w].PIN_r,withdraw[w].balance_r);
									//-----------------------------------------------------//
								    }
                                    fclose(Amount_Withdraw);
		    			    		printf("\nDear user, the Amount you have entered has been WITHDRAWN successfully!\n");
		    			    		printf("\nOld Balance : %.2f Rs\n",temporary);
		    			    		printf("Amount withdrawn : %.2f Rs\n",amount);
		    			    		printf("New Balance : %.2f Rs\n",withdraw[j].balance_r);
		    			    		break;
								}else if((amount<0 || amount>withdraw[j].balance_r) && m<2){
									printf("\n\t\t\t---Invalid Amount---\n");
									if(amount>withdraw[j].balance_r){
									    printf("\nDear user, Your current balance is %.2f Rs\n",withdraw[j].balance_r);
								    }
									printf("\nEnter again : ");
								}else if(m==2){
									printf("\n\t\t\t---Invalid Amount---\n");
									exit(0);
								}
							}
		    			    	break;
							}
							if(check3==3){
						        break;
					        }else if(check3!=3 && l<2){
					           	printf("\n\t\t\t---INCORRECT PIN---\n");
				        		printf("\nEnter again : ");
					        }
							if(l==2){
						        printf("\n\t\t\t---INCORRECT PIN---\n");
						        exit(0);
					        }
		    		    }
		    		    break;
					}
					if(check2==2){
						break;
					}else if(check2!=2 && k<2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						printf("\nEnter again : ");
					}
					if(k==2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						exit(0);
					}
				}
				break;
			}
	    }
	    if(check1==1){
	    	break;
		}else if(check1!=1 && i<2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			printf("\nEnter again : ");
		}
		if(i==2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			exit(0);
		}
	}
}
void update_account(Accounts* update,int num_of){
	char NIC[14];
	int account_number;
	int PIN;
	int i,j,k,l,m;
	int u,loop;
	int check1,check2,check3;
	int checks[14];
	int choice;
	printf("\nEnter NIC : ");
	for(i=0;i<3;i++){
		for(j=0;j<14;j++){
			scanf("\n%c",&NIC[j]);
		}
		for(j=0;j<num_of;j++){
			for(k=0;k<14;k++){
				if(NIC[k]==update[j].NIC_r[k]){
					//printf("Correct\n");
					checks[k]=1;
				}
			}
		    if(checks[0]==1&&checks[1]==1&&checks[2]==1&&checks[3]==1&&checks[4]==1&&checks[5]==1&&checks[6]==1&&checks[7]==1&&checks[8]==1&&checks[9]==1&&checks[10]==1&&checks[11]==1&&checks[12]==1&&checks[13]==1){
		    	check1=1;
		    	printf("\n\t\t\t---CORRECT NIC---\n");
		    	printf("\nEnter Account Number : ");
		    	for(k=0;k<3;k++){
		    		scanf("%d",&account_number);
		    		if(account_number==update[j].account_number_r){
		    			check2=2;
		    			printf("\n\t\t\t---CORRECT ACCOUNT NUMBER---\n");
		    			printf("\nEnter PIN : ");
		    			for(l=0;l<3;l++){
		    			    scanf("%d",&PIN);
		    			    if(PIN==update[j].PIN_r){
		    			    	check3=3;
		    			    	printf("\n\t\t\t---CORRECT PIN---\n");
		    			    	printf("\nEnter '1' to update PIN!\n");
		    			    	printf("Enter '2' to update balance(i.e to deposit amount)!\n");
		    			    	printf("\nEnter : ");
		    			    	for(m=0;m<3;m++){
		    			    		scanf("%d",&choice);
		    			    		if(choice>0 && choice<=2){
		    			    			if(choice==1){
		    			    				int new_PIN;
		    			    				int temporary;
		    			    				//-------------------------------------------------//
		    			    				printf("\nEnter new PIN : ");
		    			    				for(u=0;u<3;u++){
		    			    				    scanf("%d",&new_PIN);
		    			    				    if(new_PIN>=1111 && new_PIN<=9999){
		    			    				    	break;
												}else if(new_PIN>9999){
														printf("\nPIN has exceeded the limit (i.e. 4 digits)!\n");
														printf("\nEnter again : ");
												}else if(PIN<0 && u<2){
													printf("\n\t\t\t---Invalid Input---\n");
													printf("\nEnter again : ");
												}
												if(u==2){
													printf("\n\t\t\t---Invalid Input---\n");
													exit(0);
												}
		    			    			    }
		    			    				//-------------------------------------------------//
		    			    				temporary=update[j].PIN_r;
		    			    				update[j].PIN_r=new_PIN;
		    			    				//-------------------------------------------------//
		    			    		        FILE* update_PIN;
		    			    		        update_PIN=fopen("Bank Accounts.txt","w");
		    			    		        for(u=0;u<num_of;u++){
		    			    		        //-----------------------------------------------------//
										    fprintf(update_PIN,"Account Number : %d\t",update[u].account_number_r);
										    fprintf(update_PIN,"NIC : ");
										    for(loop=0;loop<14;loop++){
										    fprintf(update_PIN,"%c",update[u].NIC_r[loop]);
									        }
										    fprintf(update_PIN,"\tName : %s\tAge : %d\tPIN : %d\tBalance : %f\n",update[u].name_r,update[u].age_r,update[u].PIN_r,update[u].balance_r);
									        //-----------------------------------------------------//
								    }
                                    fclose(update_PIN);
                                    printf("\nDear user, Your PIN has been changed successfully!\n");
                                    printf("\nOld PIN : %d\n",temporary);
                                    printf("New PIN : %d\n",update[j].PIN_r);
                                    break;
								    }else if(choice==2){
								    	float temporary;
								    	float amount;
								    	printf("\nEnter Amount : ");
								    	for(u=0;u<3;u++){
								    	    scanf("%f",&amount);
											if(amount<0 && u<2){
												printf("\n\t\t\t---Invalid Amount---\n");
												printf("\nEnter again : ");
											}else if(amount>=0){
												break;
											}
											if(u==2){
												printf("\n\t\t\t---Invalid Amount---\n");
												exit(0);
											}	
										}
								    	temporary=update[j].balance_r;
								    	update[j].balance_r=update[j].balance_r+amount;
								    	//-------------------------------------------------//
		    			    		        FILE* deposit;
		    			    		        deposit=fopen("Bank Accounts.txt","w");
		    			    		        for(u=0;u<num_of;u++){
		    			    		        //-----------------------------------------------------//
										    fprintf(deposit,"Account Number : %d\t",update[u].account_number_r);
										    fprintf(deposit,"NIC : ");
										    for(loop=0;loop<14;loop++){
										    fprintf(deposit,"%c",update[u].NIC_r[loop]);
									        }
										    fprintf(deposit,"\tName : %s\tAge : %d\tPIN : %d\tBalance : %f\n",update[u].name_r,update[u].age_r,update[u].PIN_r,update[u].balance_r);
									        //-----------------------------------------------------//
								    }
                                    fclose(deposit);
                                    printf("\nDear user, the Amount you have entered has been DEPOSITED successfully!\n");
                                    printf("\nOld Balance : %.2f Rs\n",temporary);
                                    printf("Amount deposited : %.2f Rs\n",amount);
                                    printf("New Balance : %.2f Rs\n",update[j].balance_r);
                                    break;
									}
									break;	
									}else if((choice<=0 || choice>2) && m<2){
										printf("\n\t\t\t---Invalid Input---\n");
										printf("\nEnter again : ");
									}else if(m==2){
										printf("\n\t\t\t---Invalid Input---\n");
										exit(0);
									}
								}
		    			    	break;
							}
							if(check3==3){
						        break;
					        }else if(check3!=3 && l<2){
					           	printf("\n\t\t\t---INCORRECT PIN---\n");
				        		printf("\nEnter again : ");
					        }
							if(l==2){
						        printf("\n\t\t\t---INCORRECT PIN---\n");
						        exit(0);
					        }
		    		    }
		    		    break;
					}
					if(check2==2){
						break;
					}else if(check2!=2 && k<2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						printf("\nEnter again : ");
					}
					if(k==2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						exit(0);
					}
				}
				break;
			}
	    }
	    if(check1==1){
	    	break;
		}else if(check1!=1 && i<2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			printf("\nEnter again : ");
		}
		if(i==2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			exit(0);
		}
	}
}
void transaction(Accounts* account_transaction,int num_of){
	char NIC[14];
	int account_number;
	int PIN;
	int i,j,k,l,m,n,O;
	int t,loop;
	int check1,check2,check3,check4;
	int checks[14];
	int reciever_account_number;
	float amount;
	float temporary;
	printf("\nEnter NIC : ");
	for(i=0;i<3;i++){
		for(j=0;j<14;j++){
			scanf("\n%c",&NIC[j]);
		}
		for(j=0;j<num_of;j++){
			for(k=0;k<14;k++){
				if(NIC[k]==account_transaction[j].NIC_r[k]){
					//printf("Correct\n");
					checks[k]=1;
				}
			}
		    if(checks[0]==1&&checks[1]==1&&checks[2]==1&&checks[3]==1&&checks[4]==1&&checks[5]==1&&checks[6]==1&&checks[7]==1&&checks[8]==1&&checks[9]==1&&checks[10]==1&&checks[11]==1&&checks[12]==1&&checks[13]==1){
		    	check1=1;
		    	printf("\n\t\t\t---CORRECT NIC---\n");
		    	printf("\nEnter Account Number : ");
		    	for(k=0;k<3;k++){
		    		scanf("%d",&account_number);
		    		if(account_number==account_transaction[j].account_number_r){
		    			check2=2;
		    			printf("\n\t\t\t---CORRECT ACCOUNT NUMBER---\n");
		    			printf("\nEnter PIN : ");
		    			for(l=0;l<3;l++){
		    			    scanf("%d",&PIN);
		    			    if(PIN==account_transaction[j].PIN_r){
		    			    	check3=3;
		    			    	printf("\n\t\t\t---CORRECT PIN---\n");
		    			    	if(account_transaction[j].balance_r==0){
		    			    		printf("\nDear user, since Your current Balance is : %.2f Rs.Therefore you can not make\n\t\t\t\t any transaction!\n");
		    			    		break;
								}
		    			    	printf("\nEnter reciever Account Number : ");
		    			    	for(m=0;m<3;m++){
		    			    		scanf("\n%d",&reciever_account_number);
		    			    	    for(n=0;n<num_of;n++){
		    			    		    if(n==j){
		    			    		    	continue;
										}
										if(reciever_account_number==account_transaction[n].account_number_r){
											check4=4;
											printf("\nReciever's Account Number Found!\n");
											printf("\nEnter Amount : ");
											for(O=0;O<3;O++){
												scanf("\n%f",&amount);
												if(amount>=0 && amount<=account_transaction[j].balance_r){
													temporary=account_transaction[j].balance_r;
													account_transaction[j].balance_r=account_transaction[j].balance_r-amount;
													account_transaction[n].balance_r=account_transaction[n].balance_r+amount;
													FILE* trans;
													trans=fopen("Bank Accounts.txt","w");
													for(t=0;t<num_of;t++){
														//-----------------------------------------------------//
										                fprintf(trans,"Account Number : %d\t",account_transaction[t].account_number_r);
										                fprintf(trans,"NIC : ");
										                for(loop=0;loop<14;loop++){
										                fprintf(trans,"%c",account_transaction[t].NIC_r[loop]);
									                    }
										                fprintf(trans,"\tName : %s\tAge : %d\tPIN : %d\tBalance : %f\n",account_transaction[t].name_r,account_transaction[t].age_r,account_transaction[t].PIN_r,account_transaction[t].balance_r);
									                    //-----------------------------------------------------//
													}
													fclose(trans);
													//-----------------------------------------------------//
													trans=fopen("Bank Transactions.txt","a");
													fprintf(trans,"Sender Account Number : %d\tAmount sent : %f\tReciever's Account Number : %d\n",account_transaction[j].account_number_r,amount,account_transaction[n].account_number_r);
													fclose(trans);
													//-----------------------------------------------------//
													free(trans);
													printf("\nDear user, TRANSACTION has been made successfully!\n");
													printf("\nYour Account Number : %d\n",account_transaction[j].account_number_r);
													printf("Reciever's Account Number : %d\n",account_transaction[n].account_number_r);
													printf("\nYour Old Balance : %.2f Rs\n",temporary);
													printf("Amount sent : %.2f Rs\n",amount);
													printf("Your New balance : %.2f Rs\n",account_transaction[j].balance_r);
													break;
												}else if((amount<0 || amount>account_transaction[j].balance_r) && O<2){
													printf("\n\t\t\t---Invalid Amount---\n");
													if(amount>account_transaction[j].balance_r){
														printf("\nDear user, Your current Balance is : %.2f Rs\n",account_transaction[j].balance_r);
													}
													printf("\nEnter again : ");
												}
												if(O==2){
													printf("\n\t\t\t---Invalid Amount---\n");
											        exit(0);
												}
											}
										}
								    }
								    if(check4==4){
								    	break;
									}else if(check4!=4 && m<2){
										printf("\nReciever's Account Number not Found!\n");
										printf("\nEnter again : ");
									}
									if(m==2){
										printf("\nReciever's Account Number not Found!\n");
										exit(0);
									}
							    } 
		    			    	break;
							}
							if(check3==3){
						        break;
					        }else if(check3!=3 && l<2){
					           	printf("\n\t\t\t---INCORRECT PIN---\n");
				        		printf("\nEnter again : ");
					        }
							if(l==2){
						        printf("\n\t\t\t---INCORRECT PIN---\n");
						        exit(0);
					        }
		    		    }
		    		    break;
					}
					if(check2==2){
						break;
					}else if(check2!=2 && k<2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						printf("\nEnter again : ");
					}
					if(k==2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						exit(0);
					}
				}
				break;
			}
	    }
	    if(check1==1){
	    	break;
		}else if(check1!=1 && i<2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			printf("\nEnter again : ");
		}
		if(i==2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			exit(0);
		}
	}
}
int Number_Of_Transactions(){
	int count=0;
	char ch;
	FILE* number_of_transactions;
	number_of_transactions=fopen("Bank Transactions.txt","r");
	if(number_of_transactions==NULL){
		printf("\nCould not Open File!\n");
	}
	while(ch!=EOF){
		ch=fgetc(number_of_transactions);
		if(ch=='\n'){
			count++;
		}
	}
	fclose(number_of_transactions);
	return count;
}

Transactions* Transactions_Reader(int num_of){
	Transactions* Information;
	Information=(Transactions*)malloc(num_of*sizeof(Transactions));
	FILE* Read;
	Read=fopen("Bank Transactions.txt","r");
	int i;
	for(i=0;i<num_of;i++){
	    fscanf(Read,"Sender Account Number : %d\tAmount sent : %f\tReciever's Account Number : %d\n",&Information[i].sender_account_number,&Information[i].amount,
		&Information[i].reciever_account_number);
    }
    fclose(Read);
//    for(i=0;i<num_of;i++){
//    	printf("\nTransaction Number %d\n",(i+1));
//    	printf("\nSender Account Number : %d\n",Information[i].sender_account_number);
//        printf("Amount Transferred : %.2f Rs\n",Information[i].amount);
//        printf("Reciever's Account Number : %d\n",Information[i].reciever_account_number);
//	}
    return Information;
}
void transaction_history(Accounts* account_history,int num_of_1,Transactions* account_transactions,int num_of_2){
	char NIC[14];
	int account_number;
	int PIN;
	int i,j,k,l,m;
	int check1,check2,check3;
	int checks[14];
	int count=0;
	printf("\nEnter NIC : ");
	for(i=0;i<3;i++){
		for(j=0;j<14;j++){
			scanf("\n%c",&NIC[j]);
		}
		for(j=0;j<num_of_1;j++){
			for(k=0;k<14;k++){
				if(NIC[k]==account_history[j].NIC_r[k]){
					//printf("Correct\n");
					checks[k]=1;
				}
			}
		    if(checks[0]==1&&checks[1]==1&&checks[2]==1&&checks[3]==1&&checks[4]==1&&checks[5]==1&&checks[6]==1&&checks[7]==1&&checks[8]==1&&checks[9]==1&&checks[10]==1&&checks[11]==1&&checks[12]==1&&checks[13]==1){
		    	check1=1;
		    	printf("\n\t\t\t---CORRECT NIC---\n");
		    	printf("\nEnter Account Number : ");
		    	for(k=0;k<3;k++){
		    		scanf("%d",&account_number);
		    		if(account_number==account_history[j].account_number_r){
		    			check2=2;
		    			printf("\n\t\t\t---CORRECT ACCOUNT NUMBER---\n");
		    			printf("\nEnter PIN : ");
		    			for(l=0;l<3;l++){
		    			    scanf("%d",&PIN);
		    			    if(PIN==account_history[j].PIN_r){
		    			    	check3=3;
		    			    	printf("\n\t\t\t---CORRECT PIN---\n");
		    			    	if(num_of_2>0){
		    			    	for(m=0;m<num_of_2;m++){
		    			    		if(account_history[j].account_number_r==account_transactions[m].sender_account_number){
		    			    			printf("\nTransaction Number %d\n",(count+1));
    	                                printf("\nSender Account Number : %d\n",account_transactions[m].sender_account_number);
                                        printf("Amount Transferred : %.2f Rs\n",account_transactions[m].amount);
                                        printf("Reciever's Account Number : %d\n",account_transactions[m].reciever_account_number);
                                        count++;
									}
									if(m==(num_of_2-1) && count==0){
										printf("\nNO TRANSACTION HISTORY!\n");
									}
								}
							}else{
								printf("\nNO TRANSACTION HISTORY!\n");
							}
		    			    	break;
							}
							if(check3==3){
						        break;
					        }else if(check3!=3 && l<2){
					           	printf("\n\t\t\t---INCORRECT PIN---\n");
				        		printf("\nEnter again : ");
					        }
							if(l==2){
						        printf("\n\t\t\t---INCORRECT PIN---\n");
						        exit(0);
					        }
		    		    }
		    		    break;
					}
					if(check2==2){
						break;
					}else if(check2!=2 && k<2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						printf("\nEnter again : ");
					}
					if(k==2){
						printf("\n\t\t\t---INCORRECT ACCOUNT NUMBER---\n");
						exit(0);
					}
				}
				break;
			}
	    }
	    if(check1==1){
	    	break;
		}else if(check1!=1 && i<2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			printf("\nEnter again : ");
		}
		if(i==2){
			printf("\n\t\t\t---INCORRECT NIC---\n");
			exit(0);
		}
	}
}
