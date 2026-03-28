def rec(n, is_even):
    if n == 1:
        if is_even:
            return 4
        else:
            return 5

    if is_even: # As the value alternates!
        return 4 * rec(n - 1, True) + 5 * rec(n - 1, False)
    else:
        return 5 * rec(n - 1, True) + 4 * rec(n - 1, False)


def main():
    n = int(input("Enter the digit number: "))
    print(rec(n, 0))


if __name__ == '__main__':
    main()
