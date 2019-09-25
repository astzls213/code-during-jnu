#include "mystd.h"

int main() {
    int i;//count for addingStudent's scale.
    puts("How many students in your class? WARN: Can't >100");
    while(scanf("%d",&i)!=1||i<1)
        puts("Must be a positive integer!Again!");

    while (getchar()!='\n')// clean buffer.
        continue;

    Student students=addStudents(i);// begin to add students.

    puts("Well done! Now just select a operation you want!");
    while(1)
    {
        puts("*--------------------*");
        puts("*1.  adding score    *");
        puts("*2.  delete score    *");
        puts("*3.  change score    *");
        puts("*4.delete a student  *");
        puts("*5.print sb all Score*");
        puts("*6.      EXIT        *");
        puts("*--------------------*");
        int flag;

        scanf("%d",&flag);

        while (getchar()!='\n')
            continue;// clean buffer.If not, may be error when next input.

        switch(flag){
            case 1:
                addScore(students);break;
            case 2:
                deleteScore(students);break;
            case 3:
                changeScore(students);break;
            case 4:
                students=deleteAStudent(students);break;
            case 5:
                printScoreList(students);break;
            case 6:
                break;
            default:
                puts("Invalid input!");
        }
        if(flag==6)
            break;
    }
    puts("Bye!~");
    return 0;
}