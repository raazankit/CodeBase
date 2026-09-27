#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int data[20], hamming[30];
    int m, r = 0, i, j, k = 0;

    cout << "Enter number of data bits: ";
    cin >> m;

    while (pow(2, r) < (m + r + 1))
        r++;

    cout << "Enter data bits:\n";
    for (i = m - 1; i >= 0; i--)
        cin >> data[i];

    int total = m + r;

    k = 0;
    for (i = 1; i <= total; i++)
    {
        // Check if i is a power of 2
        if ((i & (i - 1)) == 0)
            hamming[i] = 0;
        else
            hamming[i] = data[k++];
    }

    for (i = 0; i < r; i++)
    {
        int pos = pow(2, i);
        int parity = 0;

        for (j = 1; j <= total; j++)
        {
            if (j & pos)
                parity ^= hamming[j];
        }

        hamming[pos] = parity;
    }

    cout << "\nGenerated Hamming Code:\n";

    for (i = total; i >= 1; i--)
        cout << hamming[i];

    cout << endl;

    int received[30];

    cout << "\nEnter received code:\n";

    for (i = total; i >= 1; i--)
        cin >> received[i];

    int error = 0;

    for (i = 0; i < r; i++)
    {
        int pos = pow(2, i);
        int parity = 0;

        for (j = 1; j <= total; j++)
        {
            if (j & pos)
                parity ^= received[j];
        }

        if (parity)
            error += pos;
    }

    if (error == 0)
    {
        cout << "\nNo Error Detected.\n";
    }
    else
    {
        cout << "\nError Detected at Position " << error << "\n";

        // Flip the erroneous bit
        received[error] ^= 1;

        cout << "Corrected Code:\n";

        for (i = total; i >= 1; i--)
            cout << received[i];

        cout << endl;
    }

    return 0;
}