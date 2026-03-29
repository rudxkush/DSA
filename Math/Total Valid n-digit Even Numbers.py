def rec(n, is_even):
    if n == 1:
        if is_even:
            return 4
        else:
            return 5

    if is_even: 
        return 4 * rec(n - 1, True) + 5 * rec(n - 1, False)
    else:
        return 5 * rec(n - 1, True) + 4 * rec(n - 1, False)


# Count n-digit even numbers, no leading zero, 
# no two consecutive digits equal.
def main():
    n = int(input("Enter the digit number: "))
    altFactor = (-1) ** n # As the value alternates!
    EvnCount = rec(n, 0) + altFactor 
    print('\n')
    print('Total valid n digit even numbers: {}'.format(EvnCount))
    totalOddEvn = 9 ** n
    oddCount = totalOddEvn - EvnCount
    print('Total valid n digit odd numbers: {}'.format(oddCount))


if __name__ == '__main__':
    main()
