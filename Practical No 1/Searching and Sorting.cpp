#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    float cgpa;
};

// Linear Search
int linearSearch(Student s[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(s[i].id == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(Student s[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(s[mid].id == key)
            return mid;

        if(key < s[mid].id)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

// Bubble Sort by Name
void bubbleSortName(Student s[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(s[j].name > s[j + 1].name)
            {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

// Selection Sort by CGPA
void selectionSortCGPA(Student s[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(s[j].cgpa < s[min].cgpa)
                min = j;
        }

        swap(s[i], s[min]);
    }
}

// Comparison function for sorting by ID
bool compareID(Student a, Student b)
{
    return a.id < b.id;
}

int main()
{
    int n;

    cout << "Enter Number of Students : ";
    cin >> n;

    Student *s = new Student[n];

    // Input
    for(int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "ID : ";
        cin >> s[i].id;

        cout << "Name : ";
        cin >> s[i].name;

        cout << "CGPA : ";
        cin >> s[i].cgpa;
    }

    // Display records
    cout << "\nStudent Records\n";

    for(int i = 0; i < n; i++)
    {
        cout << s[i].id << " "
             << s[i].name << " "
             << s[i].cgpa << endl;
    }

    // Linear Search
    int key;

    cout << "\nEnter ID to Search : ";
    cin >> key;

    int pos = linearSearch(s, n, key);

    if(pos != -1)
        cout << "Found using Linear Search" << endl;
    else
        cout << "Not Found" << endl;

    // Bubble Sort by Name
    bubbleSortName(s, n);

    cout << "\nSorted by Name\n";

    for(int i = 0; i < n; i++)
    {
        cout << s[i].id << " "
             << s[i].name << " "
             << s[i].cgpa << endl;
    }

    // Selection Sort by CGPA
    selectionSortCGPA(s, n);

    cout << "\nSorted by CGPA\n";

    for(int i = 0; i < n; i++)
    {
        cout << s[i].id << " "
             << s[i].name << " "
             << s[i].cgpa << endl;
    }

    // Sort by ID for Binary Search
    sort(s, s + n, compareID);

    // Binary Search
    pos = binarySearch(s, n, key);

    if(pos != -1)
        cout << "\nFound using Binary Search" << endl;
    else
        cout << "\nNot Found" << endl;

    delete[] s;

    return 0;
}
