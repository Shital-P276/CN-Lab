#include <stdio.h>
#include<math.h>
int main()
{
    int m_size, r = 0, i, j, k;
    printf("Enter the size (in bits) of message : ");
    scanf("%d", &m_size);
    while (1)
    {
        if ((m_size + r + 1) <= pow(2, r))
            break;
        r++;
    }
    int msg[m_size + 1];
    printf("Enter the message (seperated by space) : ");
    for (i = m_size; i >= 1; i--)
    {
        scanf("%d", &msg[i]);
    }
    printf("\n");
    int data[m_size + r + 1];
    int rc = 0;
    int m = 1;
    for (i = 1; i < m_size + r + 1; i++)
    {
        if (i == pow(2, rc))
        {
            data[i] = 99;
            rc++;
        }
        else
        {
            data[i] = msg[m];
            m++;
        }
    }

    for (i = 1; i < m_size + r + 1; i++)
    {
        if (data[i] == 99)
        {
            int count = 0;
            for (j = i; j < m_size + r + 1; j++)
            {
                for (k = 0; k < i; k++)
                {
                    if (data[j] == 1)
                    {
                        count++;
                    }
                    j++;
                }
                j = j + i - 1;
            }
            if (count % 2 == 0)
            {
                data[i] = 0;
            }
            else
            {
                data[i] = 1;
            }
        }
    }
    printf("The generated codeword : ");
    for (i = m_size + r; i >= 1; i--)
    {
        printf("%d", data[i]);
    }
    printf("\n---\n");
    printf("Enter the codeword received (Seperated by space): ");

    for (i = m_size + r; i >= 1; i--)
    {
        scanf("%d", &data[i]);
    }

    int parities[r];
    for (i = 0; i < r; i++)
    {
        parities[i] = 0;
    }

    int c = 0;
    for (i = 1; i < m_size + r + 1; i++)
    {
        if (i == pow(2, c))
        {
            int count = 0;
            for (j = i; j < m_size + r + 1; j++)
            {
                for (k = 0; k < i; k++)
                {
                    if (data[j] == 1)
                    {
                        count++;
                    }
                    j++;
                }
                j = j + i - 1;
            }
            if (data[i] == 1)
            {
                count--;
            }
            if (count % 2 == data[i])
            {
                parities[c] = 0;
            }
            else if (count % 2 != data[i])
            {
                parities[c] = 1;
            }
            c++;
        }
    }

    c = 0;
    for (i = 0; i < r; i++)
    {
        c += parities[i] * (pow(2, i));
    }

    if (c == 0)
    {
        printf("No error\n");
        return 0;
    }
    printf("Error at position : %d\n", c);
    if (data[c] == 0)
    {
        data[c] = 1;
    }
    else
    {
        data[c] = 0;
    }
    printf("Code after error correction is : ");
    for (i = m_size + r; i >= 1; i--)
    {
        printf("%d", data[i]);
    }
    printf("\n");
    return 0;
}
