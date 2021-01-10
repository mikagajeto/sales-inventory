#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

FILE *fp1, *fp2, *fp3;

typedef struct
{
    string name;
    float price;

}service_type;

// GENERAL FUNCTIONS
bool password();

void main_menu();

string yes_no(string question);

int get_nameAndPrice(FILE *fp, service_type array[]);

void file_print(FILE *fp, string with_num);

// FILE MANAGEMENT FUNCTIONS
int add_service(int num_of_services, service_type array[]);

int edit_price(int num_of_services, service_type array[]);

int delete_service(int number_of_services, service_type array[]);

// TRANSACTION FUNCTIONS


int main(void)
{
    string user_password = "Password1234";

    fp1 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\sales_inv_VOLUME_2\\files\\product_inventory.txt","r");

    service_type service[255];
    bool running = true;
    int menu_opt;
    string confirm;

    if(!fp1)
    {
        printf("ERROR OPENING FILE");
        exit(1);
    }
    else
    {
        // store names and prices in service.name and service.price from file 1
        int num_of_services = get_nameAndPrice(fp1 ,service);

        while (running)
        {
            main_menu(); // file management, transaction, advanced service, generate report, exit
            do{ // get menu_opt (menu options)
                menu_opt = get_int("enter: ");
            }while (menu_opt <= 0 || menu_opt > 5); // end of menu_opt
            printf("\n\n********************************************\n");


            if (menu_opt == 1) // FILE MANAGEMENT
            {

                if(1==1)//password(user_password) == true)
                {
                    int fm_opt;
                    printf("\t FILE MANAGEMENT\n\n");
                    printf("1 ADD SERVICE\n");
                    printf("2 EDIT PRICE\n");
                    printf("3 DELETE SERVICE\n");
                    printf("4 DISPLAY SERVICE LIST\n");
                    printf("\n");
                    do{ // get fm_opt (file management options)
                        fm_opt = get_int("What do you want to do (enter corresponding number)? ");
                    }while(fm_opt <= 0 || fm_opt > 4); // end of fm_opt


                    if (fm_opt == 1) // ADD SERVICE
                    {
                        printf("\n\n********************************************\n");
                        num_of_services = add_service(num_of_services, service);
                        printf("\n********************************************\n");
                    } // end of add service


                    else if (fm_opt == 2) // EDIT PRICE
                    {
                        printf("\n\n********************************************\n");
                        num_of_services = edit_price(num_of_services, service);
                        printf("\n********************************************\n");
                    } //end of edit price


                    else if (fm_opt == 3) // DELETE SERVICE
                    {
                        printf("\n\n********************************************\n");
                        num_of_services = delete_service(num_of_services, service);
                        printf("\n********************************************\n");
                    } // end of delete service


                    else if (fm_opt == 4) // DISPLAY SERVICE LIST
                    {
                        printf("\n");
                        fp1 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\sales_inv_VOLUME_2\\files\\product_inventory.txt","r");
                        file_print(fp1, "");
                        fclose(fp1);
                        printf("\n\n********************************************\n");
                    } //end of display service list


                }// end of password
                else
                    running = false;

                //print service.name and service.price in file 1int num_of_space = 0;
                fp1 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\sales_inv_VOLUME_2\\files\\product_inventory.txt","w");
                fprintf(fp1, "Services\t\t\tPrices");
                for (int i = 0; i < num_of_services; i++)
                {
                    if (strlen(service[i].name) <= 7)
                        fprintf(fp1, "\n%s\t\t\t\t%.2f", service[i].name, service[i].price);
                    if (strlen(service[i].name) <= 15 && strlen(service[i].name) > 7)
                        fprintf(fp1, "\n%s\t\t\t%.2f", service[i].name, service[i].price);
                    else if (strlen(service[i].name) <= 23 && strlen(service[i].name) > 15)
                        fprintf(fp1, "\n%s\t\t%.2f", service[i].name, service[i].price);
                    else if (strlen(service[i].name) > 23 )
                        fprintf(fp1, "\n%s\t%.2f", service[i].name, service[i].price);
                }//end of main for loop
                fclose(fp1);

                for(int i = 0; i < num_of_services; i++)
                {
                    printf("\n%d %s\t\t%.2f\n", num_of_services, service[i].name, service[i].price);
                }

            } // end of file management


            else if (menu_opt == 2) // transaction
            {

            } // end of transaction


            else if (menu_opt == 3) // ADVANCE SERVICE
            {

            } // end of advance service


            else if (menu_opt == 4) // GENERATE REPORT
            {

            } // end of generate report


            else if (menu_opt == 5) // EXIT
            {
                confirm = yes_no("Are you sure you want to quit (Y/N)?");
                if (strcmp(confirm, "y") == 0)
                    running = false;
            } // end of exit


        }//end of while(running)//


    }// end of else(1st)


}//end of main program


// GENERAL FUNCTIONS
bool password(string pw)
{
    int i = 1;
    string input_pw;

    while (i < 4)
    {
        input_pw = get_string("Enter Password: ");
        if(strcmp(input_pw,pw) == 0)
            return true;

        else
            printf("Password is incorrect! %d trial/s remaining.\n", 3-i);

        i++;
    }
    return false;
}

void main_menu() //main menu printer
{
    printf("\tMAIN MENU\n\n");
    printf("1 File Management\n");
    printf("2 Transaction\n");
    printf("3 Manage Advance Request\n");
    printf("4 Generate Report\n");
    printf("5 Exit\n");
}//end of main menu

string yes_no(string question)
{
    string response;

    while(true) // this asks user for another transaction and note that this only accepts "y" or "n" as answer
    {
        response = get_string("\n%s", question);//
        for (int i = 0; i < strlen(response); i++) //this loop converts every single char in the str_response to lowercase
        {
            response[i] = tolower(response[i]); //response = "HELLO" --> response = "hello"
        }
        if (strcmp(response, "n") == 0 || (strcmp(response, "y") == 0 ))
        {
            return response;
        }
    }
}

int get_nameAndPrice(FILE *fp, service_type array[])
{
    char cur_line[255], *token;
    int i = 0;

    while(!feof(fp))
    {
        fgets(cur_line, sizeof(cur_line), fp);
        if(i == 0)
        {
            i++;
        }
        else
        {
            token = strtok(cur_line, "\t\n");
            while (token != NULL)
            {
                if(atof(token) != 0)
                {
                    array[i-1].price = atof(token);
                    token = strtok(NULL, "\t\n");
                }

                else
                {
                    array[i-1].name = strdup(token);
                    token = strtok(NULL, "\t\n");
                }

            }
            i++;
        }
    }
    return i-1;
}

void file_print(FILE *fp, string with_num)
{
    int i = 0;
    char cur_line[255];
    if (strcmp(with_num, "with num") == 0)
    {
        while (!feof(fp))
        {
            fgets(cur_line, sizeof(cur_line), fp);
            if (i != 0)
                printf("%d %s", i, cur_line);
            i++;
        }
    }
    else
    {
        while (!feof(fp))
        {
            fgets(cur_line, 255, fp);
            printf("%s", cur_line);
        }
    }
}// end of file_print


// FILE MANAGEMENT FUNCTIONS
int add_service(int num_of_services, service_type array[])
{
    printf("\t ADD SERVICE\n");
    fp1 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\sales_inv_VOLUME_2\\files\\product_inventory.txt","a");
        // NAME
    string add_name = get_string("Enter name of service: ");
    // PRICE
    float add_price;
    do{
        add_price = get_float("Enter price of %s: ", add_name);
    }while (add_price < 0);
    // CONFIRMATION (check if add_name is already on the servicelist)
    bool not_existing = true;

    for (int i = 0; i < num_of_services; i++)
    {
        if (strcmp(add_name, array[i].name) == 0)
        {
            not_existing = false;
            printf("%s is already on the service list!",add_name);
            if(strcmp(yes_no("Do you want to edit its price? (Y/N)"),"y") == 0)
            {
                edit_price(num_of_services, array);
            }
        }
    }
    if (not_existing)
    {
        string confirm = yes_no("Are you sure you want to add another service (Y/N)? ");
        if(strcmp(confirm,"y") == 0)
        {
            num_of_services++;
            array[num_of_services-1].name = add_name;
            array[num_of_services-1].price = add_price;
        }
    }
    return num_of_services;
}// end of add service

int edit_price(int num_of_services, service_type array[])
{
    fp1 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\sales_inv_VOLUME_2\\files\\product_inventory.txt","a");

    printf("\tEDIT PRICE\n");
    // name of service
    string name = get_string("Enter name of service you want to change price: ");
    // new price
    float new_price;
    do{
        new_price = get_float("Enter price for %s: ", name);
    }while (new_price < 0);
    //check if it is in service list
    bool not_existing = true;
    for (int i = 0; i < num_of_services; i++)
    {
        if (strcmp(name, array[i].name) == 0)// if true as for confirmation
        {
            if (strcmp(yes_no("Are you sure you want to change its price (Y/N)? "),"y") == 0)
            {
                array[i].price = new_price;
                not_existing = false;
                i = num_of_services;
            }
        }
    }
    if (not_existing)
    {
        printf("%s is not on the service list!", name);
        if (strcmp(yes_no("Do you want to add it on the service list(Y/N)? "),"y") == 0 )
        {
            num_of_services = add_service(num_of_services, array);
        }
    }
    return num_of_services;
}// end of edit price

int delete_service(int number_of_services, service_type array[])
{
    printf("\tDELETE SERVICE\n");
    int n_services;
    // name of service to be deleted
    string name_del = get_string("Enter the service's name you want to be deleted: ");

    //check if service type is on the list
    bool not_existing = true;
    int j;
    for (int i = 0; i < number_of_services; i++)
    {
        if (strcmp(name_del, array[i].name) == 0)
        {
            not_existing = false;
            j = i; //store index of name_del to j
            i = number_of_services; // end loop
        }
    }
    if (!not_existing) // if not_existing is false;
    {
        //ask confirmation
        if(strcmp(yes_no("Are you sure you want to delete it from service list(Y/N)? "), "y") == 0)
        {
            n_services = number_of_services - 1; //decrement num_of_service by 1
            int i = 0, k =0;
            while(k < n_services)
            {
                if (i == j)
                    i++;

                else
                {
                    array[k].name = array[i].name;
                    array[k].price = array[i].price;
                    k++;
                    i++;
                }

            }
        }
        else
        {
            n_services = number_of_services;
        }
    }

    if (not_existing)
    {
        printf("%s is not on the service list. You can't delete %s\n", name_del, name_del);
        n_services = number_of_services;
    }
    return n_services;
}// end of delete services

// TRANSACTION FUNCTIONS


