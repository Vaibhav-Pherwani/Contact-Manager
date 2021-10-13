#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "search.h"

void main()
{
	void add_contact();
	void list_contact();
	void delete_contact();
	void edit_contact();
	void search_contact();
	void change_password();
	char pass[30],original[30],ch,choice;
	FILE *fp;
	int i;
	window(1,1,80,25);
	textbackground(15);
	clrscr();
	window(20,10,60,15);
	textbackground(BLACK);
	clrscr();
	gotoxy(4,3);
	textcolor(RED+BLINK);
	cprintf("Enter the Password: ");
	i=0;
	textcolor(WHITE);
	while(1)
	{
		ch = getch();
		if(ch==13) 			//ASCII code: Enter key
		{
			pass[i] = '\0';
			break;
		}
		pass[i++] = ch;
		printf("*");
	}
	// Reading data from the file
	fp = fopen("Pass.dat","r");
	fgets(original,30,fp);
	fclose(fp);
	if(!strcmp(original,pass)==0)
	{
		gotoxy(4,5);
		textcolor(WHITE);
		cprintf("Incorrect! Press any key...");
		getch();
		exit(0);
	}
	else
	{
		window(1,1,80,25);
		textbackground(8);
		clrscr();
		gotoxy(32,3);
		textcolor(7);
		cprintf("Contact Manager");
		gotoxy(34,7);
		cprintf("Version 1.0");
		gotoxy(5,15);
		cprintf("Please Wait: ");
		for(i=1;i<=50;i++)
		{
			cprintf("%c",219);
			delay(75);
		}
	while(1)
	{
		textbackground(1);
		clrscr();
		window(18,5,60,22);
		textbackground(BLACK);
		clrscr();
		textcolor(WHITE);
		gotoxy(17,2);
		cprintf("Main Menu");
		gotoxy(1,3);
		cprintf("___________________________________________");
		gotoxy(13,6);
		cprintf("1. Add new Contact");
		gotoxy(13,7);
		cprintf("2. Delete Contact");
		gotoxy(13,8);
		cprintf("3. Edit Contact");
		gotoxy(13,9);
		cprintf("4. List all Contacts");
		gotoxy(13,10);
		cprintf("5. Search Contact");
		gotoxy(13,11);
		cprintf("6. Change Password");
		gotoxy(13,12);
		cprintf("7. Exit");
		gotoxy(1,15);
		cprintf("___________________________________________");
		textcolor(2+BLINK);
		gotoxy(15,16);
		cprintf("Enter Choice!");
	   choice = getch();
	   switch(choice)
	   {
		case '1': add_contact();
				break;
		case '2': delete_contact();
				break;
		case '3': edit_contact();
				break;
		case '4': list_contact();
				break;
		case '5':search_contact();
				break;
		case '6':change_password();
				break;
		case '7': exit(0);
		}
	}
  }getch();
}
void add_contact()
{
	FILE *fp;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	gotoxy(27,2);
	printf("Add new Contact\n");
	printf("________________________________________________________________________________\n");
	printf("Enter serial no.\n");
	scanf("%d",&cobj.sno);
	fflush(stdin);
	printf("Enter Catagory (Casual/Professional): ");
	gets(cobj.category);
	fflush(stdin);
	printf("Enter Name: ");
	gets(cobj.name);
	fflush(stdin);
	printf("Enter gender M/F: ");
	scanf("%c",&cobj.gender);
	fflush(stdin);
	printf("Enter Age: ");
	scanf("%d",&cobj.age);
	fflush(stdin);
	printf("Enter Address: ");
	gets(cobj.address);
	fflush(stdin);
	printf("Enter Phone Number: ");
	gets(cobj.phone);
	fflush(stdin);
	fp = fopen("info.dat","ab");
	fwrite(&cobj,sizeof(cobj),1,fp);
	fclose(fp);
	textcolor(GREEN+BLINK);
	cprintf("\nSuccessfully Saved, Press any Key....");
	getch();
}
void delete_contact()
{
		char choice;
		int n,found;
		FILE *fp1,*fp2;
		window(1,1,80,25);
		textbackground(BLACK);
		textcolor(WHITE);
		clrscr();
		gotoxy(34,1);
		printf("Delete Contact");
		printf("\n_______________________________________________________________________________");
		printf("\nEnter Serial Number to be deleted: ");
		scanf("%d",&n);
		fp1=fopen("info.dat","rb");
		found=0;
		while(fread(&cobj,sizeof(cobj),1,fp1)!=NULL)
		{
			if(cobj.sno==n)
			{
				printf("\nCategory: %s",cobj.category);
				printf("\nName    : %s",cobj.name);
				printf("\nGender  : %c",cobj.gender);
				printf("\nAge     : %d",cobj.age);
				printf("\nAddress : %s",cobj.address);
				printf("\nPhone   : %s",cobj.phone);
				printf("\n--------------------------------");
				found=1;
				break;
			}
		}
		if(found==0)
		{
			textcolor(RED+BLINK);
			printf("\n");
			cprintf("Entry Not Found, Press Any Key......");
			getch();
			fclose(fp1);
			return;
		}
		printf("\nConfirm Delete(Y/N): ");
		choice = getche();
	if(choice=='y'||choice=='Y')
	  {
		rewind(fp1);
		fp2=fopen("temp.dat","wb");
		while(fread(&cobj,sizeof(cobj),1,fp1)!=NULL)
		{
			if(cobj.sno!=n)
				fwrite(&cobj,sizeof(cobj),1,fp2);
		}
		fclose(fp1);
		fclose(fp2);
		remove("info.dat");
		rename("temp.dat","info.dat");
		textcolor(GREEN+BLINK);
		printf("\n");
		cprintf("Element deleted Successfully!, Press Any Key.....");
		getch();
	  }
}
void edit_contact()
{
	int pos,n,found;
	FILE *fp;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	gotoxy(34,1);
	printf("Edit Contact\n");
	printf("________________________________________________________________________________\n");
	printf("Enter Serial Number to be Edited: ");
	scanf("%d",&n);
	fp=fopen("info.dat","r+b");
	found = 0;
	while(fread(&cobj,sizeof(cobj),1,fp)!=NULL)
	{
		if(cobj.sno==n)
		{
			printf("Category: %s\n",cobj.category);
			printf("Name    : %s\n",cobj.name);
			printf("Gender  : %c\n",cobj.gender);
			printf("Age     : %d\n",cobj.age);
			printf("Address : %s\n",cobj.address);
			printf("Phone   : %s\n",cobj.phone);
			found = 1;
			break;
		}
	}
	if(found==0)
	{
		printf("\n");
		textcolor(RED+BLINK);
		cprintf("Entry not Found, Press Any Key....");
		fclose(fp);
		getch();
		return;
	}
	printf("\nEnter New Data\n");
	pos=ftell(fp);
	fseek(fp,pos-sizeof(cobj),SEEK_SET);
	fflush(stdin);
	printf("Enter Catagory (Casual/Professional): ");
	gets(cobj.category);
	fflush(stdin);
	printf("Enter Name: ");
	gets(cobj.name);
	fflush(stdin);
	printf("Enter gender M/F: ");
	scanf("%c",&cobj.gender);
	fflush(stdin);
	printf("Enter Age: ");
	scanf("%d",&cobj.age);
	fflush(stdin);
	printf("Enter Address: ");
	gets(cobj.address);
	fflush(stdin);
	printf("Enter Phone Number: ");
	gets(cobj.phone);
	fflush(stdin);
	fwrite(&cobj,sizeof(cobj),1,fp);
	fclose(fp);
	printf("\n");
	textcolor(GREEN+BLINK);
	cprintf("Entry Updated Successfully!, Press Any Key....");
	getch();
}
void list_contact()
{
	int i;
	FILE *fp;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	gotoxy(34,1);
	printf("List of Contacts");
	printf("\n");
	for(i=1;i<=80;i++)
	{
		printf("-");
	}
	gotoxy(1,3);
	printf("SNO");
	gotoxy(8,3);
	printf("Category");
	gotoxy(20,3);
	printf("Name");
	gotoxy(36,3);
	printf("Gender");
	gotoxy(46,3);
	printf("Age");
	gotoxy(55,3);
	printf("Address");
	gotoxy(70,3);
	printf("Phone No.");
	printf("\n");
	for(i=1;i<=80;i++)
	{
		printf("-");
	}
	fp = fopen("info.dat","rb");
	i =5;
	while(fread(&cobj,sizeof(cobj),1,fp)!=NULL)
	{
		gotoxy(1,i);
		printf("%d",cobj.sno);
		gotoxy(8,i);
		printf("%s",cobj.category);
		gotoxy(20,i);
		printf("%s",cobj.name);
		gotoxy(36,i);
		printf("%c",cobj.gender);
		gotoxy(46,i);
		printf("%d",cobj.age);
		gotoxy(55,i);
		printf("%s",cobj.address);
		gotoxy(70,i);
		printf("%s",cobj.phone);
		i++;
	}
	fclose(fp);
	textcolor(GREEN+BLINK);
	printf("\n");
	cprintf("Press Any Key......");
	getch();
}
void search_contact()
{
	char ch;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	gotoxy(34,1);
	printf("Search Options\n");
	printf("________________________________________________________________________________\n");
	printf("1. Search by Serial No.\n");
	printf("2. Search by Category\n");
	printf("3. Search by Name\n");
	printf("4. Search by Gender\n");
	printf("5. Press to Return");
	textcolor(GREEN+BLINK);
	printf("\n");
	cprintf("Enter choice!");
	ch=getche();
	switch(ch)
	{
		case '1': searchby_no();
				break;
		case '2': searchby_cate();
				break;
		case '3': searchby_name();
				break;
		case '4': searchby_gender();
				break;
		case '5': return;
	}
}
void change_password()
{
	FILE *fp;
	char currentpass[30],original[30],newpass[30],confirm[30];
	window(1,1,80,25);
	textcolor(WHITE);
	clrscr();
	gotoxy(32,1);
	printf("Change Password\n");
	printf("Enter Current Password: ");
	gets(currentpass);
	fp=fopen("pass.dat","r");
	fgets(original,30,fp);
	fclose(fp);
	if(strcmp(currentpass,original)!=0)
	{
		textcolor(RED+BLINK);
		cprintf("Incorrect Password, Press Any Key.....");
		getch();
		return;
	}
	printf("Enter New Password: ");
	gets(newpass);
	printf("Re-Enter Password: ");
	gets(confirm);
	if(strcmp(confirm,newpass)!=0)
	{
		textcolor(RED+BLINK);
		cprintf("Passwords Match Failed!, Press Any Key....");
		getch();
		return;
	}
	fp=fopen("pass.dat","w");
	fprintf(fp,"%s",newpass);
	fclose(fp);
	textcolor(GREEN+BLINK);
	cprintf("Password Updated Successfully, Press Any Key...");
	getch();
}
