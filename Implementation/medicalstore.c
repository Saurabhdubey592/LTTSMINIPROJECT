#include<stdio.h>
#include<string.h>

/**
 * @brief structure is used to store the medicine details.
 * 
 */
struct MedicineDetails{
    int id,price,quantity;
    char med_Name[100],Mfg_Date[11],Exp_Date[11],info[5000];
}m[100];

void PurchaseMedicine();
void AddMedicineinStore();
void KnowInfoAboutMedicine();
void DeleteMedicine();
void ListOfMedicines();
int num=0;

/**
 * @brief taking input from the user and produce output accordingly
 * 
 */
void main(){
    int ch;
    int decision;
    printf("======================================================\n");
	printf("   ~~~~~~~MEDICAL STORE SYSTEM~~~~~~~\n");
	printf("======================================================\n");
	printf("\n1:PURCHASE A MEDICINE\n");
	printf("2:ADD MEDICINE DETAILS\n");
    printf("3:INFORMATION ABOUT THE MEDICINE\n");
    printf("4:DELETE A MEDICINE\n");
    printf("5:LIST OF MEDICINES\n");
 	printf(".....Select the option of your choice.....\n");
	scanf("%d", &ch);
    switch(ch) {
        case 1:
            PurchaseMedicine();
            break;
        case 2:
                AddMedicineinStore();
                break;
            case 3:
                KnowInfoAboutMedicine();
                break;
            case 4:
                DeleteMedicine();
                break;
            case 5:
                ListOfMedicines();
                break;
            default:
                break;
        }
        printf("--------Do you want to do anything else?--------\n");
        printf("Enter 1 to continue with other options and any other number to exit: ");
        scanf("%d", &decision);
        if(decision == 1){
            main();
        } else {
            printf("\n---------THANK YOU---------");
        }
      return;
 }
 
 /**
  * @brief function is used to purchase a medicine from the store.
  * 
  * @return function will return whether the purchase is successful or not.
  */
 void PurchaseMedicine() {
     int med,q;
     char name[100];
     int n;
     printf("\nEnter medicine name to purchase: ");
     scanf("%s", name);
     for(int i=0; i<num; i++) {
         if(strcmp(m[i].med_Name, name)==0) {
             printf("\nEnter quantity:");
             scanf("%d", &q);
             if(m[i].quantity >= q) {
                 m[i].quantity-=q;
                printf("%s purchase done",m[i].med_Name);
                return;
             } else {
                 printf("Required quantity is not available\n");
                 printf("Available quantity is: %d\n", m[i].quantity);
                 printf("Do you want to buy?(press 1 for yes and any other number for no): ");
                 scanf("%d", &n);
                 if(n==1) {
                     printf("Enter quantity:\n");
                     scanf("%d", &q);
                     m[i].quantity-=q;
                    printf("%s purchase done\n",m[i].med_Name);
                    return;
                 } else {
                     printf("\nThankyou");
                     return;
                 }
             }
         }
     }
     printf("Medicine not found\n");
     
 }
 
 /**
  * @brief Adding medicine information into the store.
  * 
  * @return Function helps in adding the details of the medicine.
  */
 void AddMedicineinStore()
 {
     char name[100];
     int q;
     printf("\nEnter name of the medicine: ");
     scanf("%s", name);
     printf("Enter quantity: ");
     scanf("%d", &q);
     for(int i=0; i<num; i++) {
         if(strcmp(m[i].med_Name, name) == 0) {
             m[i].quantity+=q;
             return;
         }
     }
  printf("Enter Medicine Id: ");
  scanf("%d",&(m[num].id));
  strcpy(m[num].med_Name,name);
  printf("Enter Manufactured Date: ");
  scanf("%s",m[num].Mfg_Date);
  printf("Enter Expiry Date: ");
  scanf("%s",m[num].Exp_Date);
  printf("Enter Price: ");
  scanf("%d",&(m[num].price));
  m[num].quantity=q;
  printf("Enter information: ");
  scanf("%s", m[num].info);
  printf("Medicine with id %d Added Successfully\n",m[num].id);
  num++;
 }

/**
 * @brief We can know the information about the medicine.
 * 
 * @return Function returns the information of the medicine like uses and price.
 */
 void KnowInfoAboutMedicine() {
     char name[100];
     printf("Enter medicine name for information: ");
     scanf("%s", name);
     for(int i=0; i<num; i++) {
         if(strcmp(m[i].med_Name, name) == 0) {
             printf("Used to cure: %s, Price: %d\n", m[i].info, m[i].price);
             return;
         }
     }
     printf("Medicine not found\n");
 }
 
 /**
  * @brief Deleting the required medicine from the medical store.
  * 
  * @return Function helps in deleting the medicine by taking medicine name as input.
  */
 void DeleteMedicine() {
     char name[100];
     int i;
     printf("Enter name of medicine: ");
     scanf("%s",name);
     for(i=0;i<num;i++){
         if(strcmp(m[i].med_Name, name) == 0)
             break;
     }
     if(i==num) {
         printf("Medicine not found\n");
     } else {
         for(int j=i; j<num; j++) {
             m[j]=m[j+1];
         }
         num--;
         printf("Medicine deleted Successfully\n");
     }
     return;
 }
 

 /**
  * @brief List of available medicines in the store is shown.
  * 
  * @return Function helps in displaying all the information of the medicines present in the store.
  */
 void ListOfMedicines() {
     if(num!=0) {
        printf("ID\tNAME\tPRICE\tQUANTITY\tINFORMATION\n");
        for(int i=0; i<num; i++) {
            printf("%d\t%s\t%d\t%d\t\t%s\n", m[i].id, m[i].med_Name, m[i].price, m[i].quantity, m[i].info);
        }
     } else {
     printf("No medicines available\n");
     }
 }
