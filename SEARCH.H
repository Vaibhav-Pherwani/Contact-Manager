void searchby_no()
{
	int found = 0;
	FILE *fp;
	int n;
	textcolor(WHITE);
	clrscr();
	gotoxy(30,1);
	printf("Search by Serial Number\n");
	printf("Enter the serial no.: ");
	scanf("%d",&n);
	fp=fopen("info.dat","r");
	while(fread(&cobj,sizeof(cobj),1,fp)!=NULL)
	{
		if(cobj.sno==n)
		{
			printf("\nCategory: %s",cobj.category);
			printf("\nName    : %s",cobj.name);
			printf("\nGender  : %c",cobj.gender);
			printf("\nAge     : %d",cobj.age);
			printf("\nAddress : %s",cobj.address);
			printf("\nPhone   : %s",cobj.phone);
			found=1;
			break;
		}
	}
	if(found==0)
	{
		textcolor(RED+BLINK);
		cprintf("\nEntry not Found, Press Any Key....");
		fclose(fp);
		getch();
		return;
	}
	fclose(fp);
	printf("\n");
	textcolor(GREEN+BLINK);
	cprintf("Press Any Key.....");
	getch();
}
void searchby_cate()
{
	char cat[15];
	int i;
	FILE *fp;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	printf("Enter Category: ");
	gets(cat);
	gotoxy(34,1);
	printf("List of Contacts");
	printf("\n");
	for(i=1;i<=80;i++)
	{
		printf("-");
	}
	gotoxy(2,3);
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
		if(strcmpi(cat,cobj.category)==0)
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
	}
	fclose(fp);
	textcolor(GREEN+BLINK);
	printf("\n");
	cprintf("Press Any Key......");
	getch();
}
void searchby_name()
{
	char nam[20];
	int i;
	FILE *fp;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(WHITE);
	clrscr();
	printf("Enter Name: ");
	gets(nam);
	gotoxy(34,1);
	printf("List of Contacts");
	printf("\n");
	for(i=1;i<=80;i++)
	{
		printf("-");
	}
	gotoxy(2,3);
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
		if(strcmpi(nam,cobj.name)==0)
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
	}
	fclose(fp);
	textcolor(GREEN+BLINK);
	printf("\n");
	cprintf("Press Any Key......");
	getch();
}

void searchby_gender()
{
	int found = 0;
	char g;
	FILE *fp;
	window(1,1,80,25);
	textcolor(WHITE);
	clrscr();
	gotoxy(30,1);
	printf("Search by Gender\n");
	printf("Enter Gender: ");
	scanf("%c",&g);
	fp=fopen("info.dat","r");
	while(fread(&cobj,sizeof(cobj),1,fp)!=NULL)
	{
		if(cobj.gender==g)
		{
			printf("\nCategory: %s",cobj.category);
			printf("\nName    : %s",cobj.name);
			printf("\nGender  : %c",cobj.gender);
			printf("\nAge     : %d",cobj.age);
			printf("\nAddress : %s",cobj.address);
			printf("\nPhone   : %s",cobj.phone);
			found=1;
			break;
		}
	}
	if(found==0)
	{
		textcolor(RED+BLINK);
		cprintf("\nEntry not Found, Press Any Key....");
		fclose(fp);
		getch();
		return;
	}
	fclose(fp);
	printf("\n");
	textcolor(GREEN+BLINK);
	getch();
}

