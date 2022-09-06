#include <iostream>
using namespace std;

int sum1(int cardNumbers[], int length){
    int sum = 0;
    cout << "sum1=";
    for (int i = 0; i < length -1; i=i+2) {
        int digit = cardNumbers[i] * 2;
        if(digit>=10){
            digit = digit-9;
        }
        cout << "+" << digit;
        sum += digit;
    }
    cout << "=" << sum << endl;
    return sum;
}

int sum2(int cardNumbers[], int length){
    int sum = 0;
    cout << "sum2=";
    for (int i = 1; i < length -1; i=i+2) {
        int digit = cardNumbers[i];
        cout << "+" << digit;
        sum += digit;
    }
    cout << "=" << sum << endl;
    return sum;
}

int main()
{
    const int max = 20;
    int cardNumbers[max];
    int size = 0;
    for (int i = 0; i < max; i++)
    {
        int temp;
        cout << "Enter card digit at position (assuming it as 1 digit) " << i + 1 << ": ";
        cin >> temp;
        if(temp == -1){
            break;
        }
        size++;
        cardNumbers[i] = temp;
    }
    int sumOne = sum1(cardNumbers, size);
    int sumTwo = sum2(cardNumbers, size);
    int total = (sumOne + sumTwo)*9;
    cout << "TOTAL : " << total << endl;
    int rightMostDigit = total%10;
    cout << "RIGHT MOST DIGIT : " << rightMostDigit << ", CARD LAST DIGIT : " << cardNumbers[size-1] << endl;
    if(rightMostDigit == cardNumbers[size-1]){
        cout << "VALID CARD NUMBER";
    } else{
        cout << "INVALID CARD NUMBER";
    }
    return 0;
}