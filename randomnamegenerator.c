#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Program Author: Than Aung Naing
*/


void line();

int main(void)
{
  char gender;
  int invalid_gender = 0;
  char genderstring[20];
  int gender_number;
  char *boynames[]= { "Kyaw", "Aung", "Htet","Min",
                      "Hla", "Win", "Myo", "Ko",
                      "Soe", "Naing", "Tun","Thura", "Lwin", "Moe", "Maung",
                      "Ye","Thu", "Phyo", "Thant", "Wai", "Hein","Nay", "Saw",
                      "Htet", "Zin","Myint", "Oo", "Khant"
                      , "Zaw", "Thet", "Sai", "Soe", "Han","San", "Thaw", "Myat"
                      , "Kaung", "Sithu", "Yan", "Htoo", "Sone", "Pyae", "Lin", "Paing"
                      , "Htay", "Than"
                    };

  char *girlnames[]= { "Aye", "Khin", "Thazin","Hnin",
                       "Su", "Nwe", "Thiri", "May", "Ei",
                       "Myat", "Phyu", "Yin","Mya", "Chaw",
                       "Pwint","Zin", "Zaw", "Shwe", "Wai", "Moe","Hsu", "Hsu",
                       "Wint", "Sandar", "Hlaing", "Yu", "Yoon", "Thwe", "Htay"
                       , "Bhone","Hnin", "Khaing", "Pyae", "Thae", "Mon",
                       "Nyein", "Chan", "Phoo", "Yati", "Oo"
                       , "Wati", "Kyi", "Yu", "Saung"
                     };

  srand(time(NULL));
  int arraysizeboys = sizeof(boynames) / sizeof(boynames[0]);
  int arraysizegirls = sizeof(girlnames) / sizeof(girlnames[0]);
  int arraysize;
  int timesCounter = 0;
  int namelength = 0;
  int times = 1;
  char username[100];

  FILE *username_file = fopen ("username.txt", "r");

  if (username_file == NULL)
    {

      do
        {
          printf("What's your name ? : ");
          fgets(username, sizeof(username), stdin);

          if (strlen(username)<=4)
            {
              printf("Name is too short !\n\n");
            }
        }
      while (strlen(username)<=4);

      username_file = fopen ("username.txt", "w");
      fprintf(username_file, username);

      fclose (username_file);
    }

  else
    {
      fgets(username, sizeof(username), username_file);
      fclose (username_file);
    }

  printf("Hello, %s", username);
  printf("\n");
  printf("Welcome to random name generator!\n");
  printf("Program author: Than Aung Naing\n");
  line();

  char user_name [5][50];
  int length;
  char full_username [200];
  char edit;

  printf("Wanna change your name ? (Y/N) : ");
  scanf("%c", &edit);

  if (edit == 'Y' || edit == 'y')
    {

      do
        {

          printf("Length of your name: ");
          scanf("%d", &length);

          for (int j = 1; j<=length; j++)
            {

              if (length == j)
                {
                  printf("Enter new name : ");
                  for (int i = 0; i<length; i++)
                    {
                      scanf("%s", user_name[i]);
                    }
                }

            }

          for (int i = 0; i<length; i++)
            {
              strcat(full_username, user_name[i]);
              strcat(full_username, " ");
            }

          if (strlen(full_username)<=4)
            {
              printf("Name is too short!\n\n");
            }
        }
      while (strlen(full_username)<=4);

      username_file = fopen ("username.txt", "w");
      fprintf(username_file, full_username);

      fclose (username_file);

      printf("Name has been changed successfully !\n", full_username);
      line();
      printf("Hello, %sagain !", full_username);
      printf("\n");
      line();
    }
  else
    {
      printf("Name hasn\'t been changed!\n");
      line ();
    }


  do
    {

      printf("Enter gender (B = boy / G = girl) : ");
      scanf(" %c", &gender);

      if (gender == 'g'|| gender == 'G'|| gender == 'b' || gender == 'B'){
        invalid_gender = 0;
      }
      else {
        invalid_gender = 1;
        printf("Enter correct gender, please!\n");
      }

    } while (invalid_gender == 1);


  if (gender == 'b' || gender == 'B')
    {
      gender_number = 0;
      arraysize = arraysizeboys;
      strcpy(genderstring, "boys");

    }

  else if (gender == 'g' || gender == 'G')
    {
      gender_number = 1;
      arraysize = arraysizegirls;
      strcpy(genderstring, "girls");
    }

  while (times)
    {
      if (timesCounter == 0)
        {

          printf("Random names will be generated for %s!\n\n", genderstring);
          line();

        }

      int randNum[4];
      char result[4][20];
      int namewords;
      char names[1000][80];
      int numberName;
      char space[10] = " ";
      char fullname[300];
      int invalid = 0;

      do
        {
          invalid = 0;

          printf("How many names do you want (1 - 1000)? : ");
          scanf("%d", &numberName);

          printf("Length of the names (1 - 4) : ");
          scanf("%d", &namewords);

          if (numberName>1000 || numberName<1)
            {
              printf("\nNumbers of names should be between 1 and 1000!\n");
            }

          printf("\n");

          if (namewords<1 || namewords>4)
            {
              printf("Length of the names should be between 1 and 4!\n\n");
            }

          if (namewords<1 || namewords>4 || numberName>1000 || numberName<1)
            {
              invalid = 1;
            }

        }
      while (invalid == 1);

      for (int l = 0; l<=numberName; l++)
        {
          char fullname[300] = " ";

          for (int i=0; i<namewords; i++)
            {

              randNum[i] = rand() % arraysize;

            }


          for (int j = 0; j < namewords; j++)
            {
              for (int i = 0; i<arraysize; i++)
                {

                  if (randNum[j] == i)
                    {
                      if (gender_number == 0) strcpy(result[j], boynames[i]);
                      else if (gender_number == 1) strcpy(result[j], girlnames[i]);
                    }
                }
            }


          for (int i = 1; i<=4; i++)
            {

              if (namewords == i)
                {
                  namelength = i-1;
                }

            }

          for(int i=0; i<=namelength; i++)
            {

              strcat(fullname, result[i]);
              strcat(fullname, space);

            }

          strcpy(names[l], fullname);

        }

      // Print the results to the screen

      if(numberName == 1) printf("\n%d random name is generated successfully !\n\n", numberName);
      else if(numberName>1) printf("\n%d random names are generated successfully !\n\n", numberName);


      for (int i = 0; i< numberName; i++)
        {
          printf("%2d %s\n", i+1, names[i]);
        }

      printf("\n");
      line();

      timesCounter++;
    }


  return 0;
}

void line()
{
  for (int i = 1; i<=20; i++)
    {
      printf("**");
    }
  printf("\n\n");
}
