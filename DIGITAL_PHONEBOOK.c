#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

struct node
{
	char number[20];
	char name[20];
	char email[50];
	struct node* next;
	struct node* prev;
} *start = NULL;
struct node* current = NULL;
int count = 0;
int calc = 0;

void update(int y)
{
	if (calc == 1)
	{
		printf("\nDeletion is not possible as 1 entry is mandatory in the record \n");
	}
	else
	{
		int i;
		struct node* temp = start;
		struct node* newnode;
		newnode = (struct node*)malloc(1 * sizeof(struct node));
		newnode->next = NULL;
		newnode->prev = NULL;
		struct node* temp1 = start;
		if (start == NULL)
		{
			printf("Underflow !!!!!");
		}
		for (i = 0; i < y - 1 && temp != NULL; i++)
		{
			temp = temp->next;
		}
		if (start == NULL)
		{
			printf("List empty");
		}
		else
		{
			if (y == 1)//position 1
			{
				temp = start;
				start = start->next; // move the next address of starting node to 2 node
				start->prev = NULL;	 // set previous address of staring node is NULL
				free(temp);
				display();
				printf("\nEnter the Phone Number : ");
				scanf("%s", &newnode->number);
				printf("Enter the Name : ");
				scanf("%s", newnode->name);
				printf("Enter the Email : ");
				scanf("%s", newnode->email);
				if (start == NULL)
				{
					start = newnode;
					current = newnode;
				}
				else
				{
					newnode->next = start;
					start->prev = newnode;
					start = newnode;
				}
			}
			else if (y == count)//last position
			{
				temp = current;
				current = current->prev;
				current->next = NULL;
				free(temp);
				display();
				printf("\nEnter the Phone Number : ");
				scanf("%s", &newnode->number);
				printf("Enter the Name : ");
				scanf("%s", &newnode->name);
				printf("Enter the Email : ");
				scanf("%s", &newnode->email);
				if (start == NULL)
				{
					start = newnode;
					current = newnode;
				}
				else
				{
					newnode->prev = current;
					current->next = newnode;
					current = newnode;
				}
			}
			else
			{
				if (y != 0 && y != count + 1)//middle position
				{
					temp1 = temp;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					free(temp1); // remove the extra node
					display();
					printf("\nEnter the Phone Number : ");
					scanf("%s", &newnode->number);
					printf("Enter the Name : ");
					scanf("%s", &newnode->name);
					printf("Enter the Email : ");
					scanf("%s", &newnode->email);

					newnode->prev = current;
					current->next = newnode;
					current = newnode;
				}
			}
		}
	}
}

void end()
{
	int k, s, c;
	char t[] = "THANK YOU FOR USING OUR PHONEBOOK !!";
	for (k = 0; t[k] != '\0'; k++)
	{
		for (s = 0; s < 10000000; s++)
		{
			c = s;
		}
		printf("%c", t[k]);
		// printf("\n");
	}
}

void mainload()
{
	int m, n, b;
	for (m = 0; m <= 170; m++)
	{
		for (n = 0; n < 1000000; n++)
		{
			b = n;
		}
		printf("*");
	}
}

void loading()
{
	int p, q, a;
	printf("\nLoading");
	for (p = 0; p <= 6; p++)
	{
		for (q = 0; q < 10000000; q++)
		{
			a = q;
		}
		printf(".");
	}
	printf("\n");
}

void create()
{
	// have to enter user credentials to start with the code functioniong
	int flg1 = 0, flg2 = 0, temp_flag = 0;
	struct node* newnode;
	newnode = (struct node*)malloc(1 * sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;
	while (flg1 == 0)
	{
		printf("\nEnter the Phone Number : ");
		scanf("%s", &newnode->number);
		if (strlen(newnode->number) > 11 || strlen(newnode->number) < 7)
		{
			printf("\nPlease enter a valid Phone Number\n");
		}
		else
		{
			flg1 = 1;
		}
	}
	printf("Enter the Name : ");
	scanf("%s", newnode->name);
	while (flg2 == 0)
	{

		printf("Enter the Email : ");
		scanf("%s", newnode->email);
		for (int i = 0; newnode->email[i] != '\0'; i++)
		{
			if (newnode->email[i] == '@' || newnode->email[i] == '.')
			{
				temp_flag = 1;
			}
		}
		if (temp_flag != 1)
		{
			printf("Invalid gmail\n");
		}
		else
		{
			flg2 = 1;
		}
	}
	if (start == NULL)
	{
		start = newnode;
		current = newnode;
	}
	else
	{
		newnode->prev = current;
		current->next = newnode;
		current = newnode;
	}
	count++;
	calc++;
}

int data_recovery()
{
	char c;
	FILE* fptr2;
	char s[100];
	printf("\nPlease enter the name of the Phone book file to access its content : ");
	printf("\n(Please give valid file name)");
	printf("\n");
	scanf("%s", s);
	fptr2 = fopen(s, "r");
	if (fptr2 == NULL)
	{
		printf("Error\n");
		exit(-1);
	}
	while ((c = getc(fptr2)) != EOF)
	{
		printf("%c", c);
	}
	printf("\n");
	fclose(fptr2);
}

int display()
{
	struct node* temp;
	temp = start;
	int i = 1;
	FILE* fptr;
	fptr = fopen("PHONEBOOK.txt", "w");
	if (fptr == NULL)
	{
		printf("Error\n");
		exit(-1);
	}
	fprintf(fptr, "\n\t\t\t\t\t\t**PHONE BOOK**\t\t\t\t\t");
	fprintf(fptr, "\n\n");
	do
	{
		printf("\nPhone Number :: +91 %s\n", temp->number);
		printf("Name  :: \t%s\n", temp->name);
		printf("Email :: \t%s\n", temp->email);
		fprintf(fptr, "\n%d)Phone Number  :: +91-%s\n", i, temp->number);
		fprintf(fptr, "  Name  \t:: %s\n", temp->name);
		fprintf(fptr, "  Email \t:: %s\n", temp->email);
		fprintf(fptr, "__________________________________");
		temp = temp->next;
		i++;
	} while (temp != NULL);
	fclose(fptr);
	return 0;
}

void search_num()
{
	struct node* temp, * temp1;
	temp = start;
	temp1 = temp;
	char ele[20];
	int flag = 0;
	printf("Enter the Phone number to search : ");
	scanf("%s", &ele);
	while (temp != NULL)
	{
		for (int i = 0; (ele[i] != '\0' && temp->number[i] != '\0'); i++)
		{
			if (ele[i] == temp->number[i])
			{
				flag = 0;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			printf("\nPhone Number :: +91 %s\n", ele);
			printf("Name :: %s\n", temp->name);
			printf("Email :: %s\n", temp->email);
			break;
		}
		temp1 = temp;
		temp = temp->next;
	}
	if (flag == 1)
	{
		printf("Not found.\n");
	}
}

int search_name()
{
	struct node* temp, * temp1;
	temp = start;
	temp1 = temp;
	char ele[20];
	int flag = 0;
	printf("Enter the name to search : ");
	scanf("%s", &ele);
	while (temp != NULL)
	{
		for (int i = 0; (ele[i] != '\0' && temp->name[i] != '\0'); i++)
		{
			if (ele[i] == temp->name[i])
			{
				flag = 0;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			printf("Phone Number :: +91 %s\n", temp->number);
			printf("Name :: %s\n", temp->name);
			printf("Email :: %s\n", temp->email);
			// break;
		}
		temp1 = temp;
		temp = temp->next;
	}
	if (flag == 1)
	{
		return 1;
	}
	return 0;
}

void search_mail()
{
	struct node* temp, * temp1;
	temp = start;
	temp1 = temp;
	char ele[20];
	int flag = 0;
	printf("Enter the mail id to search : ");
	scanf("%s", &ele);
	while (temp != NULL)
	{
		for (int i = 0; (ele[i] != '\0' && temp->email[i] != '\0'); i++)
		{
			if (ele[i] == temp->email[i])
			{
				flag = 0;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			printf("Phone Number :: +91 %s\n", temp->number);
			printf("Name :: %s\n", temp->name);
			printf("Email :: %s\n", temp->email);
			break;
		}
		temp1 = temp;
		temp = temp->next;
	}
	if (flag == 1)
	{
		printf("Not found.\n");
	}
}

void delete(int x)
{
	if (calc == 1)
	{
		printf("\nDeletion is not possible as 1 entry is mandatory in the record \n");
	}
	else
	{
		int i;
		struct node* temp = start;
		struct node* temp1 = 0;
		if (start == NULL)
		{
			printf("Underflow !!!!!");
		}
		for (i = 1; i < x && temp != NULL; i++)
		{
			temp = temp->next;
		}
		if (start == NULL)
		{
			printf("List empty");
		}
		else
		{
			if (x == 1)
			{
				temp = start;
				start = start->next; // move the next address of starting node to 2 node
				start->prev = NULL;	 // set previous address of staring node is NULL
				free(temp);
				count--;
			}
			else if (x == count)
			{
				temp = current;
				current = current->prev;
				current->next = NULL;
				free(temp);
				count--;
			}
			else
			{
				if (temp != NULL && temp->next != NULL)
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					free(temp); // remove the extra node
					count--;
				}
			}
		}
		calc--;
	}
}

int find_pos()
{
	struct node* temp, * temp1, * temp2;
	temp = start;
	char ele[20];
	int flag = 0, pos = 0, j;
	printf("Enter the number to search : ");
	scanf("%s", &ele);
	while (temp != NULL)
	{
		for (int i = 0; (ele[i] != '\0' && temp->number[i] != '\0'); i++)
		{
			if (ele[i] == temp->number[i])
			{
				flag = 0;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		pos++;
		if (flag != 1)
		{
			printf("Record found at : %d", pos);
			break;
		}
		temp1 = temp;
		temp = temp->next;
	}
	return (pos);
}

void intro()
{
	char r[] = "\n\n\t\t\t\t\t\t\tHELLO USER !!!\n";
	char l[] = "\n\t\t\t\t          ########             ###########\n\t\t\t\t        ####\t#####        #######\n\t\t\t\t      ####     #####      #######\n\t\t\t\t               #####     #######\n\t\t\t\t              #####      #######\n\t\t\t\t            #####        #######      ######\n\t\t\t\t         #####            #######      #####\n\t\t\t\t       ##############       ################\n\t\t\t\t      ###############         ###########";
	char t[] = "\n\n\t\t\t\t ** WELCOME TO YOUR PERSONALISED DIGITAL 2G SPECTRUM PHONE BOOK **";
	char u[] = "\n\t\t\t\t===========================================================";
	char v[] = "\n\n\t\t\t\t\tPLEASE ENTER YOUR CREDENTIALS TO START WITH : \n\n";
	int s, c;
	int i, j, e, f, p, q, k;
	for (j = 0; r[j] != '\0'; j++)
	{
		for (s = 0; s < 10000000; s++)
		{
			c = s;
		}
		printf("%c", r[j]);
		// printf("\n");
	}

	for (p = 0;l[p] != '\0';p++)
	{
		for (q = 0;q < 1000000;q++)
		{
			k = q;
		}
		printf("%c", l[p]);
	}

	for (i = 0; t[i] != '\0'; i++)
	{
		for (s = 0; s < 10000000; s++)
		{
			c = s;
		}
		printf("%c", t[i]);
	}
	for (e = 0; u[e] != '\0'; e++)
	{
		for (s = 0; s < 1000000; s++)
		{
			c = s;
		}
		printf("%c", u[e]);
	}
	for (f = 0; v[f] != '\0'; f++)
	{
		for (s = 0; s < 10000000; s++)
		{
			c = s;
		}
		printf("%c", v[f]);
	}
	create();
}

void main()
{
	int c;
	int need, need2;
	int flag = 1;
	mainload();
	intro();
	do
	{
		printf("\n-------------------------------PHONE BOOK------------------------------\n");
		printf("\n1) Insert the details into the Phone Book\n2) View the details from the Phone Book\n3) Search the person from his Phone Number\n4) Search the person from his Name\n5) Search the person from his Email id\n6) Delete record from the Phone Book\n7) Find the position of record in phone book \n8) To Edit a present record\n9) Data recovery\n10) Exit\n\n");
		printf("Enter the choice: ");
		scanf("%d", &c);
		loading();
		switch (c)
		{
		case 1:
			create();
			break;

		case 2:
			display();
			break;

		case 3:
			search_num();
			break;

		case 4:
			if (search_name() != 0)
				printf("Not found.\n");
			else
				printf("Successful search.\n");
			break;

		case 5:
			search_mail();
			break;

		case 6:
			need = find_pos();
			delete (need);
			break;

		case 7:
			find_pos();
			break;

		case 8:
			need2 = find_pos();
			update(need2);
			break;

		case 9:
			data_recovery();
			break;

		case 10:
			end();
			exit(0);
			break;
		}
	} while (1);

}