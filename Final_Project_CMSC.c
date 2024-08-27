#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>


int totalShop = 0;
int fChoice;
int itemsChoice;

struct items{
    char item[50];
    int type;
    int quantity;
    int price;
};

struct shop{
    char shopName[50];
    int itemsCounter;
    struct items Items[50];
};

struct shop Shop[50];

int longInput = 5;
int longPrice = 5;
int templongInput;
int tmeplongPrice;

//font
void front(){
    printf("                  **  **  **    ********    **           ******      ****      **    **    ********\n");
    printf("                  **  **  **    ********    **          *******     ******     ***  ***    ********\n");
    printf("                  **  **  **    **          **         ***         ***  ***    ** ** **    **      \n");
    printf("                  *** ** ***    *******     **         **          ***  ***    ** ** **    ******  \n");
    printf("                   ********     **          **         ***         ***  ***    **    **    **      \n");
    printf("                    ******      ********    ********    *******     ******     **    **    ********\n");
    printf("                     ****       ********    ********     ******      ****      **    **    ********\n");

    printf("\n\n");
    printf("                                                    ******     ***\n");
    printf("                                                      **      ** **\n");
    printf("                                                      **      ** **\n");
    printf("                                                      **       ***\n");

    printf("\n");
    printf("                                           **  **     ***    **  **    ***\n");
    printf("                                           **  **    ** **   **  **    ** *\n");
    printf("                                             **      ** **   **  **    ***\n");
    printf("                                             **       ***     ****     ** *\n");

    printf("\n\n");
    printf("*********     ***    ***    **       **    *********     ***    ***     *********      ****       *******     ***   ***\n");
    printf("*********     ****   ***    ***     ***    *********     ****   ***     *********     ******      ***  ***    ***   ***\n");
    printf("   ***        *** *  ***    ***     ***    ***           *** *  ***        ***       ***  ***     ***   **     *** ***\n");
    printf("   ***        ***  * ***     ***   ***     *******       ***  * ***        ***       ***  ***     ***  ***      *****\n");
    printf("   ***        ***   ****     ***   ***     ***           ***   ****        ***       ***  ***     ******         ***\n");
    printf("*********     ***    ***      **   **      *********     ***    ***        ***        ******      ***  ***       ***\n");
    printf("*********     ***    ***       *****       *********     ***    ***        ***         ****       ***   ***      ***\n");

   }

int star;

//guide whether to add shop or edit shop
int guide(){
    int choice1;
    char decid[100];

    printf("\n---USE THIS GUIDE--\n\n");
    printf("    1. Add Shop\n");
    printf("    2. Delete An Inventory\n");
    printf("    3. Show Storage\n");
    printf("    4. Edit A Storage\n");
    printf("    5. Exit Program\n");
    printf("\nYOUR CHOICE: ");

    fgets(decid, sizeof(decid), stdin);
    sscanf(decid, "%d", &choice1);

    while (!(isdigit(decid[0])) || (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5)) {
        printf("\n---INVALID INPUT---\n\n");
        printf("YOUR CHOICE: ");

        fgets(decid, sizeof(decid), stdin);
        sscanf(decid, "%d", &choice1);
    }

    return choice1;
}

int guideItem(){
    int aq;
    printf("\n---Please Use This Guide---\n");
    printf("    1. Add An Item\n");
    printf("    2. Delete An Item\n");
    printf("    3. Rearrange\n");
    printf("    4. Exit The Store\n\n");
    printf("YOUR CHOICE: ");
    char check4[100];
    do {
        gets(check4);
        aq = atoi(check4);
        if (!(isdigit(check4[0]) && strlen(check4) == 1 && (aq >= 1 && aq <= 4))) {
            printf("\n---INVALID INPUT!---\n\n");
            printf("YOUR CHOICE: ");
        } else {
            break;
        }
    } while (1);

    return aq;

    }

void addShop(int aS){

    printf("---ENTER SHOP---: ");
    gets(Shop[aS].shopName);

    int decide = 0;

    while (decide != 1) {
        decide = 1;
        for (int q = 0; q < aS; q++) {
            if (strcmp(Shop[aS].shopName, Shop[q].shopName) == 0) {
                printf("\n---CURRENTLY AVAILABLE ON THE STORAGE!---\n\n");
                printf("---ENTER SHOP---: ");
                gets(Shop[aS].shopName);
                decide = 0;
                break;
            }
        }
    }
}

//asking items
void ask(int shopNum, int itemNum){
    printf("ENTER PRODUCT: ");
    gets(Shop[shopNum].Items[itemNum].item);

    printf("*GUIDE*\n");
    printf("    1. KG\n");
    printf("    2. PACK\n");
    printf("    3. SACK\n");
    printf("STORAGE TYPE: ");
    char check[100];
    int storageType;
    do {
        gets(check);
        storageType = atoi(check);
        if (!(isdigit(check[0]) && strlen(check) == 1 && (storageType == 1 || storageType == 2 || storageType == 3))) {
            printf("\n---INVALID INPUT!---\n\n");
            printf("STORAGE TYPE: ");
        } else {
            Shop[shopNum].Items[itemNum].type = storageType;
            break;
        }
    } while (1);




    printf("ITEM'S QUANTITY: ");
    char check2[100];
    do {
        fgets(check2, sizeof(check2), stdin);
        check2[strcspn(check2, "\n")] = '\0'; // Remove trailing newline

        if (!(isdigit(check2[0])) || atoi(check2) < 1) {
            printf("\n---INVALID INPUT!---\n\n");
            printf("ITEM'S QUANTITY: ");
        } else {
            Shop[shopNum].Items[itemNum].quantity = atoi(check2);
        }

    } while (!(isdigit(check2[0])) || atoi(check2) < 1);

    printf("ITEM'S PRICE: ");
    char check3[100];
    do {
        fgets(check3, sizeof(check3), stdin);
        check3[strcspn(check3, "\n")] = '\0'; // Remove trailing newline

        if (!(isdigit(check3[0])) || atof(check3) < 1) {
            printf("\n---INVALID INPUT!---\n\n");
            printf("ITEM'S PRICE: ");
        } else {
            Shop[shopNum].Items[itemNum].price = atof(check3);
        }

    } while (!(isdigit(check3[0])) || atof(check3) < 1);


}

void deletion(int x){
    int totalDelete = 1;
    int deletion[50];
    int q = 0;

    printf("\n\n    *Can Only Delete One At A Time*");

    printf("\n\nNumber To Delete: ");
    scanf("%d", &deletion[q]);


    for(int q = 0; q < totalDelete; q++){
        int a = deletion[q];
        for(int w = 0; w < Shop[x].itemsCounter; w++){
            if(a - 1 == w){
                int e = w;
                for(e; e < Shop[x].itemsCounter - 1; e++){
                    strcpy(Shop[x].Items[e].item, Shop[x].Items[e + 1].item);
                    Shop[x].Items[e].type = Shop[x].Items[e + 1].type;
                    Shop[x].Items[e].quantity = Shop[x].Items[e + 1].quantity;
                    Shop[x].Items[e].price = Shop[x].Items[e + 1].price;
                }
                Shop[x].itemsCounter--;
                break;
            }
        }
    }
    getchar();



}

int rearrange(){
    int a;
    printf("\n---Please Use This Guide---\n");
    printf("      *Rearrange By*      \n\n");
    printf("    1. Alphabetical\n");
    printf("    2. Storage Type\n");
    printf("    3. Quantity\n");
    printf("    4. Price\n\n");
    printf("Your Choice: ");

    char what[50];
    fgets(what, sizeof(what), stdin);
    sscanf(what, "%d", &a);

    while (!(isdigit(what[0])) || (a != 1 && a != 2 && a != 3 && a != 4)) {
        printf("\n---INVALID INPUT!---\n\n");
        printf("Your Choice: ");
        fgets(what, sizeof(what), stdin);
        sscanf(what, "%d", &a);
    }

    return a;

}

void alphaArrange(int xz){
    for(int q = 0; q < Shop[xz].itemsCounter; q++){
        for(int w = 0; w < Shop[xz].itemsCounter - 1; w++){
            if(Shop[xz].Items[w].item[0] > Shop[xz].Items[w + 1].item[0]){
                char temporary[50];
                strcpy(temporary, Shop[xz].Items[w].item);
                strcpy(Shop[xz].Items[w].item, Shop[xz].Items[w + 1].item);
                strcpy(Shop[xz].Items[w + 1].item, temporary);

                int tempStoring;
                tempStoring = Shop[xz].Items[w].type;
                Shop[xz].Items[w].type= Shop[xz].Items[w + 1].type;
                Shop[xz].Items[w + 1].type = tempStoring;

                int tempQuantity;
                tempQuantity = Shop[xz].Items[w].quantity;
                Shop[xz].Items[w].quantity = Shop[xz].Items[w + 1].quantity;
                Shop[xz].Items[w + 1].quantity = tempQuantity;

                int tempPrice;
                tempPrice = Shop[xz].Items[w].price;
                Shop[xz].Items[w].price = Shop[xz].Items[w + 1].price;
                Shop[xz].Items[w + 1].price = tempPrice;
            }
        }
    }
}

void typeArrange(int xz){
    for(int q = 0; q < Shop[xz].itemsCounter; q++){
        for(int w = 0; w < Shop[xz].itemsCounter - 1; w++){
            if(Shop[xz].Items[w].type > Shop[xz].Items[w + 1].type){
                char temporary[50];
                strcpy(temporary, Shop[xz].Items[w].item);
                strcpy(Shop[xz].Items[w].item, Shop[xz].Items[w + 1].item);
                strcpy(Shop[xz].Items[w + 1].item, temporary);

                int tempStoring;
                tempStoring = Shop[xz].Items[w].type;
                Shop[xz].Items[w].type = Shop[xz].Items[w + 1].type;
                Shop[xz].Items[w + 1].type = tempStoring;

                int tempQuantity;
                tempQuantity = Shop[xz].Items[w].quantity;
                Shop[xz].Items[w].quantity = Shop[xz].Items[w + 1].quantity;
                Shop[xz].Items[w + 1].quantity = tempQuantity;

                int tempPrice;
                tempPrice = Shop[xz].Items[w].price;
                Shop[xz].Items[w].price = Shop[xz].Items[w + 1].price;
                Shop[xz].Items[w + 1].price = tempPrice;
            }
        }
    }
}

void quantityArrange(int xz){
    for(int q = 0; q < Shop[xz].itemsCounter; q++){
        for(int w = 0; w < Shop[xz].itemsCounter - 1; w++){
            if(Shop[xz].Items[w].quantity > Shop[xz].Items[w + 1].quantity){
                char temporary[50];
                strcpy(temporary, Shop[xz].Items[w].item);
                strcpy(Shop[xz].Items[w].item , Shop[xz].Items[w + 1].item );
                strcpy(Shop[xz].Items[w + 1].item , temporary);

                int tempStoring;
                tempStoring =  Shop[xz].Items[w].type;
                Shop[xz].Items[w].type = Shop[xz].Items[w + 1].type;
                Shop[xz].Items[w + 1].type = tempStoring;

                int tempQuantity;
                tempQuantity = Shop[xz].Items[w].quantity;
                Shop[xz].Items[w].quantity = Shop[xz].Items[w + 1].quantity;
                Shop[xz].Items[w + 1].quantity = tempQuantity;

                int tempPrice;
                tempPrice = Shop[xz].Items[w].price;
                Shop[xz].Items[w].price = Shop[xz].Items[w + 1].price;
                Shop[xz].Items[w + 1].price = tempPrice;
            }
        }
    }
}

void priceArrange(int xz){
    for(int q = 0; q < Shop[xz].itemsCounter; q++){
        for(int w = 0; w < Shop[xz].itemsCounter - 1; w++){
            if(Shop[xz].Items[w].price > Shop[xz].Items[w + 1].price){
                char temporary[50];
                strcpy(temporary, Shop[xz].Items[w].item );
                strcpy(Shop[xz].Items[w].item , Shop[xz].Items[w + 1].item );
                strcpy(Shop[xz].Items[w + 1].item , temporary);

                int tempStoring;
                tempStoring = Shop[xz].Items[w].type;
                Shop[xz].Items[w].type = Shop[xz].Items[w + 1].type;
                Shop[xz].Items[w + 1].type = tempStoring;

                int tempQuantity;
                tempQuantity = Shop[xz].Items[w].quantity;
                Shop[xz].Items[w].quantity = Shop[xz].Items[w + 1].quantity;
                Shop[xz].Items[w + 1].quantity = tempQuantity;

                int tempPrice;
                tempPrice = Shop[xz].Items[w].price;
                Shop[xz].Items[w].price = Shop[xz].Items[w + 1].price;
                Shop[xz].Items[w + 1].price = tempPrice;
            }
        }
    }
}

int howlong(int x){
    int totalStar;
    for(int q = 0; q < Shop[x].itemsCounter; q++){
            templongInput = strlen(Shop[x].Items[q].item);
            if(templongInput > longInput){
                int b = longInput;
                longInput = templongInput;
                templongInput = b;
            }
        }

    for(int q = 0; q < Shop[x].itemsCounter; q++){
            int a = Shop[x].Items[q].price;
            int count = 0;
            while(a > 0){
                a = a / 10;
                count++;
            }
            if(longPrice < count){
                longPrice = count;
            }
    }
    totalStar = longInput + longPrice + 71;
    return totalStar;
}

void header(int z){
    for(int q = 0; q < z; q++){
        printf("*");
    }
    printf("\n");
}

void spacing(int y){
    printf("*");
    for(int q = 0; q < y - 2; q++){
        printf(" ");
    }
    printf("*\n");
}

void heading(){
    printf("*        ");
    if(longInput == 5){
        printf("ITEMS");
    }
    else if(longInput != 5 && (longInput - 5) % 2 == 0){
        for(int q = 0; q < (longInput - 5) / 2 ; q++){
            printf(" ");
        }
        printf("ITEMS");
        for(int q = 0; q < (longInput - 5) / 2 ; q++){
            printf(" ");
        }
    }
    else if(longInput != 5 && (longInput - 5) % 2 == 1){
        for(int q = 0; q < (longInput - 5) / 2  + 1; q++){
            printf(" ");
        }
        printf("ITEMS");
        for(int q = 0; q < (longInput - 5) / 2; q++){
            printf(" ");
        }
    }

    printf("     ***     ");
    printf("TYPE     ***     QUANTITY     ***     ");

    if(longPrice == 5){
        printf("PRICE");
    }
    else if(longPrice != 5 && (longPrice - 5) % 2 == 0){
        for(int q = 0; q < (longPrice - 5) / 2 ; q++){
            printf(" ");
        }
        printf("Price");
        for(int q = 0; q < (longPrice - 5) / 2 ; q++){
            printf(" ");
        }
    }
    else if(longPrice != 5 && (longPrice - 5) % 2 == 1){
        for(int q = 0; q < (longPrice - 5) / 2  + 1; q++){
            printf(" ");
        }
        printf("Price");
        for(int q = 0; q < (longPrice - 5) / 2; q++){
            printf(" ");
        }
    }
    printf("          *");
    printf("\n");

}
void storeName(int o, int i){
    if((o - strlen(Shop[i].shopName)) % 2 == 0){
        printf("*");
        for(int q = 0; q < (((o - strlen(Shop[i].shopName)) - 4) / 2) - 1; q++){
            printf(" ");
        }
        printf("[%d] %s", i + 1, Shop[i].shopName);
        for(int q = 0; q < (((o - strlen(Shop[i].shopName)) - 4) / 2) - 1; q++){
            printf(" ");
        }
        printf("*");
    }
    else{
        printf("*");
        for(int q = 0; q < ((((o - strlen(Shop[i].shopName)) - 4) / 2)) ; q++){
            printf(" ");
        }
        printf("[%d] %s", i + 1, Shop[i].shopName);
        for(int q = 0; q < (((o - strlen(Shop[i].shopName)) - 4) / 2) - 1; q++){
            printf(" ");
        }
        printf("*");
    }
}
void total(){
    printf("\n");
    printf("******  *****  ******  ******  **    \n");
    printf("  **   **   **   **    **  **  **    \n");
    printf("  **   **   **   **    ******  **    \n");
    printf("  **    *****    **    **  **  ***** \n");

}


void printing(int STAR, int table){
    header(STAR);
    spacing(STAR);
    heading();
    spacing(STAR);
    header(STAR);
    spacing(STAR);
    storeName(STAR, table);
    printf("\n");
    spacing(STAR);

    for(int q = 0; q < Shop[table].itemsCounter; q++){
        printf("*   [%d]  ", q + 1);


        if(strlen(Shop[table].Items[q].item) == longInput){
            printf("%s", Shop[table].Items[q].item);
        }
        else{
            if((longInput - strlen(Shop[table].Items[q].item)) % 2 == 0){
                for(int p = 0; p < (longInput - strlen(Shop[table].Items[q].item)) / 2; p++){
                    printf(" ");
                }
                printf("%s", Shop[table].Items[q].item);
                for(int p = 0; p < (longInput - strlen(Shop[table].Items[q].item)) / 2; p++){
                    printf(" ");
                }
            }
            else{
                for(int p = 0; p < (longInput - strlen(Shop[table].Items[q].item)) / 2 + 1; p++){
                    printf(" ");
                }
                printf("%s", Shop[table].Items[q].item);
                for(int p = 0; p < (longInput - strlen(Shop[table].Items[q].item)) / 2; p++){
                    printf(" ");
                }
            }
        }





        printf("     ***     ");
        if(Shop[table].Items[q].type == 1){
            printf(" KG ");
        }
        else if(Shop[table].Items[q].type == 2){
            printf("PACK");
        }
        else if((Shop[table].Items[q].type == 3)){
            printf("SACK");
        }




        printf("     ***     ");

        int longTemp = 0;
        int a = Shop[table].Items[q].quantity;
        while(a > 0){
            a = a / 10;
            longTemp++;
        }
        if((8 - longTemp) % 2 == 0){
            for(int q = 0; q < (8 - longTemp) / 2; q++){
                printf(" ");
            }
            printf("%d", Shop[table].Items[q].quantity);
            for(int q = 0; q < (8 - longTemp) / 2; q++){
                printf(" ");
            }
        }
        else if((8 - longTemp) % 2 == 1){
            for(int q = 0; q < ((8 - longTemp) / 2) + 1; q++){
                printf(" ");
            }
            printf("%d", Shop[table].Items[q].quantity);
            for(int q = 0; q < (8 - longTemp) / 2; q++){
                printf(" ");
            }
        }





        printf("     ***     ");

        int temp = 0;
        int b = Shop[table].Items[q].price;
        while(b > 0){
            b = b / 10;
            temp++;
        }
        if(temp == longPrice){
            printf("%d", Shop[table].Items[q].price);
        }
        else{
            if((longPrice - temp) % 2 == 0){
                for(int q = 0; q < (longPrice - temp) / 2; q++){
                    printf(" ");
                }
                printf("%d", Shop[table].Items[q].price);
                for(int q = 0; q < (longPrice - temp) / 2; q++){
                    printf(" ");
                }
            }
            else{
                for(int q = 0; q < ((longPrice - temp) / 2) + 1; q++){
                    printf(" ");
                }
                printf("%d", Shop[table].Items[q].price);
                for(int q = 0; q < (longPrice - temp) / 2; q++){
                    printf(" ");
                }
            }
        }



        printf("          *\n");


    }
    spacing(STAR);
    header(STAR);


}

int deletingTable(){
    int choice;
    printf("\n---THE FOLLOWING STORAGE---\n\n");
    for(int q = 0; q < totalShop; q++){
        printf("    [%d]%s\n", q + 1, Shop[q].shopName);
    }
    printf("\n\nYOUR CHOICE: ");
    char hehe[50];
    fgets(hehe, sizeof(hehe), stdin);

    // Remove trailing newline
    if (hehe[strlen(hehe) - 1] == '\n') {
        hehe[strlen(hehe) - 1] = '\0';
    }

    int input = atoi(hehe);

    while (input < 0 || input > totalShop) {
        if (!(isdigit(hehe[0]))) {
            printf("\n---INVALID INPUT!---\n\n");
        } else {
            printf("\n---OUT OF RANGE!---\n\n");
        }

        printf("YOUR CHOICE: ");
        fgets(hehe, sizeof(hehe), stdin);

        // Remove trailing newline
        if (hehe[strlen(hehe) - 1] == '\n') {
            hehe[strlen(hehe) - 1] = '\0';
        }

        input = atoi(hehe);
    }

    choice = input;
    return choice;
}

void deletetabs(int hm){
    for(int q = 0; q < totalShop; q++){
        for(int e = 0; e < totalShop; e++){
            if(e == hm - 1){
                for(int w = e; w < totalShop; w++){
                    strcpy(Shop[w].shopName, Shop[w + 1].shopName);
                    Shop[w].itemsCounter = Shop[w + 1].itemsCounter;
                    for(int e = 0; e < Shop[w].itemsCounter; e++){
                        strcpy(Shop[w].Items[e].item, Shop[w + 1].Items[e].item);
                        Shop[w].Items[e].type = Shop[w + 1].Items[e].type;
                        Shop[w].Items[e].quantity = Shop[w + 1].Items[e].quantity;
                        Shop[w].Items[e].price = Shop[w + 1].Items[e].price;
                    }
                }
            break;
            }
        }break;
    break;
    }
    if(hm != 0){
        totalShop--;
    }
}

int editing(){
    int aH;
    printf("\n---THE FOLLOWING STORAGE---\n\n");
    for(int q = 0; q < totalShop; q++){
        printf("    [%d]%s\n", q + 1, Shop[q].shopName);
    }
    printf("YOUR CHOICE: ");

    char check7[100];
    do {
        gets(check7);
        aH = atoi(check7);
        if (!(isdigit(check7[0]) && strlen(check7) == 1 && (aH >= 1 && aH <= totalShop))) {
            printf("\n---INVALID INPUT!---\n\n");
            printf("YOUR CHOICE: ");
        } else {
            break;
        }
    } while (1);

    return aH;
}

void edit(int f){

    itemsChoice = guideItem();

    while(itemsChoice != 4){


        if(itemsChoice == 1){
            printf("\n");
            ask(f, Shop[f].itemsCounter);
            Shop[f].itemsCounter++;
            star = howlong(f);
            itemsChoice = guideItem();
        }


        else if(itemsChoice == 2){
            star = howlong(f);
            total();
            printing(star, f);

            deletion(f);

            star = howlong(f);
            total();
            printing(star, f);
            itemsChoice = guideItem();
        }
        else if(itemsChoice == 3){
            int reaWhat = rearrange();
            switch(reaWhat){

                case 1:
                    alphaArrange(f);
                    star = howlong(f);
                    total();
                    printing(star, f);
                    break;

                case 2:
                    typeArrange(f);
                    star = howlong(f);
                    total();
                    printing(star, f);
                    break;


                case 3:
                    quantityArrange(f);
                    star = howlong(f);
                    total();
                    printing(star, f);
                    break;

                case 4:
                    priceArrange(f);
                    star = howlong(f);
                    total();
                    printing(star, f);
                    break;

                default:
                    printf("\nINVALID INPUT!--\n\n");
                    break;
                }

            itemsChoice = guideItem();
        }
    }
}

int main(){

    front();
    fChoice = guide();
    int star;
    itemsChoice;



    while(fChoice != 5){

        if(fChoice == 1){
            addShop(totalShop);
            itemsChoice = 1;

            while(itemsChoice != 4){


                if(itemsChoice == 1){
                    printf("\n");
                    ask(totalShop, Shop[totalShop].itemsCounter);
                    Shop[totalShop].itemsCounter++;
                    star = howlong(totalShop);
                    itemsChoice = guideItem();
                }


                else if(itemsChoice == 2){
                    star = howlong(totalShop);
                    total();
                    printing(star, totalShop);

                    deletion(totalShop);

                    star = howlong(totalShop);
                    total();
                    printing(star, totalShop);
                    itemsChoice = guideItem();
                }


                else if(itemsChoice == 3){
                    int reaWhat = rearrange();
                    switch(reaWhat){

                        case 1:
                            alphaArrange(totalShop);
                            star = howlong(totalShop);
                            total();
                            printing(star, totalShop);
                            break;


                        case 2:
                            typeArrange(totalShop);
                            star = howlong(totalShop);
                            total();
                            printing(star, totalShop);
                            break;


                        case 3:
                            quantityArrange(totalShop);
                            star = howlong(totalShop);
                            total();
                            printing(star, totalShop);
                            break;


                        case 4:
                            priceArrange(totalShop);
                            star = howlong(totalShop);
                            total();
                            printing(star, totalShop);
                            break;

                        default:
                            printf("\nINVALID INPUT!--\n\n");
                            break;
                    }

                    itemsChoice = guideItem();
                }
            }
            totalShop++;
            fChoice = guide();
        }

        else if(fChoice == 2){
            if (totalShop==0){
                printf("\n\n---No Storage Available---\n");
                fChoice = guide();
            } else {
            for(int q = 0; q < totalShop; q++){
                star = howlong(q);
                total();
                printing(star, q);
                printf("\n");
                printf("\nPress Any Key/0 to Stop Deletion\n");
            }
            int sad = deletingTable();
            deletetabs(sad);
            printf("\n---THE FOLLOWING STORAGE---\n\n");
            for(int q = 0; q < totalShop; q++){
                    printf("    [%d]%s\n", q + 1, Shop[q].shopName);
            }

            for(int q = 0; q < totalShop; q++){
                star = howlong(q);
                total();
                printing(star, q);
                printf("\n");
            }
            fChoice = guide();
            }
        }

        else if(fChoice == 3){
            if (totalShop==0){
                printf("\n\n---No Storage Available---\n");
                fChoice = guide();
            } else {
                for(int q = 0; q < totalShop; q++){
                star = howlong(q);
                total();
                printing(star, q);
                printf("\n");
                }
                fChoice = guide();
            }
        }

        else if(fChoice == 4){
            if (totalShop==0){
                printf("\n\n---No Storage Available---\n");
                fChoice = guide();
            } else {
            int change = editing();
            edit(change - 1);

            fChoice = guide();
            }
        }
    }

    printf("\n\n");
        for(int q = 0; q < totalShop; q++){
            star = howlong(q);
            total();
            printing(star, q);
            printf("\n");
        }

    printf("\n\n");


    return 0;
}

