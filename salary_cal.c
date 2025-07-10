#include <stdio.h>

void savetofile(char name[], float basic, float allowence, float tax, float net) {
    FILE *f = fopen("summary.txt", "w");
    if (f == NULL) {
        printf("Error opening file.\n");
    } else {
        fprintf(f, "Employee name  : %s", name);
        fprintf(f, "Basic salary   : %.2f\n", basic);
        fprintf(f, "Allowance      : %.2f\n", allowence);
        fprintf(f, "Tax            : %.2f\n", tax);
        fprintf(f, "Net salary     : %.2f\n", net);
        fclose(f);
    }
}


int main() {
    // Write C code here
    char name[100];
    float basic,allowence,tax,net;
    
    printf("enter employee name : ");
    fgets(name,sizeof(name),stdin);
    printf("enter basic salary : ");
    scanf("%f",&basic);
    
    allowence = basic*0.2;
    tax = basic*0.1;
    net = (allowence + basic - tax);
    
    printf("employee name -- %c\n",name);
    printf("basic salary --- %2f\n",basic);
    printf("Allowence ------ %2f\n",allowence);
    printf("Tax ------------ %2f\n",tax);
    printf("Net salary ----- %2f\n",net);
    
    savetofile(name, basic, allowence, tax, net);
    return 0;
}