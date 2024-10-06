/*
Author: Shayton Wright
Date: 10/5/2024
Purpose: Take an inputed temperature from the user and what their measurement system is and then return their 
converted temperature in their selected measurement standard.
*/
#include <stdio.h>
#include <math.h>
float current_temp; //Initialize the current temp variable as a float.
int current_scale; //Initialize the current scale variable as a int.
int convert_scale; //Initialize the convert scale variable as a int.

float celsius_to_fahrenheit (float celsius){ //Lines 13-17. Function to convert celsius to fahrenheit. Prints the fahrenheit value and returns it as well.
    float fahr = (((9.0/5.0) * celsius) + 32.0);
    printf("Temperature Conversion: %.3f°F", fahr);
    return fahr;
}
float celsius_to_kelvin(float celsius){ //Lines 18-22. Function to convert celsius to kelvin. Prints the kelvin value and returns it as well.
    float kelv = (celsius + 273.15);
    printf("Temperature Conversion: %.3fK", kelv);
    return kelv;
}
float fahrenheit_to_celsius(float fahr){ //Lines 23-27. Function to convert fahrenheit to celsius. Prints the celsius value and returns it as well.
    float cels = ((5.0/9.0)* (fahr - 32));
    printf("Temperature Conversion: %.3f°C", cels);
    return cels;
}
float kelvin_to_celsius(float kelv){ //Lines 28-32. Function to convert kelvin to celsius. Prints the celsius value and returns it as well.
    float cels = (kelv - 273.15);
    printf("Temperature Conversion: %.3f°C", cels);
    return cels;
}
float kelv_to_cels_no_print(float kelv){ //Another format of the kelvin to celsius function but doesn't print the value. Simply returns it instead.
    float cels = (kelv - 273.15);
    return cels;
}
float fahr_to_cels_no_print(float fahr){ //Another format of the fahrenheit to celsius function but doesn't print the value. Simply returns it instead.
    float cels = ((5.0/9.0) * (fahr - 32));
    return cels;
}
float cat_and_adv(float celsius){ //Lines 41-57. Function that takes an inputed celsius value and prints out the correct temperature categorization and a corresponding advisory according to the assignment instructions.
    if (celsius < 0.0){
        printf("\nTemperature: Freezing.\nWeather Advisory: You should bundle up, it's very cold outside.");
    }
    else if(celsius < 10.0){
        printf("\nTemperature Category: Cold.\nWeather Advisory: Wear a jacket.");
    }
    else if (celsius < 25.0){
        printf("\nTemperature Category: Comfortable.\nWeather Advisory: You should feel comfortable.");
    }
    else if (celsius < 35.0){
        printf("\nTemperature Category: Hot.\nWeather Advisory: High temperatures, stay hydrated.");
    }
    else{
        printf("\nTemperature Category: Extreme Heat.\nWeather Advisory: Stay inside. Dangerously high temperatures.");
    }
}
int main(){ //Initialize main function.
    printf("Enter the temperature: "); //Prints temperature prompt
    scanf("%f", &current_temp); //Takes in current temperature as a float.
    printf("Enter Current Scale (1)Celsius (2)Fahrenheit (3)Kelvin: "); //Prints current scale prompt
    scanf("%d", &current_scale); //Takes in current scale as an int.
    printf("Select Scale to Convert To (1)Celsius (2)Fahrenheit (3)Kelvin: "); //Prints scale to convert to prompt.
    scanf("%d", &convert_scale); //Takes in scale to convert to as an int
    while (1){ //While loop that will only break when told to by outputing a valid input case.
        if (current_temp <= 0 && current_scale == 3){ // Checks case in which we have a negative or 0 Kelvin which is impossible.
            printf("Error: Cannot have negative Kelvin values."); //Lines 67-73. Displays error to user and re-prompts them to fill in the options again.
            printf("\nEnter the temperature: ");
            scanf("%f", &current_temp);
            printf("Enter Current Scale (1)Celsius (2)Fahrenheit (3)Kelvin: ");
            scanf("%d", &current_scale);
            printf("Select Scale to Convert To (1)Celsius (2)Fahrenheit (3)Kelvin: ");
            scanf("%d", &convert_scale);
        }
        else if (current_scale == convert_scale){ //Checks case that the user wants to convert to the scale they already entered which isn't allowed.
            printf("Error: Cannot convert to the same scale."); //Lines 76-82. Displays error to user and re-prompts them to fill in the options again.
            printf("\nEnter the temperature: ");
            scanf("%f", &current_temp);
            printf("Enter Current Scale (1)Celsius (2)Fahrenheit (3)Kelvin: ");
            scanf("%d", &current_scale);
            printf("Select Scale to Convert To (1)Celsius (2)Fahrenheit (3)Kelvin: ");
            scanf("%d", &convert_scale);
        }
        else if(current_scale > 3 || current_scale < 1){ //Checks case in which the user doesn't enter a valid temperature scale option.
            printf("Error: Invalid Current Scale"); //Lines 85-91. Displays error to user and re-prompts them to fill in the options again.
            printf("\nEnter the temperature: ");
            scanf("%f", &current_temp);
            printf("Enter Current Scale (1)Celsius (2)Fahrenheit (3)Kelvin: ");
            scanf("%d", &current_scale);
            printf("Select Scale to Convert To (1)Celsius (2)Fahrenheit (3)Kelvin: ");
            scanf("%d", &convert_scale);
        }
        else{ //If input cases are valid. We continue with the conversion for the user.
            if (current_scale == 1 && convert_scale == 2){ //Conversion case if converting celsius to fahrenheit.
                celsius_to_fahrenheit(current_temp);
                cat_and_adv(current_temp);
            }
            else if (current_scale == 1 && convert_scale == 3){ //Conversion case if converting celsius to kelvin.
                celsius_to_kelvin(current_temp);
                cat_and_adv(current_temp);
            }
            else if (current_scale == 2 && convert_scale == 1){ //Conversion case if converting fahrenheit to celsius.
                cat_and_adv(fahrenheit_to_celsius(current_temp));
            }
            else if (current_scale == 2 && convert_scale == 3){ //Conversion case if converting fahrenheit to kelvin.
                celsius_to_kelvin(fahr_to_cels_no_print(current_temp)); //Call cels to kelv function with fahr to cels as input
                cat_and_adv(fahr_to_cels_no_print(current_temp));
            }
            else if (current_scale == 3 && convert_scale == 1){ //Conversion case if converting kelvin to celsius.
                cat_and_adv(kelvin_to_celsius(current_temp));
            }
            else{ //Conversion case if converting kelvin to fahrenheit.
                celsius_to_fahrenheit(kelv_to_cels_no_print(current_temp)); //Call cels to fahr function with kelv to cels as input
                cat_and_adv(kelv_to_cels_no_print(current_temp));
            }
        break; //Breaks after outputing a valid case
        }
    }
    return 0; //Returns int 0.
}