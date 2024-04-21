#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include <string.h>
#include <unistd.h>

#define MAX_ENTRY_SIZE 3
#define MAX_CURRENCIES 10
#define MAX_URL_LENGTH 100
#define MAX_SCRIPT_LENGTH 200

/* Preview functions */
void printSymbol(char*);
void getInput(float *amountToConvert, char* baseCurrency, char **targetCurr);
int isDollar(char* currency);
int isPound(char* currency);
int isRupee(char* currency);
int isFranc(char* currency);


int main(int argc, char* argv[]) {
    /* Create some variables and constants */
    float amountToConvert;
    char* baseCurrency;
    char **targetCurr = (char**) malloc(sizeof(char*) * MAX_CURRENCIES);
    char *script = (char*) malloc(sizeof(char) * MAX_SCRIPT_LENGTH);
    char *url = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);
    const char *urlBase = "URL=\"https://api.currencybeacon.com/v1/latest?base=";
    const char *apiKey = "&api_key=LIC5zNao9c026OJdEfOV8ILIwDV8Bvqs\"";
    const char *response = "response=$(curl -s -w \"%{http_code}\" $URL)";
    const char *echo = "echo \"$response\" > currency_rates.json";

    /* Check to make sure 2 arguments were passed */
	if (argc < 2) {
        printf("Failed to provide input. See -help for info.\n");
		/* getInput(&amountToConvert, baseCurrency, targetCurr); */
        return 1;
	}

    /* If user enters '-help', display usage details */
    else if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf("--Help menu--\n");
        printf("Program expects to receive input from command-line arguments\n");
        printf("Argument 1: Amount of currency to convert.\n");
        printf("Argument 2: Currency to convert from (3 character abbreviation).\n");
        printf("Argument 3+: Currency to convert to (3 character abbreviation). Enter up to 10 currencies.\n");
        printf("Example: 1000 USD EUR CNY GBP JPY\n");
        printf("Converts $1000 US Dollars to Euro, Yuan, Pound, and Yen.\n");
        return 0;
    }

    /* Read arguments */
	else {
        /* Convert current value to float */
	    amountToConvert = atof(argv[1]);
        /* Read base currency */
        baseCurrency = argv[2];
        /* Loop through remaining currencies and add to array */
        int i;
        for (i = 3; i < argc; i++){
            /* Allocate space for each string */
            targetCurr[i - 3] = (char*) malloc(strlen(argv[i]) + 1);
            /* If allocation is unsuccessful, alert user and exit */
            if (targetCurr[i - 3] == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }
            /* Copy command-line input to array */
            else {
                strcpy(targetCurr[i - 3], argv[i]);
            }
        }
    }

    /* Prepare bash script */
    strcat(url, urlBase);
    strcat(url, baseCurrency);
    strcat(url, apiKey);
    strcat(script, url);
    strcat(script, "\n");
    strcat(script, response);
    strcat(script, "\n");
    strcat(script, echo);
    strcat(script, "\n");
    
    /* Print summary of the upcoming conversion */
    printf("Converting ");
    printSymbol(baseCurrency);
    printf("%.2f %s to ", amountToConvert, baseCurrency);
    int i;
    for (i = 0; i < argc - 3; i++) {
        printf("%s", targetCurr[i]);
        if (i < argc - 4) {
            printf(", ");
        }
        else {
            printf("\n");
        }
    }

    /* Execute script to retrieve live exchange rates*/
    system(script);

    /* Create a variable to hold json data */
    FILE *data = fopen("currency_rates.json", "r");
    /* Alert user if file did not open successfully */
    if (data == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    /* Create a buffer for data, fill with data from file, close file*/
    char buffer[10240];
    fread(buffer, 1, sizeof(buffer), data);
    fclose(data); 

    /* Parse json data */
    cJSON *json = cJSON_Parse(buffer); 
    /* Look for 'rates' key in JSON data */
    cJSON *rates = cJSON_GetObjectItemCaseSensitive(json, "rates"); 
    cJSON *rate = NULL;
    printf("Checking rates...\n"); 
    printSymbol(baseCurrency);
    printf("%.2f %s is:\n", amountToConvert, baseCurrency);
    /* Loop through target currencies */
    int k;
    for (k = 0; k < argc - 3; k++) {
        int found = 1;
        /* Confirm currency exists in JSON data
           return 0 if true */
        cJSON_ArrayForEach(rate, rates) {
            char *thisRate = rate->string;
            if (strcmp(thisRate, targetCurr[k]) == 0) {
                found = 0;
            }
        }
        if (found == 0) {
            /* Retrieve exchange rate for current currency */
            double rate = cJSON_GetObjectItem(rates, targetCurr[k])->valuedouble;
            /* Perform conversion and print result */
            double conversion = amountToConvert * rate;
            printSymbol(targetCurr[k]);
            printf("%.2f %s\n", conversion, targetCurr[k]);
        }
        else {
            printf("Unable to locate matching currency.\n");
        }
    }
     
    /* Cleanup */
    cJSON_Delete(json);
    int j;
    for (j = 0; i < argc - 3; j++) {
        free(targetCurr[j]);
    }
    free(targetCurr);
    
    return 0;
}

/* A function to match currency to its symbol for aesthetic purposes only */
void printSymbol(char* currency) {
    /* Print matching currency symbol */
    if (isDollar(currency) == 0) {
        printf("$");
    }
    else if (strcmp(currency, "EUR") == 0) {
        printf("€ ");
    }
    if (isPound(currency) == 0) {
        printf("£ ");
    }
    else if (strcmp(currency, "JPY") == 0) {
        printf("¥ ");
    }
    else if (strcmp(currency, "CNY") == 0) {
        printf("¥ ");
    }
    else if (strcmp(currency, "INR") == 0) {
        printf("₹ ");
    }
    else if (strcmp(currency, "VND") == 0) {
        printf("₫ ");
    }
    else if (isRupee(currency) == 0) {
        printf("Rs ");
    }
    else if (isFranc(currency) == 0) {
        printf("Fr ");
    }
    else {
        printf(" ");
    }
}

/* A function to get input from the user if it is not supplied via command-line arguments */
void getInput(float *amountToConvert, char* baseCurrency, char **targetCurr) {
    /* Create temp string to hold input */
    char* temp = (char*) malloc(sizeof(char) * 10);
    int numCurr;

    /* Get amount to convert from user */
    printf("Enter amount to convert: ");
    fgets(temp, 10, stdin);

    /* Convert and save user input */
    *amountToConvert = atof(temp);

    /* Get base currency from user */
    printf("Enter base currency: ");
    fgets(temp, 10, stdin);

    /* Save base currency */
    baseCurrency = temp;

    printf("How many currencies would you like to convert to: ");
    fgets(temp, 2, stdin);
    numCurr = atoi(temp);

    /* Loop until all currencies have been entered */
    int i = 0;
    while (i < numCurr) {
        printf("Enter target currency: ");
        fgets(temp, 4, stdin);
        /* Allocate space for string */
        targetCurr[i] = (char*) malloc(strlen(temp) + 1);
        if (targetCurr[i] == NULL) {
            printf("Memory allocation failed.\n");
        }
        /* Copy input value to string array */
        strcpy(targetCurr[i], temp);
        i++;
    }
}

int isDollar(char* currency) {
    /* Create an array of currencies that use $ */
    const char* array[] = {"ARS", "AUD", "BBD", "BMD", "BND", "BSD", 
    "BZD", "CAD", "CLP", "COP", "CUC", "CUP", "CVE", "DOP", "FJD", "GYD",
    "HKD", "JMD", "KYD", "LRD", "MXN", "NAD", "NZD", "SBD", "SGD", "SRD", 
    "TTD", "TWD", "USD", "UYU", "XCD", "ZWL"
    };
    int i;
    /* Loop through array looking for input currency, return 0 if found */
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        if (strcmp(currency, array[i]) == 0) {
            return 0;
        }
    }
    /* Return 1 if not found */
    return 1;

}

int isPound(char* currency) {
    /* Create an array of currencies that use $ */
    const char* array[] = {"FKP", "GBP", "GIP", "SDG", "SHP"
    };
    int i;
    /* Loop through array looking for input currency, return 0 if found */
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        if (strcmp(currency, array[i]) == 0) {
            return 0;
        }
    }
    /* Return 1 if not found */
    return 1;

}

int isRupee(char* currency) {
    /* Create an array of currencies that use $ */
    const char* array[] = {"LKR", "MUR", "NPR", "PKR", "SCR"
    };
    int i;
    /* Loop through array looking for input currency, return 0 if found */
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        if (strcmp(currency, array[i]) == 0) {
            return 0;
        }
    }
    /* Return 1 if not found */
    return 1;

}

int isFranc(char* currency) {
    /* Create an array of currencies that use $ */
    const char* array[] = {"BIF", "CDF", "GNF", "KMF", "XAF", "XOF", "XFP"
    };
    int i;
    /* Loop through array looking for input currency, return 0 if found */
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        if (strcmp(currency, array[i]) == 0) {
            return 0;
        }
    }
    /* Return 1 if not found */
    return 1;

}
