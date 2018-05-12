#include <stdio.h>
#include <math.h>

int get_digits(long long num)
{
    return (int) floor(log10(num));
}

int get_digit_sum(int n)
{
    return (int) (n / 10) + (n % 10);
}

int main(void)
{
    long long credit_card;
    printf("Number: ");
    scanf("%lld", &credit_card);

    int digits = get_digits(credit_card);
    int sum = 0;
    int first_digits = 0;
    digits++;

    for (int i = 0; i < digits; i++) {
        if (i & 1) //if i is an odd number
        {
            sum += get_digit_sum(2 * (credit_card % 10));
        }
        else {
            sum += credit_card % 10;
        }


        if (i == digits - 2)
        {
            first_digits = credit_card % 10;
        }
        else if (i == digits - 1)
        {
            first_digits = first_digits + (credit_card % 10) * 10;
        }
        credit_card /= 10;
    }
    
    if (!(sum % 10))
    {
        if (digits == 15 && (first_digits == 34 || first_digits == 37)) {
            printf("AMEX\n");
        }
        else if (digits == 16 && ((first_digits >= 50 && first_digits <= 55) || (first_digits >= 22 && first_digits <= 27)))
        {
            printf("MASTERCARD\n");
        }
        else if ((digits >= 13 && digits <= 16) && (first_digits / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
        //printf("VALID\n");
    }
    else {
        printf("INVALID\n");
    }

    return 0;
}
