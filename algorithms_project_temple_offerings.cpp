/*
-----------------------------------------------------------------------------------------------------
*** Misr International University            | Faculty of Computer Science
*** SWE 212 — Algorithms Analysis & Design   | temple offerings using Dynamic programming with C++
*** Developed on 02/06/22 by:                | Mohamed Khaled & Abdulrahman Sakr.
-----------------------------------------------------------------------------------------------------
Time complexity: O(n)
*/

#include <iostream>
using namespace std;

struct Temple
{
    int L; // the left view
    int R; // the right view
};

void offeringNumber(int n, int templeHeight[])
{

    Temple* flowers = new Temple[n];

    for (int i = 0; i < n; i++) // fills the array of left and right with nulls
    {
        flowers[i].L = -1;
        flowers[i].R = -1;
    }

    flowers[0].L = 1; // puts the first flower with 1 because it is the minimum number that can be used
    flowers[n - 1].R = 1;

    for (int i = 1; i < n; i++)
    {

        if (templeHeight[i - 1] < templeHeight[i])
            flowers[i].L = flowers[i - 1].L + 1;   // if the second temple is higher than the first add one flower

        else
            flowers[i].L = 1; // if the other temple is lower than the first then minimize the flowers wich is one 
    }

    for (int i = n - 2; i >= 0; i--)
    {

        if (templeHeight[i + 1] < templeHeight[i])
            flowers[i].R = flowers[i + 1].R + 1;

        else;
            //flowers[i].R = 1;
    }

    cout << "L: ";
    for (int i = 0; i < n; i++)
        cout << flowers[i].L << " ";
    cout << endl;

    cout << "    ";
    for (int i = 0; i < n; i++)
        cout << flowers[i].R << " ";
    cout << ":R ";
    cout << endl << endl;

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += max(flowers[i].L, flowers[i].R);

    cout << "the minimum number of flowers : " << sum << endl;
    cout << endl << endl << endl << endl << endl << endl;


    /*
    for (int i = 1; i < n; i++)
    {

        if (templeHeight[i] < templeHeight[i + 1]) {
            int f = templeHeight[i];
            for (int i = f; i > 0; i--)
            {
                for (int j = 0; j <= f; j++)
                {
                    if (j >= i)
                    {

                        if (j = f)
                             cout << f;


                        cout << "*";

                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }


        else {
            int z = templeHeight[i];
            int i = 0, j = 0;
            while (i < z) {
                while (j <= i) {
                    if (j = z)
                        cout << z;
                    cout << "* ";
                    j++;
                }
                j = 0;
                i++;
                cout << endl;
            }
        }

    }
    */ // FAILED BADLY
    // FAILED BADLY

   /*for (int i = 1; i < n; i++)
    {

        if (templeHeight[i] < templeHeight[i + 1]) {

            int rows = templeHeight[i];

            for (int i = 1; i <= rows; ++i)
            {
                for (int j = 1; j <= i; ++j)
                {
                    cout << "* ";
                }
                cout << "\n";
            }
            cout << rows << endl;
        }


        else {
            int rows = templeHeight[i];
            for (int i = rows; i >= 1; --i)
            {
                for (int j = 1; j <= i; ++j)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            cout << rows << endl;
        }



    }*/
    //filed but not really bad


    cout << "this is for the left way drawing" << endl;
    for (int i = 0; i < n; ++i) // left drawing
    {
        int n = templeHeight[i];

        if (n = templeHeight[0]) {
            int n = templeHeight[i];
            for (int j = 0; j < n; j++) {
                cout << "*";
            }
            cout << n << "  " << flowers[i].L  << " flowers" << endl;
        }
    }

    cout << endl << endl << endl;

    cout << "this is for the right way drawing" << endl;
    for (int i = 0; i < n; ++i) // right drawing
    {
        int n = templeHeight[i];

        if (n = templeHeight[0]) {
            int n = templeHeight[i];
            for (int j = 0; j < n; j++) {
                cout << "*";
            }
            cout << n << "  " << flowers[i].R << " flowers" << endl;
        }
    }







}

int main()
{
    cout << "enter the number of temples" << endl;
    int n;
    cin >> n;
    int* array_of_hights = new int[n];
    cout << "Enter the temples hights" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array_of_hights[i];
    }
    offeringNumber(n, array_of_hights);
}