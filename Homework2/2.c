
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //Open the CSV file for reading
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }
    
    char line[1024];
    int row_count = 0;
    
    //Reading the first line, which holds the column names
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("File is empty or cannot be read.\n");
        fclose(file);
        return 1;
    }
    row_count = row_count + 1;
    
    //Splitting the header line into column names
    char *fields[100]; //Array to store column names
    int field_count = 0;
    char *token = strtok(line, ",\n"); //Tokenize the first line by commas. Tokenizing is splitting the line by commas, and every element which was seperated is consodered a token
    while (token != NULL) {
        fields[field_count] = token; //Store column name
        field_count = field_count + 1;
        token = strtok(NULL, ",\n"); //Move to the next token
    }
    
    //Printing column names
    printf("Columns:\n");
    for (int i = 0; i < field_count; i = i + 1) {
        printf("%d: %s\n", i + 1, fields[i]); //Print column index and name
    }
    
    //Count the number of rows in the file
    while (fgets(line, sizeof(line), file) != NULL) {
        row_count = row_count + 1; //Increment row count for each line read
    }
    rewind(file); //Reset file pointer to the beginning
    fgets(line, sizeof(line), file); //Skip header row
    
    //Print total number of rows and columns
    printf("Total rows (including header): %d\n", row_count);
    printf("Total columns: %d\n", field_count);
    
    //Ask user for column selection
    int column;
    printf("Enter the column number to search: ");
    if (scanf("%d", &column) != 1 || column < 1 || column > field_count) {
        printf("Invalid column number.\n");
        fclose(file);
        return 1;
    }
    getchar(); //Consume newline from input buffer to avoid issues with fgets()
    
    //Ask user for the search value
    char search_value[100];
    printf("Enter the search value: ");
    fgets(search_value, sizeof(search_value), stdin);
    search_value[strcspn(search_value, "\n")] = 0; //Remove the newline character at the end
    
    //Search and print matching rows
    printf("Matching rows:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        int count = 0; //Counter to track column index
        token = strtok(line, ",\n"); //Tokenize the current row
        
        while (token != NULL) {
            //If token matches the search value in the selected column
            if (count == column - 1 && strcmp(token, search_value) == 0) {
                printf("%s\n", line); // Print the entire row
                break; //No need to check further columns in this row
            }
            token = strtok(NULL, ",\n"); //Move to the next token
            count = count + 1; //Increment column count
        }
    }
    
    //Close the file after searching
    fclose(file);
    printf("\n");
    return 0;
}
