#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <time.h>




FILE *fp1, *fp2, *fp3;
char cur_line[255], *token;
time_t cur_time;


void main_menu();

void file_management();

void file_print(FILE *fp, string with_num);

void get_price(float array[]);

string yes_no(string question);

int finals();

int main()
{
    bool running = true;
    while(running)
    {
        main_menu();
        int response = get_int("\nEnter Option Number: ");

        if (response == 1)
        {
            file_management();
        }

        else if (response == 2)
        {
            printf("\n");
            finals();
        }
        else if(response == 3)
        {

        }
        else if (response == 4)
        {

        }
        else if (response == 5)
        {
            string confirm = yes_no("Are you sure you want to quit?");
            if (strcmp(confirm, "y") == 0 )
                running = false;
        }
    }
    printf("\nABC COMPUTER SHOP DAILY SALES REPORT\n\n");
    printf("Prepared by: CABALONA MARK REYES AND SOPHIA DALUMPINES\n\n");
    printf("Date prepared: %s\n", ctime(&cur_time));


    return 0;
}

void main_menu()
{
    printf("\tMAIN MENU\n\n");
    printf("1 File Management\n");
    printf("2 Transaction\n");
    printf("3 Manage Advance Request\n");
    printf("4 Generate Report\n");
    printf("5 Exit\n");
}

void file_management()
{
    string service_name, confirm;
    int service_num;
    float price, new_price[255];

    fp1 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\01SALES_INVENTORY_v2\\sales-inventory\\files\\product_inventory.txt","a");

    printf("1. ADD\n");
    printf("2. EDIT\n");
    printf("3. DELETE\n");
    printf("4. DISPLAY\n");
    int response = get_int("ENTER: ");

    if (response == 1)
    {
        service_name = get_string("Enter Service Name: ");
        price = get_float("Enter Price:");
        confirm = yes_no("Are you sure you want to add another service(Y/N)? ");

        if (strcmp(confirm, "y") == 0)
        {
            fprintf(fp1, "\n%s\t%.2f", service_name, price);//mali 'to
            printf("You've successfully added %s to the service list!\n\n", service_name);
        }
    }
    else if (response == 2)
    {
        file_print(fp1, "with num");
        service_num = get_int("What service you want to edit? ");
        confirm = yes_no("Are you sure you want to edit service's price(Y/N)? ");
        if (strcmp(confirm, "y") == 0)
        {
            get_price(new_price);
           // use dictionary here

            printf("You've successfully edited the price!\n\n");
        }
    }

    fclose(fp1);
}//end of file_management()

void file_print(FILE *fp, string with_num)
{
    int i = 0;
    if (strcmp(with_num, "with num") == 0)
    {
        while (!feof(fp))
        {
            fgets(cur_line, 255, fp);
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
}

void get_price(float array[])
{
    int i = 0;
    fp1 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\01SALES_INVENTORY_v2\\sales-inventory\\files\\product_inventory.txt","r");
    while (!feof(fp1))
    {
        fgets(cur_line, 255, fp1);

        token = strtok(cur_line, "\n\t ");
        while (token != NULL)
        {
            if (atof(token) != 0 )//atof("2.10") = 2.10
            {
                array[i] = atof(token);
                i++;
            }
            token = strtok(NULL, "\n\t ");
        }
    }
    fclose(fp1);
}


int finals()
{
//Declaration / initialization of Variables
    int response;
    float price[255];

    float cost[255] = {0,0,0,0,0};
    float total_cost[255]={0,0,0,0,0};
    float cost_sum = 0;
    int total_count[255]={0,0,0,0,0};
    int count[255];

    cur_time = time(NULL);

    fp1 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\01SALES_INVENTORY_v2\\sales-inventory\\files\\product_inventory.txt","r");
    fp2 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\01SALES_INVENTORY_v2\\sales-inventory\\files\\sales_inventory_report.txt","a");
    fprintf(fp2,"SALES\t\t\t QUANTITY\tSALES AMOUNT\t\tDATE: %s\n", ctime(&cur_time));


    file_print(fp1, "with num");
    get_price(price);
    do
    {
        do{
            response = -1;
            response = get_int("\n\nEnter type of service you wish to avail: ");
            }while(response <=0  || response > 5);

            if (response == 1)
            {
                do{
                    count[0]= -1;
                    count[0] = get_int("How many pages? ");
                }while(count[0] < 0);
                cost[0] = price[0] * count[0];
                total_count[0] += count[0];
                total_cost[0] += cost[0];
                printf("Total Amount to be paid: %.2f\n", cost[0]);
                fprintf(fp2, "Document Printing\t %d\t\t%.2f\n", count[0], cost[0]);
            }
            else if (response == 2)
            {
                 do{
                    count[1]= -1;
                    count[1] = get_int("How many pages? ");
                }while(count[1] < 0);
                cost[1] = price[1] * count[1];
                total_count[1] += count[1];
                total_cost[1] += cost[1];
                printf("Total Amount to be paid: %.2f\n", cost[1]);
                fprintf(fp2, "Image Printing\t\t %d\t\t%.2f\n", count[1], cost[1]);
            }
            else if (response == 3)
            {
                 do{
                    count[2]= -1;
                    count[2] = get_int("How many hours? ");
                }while(count[2] < 0);
                cost[2] = price[2] * count[2];
                total_count[2] += count[2];
                total_cost[2] += cost[2];
                printf("Total Amount to be paid: %.2f\n", cost[2]);
                fprintf(fp2, "Computer Rental\t \t %d\t\t%.2f\n", count[2], cost[2]);
            }
            else if (response == 4)
            {
                do{
                    count[3]= -1;
                    count[3] = get_int("How many pages? ");
                }while(count[3] < 0);
                cost[3] = price[3] * count[3];
                total_count[3] += count[3];
                total_cost[3] += cost[3];
                printf("Total Amount to be paid: %.2f\n", cost[3]);
                fprintf(fp2, "Scanning\t\t %d\t\t%.2f\n", count[3], cost[3]);
            }
            else if (response == 5)
            {
                 do{
                    count[4]= -1;
                    count[4] = get_int("How many pages? ");
                }while(count[4] < 0);
                cost[4] = price[4] * count[4];
                total_count[4] += count[4];
                total_cost[4] += cost[4];
                printf("Total Amount to be paid: %.2f\n", cost[4]);
                fprintf(fp2, "Typing\t\t\t %d\t\t%.2f\n", count[4], cost[4]);

            }

            cost_sum = total_cost[0] + total_cost[1] + total_cost[2] + total_cost[3] + total_cost[4];

        }while(strcmp(yes_no("Another Service (Y/N)? "), "y") == 0 );// end of main do-while loop

    fprintf(fp2,"\n\n");
    printf("\nPrinting you the Sales Report...\n\n");

    fp3 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\01SALES_INVENTORY_v2\\sales-inventory\\files\\sales_record.txt","w");

    fprintf(fp3,"TYPES OF SERVICE\t QUANTITY\tAMOUNT\n\n");
    fprintf(fp3, "Document Printing\t %d\t\t%.2f\n", total_count[0], total_cost[0]);
    fprintf(fp3, "Image Printing\t\t %d\t\t%.2f\n", total_count[1], total_cost[1]);
    fprintf(fp3, "Computer Rental\t \t %d\t\t%.2f\n", total_count[2], total_cost[2]);
    fprintf(fp3, "Scanning\t\t %d\t\t%.2f\n", total_count[3], total_cost[3]);
    fprintf(fp3, "Typing\t\t\t %d\t\t%.2f", total_count[4], total_cost[4]);

    fclose(fp3);

    //opens file 2 (to read)
    fp3 = fopen("C:\\Users\\Benja\\OneDrive\\Desktop\\Mark\\ComputerProgramming1_projects\\01SALES_INVENTORY_v2\\sales-inventory\\files\\sales_record.txt","r");
    if(!fp3)
    {
        printf("Error opening sales_record.txt");
        exit(1);
    }
    else
    {
        file_print(fp3,"");
        printf("\n\nTotal Sales\t\t\t\t%.2f\n", cost_sum);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;// end of main program
}


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
