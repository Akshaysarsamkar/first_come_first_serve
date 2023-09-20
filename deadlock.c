#include <stdio.h> 
  

 #define NUM_PROCESSES 5 
 #define NUM_RESOURCES 3 
  
 
 int isSafe(int available[], int max_claim[][NUM_RESOURCES], int allocation[][NUM_RESOURCES]) { 
     int work[NUM_RESOURCES]; 
     int finish[NUM_PROCESSES] = {0}; 
  

     for (int i = 0; i < NUM_RESOURCES; i++) { 
         work[i] = available[i]; 
     } 
  
     int count = 0; 
     while (count < NUM_PROCESSES) { 
         int found = 0; 
         for (int i = 0; i < NUM_PROCESSES; i++) { 
             if (!finish[i]) { 
                 int j; 
                 for (j = 0; j < NUM_RESOURCES; j++) { 
                     if (max_claim[i][j] - allocation[i][j] > work[j]) { 
                         break; 
                     } 
                 } 
                 if (j == NUM_RESOURCES) { 
                   
                     for (int k = 0; k < NUM_RESOURCES; k++) { 
                         work[k] += allocation[i][k]; 
                     } 
                     finish[i] = 1; 
                     found = 1; 
                     count++; 
                 } 
             } 
         } 
         if (!found) { 
           
             return 0; 
         } 
     } 
    
     return 1; 
 } 
  
 int main() { 
     int available[NUM_RESOURCES] = {3, 3, 2}; 
     int max_claim[NUM_PROCESSES][NUM_RESOURCES] = { 
         {7, 5, 3}, 
         {3, 2, 2}, 
         {9, 0, 2}, 
         {2, 2, 2}, 
         {4, 3, 3} 
     }; 
     int allocation[NUM_PROCESSES][NUM_RESOURCES] = { 
         {0, 1, 6}, 
         {2, 0, 0}, 
         {3, 3, 2}, 
         {2, 1, 1}, 
         {6, 1, 2} 
     }; 
  
    
     if (isSafe(available, max_claim, allocation)) { 
      
         int minimum_resources_needed[NUM_RESOURCES]; 
         for (int i = 0; i < NUM_RESOURCES; i++) { 
             minimum_resources_needed[i] = 0; 
             for (int j = 0; j < NUM_PROCESSES; j++) { 
                 minimum_resources_needed[i] += max_claim[j][i] - allocation[j][i]; 
             } 
         } 
  
         printf("Minimum resources needed to avoid deadlock: "); 
         for (int i = 0; i < NUM_RESOURCES; i++) { 
             printf("%d ", minimum_resources_needed[i]); 
         } 
         printf("\n"); 
     } else { 
         printf("System is not in a safe state. Adjust resources.\n"); 
     } 
  
     return 0; 
 }
