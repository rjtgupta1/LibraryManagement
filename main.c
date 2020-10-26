#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
#include<dir.h>

//  ||||||||||||||||||||||| Function declaration    |||||||||||||||||||||||

void main_page();
void student();
void book();
void mini_box();
void transaction();
int dig_entry(int digit[]);
void char_entry(char alpha[]);
void add_stu();
void mod_stu();
void del_stu();
void show_stu();
void add_book();
void show_book();
void mod_book();
void del_book();
void issue();
void re_book();
void si_book();
void login();
//  ||||||||||||||||||||||| Global variables    ||||||||||||||||||||||||||||

    FILE *fp,*fp1;
    struct student
    {
        int id,mob[10];
        char name[25],course[20],city[30];

    }stu;

    struct library
    {
        int bid,stok;
        char name[100],auth[30];
        float price;
    }bk;

    struct book_issue
    {
       int stu,book;
       char s_name[25],b_name[100],auth[30];
    }is;

// ||||||||||||||||||||||||   Go to XY function   |||||||||||||||||||||||||
COORD coord={0,0};
void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
// ||||||||||||||||||||||||||  Loading      ||||||||||||||||||||||||||||||||
void loading()
{
    int i;
    system("color EC");
    mini_box();
    gotoxy(48,28);
    printf("R@J@T GUPTA");
    gotoxy(50,15);
    printf("Loading ");
    for(i=1;i<=50;i++)
    {
        Sleep(10);
        gotoxy(30+i,17);
        printf("%c",219);
        gotoxy(58,15);
        printf("%d%%",i*2);
    }
}
// |||||||||||||||||||||||||||  BOX    ||||||||||||||||||||||||||||||||||||
void box()
{
    system("cls");
    system("color EC");
    int i;
    gotoxy(15,4);
    for(i=10;i<=90;i++)
    {
        if(i==10)
            printf("%c",201);
        else if(i==90)
            printf("%c",187);
        else
            printf("%c",205);
    }
    gotoxy(15,7);
    for(i=10;i<=90;i++)
    {
        printf("%c",205);
    }
    gotoxy(15,5);
    for(i=2;i<=28;i++)
    {
        gotoxy(15,i+3);
        if(i==4)
            printf("%c",204);
        else if(i==28)
            printf("%c",200);
        else
            printf("%c",186);

    }
    gotoxy(16,31);
    for(i=11;i<=90;i++)
    {
        printf("%c",205);
    }
    gotoxy(95,5);
    for(i=2;i<=28;i++)
    {
        gotoxy(95,i+3);
        if(i==28)
            printf("%c",188);
        else if(i==4)
            printf("%c",185);
        else
            printf("%c",186);

    }

}
void mini_box()     //  ||||||||||||||||||||||||   Mini box     |||||||||||||||||||||||||||||||||||||
{
    int i;
    gotoxy(42,26);
    for(i=1;i<=24;i++)
    {
        if(i==1)
        {
            printf("%c",201);
        }
        else if(i==24)
        {
            printf("%c",187);
        }
        else
            printf("%c",205);
    }
    printf("\n");
    for(i=1;i<4;i++)
    {
        gotoxy(42,26+i);
        for(int j=1;j<=24;j++)
        {
            if(j==1)
                printf("%c",186);
            else if(j==24)
                printf("%c",186);
            else
                printf(" ");
        }
        printf("\n");
    }
    gotoxy(42,30);
    for(i=1;i<25;i++)
    {
        if(i==1)
        {
            printf("%c",200);
        }
        else if(i==24)
        {
            printf("%c",188);
        }
        else
            printf("%c",205);
    }
}
//     ||||||||||||||||||||||||||||     Digit Entry     ||||||||||||||||||||||||||||||||||||||
int dig_entry(int digit[])
{
    int num;
    int i=0;
    while(i!=10)
    {
        num=getch();
        if(num==13)
            break;
        else if( isdigit(num) == 1 )
        {
            digit[i]=num;
            printf("%c",num);
            ++i;
        }
        else if (num == 8 && i>0)
        {
            printf("%c%c%c",8,32,8);
            --i;
        }
    }
    return (digit[10]);
}
//      ||||||||||||||||||||||||||  Alphabet entry      ||||||||||||||||||||||||||||||||||||||
void char_entry(char alpha[25])
{
    char ch;
    int i=0;
    while(i!=25)
    {
        ch=getch();
        if(ch==13 && i>0)
            break;
        else if( (ch>=65 && ch<=91) || (ch>=95 && ch<=122) || ch==32)
        {
            alpha[i]=ch;
            printf("%c",ch);
            ++i;
        }
        else if (ch == 8 && i>0)
        {
            printf("%c%c%c",8,32,8);
            --i;
        }
    }
    alpha[i]='\0';
}
//      |||||||||||||||||||||||||         Login       |||||||||||||||||||||||||||||||||||||||||||||
void login()
{
    box();
    gotoxy(51,6);
    printf("Login");
    char word[5];
    char user[]="rajat";
    char pass[]="rjt";
    char name[10];
    //      ||||||||||||||||||||||||||||||      Username Box        |||||||||||||||||||||||||||||||||
    int i;
    gotoxy(42,12);
    for(i=1;i<=24;i++)
    {
        if(i==1)
        {
            printf("%c",201);
        }
        else if(i==24)
        {
            printf("%c",187);
        }
        else
            printf("%c",205);
    }
    printf("\n");
    for(i=1;i<3;i++)
    {
        gotoxy(42,12+i);
        for(int j=1;j<=24;j++)
        {
            if(j==1)
                printf("%c",186);
            else if(j==24)
                printf("%c",186);
            else
                printf(" ");
        }
        printf("\n");
    }
    gotoxy(42,15);
    for(i=1;i<25;i++)
    {
        if(i==1)
        {
            printf("%c",200);
        }
        else if(i==24)
        {
            printf("%c",188);
        }
        else
            printf("%c",205);
    }
//      |||||||||||||||||||||   Password Box  |||||||||||||||||||||||||
    gotoxy(42,20);
    for(i=1;i<=24;i++)
    {
        if(i==1)
        {
            printf("%c",201);
        }
        else if(i==24)
        {
            printf("%c",187);
        }
        else
            printf("%c",205);
    }
    printf("\n");
    for(i=1;i<3;i++)
    {
        gotoxy(42,20+i);
        for(int j=1;j<=24;j++)
        {
            if(j==1)
                printf("%c",186);
            else if(j==24)
                printf("%c",186);
            else
                printf(" ");
        }
        printf("\n");
    }
    gotoxy(42,23);
    for(i=1;i<25;i++)
    {
        if(i==1)
        {
            printf("%c",200);
        }
        else if(i==24)
        {
            printf("%c",188);
        }
        else
            printf("%c",205);
    }
//      |||||||||||||||||||||||||   Username & Password       ||||||||||||||||||||||||||||||||||||||||||
    gotoxy(50,20);
    printf("Password");
    gotoxy(50,12);
    printf("Username");
    gotoxy(50,14);
    gets(name);
    gotoxy(52,22);
    char ch;
    for(i=0;i<3;++i)
    {
        ch = getch();
        if(ch==13)
            break;
        word[i]=ch;
        printf("%c",249);
    }
    if((strcmp(user,name)==0) && (strcmp(pass,word)==0))
    {

        gotoxy(46,30);
        printf("Login Successful");
        Beep(956,750);
        Sleep(1500);
        main_page();
    }
    else
    {
        int j;
        for(int i=1;i<=3;++i)
        {
            j=0;
            Sleep(250);
            gotoxy(40,30);
            printf("Username or Password is incorrect");
            Sleep(250);
            while(j<=32)
            {
                gotoxy(40+j,30);
                printf(" ");
                ++j;
            }
            Beep(635,500);
        }
        gotoxy(40,30);
        printf("Username or Password is incorrect");
        Sleep(1000);
    }
}
//     |||||||||||||||||||||||||||  Student Management  ||||||||||||||||||||||||||||||||||||||
void student()
{
    char input;
    do
    {
        box();
        gotoxy(47,6);
        printf("Student Management");
        gotoxy(44,10);
        printf("1. Add new Student");
        gotoxy(44,13);
        printf("2. Edit Student");
        gotoxy(44,16);
        printf("3. Show Student ");
        gotoxy(44,19);
        printf("4. Delete Student");
        gotoxy(44,22);
        printf("5. Back to Home");
        mini_box();
        gotoxy(45,28);
        printf("Input here :  ");
        input = getch();
        switch(input)
        {
        case '1':
            add_stu();
            break;
        case '2':
            mod_stu();
            break;
        case '3':
            show_stu();
            break;
        case '4':
            del_stu();
            break;
        case '5':
            main_page();
            break;
        default:
            student();
            break;
        }
    }while(input!=5);
}
//      |||||||||||||||||||||||||||||||||||||   Add Student     ||||||||||||||||||||||||||||||||||||
void add_stu()
{
    box();
    fp = fopen("C:\\Library Management\\student.txt","ab");
    if(fp==NULL)
    {
        printf("Unable to open or create a file");
        exit(0);
    }
    else
    {
        gotoxy(47,6);
        printf("Add Student");
        gotoxy(18,10);
        printf("Id  \t :");
        gotoxy(18,14);
        printf("Name \t :");
        gotoxy(18,18);
        printf("Course :");
        gotoxy(18,22);
        printf("City \t :");
        gotoxy(18,26);
        printf("Mobile :");
        gotoxy(28,10);
        scanf("%d",&stu.id);
        fflush(stdin);
        gotoxy(28,14);
        char_entry(stu.name);
        gotoxy(28,18);
        gets(stu.course);
        gotoxy(28,22);
        char_entry(stu.city);
        gotoxy(28,26);
        dig_entry(stu.mob);
        fwrite(&stu,sizeof(stu),1,fp);
        gotoxy(40,28);
        printf("Data written successfully");
        Sleep(2000);
        fclose(fp);
    }
}
//      |||||||||||||||||||||||||||||   Edit student    |||||||||||||||||||||||||||||||||
void mod_stu()
{
    int id,flag=0;
    box();
    gotoxy(47,6);
    printf("Edit Student");
    gotoxy(18,10);
    printf("Id  \t :");
    gotoxy(18,14);
    printf("Name \t :");
    gotoxy(18,18);
    printf("Course :");
    gotoxy(18,22);
    printf("City \t :");
    gotoxy(18,26);
    printf("Mobile :");
    gotoxy(28,10);
    scanf("%d",&id);
    fflush(stdin);
    fp = fopen("C:\\Library Management\\student.txt","rb+");
    while(fread(&stu,sizeof(stu),1,fp)>0)
    {
        if(stu.id==id)
        {
            gotoxy(40,28);
            printf("Type details to edit");
            stu.id=id;
            fflush(stdin);
            gotoxy(28,14);
            char_entry(stu.name);
            gotoxy(28,18);
            gets(stu.course);
            gotoxy(28,22);
            char_entry(stu.city);
            gotoxy(28,26);
            dig_entry(stu.mob);
            fseek(fp,ftell(fp)-sizeof(stu),SEEK_SET);
            fwrite(&stu,sizeof(stu),1,fp);
            gotoxy(40,28);
            printf("Data Edited successfully");
            flag=1;
            fclose(fp);
            break;
        }
    }
    if(flag==0)
    {
        gotoxy(50,28);
        printf("NO data found");
    }
    Sleep(1500);
}
//      ||||||||||||||||||||||||||||    Show student    |||||||||||||||||||||||||||||||||
void show_stu()
{
    int id;
    box();
    gotoxy(47,6);
    printf("Show Student");
    gotoxy(18,10);
    printf("Id  \t :");
    gotoxy(18,14);
    printf("Name \t :");
    gotoxy(18,18);
    printf("Course :");
    gotoxy(18,22);
    printf("City \t :");
    gotoxy(18,26);
    printf("Mobile :");
    gotoxy(28,10);
    scanf("%d",&id);
    fflush(stdin);
    fp = fopen("C:\\Library Management\\student.txt","rb");
    gotoxy(50,28);
    if(fp==NULL)
        printf("NULL");
    int flag=0;
    while((fread(&stu,sizeof(stu),1,fp)>0))
    {
        if(stu.id==id)
        {
            flag=1;
            gotoxy(28,14);
            printf("%s",stu.name);
            gotoxy(28,18);
            printf("%s",stu.course);
            gotoxy(28,22);
            printf("%s",stu.city);
            gotoxy(28,26);
            for(int i=0;i<10;++i)
            {
                printf("%c",stu.mob[i]);
            }
            break;
        }
    }
    if(flag==0)
    {
        gotoxy(50,28);
        printf("NO data found");
    }
    fclose(fp);
    getch();
}
//      ||||||||||||||||||||||||||||    delete Student  |||||||||||||||||||||||||||||||||
void del_stu()
{
    int id,flag=0;
    box();
    gotoxy(47,6);
    printf("Delete Student");
    gotoxy(18,10);
    printf("Id  \t :");
    gotoxy(18,14);
    printf("Name \t :");
    gotoxy(18,18);
    printf("Course :");
    gotoxy(18,22);
    printf("City \t :");
    gotoxy(18,26);
    printf("Mobile :");
    gotoxy(28,10);
    scanf("%d",&id);
    fp = fopen("C:\\Library Management\\student.txt","rb");
    fp1 = fopen("C:\\Library Management\\tmp.txt","wb+");
    while(fread(&stu,sizeof(stu),1,fp)>0)
    {
        if(stu.id!=id)
        {
            fwrite(&stu,sizeof(stu),1,fp1);
        }
        else
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        gotoxy(50,28);
        printf("Id didn't match");
    }
    else
    {
        gotoxy(28,14);
        printf("%s",stu.name);
        gotoxy(28,18);
        printf("%s",stu.course);
        gotoxy(28,22);
        printf("%s",stu.city);
        gotoxy(28,26);
        for(int i=0;i<10;++i)
        {
            printf("%c",stu.mob[i]);
        }
        gotoxy(50,28);
        printf("Id removed successfully");
    }
    fclose(fp);
    fclose(fp1);
    remove("C:\\Library Management\\student.txt");
    rename("C:\\Library Management\\tmp.txt","C:\\Library Management\\student.txt");
    getch();
}
//      ||||||||||||||||||||||||||||    Add Book        ||||||||||||||||||||||||||||||||||
void add_book()
{
    box();
    fp=fopen("C:\\Library Management\\book.txt","ab+");
    gotoxy(47,6);
    printf("Add Book");
    gotoxy(18,10);
    printf("Book Id \t:");
    gotoxy(18,14);
    printf("Book Name \t:");
    gotoxy(18,18);
    printf("Author Name\t:");
    gotoxy(18,22);
    printf("Price \t:");
    gotoxy(18,26);
    printf("Quantity \t:");
    gotoxy(34,10);
    scanf("%d",&bk.bid);
    fflush(stdin);
    gotoxy(34,14);
    gets(bk.name);
    gotoxy(34,18);
    char_entry(bk.auth);
    gotoxy(34,22);
    scanf("%f",&bk.price);
    gotoxy(34,26);
    scanf("%d",&bk.stok);
    fwrite(&bk,sizeof(bk),1,fp);
    gotoxy(40,28);
    printf("Data written successfully");
    Sleep(1500);
    fclose(fp);
}
//      ||||||||||||||||||||||||||||    Show Book        ||||||||||||||||||||||||||||||||||
void show_book()
{
    box();
    gotoxy(47,6);
    printf("Show Book");
    gotoxy(18,10);
    printf("Book Id \t:");
    gotoxy(18,14);
    printf("Book Name \t:");
    gotoxy(18,18);
    printf("Author Name\t:");
    gotoxy(18,22);
    printf("Price \t:");
    gotoxy(18,26);
    printf("Quantity \t:");
    fp = fopen("C:\\Library Management\\book.txt","rb");
    gotoxy(50,28);
    if(fp==NULL)
        printf("NULL");
    int flag=0,id;
    gotoxy(34,10);
    scanf("%d",&id);
//    fflush(stdin);
    while((fread(&bk,sizeof(bk),1,fp)>0))
    {
        if(bk.bid==id)
        {
            flag=1;
            gotoxy(34,14);
            printf("%s",bk.name);
            gotoxy(34,18);
            printf("%s",bk.auth);
            gotoxy(34,22);
            printf("%.2f",bk.price);
            gotoxy(34,26);
            printf("%d",bk.stok);
            break;
        }
    }
    if(flag==0)
    {
        gotoxy(50,28);
        printf("NO data found");
    }
    fclose(fp);
    getch();
}
//      ||||||||||||||||||||||||||||    Delete Book        ||||||||||||||||||||||||||||||||||
void del_book()
{
    int id,flag=0;
    box();
    gotoxy(47,6);
    printf("Delete Book");
    gotoxy(18,10);
    printf("Book Id \t:");
    gotoxy(18,14);
    printf("Book Name \t:");
    gotoxy(18,18);
    printf("Author Name\t:");
    gotoxy(18,22);
    printf("Price \t:");
    gotoxy(18,26);
    printf("Quantity \t:");
    gotoxy(34,10);
    scanf("%d",&id);
    fflush(stdin);
    fp = fopen("C:\\Library Management\\book.txt","rb");
    fp1 = fopen("C:\\Library Management\\tmp.txt","wb+");
    while(fread(&bk,sizeof(bk),1,fp)>0)
    {
        if(bk.bid!=id)
        {
            fwrite(&bk,sizeof(bk),1,fp1);
        }
        else
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        gotoxy(50,28);
        printf("Id didn't match");
    }
    else
    {
        gotoxy(34,14);
        printf("%s",bk.name);
        gotoxy(34,18);
        printf("%s",bk.auth);
        gotoxy(34,22);
        printf("%.2f",bk.price);
        gotoxy(34,26);
        printf("%d",bk.stok);
        gotoxy(50,28);
        printf("Book Deleted");
    }
    fclose(fp);
    fclose(fp1);
    remove("C:\\Library Management\\book.txt");
    rename("C:\\Library Management\\tmp.txt","C:\\Library Management\\book.txt");
    getch();
}
//      ||||||||||||||||||||||||||||    Edit Book        ||||||||||||||||||||||||||||||||||
void mod_book()
{
    int flag=0,id;
    box();
    gotoxy(47,6);
    printf("Edit Book");
    gotoxy(18,10);
    printf("Book Id \t:");
    gotoxy(18,14);
    printf("Book Name \t:");
    gotoxy(18,18);
    printf("Author Name\t:");
    gotoxy(18,22);
    printf("Price \t:");
    gotoxy(18,26);
    printf("Quantity \t:");
    gotoxy(34,10);
    scanf("%d",&id);
    fp = fopen("C:\\Library Management\\book.txt","rb+");
    while(fread(&bk,sizeof(bk),1,fp)>0)
    {
        if(bk.bid==id)
        {
            gotoxy(40,28);
            printf("Type details to edit");
            gotoxy(34,10);
            bk.bid=id;
            fflush(stdin);
            gotoxy(34,14);
            gets(bk.name);
            gotoxy(34,18);
            gets(bk.auth);
            gotoxy(34,22);
            scanf("%f",&bk.price);
            gotoxy(34,26);
            scanf("%d",&bk.stok);
            fseek(fp,ftell(fp)-sizeof(bk),SEEK_SET);
            fwrite(&bk,sizeof(bk),1,fp);
            gotoxy(40,28);
            printf("Data Edited successfully");
            flag=1;
            fclose(fp);
            break;
        }
    }
    if(flag==0)
    {
        gotoxy(50,28);
        printf("NO data found");
    }
    getch();
}
//      |||||||||||||||||||||||||       Issue Book      |||||||||||||||||||||||||||||||||||
void issue()
{
    FILE *fp2;
    int s_id,b_id,flag=0;
    box();
    gotoxy(47,6);
    printf("Issue Book");
    gotoxy(18,10);
    printf("Student Id \t:");
    gotoxy(18,14);
    printf("Book Id \t:");
    gotoxy(18,18);
    printf("Student Name \t:");
    gotoxy(18,22);
    printf("Book Name\t:");
    gotoxy(18,26);
    printf("Author Name \t:");
    gotoxy(34,10);
    scanf("%d",&s_id);
    gotoxy(34,14);
    scanf("%d",&b_id);
    fp = fopen("C:\\Library Management\\issue.txt","ab+");
    fp1 = fopen("C:\\Library Management\\student.txt","rb+");
    fp2 = fopen("C:\\Library Management\\book.txt","rb+");
    while(fread(&stu,sizeof(stu),1,fp1)>0)
    {
        if(s_id==stu.id)
        {
            while(fread(&bk,sizeof(bk),1,fp2)>0)
            {
                if(bk.bid==b_id)
                {
                    is.stu=stu.id;
                    is.book=bk.bid;
                    strcpy(is.s_name,stu.name);
                    strcpy(is.b_name,bk.name);
                    strcpy(is.auth,bk.auth);
                    fwrite(&is,sizeof(is),1,fp);
                    gotoxy(34,18);
                    printf("%s",stu.name);
                    gotoxy(34,22);
                    printf("%s",bk.name);
                    gotoxy(34,26);
                    printf("%s",bk.auth);
                    gotoxy(50,28);
                    printf("Book issued");
                    Sleep(1500);
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==0)
    {
        gotoxy(47,28);
        printf("Wrong student or book id");
        Beep(635,500);
        Sleep(1500);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}
//      |||||||||||||||||||||||||       Return Book      |||||||||||||||||||||||||||||||||||
void re_book()
{
    int s_id,b_id,flag=0;
    box();
    gotoxy(47,6);
    printf("Return Book");
    gotoxy(18,10);
    printf("Student Id \t:");
    gotoxy(18,14);
    printf("Book Id \t:");
    gotoxy(18,18);
    printf("Student Name \t:");
    gotoxy(18,22);
    printf("Book Name\t:");
    gotoxy(18,26);
    printf("Author Name \t:");
    gotoxy(34,10);
    scanf("%d",&s_id);
    gotoxy(34,14);
    scanf("%d",&b_id);
    fp = fopen("C:\\Library Management\\issue.txt","rb+");
    fp1 = fopen("C:\\Library Management\\tmp.txt","wb+");
    while(fread(&is,sizeof(is),1,fp)>0)
    {
        if(is.stu==s_id && is.book==b_id)
        {
            flag=1;
            gotoxy(34,18);
            printf("%s",is.s_name);
            gotoxy(34,22);
            printf("%s",is.b_name);
            gotoxy(34,26);
            printf("%s",is.auth);
        }
        else
        {
            fwrite(&is,sizeof(is),1,fp1);
        }
    }
    if(flag==0)
    {
        gotoxy(47,28);
        printf("Wrong student or book id");
    }
    else
    {
        gotoxy(50,28);
        printf("Book Returned");
    }
    fclose(fp);
    fclose(fp1);
    remove("C:\\Library Management\\issue.txt");
    rename("C:\\Library Management\\tmp.txt","C:\\Library Management\\issue.txt");
    getch();
}
//      |||||||||||||||||||||||||       Show issued Book      |||||||||||||||||||||||||||||||||||
void si_book()
{
    int id;
    box();
    gotoxy(47,6);
    printf("Show Issued Book");
    gotoxy(18,10);
    printf("Student Id :");
    gotoxy(47,10);
    printf("Student Name :");
    gotoxy(16,12);
    for(int i=1;i<80;++i)
        printf("%c",196);
    gotoxy(47,13);
    printf("Issued Book list");
    gotoxy(16,14);
    for(int i=1;i<80;++i)
        printf("%c",196);
    gotoxy(17,15);
    printf("Sr. No. |");
    gotoxy(28,15);
    printf("Book Id  |");
    gotoxy(16,16);
    for(int i=1;i<80;++i)
        printf("%c",196);
    gotoxy(56,15);
    printf("Book Name");
    gotoxy(34,10);
    scanf("%d",&id);
    fp = fopen("C:\\Library Management\\issue.txt","rb+");
    int flag=0,j=0,sr=1;
    while(fread(&is,sizeof(is),1,fp)>0)
    {
        if(id==is.stu)
        {
            gotoxy(20,17+j);
            printf("%d.",sr);
            gotoxy(62,10);
            printf("%s",is.s_name);
            gotoxy(30,17+j);
            printf("%d",is.book);
            gotoxy(57,17+j);
            printf("%s",is.b_name);
            flag=1;
            j+=2;
            ++sr;
        }
    }
    if(flag==0)
    {
        gotoxy(50,28);
        printf("Data Not found");
    }
    fclose(fp);
    getch();
}
//      |||||||||||||||||||||||||       Main_Page   |||||||||||||||||||||||||||||
void main_page()
{
    char input;
    do
    {
        box();
        mini_box();
        gotoxy(47,6);
        printf("Library Management");
        gotoxy(44,12);
        printf("1. Student Management");
        gotoxy(44,16);
        printf("2. Book Management");
        gotoxy(44,20);
        printf("3. Book Transaction");
        gotoxy(44,24);
        printf("4. Close");
        gotoxy(45,28);
        printf("Input here :  ");
        input = getch();
        switch(input)
        {
        case '1':
            student();
            break;
        case '2':
            book();
            break;
        case '3':
            transaction();
            break;
        case '4':
            exit(0);
        default:
            main_page();
            break;
        }
    }while(input!=4);
}
void book()     //  |||||||||||||||||||||||||||| Book function      ||||||||||||||||||||||||||||||||||
{
    char input;
    do
    {
        box();
        gotoxy(47,6);
        printf("Book Management");
        gotoxy(44,10);
        printf("1. Add new Book");
        gotoxy(44,13);
        printf("2. Edit Book");
        gotoxy(44,16);
        printf("3. Show Book ");
        gotoxy(44,19);
        printf("4. Delete Book");
        gotoxy(44,22);
        printf("5. Back to Home");
        mini_box();
        gotoxy(45,28);
        printf("Input here :  ");
        input = getch();
        switch(input)
        {
        case '1':
            add_book();
            break;
        case '2':
            mod_book();
            break;
        case '3':
            show_book();
            break;
        case '4':
            del_book();
            break;
        case '5':
            main_page();
            break;
        default:
            book();
            break;
        }
    }while(input!=5);
}
void transaction()  // |||||||||||||||||||| Book Transaction    |||||||||||||||||||||||||||||||||||||||
{
    int input;
    do
    {
        box();
        gotoxy(47,6);
        printf("Book Transaction");
        gotoxy(44,10);
        printf("1. Issue Book");
        gotoxy(44,14);
        printf("2. Return Book");
        gotoxy(44,18);
        printf("3. Show Issued Book ");
        gotoxy(44,22);
        printf("4. Back to Home");
        mini_box();
        gotoxy(45,28);
        printf("Input here :  ");
        input = getch();
        switch(input)
            {
            case '1':
                issue();
                break;
            case '2':
               re_book();
                break;
            case '3':
                si_book();
                break;
            case '4':
                main_page();
                break;
            default:
                transaction();
                break;
            }
        }while(input!=4);
}
int main()      //  ||||||||||||||||||||||  Main Function   |||||||||||||||||||||||||||||||||||||||
{
    system("title Library Management");
    mkdir("C:\\Library Management");
    loading();
    login();
}
