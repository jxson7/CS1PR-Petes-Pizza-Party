#include <stdio.h>

static float sum(float a, float b); // declaration

float total;

// this function is impure
void printTaxedReceipt(float values[], float num_values){
	total = 0; // this is impure as we access a global state

	// Updated to work out the total tax paid too
	float totalTax = 0;
	for(int i = 0; i < num_values; i++) {
	    float tax = values[i] * 0.2;
	    // add this tax to the running total
	    totalTax = sum(totalTax, tax); // is sum pure?
	    // add this value plus the tax to the running total
	    total = sum(values[i] + tax, total);
 	}
	printf("Total Price: %.2f\nTotal Tax: %.2f\n", total, totalTax); // printf is impure as the sideeffect is printing on stdout
}

// pure implementation of sum:
static float sum(float a, float b){
  return a+b;
}

int main(){
	printTaxedReceipt((float[2]){10, 15}, 2);
  return 0;
}
