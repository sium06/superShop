#include<stdio.h>
#include<conio.h>          //getch()
#include<windows.h>
#include<string.h>          //strcmp()

//list of function prototype
void Password(void);
void mainmenu(void);
void searchproduct(void);
void addproduct(void);
void sellproduct(void);
void stockproduct(void);
void closeapplication(void);

FILE *fp_pass, *fp_pro, *fp_temp;  //list of files

struct product
{
    int pieces;
    int code[3];
    char name[10];
    double price;
};
struct product a;

int main()
{
    Password();

    return 0;
}

void Password(void)  //for password option
{
    int j;
    char d[25] = " Password Protected";

    printf("\n\t");
    for(j = 0; j < 20; j++){
        printf("*");
        Sleep(20);
    }
    for(j = 0; j < 20; j++){
        printf("%c", d[j]);
        Sleep(200);
    }
    for(j = 0; j < 20; j++){
        printf("*");
        Sleep(20);
    }

    int i= 0, z = 0, count = 0;
    int len;
	char pass[10];

    fp_pass = fopen("PASS.txt","r");

    fscanf(fp_pass, " %[^\n]", pass);

	len = strlen(pass);

    printf("\nEnter Password:");

    char passs[10];

    for(i = 0; i < len; i++){
    	passs[i] = getch();
    	printf("*");
	}
    for(i = 0; i < len; i++){
    	if(passs[i]==pass[z]){
    		count++;
		}
		z++;
	}
	if(count==len){
        printf("\nPassword match");
        printf("\nPress any key to continue.....");
        getch();
        int a;
        for(a = 0; a < 16; a++){
            printf("\n");
        }
        mainmenu();
	}
	else{
        printf("\n\aWarning!! Incorrect Password");

        printf("\n\nForget Password?(Y/N)");
        if(getch()=='y'){

            char temp[10];

            fp_pass = fopen("PASS.txt","w");

            printf("\n\n Enter new password: ");
            scanf(" %[^\n]", temp);

            printf("\nPassword is successfully saved");

            fprintf(fp_pass,"%s\n", temp);
        }
        else{
            Password();
        }
	}
    fclose(fp_pass);
}

void mainmenu(void)  //for menu function
{
    printf(" \n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 The Supper Shop");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\xB2 1. Search product\n");
    printf("\t\t\xB2 2. Add product \n");
    printf("\t\t\xB2 3. Sell product \n");
    printf("\t\t\xB2 4. Stock product \n");
    printf("\t\t\xB2 5. Close Application \n");
    printf("\t\t-----------------------------------------------");
    printf("\n\n\nEnter your choice:\n\n");

    switch (getch())
    {
        case '1':{
            searchproduct();
            break;
        }
        case '2':{
            addproduct();
            break;
        }
        case '3':{
            sellproduct();
            break;
        }
        case '4':{
            stockproduct();
            break;
        }
        case '5':{
            printf("\nExiting in few second...........>");
            exit(0);
        }
        default:{
            printf("\n\aWrong Entry!! Please re-entered correct option");
            if(getch()){
                int a;
                for(a = 0; a < 16; a++){
                    printf("\n");
                }
                mainmenu();
            }
        }
    }
}

void searchproduct()  //function that search product
{
    printf("\n\t************************** Search Product **************************");

    printf("\n\n 1. Search By Product Code");
    printf("\n\n 2. Search By Product Name");
    printf("\n\nEnter Your Choice");

    switch(getch())
    {
        case '1':{
            int c[3];
            int count = 0;

            printf("\n**** Search Product By Code ****");

            printf("\n\nEnter the product Code:");
            scanf("%s", &c);

            printf("\n\nSearching.....");

            fp_pro = fopen("product.txt", "r");

            while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
                if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
                    printf("\n\nThe Product is available");
                    printf("\n Total Pieces/kg: %d", a.pieces);
                    printf("\n Code: %s", a.code);
                    printf("\n Name: %s", a.name);
                    printf("\n Price: %0.2lfTK.", a.price);

                    count++;

                    fclose(fp_pro);
                }
            }
            if(count == 0){
                printf("\n\aNo Product Found");
            }
            printf("\n\nTry another search?(Y/N)");
            if(getch()=='y'){
                searchproduct();
            }
            else{
                int a;
                for(a = 0; a < 16; a++){
                    printf("\n");
                }
                mainmenu();
                break;
            }
        }
        case '2':{
            char n[10];
            int count = 0;

            printf("\n**** Search Product By Name ****");

            printf("\n\nEnter Product Name:");
            scanf("%s", n);

            printf("\n\nSearching.....");

            fp_pro = fopen("product.txt", "r");

            while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
                if(strcmp(a.name,(n))==0){  //checks whether a.name is equal to n or not
                    printf("\n\nThe Product is available");
                    printf("\n Total Pieces/kg: %d", a.pieces);
                    printf("\n Code: %s", a.code);
                    printf("\n Name: %s", a.name);
                    printf("\n Price: %0.2lfTK.", a.price);

                    count++;

                    fclose(fp_pro);
                }
            }
            if(count == 0){
                printf("\n\aNo Product Found");
            }
            printf("\n\nTry another search?(Y/N)");
            if(getch()=='y'){
                searchproduct();
            }
            else{
                int a;
                for(a = 0; a < 16; a++){
                    printf("\n");
                }
                mainmenu();
                break;
            }
        }
        default:{
            printf("\n\aWrong Entry!! Please re-entered correct option");
            if(getch()){
                searchproduct();
            }
        }
    }
}

void addproduct(void)  //function that add product
{
    int i;

    printf("\nSELECT CATEGOIES");
    printf("\n 1. Cosmetic");
    printf("\n 2. Confectionary");
    printf("\n 3. Oil");
    printf("\n 4. Rice");
    printf("\n 5. Fish");
    printf("\n 6. Flesh");
    printf("\n 7. Vegetable");
    printf("\n 8. Spice");
    printf("\n 9. Back to main menu");

    printf("\nEnter your choice:");
    scanf("%d", &i);

    if(i == 9){
        int a;
        for(a = 0; a < 16; a++){
            printf("\n");
        }
        mainmenu();
    }

    int c[3];
    int p, s;
    double pr;

    printf("\nAdd Previous Item or Add New Item?(P/N):");

    if(getch()=='p'){
        printf("\nEnter Product Code: ");
        scanf("%s", &c);

        fp_pro = fopen("product.txt", "r");
        fp_temp = fopen("temp.txt", "w");

        while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
            if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
                printf("\n\nProduct Name: %s", a.name);
                printf("\n\nPrevious Pieces/kg: %d", a.pieces);
                printf("\nEnter Current Pieces/kg: ");
                scanf("%d", &p);
                printf("\n\nPrevious Price: %0.2lfTK.", a.price);
                printf("\nEnter Current Price: ");
                scanf("%lf", &pr);

                s = a.pieces + p;

                fprintf(fp_temp, "%d %s %s %0.2lf\n", s, a.code, a.name, pr);
            }
            else{
                fprintf(fp_temp, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);
            }
        }

        fclose(fp_temp);
        fclose(fp_pro);

        fp_temp = fopen("temp.txt", "r");
        fp_pro = fopen("product.txt", "w");

        while(fscanf(fp_temp, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
            fprintf(fp_pro, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);
        }

        fclose(fp_temp);
        fclose(fp_pro);

    }
    else{

        fp_pro = fopen("product.txt", "a");

        printf("\nEnter Product Code: ");
        scanf("%s", &a.code);
        printf("\nEnter Product Pieces/kg: ");
        scanf("%d", &a.pieces);
        printf("\nEnter Product Name: ");
        scanf("%s", &a.name);
        printf("\nEnter Product Price: ");
        scanf("%lf", &a.price);

        fprintf(fp_pro, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);

        fclose(fp_pro);
    }
    printf("\n\nProduct is successfully saved");

    printf("\nSave any more?(Y/N):");
    if(getch()=='y'){
        addproduct();
    }
    else{
        int a;
        for(a = 0; a < 16; a++){
            printf("\n");
        }
        mainmenu();
    }
}

void sellproduct(void)  //function that sell product
{
    int t, i, p, c[3];
    int t_p;
    double total = 0, total_p = 0;

    printf("\nEnter total type of item: ");
    scanf("%d", &t);

    for (i = 0; i < t; i++){
        printf("\nEnter product code: ");
        scanf("%s", &c);

        fp_pro = fopen("product.txt", "r");

        while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
                if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
                    printf("\nEnter total pieces/kg: ");
                    scanf("%d", &p);

                    total = p * a.price;

                    t_p = a.pieces - p;

                    printf("\n\n\t%s\t\t\t\t\t   %0.2lf/=", a.name, total);

                    fclose(fp_pro);

                    total_p = total_p + total;
                }
        }

        fp_pro = fopen("product.txt", "r");
        fp_temp = fopen("temp.txt", "w");

        while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
            if(strcmp(a.code,(c))==0){  //checks whether a.code is equal to c or not
                fprintf(fp_temp, "%d %s %s %0.2lf\n", t_p, a.code, a.name, a.price);
            }
            else{
                fprintf(fp_temp, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);
            }
        }

        fclose(fp_pro);
        fclose(fp_temp);

        fp_temp = fopen("temp.txt", "r");
        fp_pro = fopen("product.txt", "w");

        while(fscanf(fp_temp, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
                fprintf(fp_pro, "%d %s %s %0.2lf\n", a.pieces, a.code, a.name, a.price);
        }

        fclose(fp_temp);
        fclose(fp_pro);

    }
    printf("\n\t=============================================================");
    printf("\n\tTotal \t\t\t\t\t = %0.2lf Taka\n", total_p);

    if(total_p = 0){
        printf("\nProduct code not in record");
    }

    printf("\n\nAny more item sell?(Y/N)");
    if(getch()=='y'){
        sellproduct();
    }
    else{
        int a;
        for(a = 0; a < 16; a++){
            printf("\n");
        }
        mainmenu();
    }
}

void stockproduct(void)  //show the list of stock product
{
    printf("\n\t********************* Stock Product List ********************");

    printf("\n\n Pieces/kg\t\tProduct Code\t\tProduct Name\t\tProduct Price");

    fp_pro = fopen("product.txt", "r");

    while(fscanf(fp_pro, "%d %s %s %lf", &a.pieces, &a.code, &a.name, &a.price)!= EOF){
        printf("\n\n %d\t\t%s\t\t\t%s\t\t\t%0.2lf/=", a.pieces, a.code, a.name, a.price);
    }

    fclose(fp_pro);

    printf("\n\nSave any more item?(Y/N)");
    if(getch()=='y'){
        addproduct();
    }
    else{
        int a;
        for(a = 0; a < 16; a++){
            printf("\n");
        }
        mainmenu();
    }
}


//End of program


