/**
 * @file MedicalStore.h
 * @author Saurabh Dubey (https://github.com/Saurabhdubey592)
 * @brief Medical store system can manage the medicine information in the store.
 * @version 0.1
 * @date 2021-07-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __MEDICALSTORESYSTEM_H__
#define __MEDICALSTORESYSTEM_H__

 #include<stdio.h>
 #include <string.h>

/**
  * @brief function is used to purchase a medicine from the store.
  * 
  * @return function will return whether the purchase is successful or not.
  */
 void PurchaseMedicine();

/**
  * @brief Adding medicine information into the store.
  * 
  * @return Function helps in adding the details of the medicine.
  */
 void AddMedicineinStore();

 /**
 * @brief We can know the information about the medicine.
 * 
 * @return Function returns the information of the medicine like uses and price.
 */
 void KnowInfoAboutMedicine();

 /**
  * @brief Deleting the required medicine from the medical store.
  * 
  * @return Function helps in deleting the medicine by taking medicine name as input.
  */
 void DeleteMedicine();

 /**
  * @brief List of available medicines in the store is shown.
  * 
  * @return Function helps in displaying all the information of the medicines present in the store.
  */
 void ListOfMedicines();
#endif
