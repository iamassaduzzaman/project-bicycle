#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for user profile
typedef struct UserProfile
{
  char name[10];
  int id;
  int cycle_taken;
  int pass;
  struct UserProfile *next;
} node;

// gobal user node declaration
node *default_user;

// some glabal variable
int total_cycle_we_have = 50;
int on_field = 0;
int one_time = 1;

// function prototype
void about_project();
void log_in();
void create_account();
void navigate(int ID);
void user_profile(int ID);
void cycle_availibility(int ID);
void cycle_on_field(int ID);
void rent_a_cycle(int ID);
void return_a_cycle(int ID);

// default user information
void demo_user()
{
  strcpy(default_user->name, "Tushar");
  default_user->id = 9999;
  default_user->pass = 9999;
  default_user->cycle_taken = 0;
  default_user->next = NULL;
}

int main()
{
  if (one_time)
  {
    default_user = (node *)malloc(sizeof(node)); // memory allocation for default user
    demo_user();                                 // initialization of default user
  }
  one_time = 0;

  printf("\n---------------- Welcome to Daffodil Bicycle for Green Campus! ----------------\n\n");
  printf("\t\t[1] Log in\n");
  printf("\t\t[2] Create new account\n");
  printf("\t\t[3] Exit\n");
  printf("\t\t[4] About Project and Updates\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  // log in
  case 1:
    log_in();
    break;

  // create new account
  case 2:
    create_account();
    break;

  // exit program
  case 3:
    exit(0);
    break;

  // about us
  case 4:
    about_project();
    break;
  }

  return 0;
}

// aboutProject funtion defination
void about_project()
{
  printf("\n\n");
  FILE *fp = NULL;
  char ch;
  fp = fopen("text.txt", "r");
  while (!feof(fp))
  {
    ch = fgetc(fp);
    printf("%c", ch);
  }

  fclose(fp);

  printf("\n\n-----------------------------------------------------\n");
  printf("\t\t[1] Home\n");
  printf("\t\t[2] Exit\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  if (choice == 1)
  {
    main();
  }
  else
  {
    exit(0);
  }
}

// login
void log_in()
{
  int ID, PASS;
  printf("ID: ");
  scanf("%d", &ID);
  printf("Password: ");
  scanf("%d", &PASS);

  node *temp = default_user;
  int flag = 0;
  char user[10];
  while (temp != NULL)
  {
    if (temp->id == ID && temp->pass == PASS)
    {
      strcpy(user, temp->name);
      flag = 1;
      break;
    }
    temp = temp->next;
  }

  if (flag)
  {
    printf("\n----------------- hello %s! -----------------------\n", user);
    navigate(ID);
  }
  else
  {
    printf("\n\t\tOpps! Wrong credentails.\t\t\n\n");
    printf("\t\t[1] Log in again\n");
    printf("\t\t[2] Home\t\t\n");
    printf("\t\t[3] Exit\t\t\n");

    int choice;
    printf("Your Choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
      log_in();
    }
    else if (choice == 2)
    {
      main();
    }
    else
    {
      exit(0);
    }
  }
}

// new account
void create_account()
{
  char your_name[10];
  int your_id, your_pass;
  printf("\nYour Name: ");
  scanf("%s", &your_name);
  getchar();
  printf("Your ID: ");
  scanf("%d", &your_id);
  printf("Your Password: ");
  scanf("%d", &your_pass);

  node *newNode = malloc(sizeof(node));
  strcpy(newNode->name, your_name);
  newNode->id = your_id;
  newNode->pass = your_pass;
  newNode->cycle_taken = 0;
  newNode->next = NULL;

  node *temp = default_user;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;

  printf("Yayyyyyy!!! you have been successfully registered :)\n");
  printf("-----------------------------------------------------\n");
  printf("\t\t[1] Log In\n");
  printf("\t\t[2] Exit\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  if (choice == 1)
  {
    log_in();
  }
  else
  {
    exit(0);
  }
}

// navigate
void navigate(int ID)
{
  printf("\n");
  printf("\t\t[1] Your Profile\t\t\n");
  printf("\t\t[2] Check Cycle Availability\t\t\n");
  printf("\t\t[3] Cycle on Field\t\t\n");
  printf("\t\t[4] Rent a Cycle\t\t\n");
  printf("\t\t[5] Return a Cycle\t\t\n");
  printf("\t\t[6] Exit\t\t\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    user_profile(ID);
    break;

  case 2:
    cycle_availibility(ID);
    break;

  case 3:
    cycle_on_field(ID);
    break;

  case 4:
    rent_a_cycle(ID);
    break;

  case 5:
    return_a_cycle(ID);
    break;

  case 6:
    exit(0);
    break;
  }
}

// user profile
void user_profile(int ID)
{
  node *temp = default_user;
  while (temp != NULL)
  {

    if (temp->id == ID)
    {
      printf("\nYour Name: %s\n", temp->name);
      printf("Your ID: %d\n", temp->id);
      if (temp->cycle_taken == 1)
      {
        printf("Cycle Taken: YES\n");
      }
      else
      {
        printf("Cycle Taken: NO\n");
      }
      break;
    }
    temp = temp->next;
  }

  printf("-----------------------------------------------------\n");
  printf("\t\t[1] Navigate\n");
  printf("\t\t[2] Log Out\n");
  printf("\t\t[3] Exit\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  if (choice == 1)
  {
    navigate(ID);
  }
  else if (choice == 2)
  {
    printf("Sorry to see you go! see you later.\n");
    main();
  }
  else
  {
    exit(0);
  }
}

// cycle availibility check
void cycle_availibility(int ID)
{
  printf("Total Cycle Available: %d\n", total_cycle_we_have);
  printf("-----------------------------------------------------\n");
  printf("\t\t[1] Navigate\n");
  printf("\t\t[2] Log Out\n");
  printf("\t\t[3] Exit\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  if (choice == 1)
  {
    navigate(ID);
  }
  else if (choice == 2)
  {
    printf("Sorry to see you go! see you later.\n");
    main();
  }
  else
  {
    exit(0);
  }
}

// cycle on field
void cycle_on_field(int ID)
{
  printf("Total Cycle On Field: %d\n", on_field);
  printf("-----------------------------------------------------\n");
  printf("\t\t[1] Navigate\n");
  printf("\t\t[2] Log Out\n");
  printf("\t\t[3] Exit\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  if (choice == 1)
  {
    navigate(ID);
  }
  else if (choice == 2)
  {
    printf("Sorry to see you go! see you later.\n");
    main();
  }
  else
  {
    exit(0);
  }
}

// rent a cycle
void rent_a_cycle(int ID)
{
  total_cycle_we_have--;
  on_field++;
  node *temp = default_user;
  while (temp != NULL)
  {
    if (temp->id == ID)
    {
      temp->cycle_taken = 1;
      break;
    }
    temp = temp->next;
  }

  printf("-----------------------------------------------------\n");
  printf("\t\t[1] Navigate\n");
  printf("\t\t[2] Log Out\n");
  printf("\t\t[3] Exit\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  if (choice == 1)
  {
    navigate(ID);
  }
  else if (choice == 2)
  {
    printf("Sorry to see you go! see you later.\n");
    main();
  }
  else
  {
    exit(0);
  }
}

// return cycle
void return_a_cycle(int ID)
{
  total_cycle_we_have++;
  on_field--;
  node *temp = default_user;
  while (temp != NULL)
  {
    if (temp->id == ID)
    {
      temp->cycle_taken = 0;
      break;
    }
    temp = temp->next;
  }

  printf("-----------------------------------------------------\n");
  printf("\t\t[1] Navigate\n");
  printf("\t\t[2] Log Out\n");
  printf("\t\t[3] Exit\n");

  int choice;
  printf("Your Choice: ");
  scanf("%d", &choice);

  if (choice == 1)
  {
    navigate(ID);
  }
  else if (choice == 2)
  {
    printf("Sorry to see you go! see you later.\n");
    main();
  }
  else
  {
    exit(0);
  }
}
