int compareMyStrings(const char *arg1, const char *arg2);
int non_decreasing(double arr[], int number_elements);
int push_back(int el_val);

int push_back(int el_val)
{
}

int non_decreasing(double arr[], int number_elements)
{

    for (int i = 1; i < number_elements; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int compareMyStrings(const char *arg1, const char *arg2)
{
    int i = 0;

    while (arg1[i] != '\0')
    {
        if (arg1[i] == arg2[i])
        {
        }
    }
}

int main()
{
    double arr[] = {3, 3, 3, 5, 2};

    printf("%d", non_decreasing(arr, 5));

    return 0;
}